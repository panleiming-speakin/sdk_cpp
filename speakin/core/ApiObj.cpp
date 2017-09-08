#include "ApiObj.h"
#include "CBson.h"
#include "Utils.h"

speakin_mobi::sdk::ApiObj::CListModuleRequest::CListModuleRequest(){}

speakin_mobi::sdk::ApiObj::CListModuleRequest::~CListModuleRequest(){}

std::string speakin_mobi::sdk::ApiObj::CListModuleRequest::getData() const
{
    CBson b;
    return b.getData();
}

speakin_mobi::sdk::ApiObj::CListModuleResponse::CListModuleResponse(){}

speakin_mobi::sdk::ApiObj::CListModuleResponse::~CListModuleResponse(){}

bool speakin_mobi::sdk::ApiObj::CListModuleResponse::setData(const std::string &data)
{
    CBson b(data);
    CBsonList list;
    if(!b.getBsonArray("module_list", list)) {
        return false;
    } else {
        int size = list.size();
        CBson *b;
        for(int i=0; i<size; i++) {
            CModule mode;
            b = list[i];
            if(!b->getBsonValue("voice_bit_count", mode.voice_bit_count)) {
                return false;
            }
            if(!b->getBsonValue("voice_lang", mode.voice_lang)) {
                return false;
            }
            if(!b->getBsonValue("voice_rate", mode.voice_rate)) {
                return false;
            }
            module_list.push_back(mode);
        }
    }
    return true;
}


speakin_mobi::sdk::ApiObj::CStartSessionRequest::CStartSessionRequest(){
    can_register = true;
    can_verify = true;
    can_identity = true;
}

speakin_mobi::sdk::ApiObj::CStartSessionRequest::~CStartSessionRequest(){}

std::string speakin_mobi::sdk::ApiObj::CStartSessionRequest::getData() const
{
    CBson b;
    b.appendBsonValue("user_id", user_id);
    b.appendBsonValue("can_register", can_register);
    b.appendBsonValue("can_verify", can_verify);
    b.appendBsonValue("can_identity", can_identity);
    b.appendBsonValue("ttl", ttl);
    return b.getData();
}


speakin_mobi::sdk::ApiObj::CStartSessionResponse::CStartSessionResponse(){}

speakin_mobi::sdk::ApiObj::CStartSessionResponse::~CStartSessionResponse(){}

bool speakin_mobi::sdk::ApiObj::CStartSessionResponse::setData(const std::string &data){
    CBson b;
    b.setData(data);
    if(!b.getBsonValue("session_id", session_id)) {
        return false;
    }
    if(!b.getBsonValue("expire_time_stamp", expire_time_stamp)) {
        return false;
    }
    if(!b.getBsonValue("session_secret", session_secret)) {
        return false;
    }
    return true;
}

speakin_mobi::sdk::ApiObj::CQueryTraceRequest::CQueryTraceRequest(){}

speakin_mobi::sdk::ApiObj::CQueryTraceRequest::~CQueryTraceRequest(){}

std::string speakin_mobi::sdk::ApiObj::CQueryTraceRequest::getData() const
{
    CBson b;
    b.appendBsonValue("offset", offset);
    b.appendBsonValue("limit", limit);
    return b.getData();

}

speakin_mobi::sdk::ApiObj::CQueryTraceResponse::CQueryTraceResponse(){}

speakin_mobi::sdk::ApiObj::CQueryTraceResponse::~CQueryTraceResponse(){}

bool speakin_mobi::sdk::ApiObj::CQueryTraceResponse::setData(const std::string &data)
{
    CBson b;
    b.setData(data);
    if(!b.getBsonValue("total_count", total_count)) {
        return false;
    }
    if(!b.getBsonValue("log_content", log_content)) {
        return false;
    }
    return true;
}
