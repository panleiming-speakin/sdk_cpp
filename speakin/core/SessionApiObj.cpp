#include "SessionApiObj.h"
#include "CBson.h"

namespace speakin_mobi {
namespace sdk {

SessionApiObj::CStartRecordRequest::CStartRecordRequest()
{
    gen_text = false;
}

SessionApiObj::CStartRecordRequest::~CStartRecordRequest(){}

std::string SessionApiObj::CStartRecordRequest::getData() const
{
    CBson b;
    b.appendBsonValue("gen_text", gen_text);
    b.appendBsonValue("voice_bit_count", voice_bit_count);
    b.appendBsonValue("voice_rate", voice_rate);
    b.appendBsonValue("voice_lang", voice_lang);
    b.appendBsonValue("data_format", data_format);
    b.appendBsonValue("target_action", target_action);
    return b.getData();
}

SessionApiObj::CStartRecordResponse::CStartRecordResponse(){}

SessionApiObj::CStartRecordResponse::~CStartRecordResponse(){}

bool SessionApiObj::CStartRecordResponse::setData(const string &data)
{
    CBson b;
    b.setData(data);
    if(b.hasError()) {
        return false;
    }
    if(!b.getBsonValue("record_id", record_id)) {
        return false;
    }
    if(!b.getBsonValue("text", text)) {
        return false;
    }
    return true;
}

SessionApiObj::CUploadRecordPartRequest::CUploadRecordPartRequest(){}

SessionApiObj::CUploadRecordPartRequest::~CUploadRecordPartRequest(){}

string SessionApiObj::CUploadRecordPartRequest::getData() const
{
    CBson b;
    b.appendBsonValue("record_id", record_id);
    b.appendBsonValue("index_id", index_id);
    b.appendBsonValueBinary("data", data);
    return b.getData();
}

SessionApiObj::CUploadRecordPartResponse::CUploadRecordPartResponse(){}

SessionApiObj::CUploadRecordPartResponse::~CUploadRecordPartResponse(){}

bool SessionApiObj::CUploadRecordPartResponse::setData(const string &data)
{
    return true;
}

SessionApiObj::CUploadRecordDoneRequest::CUploadRecordDoneRequest(){}

SessionApiObj::CUploadRecordDoneRequest::~CUploadRecordDoneRequest(){}

string SessionApiObj::CUploadRecordDoneRequest::getData() const
{
     CBson b;
     b.appendBsonValue("record_id", record_id);
     return b.getData();
}

SessionApiObj::CUploadRecordDoneResponse::CUploadRecordDoneResponse(){}

SessionApiObj::CUploadRecordDoneResponse::~CUploadRecordDoneResponse(){}

bool SessionApiObj::CUploadRecordDoneResponse::setData(const string &data)
{
    return true;
}

SessionApiObj::CUploadRecordCancelRequest::CUploadRecordCancelRequest(){}

SessionApiObj::CUploadRecordCancelRequest::~CUploadRecordCancelRequest(){}

string SessionApiObj::CUploadRecordCancelRequest::getData() const
{
    CBson b;
    b.appendBsonValue("record_id", record_id);
    return b.getData();
}

SessionApiObj::CUploadRecordCancelResponse::CUploadRecordCancelResponse(){}

SessionApiObj::CUploadRecordCancelResponse::~CUploadRecordCancelResponse(){}

bool SessionApiObj::CUploadRecordCancelResponse::setData(const string &data)
{
    return true;
}

SessionApiObj::CRegisterRequest::CRegisterRequest(){}

SessionApiObj::CRegisterRequest::~CRegisterRequest(){}

string SessionApiObj::CRegisterRequest::getData() const
{
    CBson b;
    b.appendBsonValue("record_id_list", record_id_list);
    return b.getData();
}

SessionApiObj::CRegisterResponse::CRegisterResponse(){}

SessionApiObj::CRegisterResponse::~CRegisterResponse(){}

bool SessionApiObj::CRegisterResponse::setData(const string &data)
{
    return true;
}

SessionApiObj::CVerifyRequest::CVerifyRequest(){}

SessionApiObj::CVerifyRequest::~CVerifyRequest(){}

string SessionApiObj::CVerifyRequest::getData() const
{
    CBson b;
    b.appendBsonValue("record_id", record_id);
    return b.getData();
}

SessionApiObj::CVerifyResponse::CVerifyResponse()
{
    result = false;
}

SessionApiObj::CVerifyResponse::~CVerifyResponse(){}

bool SessionApiObj::CVerifyResponse::setData(const string &data)
{
    CBson b;
    b.setData(data);
    if(b.hasError()) {
        return false;
    }
    if(!b.getBsonValue("result", result)) {
        return false;
    }
    if(!b.getBsonValue("score", score)) {
        return false;
    }
    if(!b.getBsonValue("threshold_score", threshold_score)) {
        return false;
    }
    return true;
}

SessionApiObj::CIdentityRequest::CIdentityRequest()
{
    filter_user = false;
}

SessionApiObj::CIdentityRequest::~CIdentityRequest(){}

string SessionApiObj::CIdentityRequest::getData() const
{
    CBson b;
    b.appendBsonValue("record_id", record_id);
    b.appendBsonValue("filter_user", filter_user);
    b.appendBsonValue("filter_user_id_list", filter_user_id_list);
    return b.getData();
}

SessionApiObj::CIdentityResponse::CIdentityResponse(){}

SessionApiObj::CIdentityResponse::~CIdentityResponse(){}

bool SessionApiObj::CIdentityResponse::setData(const string &data)
{
    CBson b;
    b.setData(data);
    if(b.hasError()) {
        return false;
    }
    if(!b.getBsonArray("user_id_list", user_id_list)) {
        return false;
    }
    return true;
}

}
}
