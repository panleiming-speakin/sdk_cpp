#include "ApiError.h"

namespace speakin_mobi {
namespace sdk {

ApiError::ApiError()
    : m_has_error(false),
      m_error_id(""),
      m_error_desc("")
{

}

ApiError::ApiError(const std::string &error_id, const std::string &error_desc)
    : m_has_error(true),
      m_error_id(error_id),
      m_error_desc(error_desc)

{
}

ApiError::~ApiError()
{
}

void ApiError::setError(const std::string &error_id, const std::string &error_desc)
{
    m_has_error = true;
    m_error_id = error_id;
    m_error_desc = error_desc;
}

bool ApiError::has_error() const
{
    return m_has_error;
}

std::string ApiError::error() const
{
    string err = m_error_id + "," + m_error_desc;
    return err;
}

string ApiError::error_id() const
{
    return m_error_id;
}

string ApiError::error_desc() const
{
    return m_error_desc;
}

}
}
