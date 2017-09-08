#ifndef RESPONSEWARP_H
#define RESPONSEWARP_H

#include <string>
#include <stdint.h>
#include "CBson.h"
#include "ApiError.h"

namespace speakin_mobi {
namespace sdk {

using std::string;

class ResponseWarp
{
public:
    ResponseWarp(const string &secret,const string &body_str);

    ApiError error() const;

    string data() const;

private:
    bool checkSign();

private:
    string m_secret;
    ApiError m_error;
    string m_data;
    uint64_t m_excueteTime;
    string m_sign;
};

}
}

#endif // RESPONSEWARP_H
