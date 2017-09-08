#include "BaseApi.h"
#include <sstream>
#include "HttpCurl.h"
#include "RequestWarp.h"
#include "ResponseWarp.h"
#include "Utils.h"
#include "ApiError.h"
#include "CBson.h"

namespace speakin_mobi {
namespace sdk {

using std::string;

BaseApi::BaseApi(const string &app_id,
                 ID_TYPE id_type,
                 const string &secret,
                 string url,
                 bool skip_crypt
                 )
    : m_app_id(app_id),
      m_id_type(id_type),
      m_secret(secret),
      m_skip_crypt(skip_crypt),
      m_curl_http(new HttpCurl(url))
{
    if(m_curl_http) {
        if(m_curl_http->initCurlResource()) {
            delete m_curl_http;
            m_curl_http = NULL;
        }
    }
}

BaseApi::~BaseApi()
{
    if(m_curl_http)
        delete m_curl_http;
}

ApiError BaseApi::callApi(string url, const BaseReqObj &req_data, BaseRspObj &rsp_data)
{
    #ifdef __GXX_EXPERIMENTAL_CXX0X__
    if (m_callback) {
        return m_callback(*this, url, req_data, rsp_data);
    }
    #endif

    ApiError err;
    if(!m_curl_http) {
        err.setError("common.unknown", "internal  error");
        return err;
    }

    RequestWarp reqWarp(m_app_id, m_id_type, m_secret, m_skip_crypt);
    reqWarp.setData(req_data);

    /* 设置路径 */
    m_curl_http->setUrlPath(url);
    /* 发送方式为post,数据格式为Bson,发送数据为Bson */
    string form_dat = reqWarp.getRequestBody();
    string response_string;

    int ret = m_curl_http->postMsg(form_dat, response_string);
    if(ret != 0) {
        if(ret == -1) {
            err.setError("common.unknown", "curl_easy_init failed");
            return err;
        } else {
            std::stringstream ss;
            ss << "postMsg failed, CURLcode:" << ret;
            err.setError("common.unknown", ss.str());
            return err;
        }
    }

    ResponseWarp rspWarp(m_secret, response_string);
    if(!rspWarp.error().has_error()) {
        if(!rsp_data.setData(rspWarp.data())) {
            err.setError("common.unknown", "internal  error");
            return err;
        }
    }
    return rspWarp.error();
}

}
}
