#ifndef BASEAPI_H
#define BASEAPI_H

#include <functional>
#include "ApiTypes.h"
#include "BaseObj.h"
#include "ApiError.h"

namespace speakin_mobi {
namespace sdk {

class HttpCurl;

class BaseApi
{
public:

#ifdef __GXX_EXPERIMENTAL_CXX0X__
    /**
     * @brief CALLBACK_TYPE
     *
     *     "data bson format"
     */
    typedef std::function<ApiError (class BaseApi &base_api, string url, const BaseReqObj &req_data, BaseRspObj &rsp_data)> CALLBACK_TYPE;
#endif

    explicit BaseApi(const string &app_id, ID_TYPE id_type, const string &secret, string url, bool skip_crypt=false);
    virtual ~BaseApi();

    ApiError callApi(string url, const BaseReqObj &req_data, BaseRspObj &rsp_data);

#ifdef __GXX_EXPERIMENTAL_CXX0X__
    void RegisterCallback(CALLBACK_TYPE callback) {
      m_callback = callback;
    }
#endif

public:
    string m_app_id;
    ID_TYPE m_id_type;
    string m_secret;
    bool m_skip_crypt;
    HttpCurl *m_curl_http;

#ifdef __GXX_EXPERIMENTAL_CXX0X__
    CALLBACK_TYPE m_callback;
#endif
};

}
}

#endif // BASEAPI_H
