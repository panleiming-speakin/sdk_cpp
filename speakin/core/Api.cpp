#include "Api.h"
#include "UserApi.h"

namespace speakin_mobi {
namespace sdk {

Api::Api(const string &app_id,
         const string &app_secret,
         const string &url,
         bool skip_crypt)
    : BaseApi(app_id, APP_ID, app_secret, url, skip_crypt)
{

}

ApiError Api::listModule(ApiObj::CListModuleRequest &req_data, ApiObj::CListModuleResponse &rsp_data, const std::string &trace_id)
{
    string url = "/v1/list_module?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError Api::startSession(ApiObj::CStartSessionRequest &req_data, ApiObj::CStartSessionResponse &rsp_data, const std::string &trace_id)
{
    string url = "/v1/start_session?traceId=" +  trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError Api::queryTrace(ApiObj::CQueryTraceRequest &req_data, ApiObj::CQueryTraceResponse &rsp_data, const std::string &trace_id)
{
    string url = "/v1/query_trace?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}


}
}
