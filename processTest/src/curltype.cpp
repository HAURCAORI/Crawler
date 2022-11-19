#include "curltype.h"
#include "stringextension.h"

namespace Crawler {

MIME::MIME(const std::string& mime) {
    std::string str = TrimAndLower(mime);
    if(str.find('/') != std::string::npos){
        type = str.substr(0,str.find('/'));
        subtype = str.substr(str.find('/')+1);
    } else {
        type = str;
    }
}

bool MIME::operator==(const MIME& rhs) {
    return (type == rhs.type) && (subtype == rhs.subtype);
}

}