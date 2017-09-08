#ifndef SESSIONAPIOBJ_H
#define SESSIONAPIOBJ_H

#include <string>
#include <list>
#include "BaseObj.h"

namespace speakin_mobi {
namespace sdk {

namespace SessionApiObj {

/* 开始上传 请求对象数据 */
class CStartRecordRequest : public BaseReqObj
{
public:
    CStartRecordRequest();
    ~CStartRecordRequest();
    bool gen_text;              /* 是否生成文本 */
    short voice_bit_count;      /* 8或16bit */
    int voice_rate;             /* 采样率 */
    std::string voice_lang;     /* 声纹模型语言 */
    std::string data_format;    /* 数据类型，可选值为WAV,PCM */
    std::string target_action;  /* 语音用途，目前值为REGISTER,VERIFY,IDENTITY */
private:
    std::string getData() const;
};

/* 开始上传 响应对象数据 */
class CStartRecordResponse : public BaseRspObj
{
public:
    CStartRecordResponse();
    ~CStartRecordResponse();
    std::string record_id; /* 上传的文件ID */
    std::string text;      /* 生成的文本 */
private:
    bool setData(const std::string &data);
};

/* 上传文件片段 请求对象数据 */
class CUploadRecordPartRequest : public BaseReqObj
{
public:
    CUploadRecordPartRequest();
    ~CUploadRecordPartRequest();
    std::string record_id; /* 上传的文件ID */
    int index_id;          /* 文件片段ID,从1开始计数 */
    std::string data;      /* 文件数据 */
private:
    std::string getData() const;
};


/* 上传文件片段 响应对象数据 */
class CUploadRecordPartResponse : public BaseRspObj
{
public:
    CUploadRecordPartResponse();
    ~CUploadRecordPartResponse();
private:
    bool setData(const std::string &data);
};

/* 完成上传文件 请求对象数据 */
class CUploadRecordDoneRequest : public BaseReqObj
{
public:
    CUploadRecordDoneRequest();
    ~CUploadRecordDoneRequest();
    std::string record_id; /* 上传的文件ID */
private:
    std::string getData() const;
};

/* 完成上传文件 响应对象数据 */
class CUploadRecordDoneResponse : public BaseRspObj
{
public:
    CUploadRecordDoneResponse();
    ~CUploadRecordDoneResponse();
private:
    bool setData(const std::string &data);
};

/* 取消上传文件 请求对象数据 */
class CUploadRecordCancelRequest : public BaseReqObj
{
public:
    CUploadRecordCancelRequest();
    ~CUploadRecordCancelRequest();
    std::string record_id; /* 上传的文件ID */
private:
    std::string getData() const;
};

/* 取消上传文件  响应对象数据 */
class CUploadRecordCancelResponse : public BaseRspObj
{
public:
    CUploadRecordCancelResponse();
    ~CUploadRecordCancelResponse();
private:
    bool setData(const std::string &data);
};

/* 声纹注册 请求对象数据 */
class CRegisterRequest : public BaseReqObj
{
public:
    CRegisterRequest();
    ~CRegisterRequest();
    std::list<std::string> record_id_list; /* 上传的文件ID列表 */
private:
    std::string getData() const;
};

/* 声纹注册 响应对象数据 */
class CRegisterResponse : public BaseRspObj
{
public:
    CRegisterResponse();
    ~CRegisterResponse();
private:
    bool setData(const std::string &data);
};

/* 声纹验证 请求对象数据 */
class CVerifyRequest : public BaseReqObj
{
public:
    CVerifyRequest();
    ~CVerifyRequest();
    std::string record_id; /* 上传的文件ID */
private:
    std::string getData() const;
};

/* 声纹验证 响应对象数据 */
class CVerifyResponse : public BaseRspObj
{
public:
    CVerifyResponse();
    ~CVerifyResponse();
    bool result;            /* 结果 */
    double score;           /* 分数 */
    double threshold_score; /* 阈值 */
private:
    bool setData(const std::string &data);
};

/* 声纹匹配 请求对象数据 */
class CIdentityRequest : public BaseReqObj
{
public:
    CIdentityRequest();
    ~CIdentityRequest();
    std::string record_id;                      /* 上传文件ID */
    bool filter_user;                           /* 是否启用用户过滤 */
    std::list<std::string> filter_user_id_list; /* 用户列表 */
private:
    std::string getData() const;
};

/* 声纹匹配 响应对象数据 */
class CIdentityResponse : public BaseRspObj
{
public:
    CIdentityResponse();
    ~CIdentityResponse();
    std::list<std::string> user_id_list; /* 所有匹配的用户列表 */
    std::list<double> score_diff_list; /* 分数列表 */
private:
    bool setData(const std::string &data);
};

}

}
}
#endif // SESSIONAPIOBJ_H
