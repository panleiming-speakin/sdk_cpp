#ifndef USERAPIOBJ_H
#define USERAPIOBJ_H

#include <string>
#include <list>
#include <map>
#include "BaseObj.h"

namespace speakin_mobi {
namespace sdk {

namespace UserApiObj {

/* 设置用户 请求对象数据 */
class CSetAppUserRequest : public BaseReqObj
{
public:
    CSetAppUserRequest();
    ~CSetAppUserRequest();
    std::string user_id;      /* 用户ID,需要保证在单个APPID内唯一 */
    std::string user_type;    /* 用户类型，类型有DEV,PEOPLE,VIRTUAL */
    bool valid;               /* 是否有效 */
    bool access_all_app_user; /* 是否可以访问APP内所有用户 */
private:
    std::string getData() const;
};

/* 设置用户 响应对象数据 */
class CSetAppUserResponse : public BaseRspObj
{
public:
    CSetAppUserResponse();
    ~CSetAppUserResponse();
private:
    bool setData(const std::string &data);
};

/* 获取用户 请求对象数据 */
class CGetAppUserRequest : public BaseReqObj
{
public:
    CGetAppUserRequest();
    ~CGetAppUserRequest();
    std::string user_id;     /* 用户ID,需要保证在单个APPID内唯一 */
private:
    std::string getData() const;
};

/* 获取用户 响应对象数据 */
class CGetAppUserResponse : public BaseRspObj
{
public:
    CGetAppUserResponse();
    ~CGetAppUserResponse();
    std::string user_id;      /* 用户ID,需要保证在单个APPID内唯一 */
    std::string user_type;    /* 用户类型，目前值为DEV,PEOPLE,VIRTUAL */
    bool valid;               /* 是否有效 */
    bool access_all_app_user; /* 是否可以访问APP内所有用户 */
private:
    bool setData(const std::string &data);
};

/* 增加子用户 请求对象数据 */
class CAddChildAppUserRequest : public BaseReqObj
{
public:
    CAddChildAppUserRequest();
    ~CAddChildAppUserRequest();
    std::string user_id;       /* 用户ID */
    std::string child_user_id; /* 子用户ID */
private:
    std::string getData() const;
};

/* 增加子用户 响应对象数据 */
class CAddChildAppUserResponse : public BaseRspObj
{
public:
    CAddChildAppUserResponse();
    ~CAddChildAppUserResponse();
private:
    bool setData(const std::string &data);
};

/* 删除子用户 请求对象数据 */
class CRemoveChildAppUserRequest : public BaseReqObj
{
public:
    CRemoveChildAppUserRequest();
    ~CRemoveChildAppUserRequest();
    std::string user_id;       /* 用户ID */
    std::string child_user_id; /* 子用户ID */
private:
    std::string getData() const;
};

/* 删除子用户 响应对象数据 */
class CRemoveChildAppUserResponse : public BaseRspObj
{
public:
    CRemoveChildAppUserResponse();
    ~CRemoveChildAppUserResponse();
private:
    bool setData(const std::string &data);
};

/* 获取子用户数量 请求对象数据 */
class CGetChildAppUserCountRequest : public BaseReqObj
{
public:
    CGetChildAppUserCountRequest();
    ~CGetChildAppUserCountRequest();
    std::string user_id; /* 用户ID */
private:
    std::string getData() const;
};

/* 获取子用户数量 响应对象数据*/
class CGetChildAppUserCountResponse : public BaseRspObj
{
public:
    CGetChildAppUserCountResponse();
    ~CGetChildAppUserCountResponse();
    int count; /* 子用户数量 */
private:
    bool setData(const std::string &data);
};

/* 列出子用户 请求对象数据  */
class CListChildAppUserRequest : public BaseReqObj
{
public:
    CListChildAppUserRequest();
    ~CListChildAppUserRequest();
    std::string user_id; /* 用户ID */
    int offset;          /* 偏移 */
    int limit;           /* 数量 */
private:
    std::string getData() const;
};

/* 列出子用户 响应对象数据 */
class CListChildAppUserResponse : public BaseRspObj
{
public:
    CListChildAppUserResponse();
    ~CListChildAppUserResponse();
    std::list<std::string> child_user_id_list; /* child用户Id列表 */
private:
    bool setData(const std::string &data);
};

/* 检查是否包含某个子用户 请求对象数据 */
class CContainChildAppUserRequest : public BaseReqObj
{
public:
    CContainChildAppUserRequest();
    ~CContainChildAppUserRequest();
    std::string user_id;       /* 用户ID */
    std::string child_user_id; /* 子用户ID */
private:
    std::string getData() const;
};

/* 检查是否包含某个子用户 响应对象数据 */
class CContainChildAppUserResponse : public BaseRspObj
{
public:
    CContainChildAppUserResponse();
    ~CContainChildAppUserResponse();
    bool contain; /* 是否包含子用户 */
private:
    bool setData(const std::string &data);
};

}

}
}
#endif // USERAPIOBJ_H
