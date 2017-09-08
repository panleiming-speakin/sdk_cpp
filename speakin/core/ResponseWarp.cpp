#include "ResponseWarp.h"
#include <sstream>
#include "CryptUtil.h"
#include "Utils.h"
#include "CBson.h"

namespace speakin_mobi {
namespace sdk {

ResponseWarp::ResponseWarp(const string &secret, const string &body_str)
    : m_secret(secret)
{  
    CBson b(body_str);
    if(b.hasError()) {
        m_error.setError("common.unknown", "internal  error");
    }

    bool result =false;
    bool has_err = false;

    do {
        if(!b.getBsonValue("has_error", has_err)) {
            break;
        }

        CBson error;
        if(has_err && b.getBsonValue("error", error)) {
            if(error.hasError()) {
                break;
            }

            string error_id;
            if(!error.getBsonValue("id", error_id)) {
                break;
            }

            string error_desc;
            if(!error.getBsonValue("desc", error_desc)) {
                break;
            }

            m_error.setError(error_id, error_desc);
        }

        if(!has_err) {
            string data;
            if(!b.getBsonBinary("data", data)) {
                break;
            }
            CryptUtil::aesDecrypt(m_secret, data, m_data);

            if(!b.getBsonValue("t",m_excueteTime)) {
                break;
            }

            if(!b.getBsonBinary("sign", m_sign)) {
                break;
            }
        }
        result = true;
    }while(0);

    if(!result) {
        m_error.setError("common.unknown", "internal  error");
        return;
    } else {
        if(!m_error.has_error()) {
            if(!checkSign()) {
                m_error.setError("common.wrong_sign", "wrong sign");
            }
        }
    }

    return;
}

bool ResponseWarp::checkSign()
{
    string has_error_str = m_error.has_error()?"true":"false";

    stringstream ss;
    ss << m_excueteTime << has_error_str << m_error.error_id() <<m_error.error_desc();
    string sign_content = ss.str();
    sign_content.append(m_data.c_str(), m_data.length());
    sign_content.append(m_secret.c_str(),m_secret.length());
    string sign = Sha1Util::sha1(sign_content);
    if(sign == m_sign) {
        return true;
    }
    m_error.setError("common.wrong_sign", "wrong sign");
    return false;
}

string ResponseWarp::data() const
{
    return m_data;
}

ApiError ResponseWarp::error() const
{
    return m_error;
}


}
}
