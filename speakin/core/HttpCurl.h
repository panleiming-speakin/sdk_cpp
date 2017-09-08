#ifndef HTTPCURL_H
#define HTTPCURL_H

#include <curl/curl.h>
#include <string>

namespace speakin_mobi {
namespace sdk {

using namespace std;

class HttpCurl
{
public:
    explicit HttpCurl(const string &ip);
    ~HttpCurl();
    void setUrlPath(const string &url_path);
    bool initCurlResource();

    int postMsg(const string &form_data, string &sRec);

public:
    static bool globalInit();                /* 进行所有CURL开始之前，全局变量初始化，放在主线程中调用 */
    static void globalCleanup();             /* 清理全局变量初始化 */
    static void setCurlOptTimeout(int timeout);        /* 设置请求允许的最大时间 CURLOPT_TIMEOUT (单位:秒) */
    static void setCurlOptConnectTimeOut(int timeout); /* 设置连接超时时间 CURLOPT_CONNECTTIMEOUT (单位:秒) */
                                                       /* Set to zero to switch to the default built-in connection timeout - 300 seconds. */

private:
    CURL *m_curl;
    string m_ip;                     /* ip */
    string m_url_path;               /* 路径 */
    struct curl_slist* m_pHeaders;

private:
    static size_t httpDataWriter(void* buffer, size_t size, size_t nmemb, void* content);

private:
    static bool is_global_init;         /* 全局初始化 */
    static int  s_default_time;         /* CURLOPT_TIMEOUT - set maximum time the request is allowed to take */
    static int  s_connect_default_time; /* CURLOPT_CONNECTTIMEOUT - timeout for the connect phase */
};

}
}

#endif // HTTPCURL_H
