#ifndef REQUESTWARP_H
#define REQUESTWARP_H

#include <map>
#include "ApiObj.h"
#include "ApiTypes.h"
#include "ApiError.h"
#include "BaseObj.h"

namespace speakin_mobi {
namespace sdk {

using namespace std;

class RequestWarp
{
public:
    RequestWarp(const string &id, ID_TYPE id_type, const string &secret, bool skip_crypt);
    ~RequestWarp();

    void setData(const BaseReqObj &req_data);

    string getRequestBody();

private:
    string m_id;
    ID_TYPE m_id_type;
    string m_secret;
    string m_data;
    bool m_skip_crypt;
};

}
}
#endif // REQUESTWARP_H
