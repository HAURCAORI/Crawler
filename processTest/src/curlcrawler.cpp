#include "curlcrawler.h"
#define RAPIDJSON_HAS_STDSTRING 1
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/writer.h>

#include <fstream>
#include <unistd.h>
#include <chrono>
#include <iostream>

#include "stringextension.h"

static std::string ReplacePlaceholder(const std::string& original, size_t index, const std::string& str) {
    if(original.empty()) { return std::string(); }
    if(index > 9) { return original; }
    std::string ret(original);
    for(auto it = ret.begin(); it != ret.end(); ++it) {
        if(*it == '$') {
            if(!isdigit(*(it+1))) { continue; }
            if((*(it+1) - '0') == (int) index) {
                size_t pos = std::distance(ret.begin(), it);
                ret = ret.replace(it, it+2, str);
                it = ret.begin() + pos + str.size() - 1;
            }
        }
    }
    return ret;
}

static std::vector<std::string> ReplacePlaceholders(const std::string& original, const Crawler::Placeholders& plhs, size_t index = 0) {
    if(plhs.empty()) { return std::vector<std::string>(1,original); }
    if(index >= plhs.size()) { return std::vector<std::string>(1,original); }
    std::vector<std::string> ret;
    for(auto& el : plhs[index]) {
        std::string rep = ReplacePlaceholder(original, index, el);
        std::vector<std::string> temp = ReplacePlaceholders(rep, plhs, index+1);
        ret.insert(ret.end(),std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
        if(rep == original) {
            break;
        }
    }
    return ret;
}

namespace Crawler {

void CrawlingObject::enqueueObject(const std::string& url) {
    // URI : URL, Method, Headers, Options 처리 / Parameters, Placeholders는 전처리 됨
    // URL
    if(url.empty()) { return; }

    // POST의 경우 url에서 parameters 분리 
    std::string objectURL(url);
    std::string postFields;
    if(getMethod() == Method::POST) {
        if(url.find('?') != std::string::npos) {
            objectURL = url.substr(0, url.find('?'));
            postFields = url.substr(url.find('?') + 1);
        }
    }

    CURLObject obj(objectURL);
    if(!obj) { return; }

    // Method
    if(getMethod() == Method::POST) {
        obj.setOption(CURLOPT_POST, 1L);
        obj.setOption(CURLOPT_POSTFIELDS, postFields.c_str());
    }

    // Headers
    for(auto& list : getHeaders()) {
        if(list.find(':') != std::string::npos) {
            obj.appendHeader(list);
        }
    }
    
    // Options
    for(auto& list : getURIOptions()) {
        auto it = StringMapCURLOption.find(TrimAndUpper(list.first));
        if(it != StringMapCURLOption.end()) {
            std::string value = list.second;
            if(isdigit(value.front())) {
                obj.setOption(it->second, std::atol(value.c_str()));
            } else {
                obj.setOption(it->second, value);
            }
        } else {
            fprintf(stderr, "Unknown option '%s'", list.first.c_str());
        }
    }
    
    // Output 처리
    // Adapter

    switch (getAdapter()) {
    case AdapterType::IO_ADAPTER_CONSOLE:
        obj.setAdapter<Crawler::IOAdapterConsole>();
        break;
    case AdapterType::IO_ADAPTER_FILE:
        obj.setAdapter<Crawler::IOAdapterFile>();
        break;
    default:
        // default :: IO_ADAPTER
        obj.setAdapter<Crawler::IOAdapter>();
        break;
    }


    // Options
    for(auto& list : getOutputOptions()) {
        auto it = StringMapAdapterOption.find(TrimAndUpper(list.first));
        if(it != StringMapAdapterOption.end()) {
            std::string value = list.second;
            if(TrimAndLower(value) == "true") {
                obj.setAdapterOption(it->second, true);
            } else if(TrimAndLower(value) == "false") {
                obj.setAdapterOption(it->second, false);
            } else if(isdigit(value.front())) {
                obj.setAdapterOption(it->second, std::atoi(value.c_str()));
            } else {
                obj.setAdapterOption(it->second, value);
            }
        } else {
            fprintf(stderr, "Unknown adapter option '%s'", list.first.c_str());
        }
    }

    // Target with Placeholder
    obj.setAdapterTarget(ReplacePlaceholders(getTarget(), getOutputPlaceholders()));


    // future 객체를 통해 성공 여부 확인
    auto task = std::packaged_task<void(bool)>([this](bool result) { success(result); });
    mFuture = task.get_future();
    obj.setCallback(std::move(task));
    CURLThreadPool::getInstance().EnqueueCURL(std::move(obj));
}

void CrawlingObject::success(bool result) {
    // Info 업데이트(Success, Timestamp, PerformCount, Details)
    if(!mCrawlingNode.HasMember("Info")) { return; }
    if(!mCrawlingNode["Info"].HasMember("Success")) { return; }
    if(!mCrawlingNode["Info"]["Success"].IsBool()) { return; }
    if(!mCrawlingNode["Info"].HasMember("Timestamp")) { return; }
    if(!mCrawlingNode["Info"]["Timestamp"].IsInt64()) { return; }
    if(!mCrawlingNode["Info"].HasMember("PerformCount")) { return; }
    if(!mCrawlingNode["Info"]["PerformCount"].IsInt()) { return; }
    if(!mCrawlingNode["Info"].HasMember("Details")) { return; }
    if(!mCrawlingNode["Info"]["Details"].IsString()) { return; }
    
    if(result) {
        mCrawlingNode["Info"]["Success"].SetBool(true);
        mCrawlingNode["Info"]["Details"].SetString("");
    } else {
        mCrawlingNode["Info"]["Success"].SetBool(false);
        mCrawlingNode["Info"]["Details"].SetString("perform fail");
    }

    mCrawlingNode["Info"]["Timestamp"].SetInt64(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    int count = mCrawlingNode["Info"]["PerformCount"].GetInt();
    mCrawlingNode["Info"]["PerformCount"].SetInt(count + 1);
}

CrawlingObject::CrawlingObject(rapidjson::Value& value, rapidjson::Allocation& allocation) : mCrawlingNode(value), alloc(allocation) {}

CrawlingObject::~CrawlingObject() noexcept {
    using namespace std::chrono_literals;
    mFuture.wait_for(10s);
}

// Process
void CrawlingObject::execute() {
    std::string url = getURL();
    std::string parameters = getParameters();
    if(!parameters.empty()) {
        if(parameters.front() != '?') {
            parameters.insert(0, "?");
        }
        url.append(parameters);
    }

    auto strs = ReplacePlaceholders(url, getURLPlaceholders());
    for(auto& s : strs) {
        enqueueObject(s);
    }
}

// URI
std::string CrawlingObject::getURL() const {
    if(!mCrawlingNode.HasMember("URI")) { return std::string(); }
    if(!mCrawlingNode["URI"].HasMember("URL")) { return std::string(); }
    if(!mCrawlingNode["URI"]["URL"].IsString()) { return std::string(); }
    return mCrawlingNode["URI"]["URL"].GetString();
}

Method CrawlingObject::getMethod() const {
    if(!mCrawlingNode.HasMember("URI")) { return Method::NONE; }
    if(!mCrawlingNode["URI"].HasMember("Method")) { return Method::NONE; }
    if(!mCrawlingNode["URI"]["Method"].IsString()) { return Method::NONE; }
    std::string value = TrimAndLower(mCrawlingNode["URI"]["Method"].GetString());
    if(value == "get") {
        return Method::GET;
    } else if(value == "post") {
        return Method::POST;
    } else {
        return Method::NONE;
    }
}

std::vector<std::string> CrawlingObject::getHeaders() const {
    std::vector<std::string> ret;
    if(!mCrawlingNode.HasMember("URI")) { return ret; }
    if(!mCrawlingNode["URI"].HasMember("Headers")) { return ret; }
    if(!mCrawlingNode["URI"]["Headers"].IsArray()) { return ret; }
    for(const auto& list : mCrawlingNode["URI"]["Headers"].GetArray()) {
        if(!list.IsString()) { break; }
        ret.push_back(list.GetString());        
    }
    return ret;
}

Options CrawlingObject::getURIOptions() const {
    Options ret;
    if(!mCrawlingNode.HasMember("URI")) { return ret; }
    if(!mCrawlingNode["URI"].HasMember("Options")) { return ret; }
    if(!mCrawlingNode["URI"]["Options"].IsArray()) { return ret; }
    for(const auto& list : mCrawlingNode["URI"]["Options"].GetArray()) {
        if(!list.IsObject()) { break; }
        if(!list.MemberBegin()->name.IsString()) { break; }
        if(!list.MemberBegin()->value.IsString()) { break; }
        ret.push_back(std::make_pair<std::string,std::string>(list.MemberBegin()->name.GetString(), list.MemberBegin()->value.GetString()));        
    }
    return ret;
}

std::string CrawlingObject::getParameters() const {
    if(!mCrawlingNode.HasMember("URI")) { return std::string(); }
    if(!mCrawlingNode["URI"].HasMember("Parameters")) { return std::string(); }
    if(!mCrawlingNode["URI"]["Parameters"].IsString()) { return std::string(); }
    return mCrawlingNode["URI"]["Parameters"].GetString();
}

Placeholders CrawlingObject::getURLPlaceholders() const {
    Placeholders ret;
    if(!mCrawlingNode.HasMember("URI")) { return ret; }
    if(!mCrawlingNode["URI"].HasMember("Placeholders")) { return ret; }
    if(!mCrawlingNode["URI"]["Placeholders"].IsArray()) { return ret; }
    for(const auto& list : mCrawlingNode["URI"]["Placeholders"].GetArray()) {
        if(!list.IsArray()) { break; }
        Placeholder item;
        for(const auto& arr : list.GetArray()) {
            if(!arr.IsString()) { break; }
            item.push_back(arr.GetString());
        }  
        ret.push_back(item);
    }
    return ret;
}

void CrawlingObject::setURL(const std::string& url) {
    if(!mCrawlingNode.HasMember("URI")) { return; }
    if(!mCrawlingNode["URI"].HasMember("URL")) { return; }
    mCrawlingNode["URI"]["URL"].SetString(url, alloc);
}

void CrawlingObject::setMethod(Method method) {
    if(!mCrawlingNode.HasMember("URI")) { return; }
    if(!mCrawlingNode["URI"].HasMember("Method")) { return; }
    switch(method) {
        case Method::GET: mCrawlingNode["URI"]["Method"].SetString("GET", alloc);
        break;
        case Method::POST: mCrawlingNode["URI"]["Method"].SetString("POST", alloc);
        break;
        default: mCrawlingNode["URI"]["Method"].SetString(std::string(), alloc);
        break;
    }
}

void CrawlingObject::setHeaders(const Headers& headers) {
    if(!mCrawlingNode.HasMember("URI")) { return; }
    if(!mCrawlingNode["URI"].HasMember("Headers")) { return; }
    if(!mCrawlingNode["URI"]["Headers"].IsArray()) { return; }
    mCrawlingNode["URI"]["Headers"].Clear();
    for(auto& el : headers) {
        mCrawlingNode["URI"]["Headers"].PushBack(rapidjson::Value(el, alloc).Move(), alloc);
    }
}

void CrawlingObject::appendHeader(const std::string& header){
    if(!mCrawlingNode.HasMember("URI")) { return; }
    if(!mCrawlingNode["URI"].HasMember("Headers")) { return; }
    if(!mCrawlingNode["URI"]["Headers"].IsArray()) { return; }
    mCrawlingNode["URI"]["Headers"].PushBack(rapidjson::Value(header, alloc).Move(), alloc);
}

void CrawlingObject::setURIOptions(const Options& options) {
    if(!mCrawlingNode.HasMember("URI")) { return; }
    if(!mCrawlingNode["URI"].HasMember("Options")) { return; }
    if(!mCrawlingNode["URI"]["Options"].IsArray()) { return; }
    mCrawlingNode["URI"]["Options"].Clear();
    for(auto& el : options) {
        rapidjson::Value node(rapidjson::kObjectType);
        node.AddMember(rapidjson::Value(el.first,alloc).Move(), rapidjson::Value(el.second,alloc).Move(), alloc);
        mCrawlingNode["URI"]["Options"].PushBack(node.Move(), alloc);
    }
}

void CrawlingObject::appendURIOption(const Option& option) {
    if(!mCrawlingNode.HasMember("URI")) { return; }
    if(!mCrawlingNode["URI"].HasMember("Options")) { return; }
    if(!mCrawlingNode["URI"]["Options"].IsArray()) { return; }
    rapidjson::Value node(rapidjson::kObjectType);
    node.AddMember(rapidjson::Value(option.first,alloc).Move(), rapidjson::Value(option.second,alloc).Move(), alloc);
    mCrawlingNode["URI"]["Options"].PushBack(node.Move(), alloc);
}

void CrawlingObject::setParameters(const std::string& parameters){
    if(!mCrawlingNode.HasMember("URI")) { return; }
    if(!mCrawlingNode["URI"].HasMember("Parameters")) { return; }
    mCrawlingNode["URI"]["Parameters"].SetString(parameters, alloc);
}

void CrawlingObject::setURLPlaceholders(const Placeholders& placeholders) {
    if(!mCrawlingNode.HasMember("URI")) { return; }
    if(!mCrawlingNode["URI"].HasMember("Placeholders")) { return; }
    if(!mCrawlingNode["URI"]["Placeholders"].IsArray()) { return; }
    mCrawlingNode["URI"]["Placeholders"].Clear();
    for(auto& el : placeholders) {
        rapidjson::Value temp(rapidjson::kArrayType);
        for(auto& arr : el) {
            temp.PushBack(rapidjson::Value(arr, alloc).Move(),alloc);
        }
        mCrawlingNode["URI"]["Placeholders"].PushBack(temp.Move(), alloc);
    }
}

// OUTPUT
std::string CrawlingObject::getTarget() const {
    if(!mCrawlingNode.HasMember("Output")) { return std::string(); }
    if(!mCrawlingNode["Output"].HasMember("Target")) { return std::string(); }
    if(!mCrawlingNode["Output"]["Target"].IsString()) { return std::string(); }
    return mCrawlingNode["Output"]["Target"].GetString();
}

OutputType CrawlingObject::getOutputType() const {
    if(!mCrawlingNode.HasMember("Output")) { return OutputType::NONE; }
    if(!mCrawlingNode["Output"].HasMember("Type")) { return OutputType::NONE; }
    if(!mCrawlingNode["Output"]["Type"].IsString()) { return OutputType::NONE; }
    std::string value = TrimAndLower(mCrawlingNode["Output"]["Type"].GetString());
    if(value == "string") {
        return OutputType::String;
    } else if(value == "value") {
        return OutputType::Value;
    } else if(value == "bool") {
        return OutputType::Bool;
    } else {
        return OutputType::NONE;
    }
}

AdapterType CrawlingObject::getAdapter() const {
    if(!mCrawlingNode.HasMember("Output")) { return AdapterType::NONE; }
    if(!mCrawlingNode["Output"].HasMember("Adapter")) { return AdapterType::NONE; }
    if(!mCrawlingNode["Output"]["Adapter"].IsString()) { return AdapterType::NONE; }
    std::string value = TrimAndUpper(mCrawlingNode["Output"]["Adapter"].GetString());
    if(value == "IO_ADAPTER" ) {
        return AdapterType::IO_ADAPTER;
    } else if(value == "IO_ADAPTER_CONSOLE" ) {
        return AdapterType::IO_ADAPTER_CONSOLE;
    } else if(value == "IO_ADAPTER_FILE" ) {
        return AdapterType::IO_ADAPTER_FILE;
    } else {
        return AdapterType::IO_ADAPTER;
    }
}

Options CrawlingObject::getOutputOptions() const {
    Options ret;
    if(!mCrawlingNode.HasMember("Output")) { return ret; }
    if(!mCrawlingNode["Output"].HasMember("Options")) { return ret; }
    if(!mCrawlingNode["Output"]["Options"].IsArray()) { return ret; }
    for(const auto& list : mCrawlingNode["Output"]["Options"].GetArray()) {
        if(!list.IsObject()) { break; }
        if(!list.MemberBegin()->name.IsString()) { break; }
        if(!list.MemberBegin()->value.IsString()) { break; }
        ret.push_back(std::make_pair<std::string,std::string>(list.MemberBegin()->name.GetString(), list.MemberBegin()->value.GetString()));        
    }
    return ret;
}

Placeholders CrawlingObject::getOutputPlaceholders() const {
    Placeholders ret;
    if(!mCrawlingNode.HasMember("Output")) { return ret; }
    if(!mCrawlingNode["Output"].HasMember("Placeholders")) { return ret; }
    if(!mCrawlingNode["Output"]["Placeholders"].IsArray()) { return ret; }
    for(const auto& list : mCrawlingNode["Output"]["Placeholders"].GetArray()) {
        if(!list.IsArray()) { break; }
        Placeholder item;
        for(const auto& arr : list.GetArray()) {
            if(!arr.IsString()) { break; }
            item.push_back(arr.GetString());
        }  
        ret.push_back(item);    
    }
    return ret;
}

void CrawlingObject::setTarget(const std::string& target) {
    if(!mCrawlingNode.HasMember("Output")) { return; }
    if(!mCrawlingNode["Output"].HasMember("Target")) { return; }
    mCrawlingNode["Output"]["Target"].SetString(target, alloc);
}

void CrawlingObject::setOutputType(OutputType outputtype) {
    if(!mCrawlingNode.HasMember("Output")) { return; }
    if(!mCrawlingNode["Output"].HasMember("Type")) { return; }
    switch(outputtype) {
        case OutputType::String : mCrawlingNode["Output"]["Type"].SetString("String", alloc);
        break;
        case OutputType::Value : mCrawlingNode["Output"]["Type"].SetString("Value", alloc);
        break;
        case OutputType::Bool : mCrawlingNode["Output"]["Type"].SetString("Bool", alloc);
        break;
        default: mCrawlingNode["Output"]["Type"].SetString("NULL", alloc);
        break;
    }
}

void CrawlingObject::setAdapter(AdapterType adapter) {
    if(!mCrawlingNode.HasMember("Output")) { return; }
    if(!mCrawlingNode["Output"].HasMember("Adapter")) { return; }
    switch(adapter) {
        case AdapterType::IO_ADAPTER : mCrawlingNode["Output"]["Adapter"].SetString("IO_ADAPTER", alloc);
        break;
        case AdapterType::IO_ADAPTER_CONSOLE : mCrawlingNode["Output"]["Adapter"].SetString("IO_ADAPTER_CONSOLE", alloc);
        break;
        case AdapterType::IO_ADAPTER_FILE : mCrawlingNode["Output"]["Adapter"].SetString("IO_ADAPTER_FILE", alloc);
        break;
        default: mCrawlingNode["Output"]["Adapter"].SetString("NULL", alloc);
        break;
    }
}

void CrawlingObject::setOutputOptions(const Options& options) {
    if(!mCrawlingNode.HasMember("Output")) { return; }
    if(!mCrawlingNode["Output"].HasMember("Options")) { return; }
    if(!mCrawlingNode["Output"]["Options"].IsArray()) { return; }
    mCrawlingNode["Output"]["Options"].Clear();
    for(auto& el : options) {
        rapidjson::Value node(rapidjson::kObjectType);
        node.AddMember(rapidjson::Value(el.first,alloc).Move(), rapidjson::Value(el.second,alloc).Move(), alloc);
        mCrawlingNode["Output"]["Options"].PushBack(node.Move(), alloc);
    }
}

void CrawlingObject::appendOutputOption(const Option& option) {
    if(!mCrawlingNode.HasMember("Output")) { return; }
    if(!mCrawlingNode["Output"].HasMember("Options")) { return; }
    if(!mCrawlingNode["Output"]["Options"].IsArray()) { return; }
    rapidjson::Value node(rapidjson::kObjectType);
    node.AddMember(rapidjson::Value(option.first,alloc).Move(), rapidjson::Value(option.second,alloc).Move(), alloc);
    mCrawlingNode["Output"]["Options"].PushBack(node.Move(), alloc);
}

void CrawlingObject::setOutputPlaceholders(const Placeholders& placeholders) {
    if(!mCrawlingNode.HasMember("Output")) { return; }
    if(!mCrawlingNode["Output"].HasMember("Placeholders")) { return; }
    if(!mCrawlingNode["Output"]["Placeholders"].IsArray()) { return; }
    mCrawlingNode["Output"]["Placeholders"].Clear();
    for(auto& el : placeholders) {
        rapidjson::Value temp(rapidjson::kArrayType);
        for(auto& arr : el) {
            temp.PushBack(rapidjson::Value(arr, alloc).Move(),alloc);
        }
        mCrawlingNode["URI"]["Placeholders"].PushBack(temp.Move(), alloc);
    }
}

// SCHEDULE
ScheduleType CrawlingObject::getScheduleType() const {
    if(!mCrawlingNode.HasMember("Schedule")) { return ScheduleType::NONE; }
    if(!mCrawlingNode["Schedule"].HasMember("Type")) { return ScheduleType::NONE; }
    if(!mCrawlingNode["Schedule"]["Type"].IsString()) { return ScheduleType::NONE; }
    std::string value = TrimAndLower(mCrawlingNode["Schedule"]["Type"].GetString());
    if(value == "once") {
        return ScheduleType::Once;
    } else if(value == "time") {
        return ScheduleType::Time;
    } else if(value == "interval") {
        return ScheduleType::Interval;
    } else if(value == "weekly") {
        return ScheduleType::Weekly;
    } else if(value == "daily") {
        return ScheduleType::Daily;
    } else {
        return ScheduleType::NONE;
    }
}

std::string CrawlingObject::getScheduleValue() const {
    if(!mCrawlingNode.HasMember("Schedule")) { return std::string(); }
    if(!mCrawlingNode["Schedule"].HasMember("Value")) { return std::string(); }
    if(!mCrawlingNode["Schedule"]["Value"].IsString()) { return std::string(); }
    return mCrawlingNode["Schedule"]["Value"].GetString();
}

void CrawlingObject::setScheduleType(ScheduleType scheduletype) {
    if(!mCrawlingNode.HasMember("Schedule")) { return; }
    if(!mCrawlingNode["Schedule"].HasMember("Type")) { return; }
    switch(scheduletype) {
        case ScheduleType::Once: mCrawlingNode["Schedule"]["Type"].SetString("Once", alloc);
        break;
        case ScheduleType::Time : mCrawlingNode["Schedule"]["Type"].SetString("Time", alloc);
        break;
        case ScheduleType::Interval : mCrawlingNode["Schedule"]["Type"].SetString("Interval", alloc);
        break;
        case ScheduleType::Weekly : mCrawlingNode["Schedule"]["Type"].SetString("Weekly", alloc);
        break;
        case ScheduleType::Daily : mCrawlingNode["Schedule"]["Type"].SetString("Daily", alloc);
        break;
        default: mCrawlingNode["Schedule"]["Type"].SetString("NULL", alloc);
        break;
    }
}

void CrawlingObject::setScheduleValue(const std::string& value) {
    if(!mCrawlingNode.HasMember("Schedule")) { return; }
    if(!mCrawlingNode["Schedule"].HasMember("Value")) { return; }
    mCrawlingNode["Schedule"]["Value"].SetString(value, alloc);
}

// INFO
bool CrawlingObject::isValid() const {
    if(!mCrawlingNode.HasMember("Info")) { return false; }
    if(!mCrawlingNode["Info"].HasMember("Valid")) { return false; }
    if(!mCrawlingNode["Info"]["Valid"].IsBool()) { return false; }
    return mCrawlingNode["Info"]["Valid"].GetBool();
}

bool CrawlingObject::isSuccess() const {
    if(!mCrawlingNode.HasMember("Info")) { return false; }
    if(!mCrawlingNode["Info"].HasMember("Success")) { return false; }
    if(!mCrawlingNode["Info"]["Success"].IsBool()) { return false; }
    return mCrawlingNode["Info"]["Success"].GetBool();
}

int64_t CrawlingObject::getTimestamp() const {
    if(!mCrawlingNode.HasMember("Info")) { return 0; }
    if(!mCrawlingNode["Info"].HasMember("Timestamp")) { return 0; }
    if(!mCrawlingNode["Info"]["Timestamp"].IsInt64()) { return 0; }
    return mCrawlingNode["Info"]["Timestamp"].GetInt64();
}

int CrawlingObject::getPerformCount() const {
    if(!mCrawlingNode.HasMember("Info")) { return 0; }
    if(!mCrawlingNode["Info"].HasMember("PerformCount")) { return 0; }
    if(!mCrawlingNode["Info"]["PerformCount"].IsInt()) { return 0; }
    return mCrawlingNode["Info"]["PerformCount"].GetInt();
}

std::string CrawlingObject::getDetails() const {
    if(!mCrawlingNode.HasMember("Info")) { return 0; }
    if(!mCrawlingNode["Info"].HasMember("Details")) { return 0; }
    if(!mCrawlingNode["Info"]["Details"].IsString()) { return 0; }
    return mCrawlingNode["Info"]["Details"].GetString();
}


CURLCrawler::CURLCrawler() : mDoc(std::make_unique<rapidjson::Document>()) {
    
}

CURLCrawler::~CURLCrawler() noexcept {
    saveListFile();
}

bool CURLCrawler::loadList(const std::string& path) {
    mListFilePath = path;
    return loadListFile();
}

bool CURLCrawler::createListFile(const std::string& path, bool trunc) {
    if(!trunc) {
        if(access(path.c_str(),F_OK) != -1) {
            fprintf(stderr, "File already exists.\r\n");
            return false;
        }
    }
    std::ofstream ofs(path);
    ofs << DEFAULT_JSON;
    return true;
}

void CURLCrawler::addList(const std::string& id, const URI& uri, Output output, Schedule schedule) {
    if(!isLoaded) { return; }
    if(!mDoc->HasMember(ROOT_NODE)) { return; }
    (*mDoc)[ROOT_NODE].PushBack(createListNode(id, uri, output, schedule).Move(), mDoc->GetAllocator());
}

void CURLCrawler::addList(const std::string& id, const std::string& url, const std::string& target, Adapter adapter) {
    if(!isLoaded) { return; }
    if(!mDoc->HasMember(ROOT_NODE)) { return; }
    (*mDoc)[ROOT_NODE].PushBack(createListNode(id,URI(url), Output(target, adapter), Schedule()).Move(), mDoc->GetAllocator());
}

CrawlingObject CURLCrawler::at(size_t index) {
    if(!isLoaded) {
        throw std::runtime_error("JSON file doesn't loaded.");
    }
    if(index >= (*mDoc)[ROOT_NODE].Size()) { 
        throw std::out_of_range("CurlCrawler out of range.");
    }
    return CrawlingObject((*mDoc)[ROOT_NODE].GetArray()[index], mDoc->GetAllocator());
}

CrawlingObject CURLCrawler::at(const std::string& id) {
    if(!(*mDoc)[ROOT_NODE].HasMember(id)) { 
        throw std::out_of_range("CurlCrawler out of range.");
    }
    return CrawlingObject((*mDoc)[ROOT_NODE][id], mDoc->GetAllocator());
}

CrawlingObject CURLCrawler::operator[](size_t index) {
    return CrawlingObject((*mDoc)[ROOT_NODE].GetArray()[index], mDoc->GetAllocator());
}

CrawlingObject CURLCrawler::operator[](const std::string& id) {
    return CrawlingObject((*mDoc)[ROOT_NODE][id], mDoc->GetAllocator());
}

rapidjson::Value CURLCrawler::createListNode(const std::string& id, const URI& uri, const Output& output, const Schedule& schedule) {
    auto& alloc = mDoc->GetAllocator();
    rapidjson::Value object(rapidjson::kObjectType);
    // ID Node
    {
        object.AddMember("ID", id, alloc);
        mCount++;
    }

    // URI Node
    {
        rapidjson::Value node_URI(rapidjson::kObjectType);
        node_URI.AddMember("URL", uri.url, alloc);
        node_URI.AddMember("Method", strMethod.at(uri.method), alloc);
        rapidjson::Value node_Headers(rapidjson::kArrayType);
        for(auto& el : uri.headers) { node_Headers.PushBack(rapidjson::Value(el, alloc).Move(), alloc); }
        node_URI.AddMember("Headers",node_Headers, alloc);
        node_URI.AddMember("Parameters", uri.parameters, alloc);
        rapidjson::Value node_Placeholders(rapidjson::kArrayType);
        for(auto& el : uri.placeholders) { node_Placeholders.PushBack(rapidjson::Value(el, alloc).Move(), alloc); }
        node_URI.AddMember("Placeholders", node_Placeholders.Move(), alloc);
        node_URI.AddMember("Options", rapidjson::Value(rapidjson::kArrayType), alloc);
        object.AddMember("URI", node_URI.Move(), alloc);
    }

    // Output Node
    {
        rapidjson::Value node_Output(rapidjson::kObjectType);
        node_Output.AddMember("Target", output.target, alloc);
        rapidjson::Value node_Placeholders(rapidjson::kArrayType);
        for(const auto& el : output.placeholders) { node_Placeholders.PushBack(rapidjson::Value(el, alloc).Move(), alloc); }
        node_Output.AddMember("Placeholders", node_Placeholders.Move(), alloc);
        node_Output.AddMember("Type", strOutputType.at(output.type), alloc);
        node_Output.AddMember("Adapter", strAdapter.at(output.adapter), alloc);
        node_Output.AddMember("Options", rapidjson::Value(rapidjson::kArrayType), alloc);
        object.AddMember("Output", node_Output.Move(), alloc);
    }
    
    // Schedule Node
    {
        rapidjson::Value node_Schedule(rapidjson::kObjectType);
        node_Schedule.AddMember("Type", strScheduleType.at(schedule.type), alloc);
        node_Schedule.AddMember("Value", schedule.value, alloc);
        object.AddMember("Schedule", node_Schedule.Move(), alloc);
    }

    // Info Node
    {
        object.AddMember("Info", createInfoNode().Move(), alloc);
    }

    validCheck(object);
    return object;
}

rapidjson::Value CURLCrawler::createInfoNode() {
    auto& alloc = mDoc->GetAllocator();
    rapidjson::Value node_Info(rapidjson::kObjectType);
    node_Info.AddMember("Valid", false, alloc);
    node_Info.AddMember("Success", false, alloc);
    node_Info.AddMember("Timestamp", std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(), alloc);
    node_Info.AddMember("PerformCount", 0, alloc);
    node_Info.AddMember("Details", "", alloc);
    return node_Info;
}

void CURLCrawler::validCheckAll() {
    for(auto& node : (*mDoc)[ROOT_NODE].GetArray()) {
        validCheck(node);
    }
}

void CURLCrawler::validCheck(rapidjson::Value& node) {
    auto& alloc = mDoc->GetAllocator();
    // Info의 모든 노드가 갖추어졌는지 확인.
    if(!node.HasMember("Info")) {
        node.AddMember("Info", createInfoNode().Move(), alloc);
    } else {
        if(!node["Info"].HasMember("Valid")) {
            node["Info"].AddMember("Valid", false, alloc);
        }
        if(!node["Info"].HasMember("Success")) {
            node["Info"].AddMember("Success", false, alloc);
        }
        if(!node["Info"].HasMember("Timestamp")) {
            node["Info"].AddMember("Timestamp", std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(), alloc);
        }
        if(!node["Info"].HasMember("PerformCount")) {
            node["Info"].AddMember("PerformCount", 0, alloc);
        }
        if(!node["Info"].HasMember("Details")) {
            node["Info"].AddMember("Details", 0, alloc);
        }
    }

    // 상위 필수 노드 확인
    node["Info"]["Valid"].SetBool(false);
    if(!node.HasMember("ID") || !node.HasMember("URI") || !node.HasMember("Output") || !node.HasMember("Schedule")) {
        node["Info"]["Details"].SetString("Requires : 'ID', 'URI', 'Output', 'Schedule'\r\n");
        return;
    }

    if(!node["URI"].HasMember("URL") || !node["URI"].HasMember("Headers")) {
        node["Info"]["Details"].SetString("URL Requires : 'URL', 'Headers'\r\n");
        return;
    }

    if(!node["Output"].HasMember("Target") || !node["Output"].HasMember("Adapter") || !node["Output"].HasMember("Options")) {
        node["Info"]["Details"].SetString("Output Requires : 'Target', 'Adapter', 'Options'\r\n");
        return;
    }

    if(!node["Schedule"].HasMember("Type") || !node["Schedule"].HasMember("Value")) {
        node["Info"]["Details"].SetString("Schedule Requires : 'Type', 'Value'\r\n");
        return;
    }
    node["Info"]["Valid"].SetBool(true);
}

bool CURLCrawler::saveListFile() noexcept{
    if(!isLoaded) { return true; }
    std::ofstream ofs(mListFilePath);
    rapidjson::OStreamWrapper osw(ofs);
    rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);
    bool ret = mDoc->Accept(writer);
    if(!ret) {
        fprintf(stderr, "Error while saving file.\r\n");
        return false;
    }
    return true;
}

bool CURLCrawler::loadListFile() {
    isLoaded = false;
    if(access(mListFilePath.c_str(),F_OK) == -1) {
        createListFile(mListFilePath);
    }

    std::ifstream ifs(mListFilePath);

    if(!ifs.good()) {
        fprintf(stderr, "Error while opening file.\r\n");
        return false;
    }
    rapidjson::IStreamWrapper isw(ifs);
    rapidjson::ParseResult ret = mDoc->ParseStream(isw);
    if(!ret) {
        fprintf(stderr, "JSON parse error\r\n");
        return false;
    }

    if(!mDoc->HasMember(ROOT_NODE)) {
        fprintf(stderr, "CrawlingLists file must have 'CrawlingList' node\r\n");
        return false;
    }

    if(!(*mDoc)[ROOT_NODE].IsArray()) {
        fprintf(stderr, "'CrawlingList' node must be Array\r\n");
        return false;
    }

    validCheckAll();

    isLoaded = true;
    return true;
}

const std::string CURLCrawler::DEFAULT_PATH = "./CrawlingLists.json";
const std::string CURLCrawler::DEFAULT_JSON = "{\"CrawlingList\":[]}";
const char* CURLCrawler::ROOT_NODE = "CrawlingList";
}