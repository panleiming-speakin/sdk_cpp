#ifndef API_H
#define API_H

#include <string>
#include "BaseApi.h"
#include "ApiObj.h"
#include "ApiError.h"

namespace speakin_mobi {
namespace sdk {

class UserApi;

class Api : public BaseApi
{
public:
    explicit Api(const string &app_id, const string &app_secret, const string &url, bool skip_crypt=false);
    ApiError listModule(ApiObj::CListModuleRequest &req_data, ApiObj::CListModuleResponse &rsp_data, const std::string &trace_id="");
    ApiError startSession(ApiObj::CStartSessionRequest &req_data, ApiObj::CStartSessionResponse &rsp_data, const std::string &trace_id="");
    ApiError queryTrace(ApiObj::CQueryTraceRequest &req_data, ApiObj::CQueryTraceResponse &rsp_data,  const std::string &trace_id="");
};

}
}
#endif // API_H
