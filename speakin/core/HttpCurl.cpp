#include "HttpCurl.h"
#include <errno.h>

namespace speakin_mobi {
namespace sdk {

bool HttpCurl::is_global_init = false;
int HttpCurl::s_default_time = 0;
int HttpCurl::s_connect_default_time = 0;

HttpCurl::HttpCurl(const string &ip)
    : m_ip(ip),
      m_curl(NULL)
{
    m_pHeaders = curl_slist_append(NULL, "User-Agent: c-curl-client");
    m_pHeaders = curl_slist_append(m_pHeaders, "Content-Type: application/bson");
}

HttpCurl::~HttpCurl()
{
    if(m_pHeaders) {
        curl_slist_free_all(m_pHeaders);
    }

    if(m_curl) {
        curl_easy_cleanup(m_curl);
    }
}

bool HttpCurl::globalInit()
{
    return CURLE_OK == curl_global_init(CURL_GLOBAL_ALL);
}

void HttpCurl::globalCleanup()
{
    curl_global_cleanup();
}

void HttpCurl::setCurlOptTimeout(int timeout)
{
    s_default_time = timeout;
}

void HttpCurl::setCurlOptConnectTimeOut(int timeout)
{
    s_connect_default_time = timeout;
}

void HttpCurl::setUrlPath(const string &url_path)
{
    m_url_path = url_path;
}

bool HttpCurl::initCurlResource()
{
    m_curl = curl_easy_init();
    return NULL == m_curl;
}

int HttpCurl::postMsg(const string &form_data, string &sRec)
{
    int result = -1;
    CURLcode res;

    if(!m_curl) {
        initCurlResource();
    }

    if (m_curl) {
        /* 禁用掉alarm这种超时 */
        curl_easy_setopt(m_curl, CURLOPT_NOSIGNAL, 1);

        /* 设置连接超时时间 */
        curl_easy_setopt(m_curl, CURLOPT_CONNECTTIMEOUT, s_connect_default_time);

        /* 设置请求允许的最大时间 */
        curl_easy_setopt(m_curl, CURLOPT_TIMEOUT, s_default_time);

        curl_easy_setopt(m_curl, CURLOPT_FORBID_REUSE, 1);

        std::string s_url = this->m_ip + m_url_path;
        curl_easy_setopt(m_curl, CURLOPT_URL, (char*)s_url.c_str());

        curl_easy_setopt(m_curl, CURLOPT_HTTPHEADER, m_pHeaders);

        curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, form_data.c_str());
        curl_easy_setopt(m_curl, CURLOPT_POSTFIELDSIZE, form_data.length());
        curl_easy_setopt(m_curl, CURLOPT_TCP_KEEPALIVE, 1L);

        sRec.clear();
        curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, httpDataWriter);
        curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, (void*)&sRec);

        res = curl_easy_perform(m_curl);
        result=res;
    }
    return result;
}

/*
 * 回调函数，处理返回的数据
 * 参数1：缓存存放
 * 参数2：缓存块数
 * 参数3：缓存每块大小
 * 参数4：WRITEDATA对应的数据流
 * 返回值, 数据所占字节数
 */
size_t HttpCurl::httpDataWriter(void* buffer, size_t size, size_t nmemb, void* content)
{
    long totalSize = size*nmemb;
    std::string* symbolBuffer = (std::string*)content;
    if(symbolBuffer) {
        symbolBuffer->append((char *)buffer, ((char*)buffer)+totalSize);
        return totalSize;
    } else {
        return 0;
    }
}

}
}
