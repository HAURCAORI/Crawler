#ifndef CURL_TYPE_H
#define CURL_TYPE_H

#include <string>
#include <map>
#include <curl/curl.h>

namespace Crawler {

// MIME struct

struct MIME {
    std::string type;
    std::string subtype;
    MIME(const std::string& type, const std::string& subtype) : type(type), subtype(subtype) {}
    inline std::string get() const { return type + "/" + subtype; }
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

static const std::map<HTMLHeader, std::string> HTMLHeaderString  = {
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

#define StringMap(opt) { #opt, opt }

static const std::map<std::string, CURLoption> StringMapCURLOption = {
    StringMap(CURLOPT_WRITEDATA),
    StringMap(CURLOPT_URL),
    StringMap(CURLOPT_PORT),
    StringMap(CURLOPT_PROXY),
    StringMap(CURLOPT_USERPWD),
    StringMap(CURLOPT_PROXYUSERPWD),
    StringMap(CURLOPT_RANGE),
    StringMap(CURLOPT_READDATA),
    StringMap(CURLOPT_ERRORBUFFER),
    StringMap(CURLOPT_WRITEFUNCTION),
    StringMap(CURLOPT_READFUNCTION),
    StringMap(CURLOPT_TIMEOUT),
    StringMap(CURLOPT_INFILESIZE),
    StringMap(CURLOPT_POSTFIELDS),
    StringMap(CURLOPT_REFERER),
    StringMap(CURLOPT_FTPPORT),
    StringMap(CURLOPT_USERAGENT),
    StringMap(CURLOPT_LOW_SPEED_LIMIT),
    StringMap(CURLOPT_LOW_SPEED_TIME),
    StringMap(CURLOPT_RESUME_FROM),
    StringMap(CURLOPT_COOKIE),
    StringMap(CURLOPT_HTTPHEADER),
    StringMap(CURLOPT_HTTPPOST),
    StringMap(CURLOPT_SSLCERT),
    StringMap(CURLOPT_KEYPASSWD),
    StringMap(CURLOPT_CRLF),
    StringMap(CURLOPT_QUOTE),
    StringMap(CURLOPT_HEADERDATA),
    StringMap(CURLOPT_COOKIEFILE),
    StringMap(CURLOPT_SSLVERSION),
    StringMap(CURLOPT_TIMECONDITION),
    StringMap(CURLOPT_TIMEVALUE),
    StringMap(CURLOPT_CUSTOMREQUEST),
    StringMap(CURLOPT_STDERR),
    StringMap(CURLOPT_POSTQUOTE),
    StringMap(CURLOPT_OBSOLETE40),
    StringMap(CURLOPT_VERBOSE),
    StringMap(CURLOPT_HEADER),
    StringMap(CURLOPT_NOPROGRESS),
    StringMap(CURLOPT_NOBODY),
    StringMap(CURLOPT_FAILONERROR),
    StringMap(CURLOPT_UPLOAD),
    StringMap(CURLOPT_POST),
    StringMap(CURLOPT_DIRLISTONLY),
    StringMap(CURLOPT_APPEND),
    StringMap(CURLOPT_NETRC),
    StringMap(CURLOPT_FOLLOWLOCATION),
    StringMap(CURLOPT_TRANSFERTEXT),
    StringMap(CURLOPT_PUT),
    StringMap(CURLOPT_PROGRESSFUNCTION),
    StringMap(CURLOPT_XFERINFODATA),
    StringMap(CURLOPT_AUTOREFERER),
    StringMap(CURLOPT_PROXYPORT),
    StringMap(CURLOPT_POSTFIELDSIZE),
    StringMap(CURLOPT_HTTPPROXYTUNNEL),
    StringMap(CURLOPT_INTERFACE),
    StringMap(CURLOPT_KRBLEVEL),
    StringMap(CURLOPT_SSL_VERIFYPEER),
    StringMap(CURLOPT_CAINFO),
    StringMap(CURLOPT_MAXREDIRS),
    StringMap(CURLOPT_FILETIME),
    StringMap(CURLOPT_TELNETOPTIONS),
    StringMap(CURLOPT_MAXCONNECTS),
    StringMap(CURLOPT_OBSOLETE72),
    StringMap(CURLOPT_FRESH_CONNECT),
    StringMap(CURLOPT_FORBID_REUSE),
    StringMap(CURLOPT_RANDOM_FILE),
    StringMap(CURLOPT_EGDSOCKET),
    StringMap(CURLOPT_CONNECTTIMEOUT),
    StringMap(CURLOPT_HEADERFUNCTION),
    StringMap(CURLOPT_HTTPGET),
    StringMap(CURLOPT_SSL_VERIFYHOST),
    StringMap(CURLOPT_COOKIEJAR),
    StringMap(CURLOPT_SSL_CIPHER_LIST),
    StringMap(CURLOPT_HTTP_VERSION),
    StringMap(CURLOPT_FTP_USE_EPSV),
    StringMap(CURLOPT_SSLCERTTYPE),
    StringMap(CURLOPT_SSLKEY),
    StringMap(CURLOPT_SSLKEYTYPE),
    StringMap(CURLOPT_SSLENGINE),
    StringMap(CURLOPT_SSLENGINE_DEFAULT),
    StringMap(CURLOPT_DNS_USE_GLOBAL_CACHE),
    StringMap(CURLOPT_DNS_CACHE_TIMEOUT),
    StringMap(CURLOPT_PREQUOTE),
    StringMap(CURLOPT_DEBUGFUNCTION),
    StringMap(CURLOPT_DEBUGDATA),
    StringMap(CURLOPT_COOKIESESSION),
    StringMap(CURLOPT_CAPATH),
    StringMap(CURLOPT_BUFFERSIZE),
    StringMap(CURLOPT_NOSIGNAL),
    StringMap(CURLOPT_SHARE),
    StringMap(CURLOPT_PROXYTYPE),
    StringMap(CURLOPT_ACCEPT_ENCODING),
    StringMap(CURLOPT_PRIVATE),
    StringMap(CURLOPT_HTTP200ALIASES),
    StringMap(CURLOPT_UNRESTRICTED_AUTH),
    StringMap(CURLOPT_FTP_USE_EPRT),
    StringMap(CURLOPT_HTTPAUTH),
    StringMap(CURLOPT_SSL_CTX_FUNCTION),
    StringMap(CURLOPT_SSL_CTX_DATA),
    StringMap(CURLOPT_FTP_CREATE_MISSING_DIRS),
    StringMap(CURLOPT_PROXYAUTH),
    StringMap(CURLOPT_SERVER_RESPONSE_TIMEOUT),
    StringMap(CURLOPT_IPRESOLVE),
    StringMap(CURLOPT_MAXFILESIZE),
    StringMap(CURLOPT_INFILESIZE_LARGE),
    StringMap(CURLOPT_RESUME_FROM_LARGE),
    StringMap(CURLOPT_MAXFILESIZE_LARGE),
    StringMap(CURLOPT_NETRC_FILE),
    StringMap(CURLOPT_USE_SSL),
    StringMap(CURLOPT_POSTFIELDSIZE_LARGE),
    StringMap(CURLOPT_TCP_NODELAY),
    StringMap(CURLOPT_FTPSSLAUTH),
    StringMap(CURLOPT_IOCTLFUNCTION),
    StringMap(CURLOPT_IOCTLDATA),
    StringMap(CURLOPT_FTP_ACCOUNT),
    StringMap(CURLOPT_COOKIELIST),
    StringMap(CURLOPT_IGNORE_CONTENT_LENGTH),
    StringMap(CURLOPT_FTP_SKIP_PASV_IP),
    StringMap(CURLOPT_FTP_FILEMETHOD),
    StringMap(CURLOPT_LOCALPORT),
    StringMap(CURLOPT_LOCALPORTRANGE),
    StringMap(CURLOPT_CONNECT_ONLY),
    StringMap(CURLOPT_CONV_FROM_NETWORK_FUNCTION),
    StringMap(CURLOPT_CONV_TO_NETWORK_FUNCTION),
    StringMap(CURLOPT_CONV_FROM_UTF8_FUNCTION),
    StringMap(CURLOPT_MAX_SEND_SPEED_LARGE),
    StringMap(CURLOPT_MAX_RECV_SPEED_LARGE),
    StringMap(CURLOPT_FTP_ALTERNATIVE_TO_USER),
    StringMap(CURLOPT_SOCKOPTFUNCTION),
    StringMap(CURLOPT_SOCKOPTDATA),
    StringMap(CURLOPT_SSL_SESSIONID_CACHE),
    StringMap(CURLOPT_SSH_AUTH_TYPES),
    StringMap(CURLOPT_SSH_PUBLIC_KEYFILE),
    StringMap(CURLOPT_SSH_PRIVATE_KEYFILE),
    StringMap(CURLOPT_FTP_SSL_CCC),
    StringMap(CURLOPT_TIMEOUT_MS),
    StringMap(CURLOPT_CONNECTTIMEOUT_MS),
    StringMap(CURLOPT_HTTP_TRANSFER_DECODING),
    StringMap(CURLOPT_HTTP_CONTENT_DECODING),
    StringMap(CURLOPT_NEW_FILE_PERMS),
    StringMap(CURLOPT_NEW_DIRECTORY_PERMS),
    StringMap(CURLOPT_POSTREDIR),
    StringMap(CURLOPT_SSH_HOST_PUBLIC_KEY_MD5),
    StringMap(CURLOPT_OPENSOCKETFUNCTION),
    StringMap(CURLOPT_OPENSOCKETDATA),
    StringMap(CURLOPT_COPYPOSTFIELDS),
    StringMap(CURLOPT_PROXY_TRANSFER_MODE),
    StringMap(CURLOPT_SEEKFUNCTION),
    StringMap(CURLOPT_SEEKDATA),
    StringMap(CURLOPT_CRLFILE),
    StringMap(CURLOPT_ISSUERCERT),
    StringMap(CURLOPT_ADDRESS_SCOPE),
    StringMap(CURLOPT_CERTINFO),
    StringMap(CURLOPT_USERNAME),
    StringMap(CURLOPT_PASSWORD),
    StringMap(CURLOPT_PROXYUSERNAME),
    StringMap(CURLOPT_PROXYPASSWORD),
    StringMap(CURLOPT_NOPROXY),
    StringMap(CURLOPT_TFTP_BLKSIZE),
    StringMap(CURLOPT_SOCKS5_GSSAPI_SERVICE),
    StringMap(CURLOPT_SOCKS5_GSSAPI_NEC),
    StringMap(CURLOPT_PROTOCOLS),
    StringMap(CURLOPT_REDIR_PROTOCOLS),
    StringMap(CURLOPT_SSH_KNOWNHOSTS),
    StringMap(CURLOPT_SSH_KEYFUNCTION),
    StringMap(CURLOPT_SSH_KEYDATA),
    StringMap(CURLOPT_MAIL_FROM),
    StringMap(CURLOPT_MAIL_RCPT),
    StringMap(CURLOPT_FTP_USE_PRET),
    StringMap(CURLOPT_RTSP_REQUEST),
    StringMap(CURLOPT_RTSP_SESSION_ID),
    StringMap(CURLOPT_RTSP_STREAM_URI),
    StringMap(CURLOPT_RTSP_TRANSPORT),
    StringMap(CURLOPT_RTSP_CLIENT_CSEQ),
    StringMap(CURLOPT_RTSP_SERVER_CSEQ),
    StringMap(CURLOPT_INTERLEAVEDATA),
    StringMap(CURLOPT_INTERLEAVEFUNCTION),
    StringMap(CURLOPT_WILDCARDMATCH),
    StringMap(CURLOPT_CHUNK_BGN_FUNCTION),
    StringMap(CURLOPT_CHUNK_END_FUNCTION),
    StringMap(CURLOPT_FNMATCH_FUNCTION),
    StringMap(CURLOPT_CHUNK_DATA),
    StringMap(CURLOPT_FNMATCH_DATA),
    StringMap(CURLOPT_RESOLVE),
    StringMap(CURLOPT_TLSAUTH_USERNAME),
    StringMap(CURLOPT_TLSAUTH_PASSWORD),
    StringMap(CURLOPT_TLSAUTH_TYPE),
    StringMap(CURLOPT_TRANSFER_ENCODING),
    StringMap(CURLOPT_CLOSESOCKETFUNCTION),
    StringMap(CURLOPT_CLOSESOCKETDATA),
    StringMap(CURLOPT_GSSAPI_DELEGATION),
    StringMap(CURLOPT_DNS_SERVERS),
    StringMap(CURLOPT_ACCEPTTIMEOUT_MS),
    StringMap(CURLOPT_TCP_KEEPALIVE),
    StringMap(CURLOPT_TCP_KEEPIDLE),
    StringMap(CURLOPT_TCP_KEEPINTVL),
    StringMap(CURLOPT_SSL_OPTIONS),
    StringMap(CURLOPT_MAIL_AUTH),
    StringMap(CURLOPT_SASL_IR),
    StringMap(CURLOPT_XFERINFOFUNCTION),
    StringMap(CURLOPT_XOAUTH2_BEARER),
    StringMap(CURLOPT_DNS_INTERFACE),
    StringMap(CURLOPT_DNS_LOCAL_IP4),
    StringMap(CURLOPT_DNS_LOCAL_IP6),
    StringMap(CURLOPT_LOGIN_OPTIONS),
    StringMap(CURLOPT_SSL_ENABLE_NPN),
    StringMap(CURLOPT_SSL_ENABLE_ALPN),
    StringMap(CURLOPT_EXPECT_100_TIMEOUT_MS),
    StringMap(CURLOPT_PROXYHEADER),
    StringMap(CURLOPT_HEADEROPT),
    StringMap(CURLOPT_PINNEDPUBLICKEY),
    StringMap(CURLOPT_UNIX_SOCKET_PATH),
    StringMap(CURLOPT_SSL_VERIFYSTATUS),
    StringMap(CURLOPT_SSL_FALSESTART),
    StringMap(CURLOPT_PATH_AS_IS),
    StringMap(CURLOPT_PROXY_SERVICE_NAME),
    StringMap(CURLOPT_SERVICE_NAME),
    StringMap(CURLOPT_PIPEWAIT),
    StringMap(CURLOPT_DEFAULT_PROTOCOL),
    StringMap(CURLOPT_STREAM_WEIGHT),
    StringMap(CURLOPT_STREAM_DEPENDS),
    StringMap(CURLOPT_STREAM_DEPENDS_E),
    StringMap(CURLOPT_TFTP_NO_OPTIONS),
    StringMap(CURLOPT_CONNECT_TO),
    StringMap(CURLOPT_TCP_FASTOPEN),
    StringMap(CURLOPT_KEEP_SENDING_ON_ERROR),
    StringMap(CURLOPT_PROXY_CAINFO),
    StringMap(CURLOPT_PROXY_CAPATH),
    StringMap(CURLOPT_PROXY_SSL_VERIFYPEER),
    StringMap(CURLOPT_PROXY_SSL_VERIFYHOST),
    StringMap(CURLOPT_PROXY_SSLVERSION),
    StringMap(CURLOPT_PROXY_TLSAUTH_USERNAME),
    StringMap(CURLOPT_PROXY_TLSAUTH_PASSWORD),
    StringMap(CURLOPT_PROXY_TLSAUTH_TYPE),
    StringMap(CURLOPT_PROXY_SSLCERT),
    StringMap(CURLOPT_PROXY_SSLCERTTYPE),
    StringMap(CURLOPT_PROXY_SSLKEY),
    StringMap(CURLOPT_PROXY_SSLKEYTYPE),
    StringMap(CURLOPT_PROXY_KEYPASSWD),
    StringMap(CURLOPT_PROXY_SSL_CIPHER_LIST),
    StringMap(CURLOPT_PROXY_CRLFILE),
    StringMap(CURLOPT_PROXY_SSL_OPTIONS),
    StringMap(CURLOPT_PRE_PROXY),
    StringMap(CURLOPT_PROXY_PINNEDPUBLICKEY),
    StringMap(CURLOPT_ABSTRACT_UNIX_SOCKET),
    StringMap(CURLOPT_SUPPRESS_CONNECT_HEADERS),
    StringMap(CURLOPT_REQUEST_TARGET),
    StringMap(CURLOPT_SOCKS5_AUTH),
    StringMap(CURLOPT_SSH_COMPRESSION),
    StringMap(CURLOPT_MIMEPOST),
    StringMap(CURLOPT_TIMEVALUE_LARGE),
    StringMap(CURLOPT_HAPPY_EYEBALLS_TIMEOUT_MS),
    StringMap(CURLOPT_RESOLVER_START_FUNCTION),
    StringMap(CURLOPT_RESOLVER_START_DATA),
    StringMap(CURLOPT_HAPROXYPROTOCOL),
    StringMap(CURLOPT_DNS_SHUFFLE_ADDRESSES),
    StringMap(CURLOPT_TLS13_CIPHERS),
    StringMap(CURLOPT_PROXY_TLS13_CIPHERS),
    StringMap(CURLOPT_DISALLOW_USERNAME_IN_URL),
    StringMap(CURLOPT_DOH_URL),
    StringMap(CURLOPT_UPLOAD_BUFFERSIZE),
    StringMap(CURLOPT_UPKEEP_INTERVAL_MS),
    StringMap(CURLOPT_CURLU),
    StringMap(CURLOPT_TRAILERFUNCTION),
    StringMap(CURLOPT_TRAILERDATA),
    StringMap(CURLOPT_HTTP09_ALLOWED),
    StringMap(CURLOPT_ALTSVC_CTRL),
    StringMap(CURLOPT_ALTSVC),
    StringMap(CURLOPT_MAXAGE_CONN),
    StringMap(CURLOPT_SASL_AUTHZID),
    StringMap(CURLOPT_MAIL_RCPT_ALLLOWFAILS),
    StringMap(CURLOPT_SSLCERT_BLOB),
    StringMap(CURLOPT_SSLKEY_BLOB),
    StringMap(CURLOPT_PROXY_SSLCERT_BLOB),
    StringMap(CURLOPT_PROXY_SSLKEY_BLOB),
    StringMap(CURLOPT_ISSUERCERT_BLOB),
    StringMap(CURLOPT_PROXY_ISSUERCERT),
    StringMap(CURLOPT_PROXY_ISSUERCERT_BLOB),
    StringMap(CURLOPT_SSL_EC_CURVES),
    StringMap(CURLOPT_HSTS_CTRL),
    StringMap(CURLOPT_HSTS),
    StringMap(CURLOPT_HSTSREADFUNCTION),
    StringMap(CURLOPT_HSTSREADDATA),
    StringMap(CURLOPT_HSTSWRITEFUNCTION),
    StringMap(CURLOPT_HSTSWRITEDATA),
    StringMap(CURLOPT_AWS_SIGV4),
    StringMap(CURLOPT_DOH_SSL_VERIFYPEER),
    StringMap(CURLOPT_DOH_SSL_VERIFYHOST),
    StringMap(CURLOPT_DOH_SSL_VERIFYSTATUS),
    StringMap(CURLOPT_CAINFO_BLOB),
    StringMap(CURLOPT_PROXY_CAINFO_BLOB),
    StringMap(CURLOPT_SSH_HOST_PUBLIC_KEY_SHA256),
    StringMap(CURLOPT_PREREQFUNCTION),
    StringMap(CURLOPT_PREREQDATA),
    StringMap(CURLOPT_MAXLIFETIME_CONN),
    StringMap(CURLOPT_MIME_OPTIONS),
    StringMap(CURLOPT_SSH_HOSTKEYFUNCTION),
    StringMap(CURLOPT_SSH_HOSTKEYDATA),
    StringMap(CURLOPT_PROTOCOLS_STR),
    StringMap(CURLOPT_REDIR_PROTOCOLS_STR)
};



}

#endif