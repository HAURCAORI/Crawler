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

namespace Crawler {

CrawlingObject::CrawlingObject(rapidjson::Value& value) : mValue(value) {}

CrawlingObject::~CrawlingObject() noexcept {}

std::string CrawlingObject::getURL() const {
    if(!mValue.HasMember("URI")) { return "null"; }
    if(!mValue["URI"].HasMember("URL")) { return "null"; }
    if(!mValue["URI"]["URL"].IsString()) { return "null"; }
    return mValue["URI"]["URL"].GetString();
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
    if(index >= (*mDoc)[ROOT_NODE].Size()) { 
        throw std::out_of_range("CurlCrawler out of range.");
    }
    return CrawlingObject((*mDoc)[ROOT_NODE].GetArray()[index]);
}

CrawlingObject CURLCrawler::at(const std::string& id) {
    if(!(*mDoc)[ROOT_NODE].HasMember(id)) { 
        throw std::out_of_range("CurlCrawler out of range.");
    }
    return CrawlingObject((*mDoc)[ROOT_NODE][id]);
}

CrawlingObject CURLCrawler::operator[](size_t index) {
    return CrawlingObject((*mDoc)[ROOT_NODE].GetArray()[index]);
}

CrawlingObject CURLCrawler::operator[](const std::string& id) {
    return CrawlingObject((*mDoc)[ROOT_NODE][id]);
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

    // 상위 노드 확인
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