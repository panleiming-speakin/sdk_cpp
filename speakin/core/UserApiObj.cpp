#include "UserApiObj.h"
#include "CBson.h"

namespace speakin_mobi {
namespace sdk {

UserApiObj::CSetAppUserRequest::CSetAppUserRequest()
{
    valid = true;
    access_all_app_user = false;
}

UserApiObj::CSetAppUserRequest::~CSetAppUserRequest(){}

std::string UserApiObj::CSetAppUserRequest::getData() const
{
    CBson b;
    b.appendBsonValue("user_id", user_id);
    b.appendBsonValue("user_type", user_type);
    b.appendBsonValue("valid", valid);
    b.appendBsonValue("access_all_app_user", access_all_app_user);
    return b.getData();
}

UserApiObj::CSetAppUserResponse::CSetAppUserResponse(){}

UserApiObj::CSetAppUserResponse::~CSetAppUserResponse(){}

bool UserApiObj::CSetAppUserResponse::setData(const string &data)
{
    return true;
}

UserApiObj::CGetAppUserRequest::CGetAppUserRequest(){}

UserApiObj::CGetAppUserRequest::~CGetAppUserRequest(){}

string UserApiObj::CGetAppUserRequest::getData() const{
    CBson b;
    b.appendBsonValue("user_id", user_id);
    return b.getData();
}

speakin_mobi::sdk::UserApiObj::CGetAppUserResponse::CGetAppUserResponse(){}

UserApiObj::CGetAppUserResponse::~CGetAppUserResponse(){}

bool UserApiObj::CGetAppUserResponse::setData(const string &data){
     CBson b;
     b.setData(data);
     if(b.hasError()) {
         return false;
     }
     if(!b.getBsonValue("user_id", user_id)) {
         return false;
     }
     if(!b.getBsonValue("user_type", user_type)) {
         return false;
     }
     if(!b.getBsonValue("valid", valid)) {
         return false;
     }
     if(!b.getBsonValue("access_all_app_user", access_all_app_user)) {
         return false;
     }
     return true;
}

UserApiObj::CAddChildAppUserRequest::CAddChildAppUserRequest(){}

UserApiObj::CAddChildAppUserRequest::~CAddChildAppUserRequest(){}

string UserApiObj::CAddChildAppUserRequest::getData() const{
    CBson b;
    b.appendBsonValue("user_id", user_id);
    b.appendBsonValue("child_user_id", child_user_id);
    return b.getData();
}

UserApiObj::CAddChildAppUserResponse::CAddChildAppUserResponse(){}

UserApiObj::CAddChildAppUserResponse::~CAddChildAppUserResponse(){}

bool UserApiObj::CAddChildAppUserResponse::setData(const string &data)
{
    return true;
}

UserApiObj::CRemoveChildAppUserRequest::CRemoveChildAppUserRequest(){}

UserApiObj::CRemoveChildAppUserRequest::~CRemoveChildAppUserRequest(){}

string UserApiObj::CRemoveChildAppUserRequest::getData() const{
    CBson b;
    b.appendBsonValue("user_id", user_id);
    b.appendBsonValue("child_user_id", child_user_id);
    return b.getData();
}

UserApiObj::CRemoveChildAppUserResponse::CRemoveChildAppUserResponse(){}

UserApiObj::CRemoveChildAppUserResponse::~CRemoveChildAppUserResponse(){}

bool UserApiObj::CRemoveChildAppUserResponse::setData(const string &data)
{
    return true;
}

UserApiObj::CGetChildAppUserCountRequest::CGetChildAppUserCountRequest(){}

UserApiObj::CGetChildAppUserCountRequest::~CGetChildAppUserCountRequest(){}

string UserApiObj::CGetChildAppUserCountRequest::getData() const
{
    CBson b;
    b.appendBsonValue("user_id", user_id);
    return b.getData();
}

UserApiObj::CGetChildAppUserCountResponse::CGetChildAppUserCountResponse(){}

UserApiObj::CGetChildAppUserCountResponse::~CGetChildAppUserCountResponse() {}

bool UserApiObj::CGetChildAppUserCountResponse::setData(const string &data)
{
     CBson b;
     b.setData(data);
     if(b.hasError()) {
         return false;
     }
     if(!b.getBsonValue("count", count)) {
         return false;
     }
     return true;
}

UserApiObj::CListChildAppUserRequest::CListChildAppUserRequest(){}

UserApiObj::CListChildAppUserRequest::~CListChildAppUserRequest(){}

string UserApiObj::CListChildAppUserRequest::getData() const
{
    CBson b;
    b.appendBsonValue("user_id", user_id);
    b.appendBsonValue("offset", offset);
    b.appendBsonValue("limit", limit);
    return b.getData();
}

UserApiObj::CListChildAppUserResponse::CListChildAppUserResponse(){}

UserApiObj::CListChildAppUserResponse::~CListChildAppUserResponse(){}

bool UserApiObj::CListChildAppUserResponse::setData(const string &data)
{
    CBson b;
    b.setData(data);
    if(b.hasError()) {
        return false;
    }

    if(!b.getBsonArray("child_user_id_list", child_user_id_list)) {
        return false;
    }
    return true;
}

UserApiObj::CContainChildAppUserRequest::CContainChildAppUserRequest(){}

UserApiObj::CContainChildAppUserRequest::~CContainChildAppUserRequest(){}

string UserApiObj::CContainChildAppUserRequest::getData() const
{
    CBson b;
    b.appendBsonValue("user_id", user_id);
    b.appendBsonValue("child_user_id", child_user_id);
    return b.getData();
}

UserApiObj::CContainChildAppUserResponse::CContainChildAppUserResponse()
{
    contain = false;
}

UserApiObj::CContainChildAppUserResponse::~CContainChildAppUserResponse(){}

bool UserApiObj::CContainChildAppUserResponse::setData(const string &data)
{
    CBson b;
    b.setData(data);
    if(b.hasError()) {
        return false;
    }
    if(!b.getBsonValue("contain", contain)) {
        return false;
    }
    return true;
}

}
}
