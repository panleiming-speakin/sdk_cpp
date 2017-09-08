#ifndef USERAPI_H
#define USERAPI_H

#include "BaseApi.h"
#include "UserApiObj.h"
#include "ApiError.h"

namespace speakin_mobi {
namespace sdk {

class UserApi : public BaseApi
{
public:
    explicit UserApi(const std::string &app_id, const std::string &app_secret, const std::string &url, bool skip_crypt=false);
    ~UserApi();

    ApiError setAppUser(UserApiObj::CSetAppUserRequest &req_data, UserApiObj::CSetAppUserResponse &rsp_data, const std::string &trace_id="");
    ApiError getAppUser(UserApiObj::CGetAppUserRequest &req_data, UserApiObj::CGetAppUserResponse &rsp_data, const std::string &trace_id="");
    ApiError addChildAppUser(UserApiObj::CAddChildAppUserRequest &req_data, UserApiObj::CAddChildAppUserResponse &rsp_data, const std::string &trace_id="");
    ApiError removeChildAppUser(UserApiObj::CRemoveChildAppUserRequest &req_data, UserApiObj::CRemoveChildAppUserResponse &rsp_data, const std::string &trace_id="");
    ApiError getChildAppUserCount(UserApiObj::CGetChildAppUserCountRequest &req_data, UserApiObj::CGetChildAppUserCountResponse &rsp_data, const std::string &trace_id="");
    ApiError listChildAppUser(UserApiObj::CListChildAppUserRequest &req_data, UserApiObj::CListChildAppUserResponse &rsp_data, const std::string &trace_id="");
    ApiError containChildAppUser(UserApiObj::CContainChildAppUserRequest &req_data, UserApiObj::CContainChildAppUserResponse &rsp_data, const std::string &trace_id="");
};

}
}
#endif // USERAPI_H
