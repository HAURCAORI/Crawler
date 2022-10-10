#include <curltype.h>

namespace Crawler {

MIME::MIME(const std::string& type, const std::string& subtype) : type(type), subtype(subtype) {}
std::string MIME::get() { return type + "/" + subtype; }

const std::map<HTMLHeader, std::string> HTMLHeaderString = {
    // General Headers
    { HTMLHeader::date, "Date" }, { HTMLHeader::pragma, "Pragma" }, { HTMLHeader::cacheControl, "Cache-Control" },
    { HTMLHeader::upgrade, "Upgrade" }, { HTMLHeader::via, "Via" }, { HTMLHeader::connection, "Connection" }, { HTMLHeader::transferEncoding, "Transfer-Encoding" },
    // Request Headers
    { HTMLHeader::host, "HOST" }, { HTMLHeader::userAgent, "User-agent" }, { HTMLHeader::referer, "Referer" },
    { HTMLHeader::accept, "Accept" }, { HTMLHeader::acceptCharset, "Accept-charset" }, { HTMLHeader::acceptLanguage, "Accept-language" },
    { HTMLHeader::acceptEncoding, "Accept-encoding" }, { HTMLHeader::ifModifiedSince, "If-Modified-Since" },
    { HTMLHeader::authorization, "Authorization" }, { HTMLHeader::origin, "Origin" }, { HTMLHeader::cookie, "Cookie" },
    // Response Headers
    { HTMLHeader::server, "Server" }, { HTMLHeader::age, "Age" }, { HTMLHeader::referrerPolicy, "Referrer-policy" },
    { HTMLHeader::wwwAuthenticate, "WWW-Authenticate" }, { HTMLHeader::proxyAuthenticate, "Proxy-Authenticate" }, { HTMLHeader::setCookie, "Set-Cookie" },
    // Entity Headers
    { HTMLHeader::contentType, "Content-type" }, { HTMLHeader::contentLength, "Content-Length" }, { HTMLHeader::contentLanguage, "Content-language" },
    { HTMLHeader::contentLocation, "Content-location" }, { HTMLHeader::contentDisposition, "Content-disposition" }, { HTMLHeader::contentSecurityPolicy, "Content-Security-Policy" },
    { HTMLHeader::contentEncoding, "Content-Encoding" }, { HTMLHeader::location, "Location" }, { HTMLHeader::lastModified, "Last-Modified" }, { HTMLHeader::allow, "Allow" },
    { HTMLHeader::expires, "Expires" }, { HTMLHeader::etag, "ETag" }
};
}