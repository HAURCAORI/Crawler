#pragma once
#include <string>
#include <map>

namespace Crawler {

// MIME struct
struct MIME {
    std::string type;
    std::string subtype;
    MIME(const std::string& type, const std::string& subtype);
    std::string get();
};

// MIME presets
static const MIME MIME_TEXT_PLAIN = MIME("text","plain");
static const MIME MIME_TEXT_CSS = MIME("text","css");
static const MIME MIME_TEXT_CSV = MIME("text","csv");
static const MIME MIME_TEXT_HTML = MIME("text","html");
static const MIME MIME_TEXT_XML = MIME("text","xml");
static const MIME MIME_MULTI_FORM = MIME("multipart","form-data");
static const MIME MIME_IMAGE_PNG = MIME("image","png");
static const MIME MIME_IMAGE_JPEG = MIME("image","jpeg");
static const MIME MIME_AUDIO_MPEG = MIME("audio","mpeg");
static const MIME MIME_APP_ZIP = MIME("application","zip");
static const MIME MIME_APP_XML = MIME("application","xml");
static const MIME MIME_APP_URLENCODED = MIME("application","x-www-form-urlencoded");
static const MIME MIME_APP_PDF = MIME("application","pdf");
static const MIME MIME_APP_JSON = MIME("application","json");
static const MIME MIME_APP_JAVASCRIPT = MIME("application","javascript");


// HTML header updated(22.10.10).
enum class HTMLHeader {
    // General Headers
    date, pragma, cacheControl, upgrade, via, connection, transferEncoding,
    // Request Headers
    host, userAgent, referer, accept, acceptCharset, acceptLanguage, acceptEncoding,
    ifModifiedSince, authorization, origin, cookie,
    // Response Headers
    server, age, referrerPolicy, wwwAuthenticate, proxyAuthenticate, setCookie,
    // Entity Headers
    contentType, contentLength, contentLanguage, contentLocation, contentDisposition,
    contentSecurityPolicy, contentEncoding, location, lastModified, allow, expires, etag
};

static const std::map<HTMLHeader, std::string> HTMLHeaderString;

}
