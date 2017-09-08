#include "RequestWarp.h"
#include <sstream>
#include "CryptUtil.h"
#include "Utils.h"
#include "CBson.h"

namespace speakin_mobi {
namespace sdk {

RequestWarp::RequestWarp(const string &id, ID_TYPE id_type, const string &secret, bool skip_crypt)
    : m_id(id),
      m_id_type(id_type),
      m_secret(secret),
      m_skip_crypt(skip_crypt)
{

}

RequestWarp::~RequestWarp()
{

}

void RequestWarp::setData(const BaseReqObj &req_data)
{
    m_data = req_data.getData();
}


string RequestWarp::getRequestBody()
{
    long long call_timestamp = getCurrentTimeMillis();
    string data = CryptUtil::aesCrypt(m_secret, m_data);

    CBson b;
    b.appendBsonValue("id", m_id);
    b.appendBsonValue("id_type", id_type_name[m_id_type]);
    b.appendBsonValue("t", call_timestamp);
    if(!m_skip_crypt) {
        string data = CryptUtil::aesCrypt(m_secret, m_data);
        b.appendBsonValueBinary("data", data);
    } else {
        b.appendBsonValueBinary("data", m_data);
    }
    b.appendBsonValue("skip_crypt", m_skip_crypt);

    stringstream sign_content;
    sign_content << m_id << id_type_name[m_id_type] << call_timestamp << m_data << m_secret;
    string sign = Sha1Util::sha1(sign_content.str());
    b.appendBsonValueBinary("sign", sign);

    return b.getData();
}

}
}
