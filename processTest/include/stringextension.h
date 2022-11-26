#ifndef STRING_EXTENSION_H
#define STRING_EXTENSION_H

#include <string>
#include <vector>
#include <algorithm>

static inline bool isAlphabet(char ch) noexcept {
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
}

static inline bool isWord(char ch) noexcept {
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch & 0x80);
}

static inline bool isSpace(char ch) noexcept {
    return (ch == ' ') || (ch == '\r') || (ch == '\n')|| (ch == '\t'); 
}

static inline bool isEmpty(const std::string& str) noexcept {
    return str.empty() || (str == " ") || (str == "\r") || (str == "\n")|| (str == "\t");
}

// iter_begin 부터 iter_end까지 target이 포함되어 있는지 확인
// source: abcdef / target: abc => true / target: abd => false
static inline bool matchString(std::string::iterator iter_begin, std::string::iterator iter_end, const std::string& target) noexcept {
    bool match = true;
    auto it_target_tag = target.begin();
    for (auto it_tag = iter_begin; it_target_tag != target.end() && it_tag != iter_end; ++it_tag, ++it_target_tag) {
        if (*it_tag != *it_target_tag) {
            match = false;
            break;
        }
    }
    return match;
}

static inline std::vector<std::string> split(std::string s, std::string delimiter) noexcept {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

static inline std::string leftTrim(const std::string &str) {
    std::string ret(str);
    ret.erase(ret.begin(), std::find_if(ret.begin(), ret.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    return ret;
}

static inline std::string rightTrim(const std::string &str) {
    std::string ret(str);
    ret.erase(std::find_if(ret.rbegin(), ret.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), ret.end());
    return ret;
}


static inline std::string TrimAndLower(const std::string& str) noexcept {
    if(str.length() == 0) { return ""; }
    std::string ret(str);
    unsigned int f,e;
    f = ret.find_first_not_of("\t\r\n");
    e = ret.find_last_not_of("\t\r\n");

    if(f == std::string::npos) { return ""; }
    ret = std::string(ret,f,e-f+1);
    for (size_t a = 0; a < ret.size(); a++) {
		if (int(ret[a]) < 97&&isalpha(ret[a])) {
			ret[a] = ret[a] + 32;
        }
	}
    return ret;
}

static inline std::string TrimAndUpper(const std::string& str) noexcept {
    if(str.length() == 0) { return ""; }
    std::string ret(str);
    unsigned int f,e;
    f = ret.find_first_not_of("\t\r\n");
    e = ret.find_last_not_of("\t\r\n");

    if(f == std::string::npos) { return ""; }
    ret = std::string(ret,f,e-f+1);
    for (size_t a = 0; a < ret.size(); a++) {
		if (int(ret[a]) > 96&&isalpha(ret[a])) {
			ret[a] = ret[a] - 32;
        }
	}
    return ret;
}

static inline void stringAppendDelimiter(std::string& str, const std::string& append, const std::string& delimiter = ",") {
    if(str.empty()) {
        str += append;
    } else {
        str += delimiter;
        str += append;
    }
}

#endif