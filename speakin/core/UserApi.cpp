#include "UserApi.h"

namespace speakin_mobi {
namespace sdk {

UserApi::UserApi(const string &app_id, const string &app_secret, const string &url, bool skip_crypt)
    : BaseApi(app_id, APP_ID, app_secret, url, skip_crypt)
{

}

UserApi::~UserApi()
{

}

ApiError UserApi::setAppUser(UserApiObj::CSetAppUserRequest &req_data, UserApiObj::CSetAppUserResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/user/set?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError UserApi::getAppUser(UserApiObj::CGetAppUserRequest &req_data, UserApiObj::CGetAppUserResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/user/get?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError UserApi::addChildAppUser(UserApiObj::CAddChildAppUserRequest &req_data, UserApiObj::CAddChildAppUserResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/user/add_child?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError UserApi::removeChildAppUser(UserApiObj::CRemoveChildAppUserRequest &req_data, UserApiObj::CRemoveChildAppUserResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/user/remove_child?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError UserApi::getChildAppUserCount(UserApiObj::CGetChildAppUserCountRequest &req_data, UserApiObj::CGetChildAppUserCountResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/user/get_child_count?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError UserApi::listChildAppUser(UserApiObj::CListChildAppUserRequest &req_data, UserApiObj::CListChildAppUserResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/user/list_child?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError UserApi::containChildAppUser(UserApiObj::CContainChildAppUserRequest &req_data, UserApiObj::CContainChildAppUserResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/user/contain_child?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

}
}
