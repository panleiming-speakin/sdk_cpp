#ifndef RECORDSTREAM_H
#define RECORDSTREAM_H

#include <string>
#include "ApiError.h"

namespace speakin_mobi {
namespace sdk {

class SessionApi;

class RecordStream
{
public:
    RecordStream(SessionApi *api, const std::string &record_id, const std::string &trace_id="");
    ~RecordStream();

    ApiError write(const char *data, int len, int index);

    ApiError done();

    ApiError cancel();

private:
    SessionApi *m_api;
    std::string m_record_id;
    std::string m_trace_id;
};
}
}
#endif // RECORDSTREAM_H
