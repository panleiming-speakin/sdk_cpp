#ifndef APIOBJ_H
#define APIOBJ_H

#include <string>
#include <list>
#include <stdint.h>
#include "BaseObj.h"

namespace speakin_mobi {
namespace sdk {

namespace ApiObj {

/* 创建用户会话 请求对象数据 */
class CStartSessionRequest : public BaseReqObj
{
public:
    CStartSessionRequest();
    ~CStartSessionRequest();

    std::string user_id;    /* 用户ID */
    bool can_register;      /* 是否允许注册 */
    bool can_verify;        /* 是否允许验证 */
    bool can_identity;      /* 是否允许识别 */
    int ttl;                /* 会话生命周期，单位秒 */
private:
    std::string getData() const;
};

/* 创建用户会话 响应对象数据 */
class CStartSessionResponse : public BaseRspObj
{
public:
    CStartSessionResponse();
    ~CStartSessionResponse();
    std::string session_id;          /* 会话ID */
    uint64_t expire_time_stamp;      /* 会话过期时间.1970年以来的毫秒数 */
    std::string session_secret;      /* 会话密钥 */
private:
    bool setData(const std::string &data);
};

/* 列出可用声纹模型 请求对象数据 */
class CListModuleRequest : public BaseReqObj
{
public:
    CListModuleRequest();
    ~CListModuleRequest();
private:
    std::string getData() const;
};

class CModule
{
public:
    int voice_bit_count;      /* 8或16 bit */
    int voice_rate; 	      /* 采样率 */
    std::string voice_lang;   /* 模型支持的语言类型 */
};

/* 列出可用声纹模型 响应对象数据 */
class CListModuleResponse : public BaseRspObj
{
public:
    CListModuleResponse();
    ~CListModuleResponse();
    std::list<CModule> module_list; /* 模型列表 */
private:
    bool setData(const std::string &data);
};

/* 日志回溯请求 */
class CQueryTraceRequest : public BaseReqObj
{
public:
    CQueryTraceRequest();
    ~CQueryTraceRequest();
    int offset;
    int limit;
private:
    std::string getData() const;
};

/* 日志回溯应答 */
class CQueryTraceResponse : public BaseRspObj
{
public:
    CQueryTraceResponse();
    ~CQueryTraceResponse();
    int total_count;
    std::string log_content;
private:
    bool setData(const std::string &data);

};

}

}
}


#endif // APIOBJ_H
