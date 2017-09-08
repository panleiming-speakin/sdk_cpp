#ifndef APIERROR_H
#define APIERROR_H

#include <string>

namespace speakin_mobi {
namespace sdk {

using std::string;

class ApiError
{
public:
    ApiError();
    ApiError(const std::string &error_id,const std::string &error_desc);
    ~ApiError();
    void setError(const std::string &error_id,const std::string &error_desc);
    bool has_error() const;
    std::string error() const;

    string error_id() const;

    string error_desc() const;

private:
    bool m_has_error;
    string m_error_id;
    string m_error_desc;
};

}
}

#endif // APIERROR_H
