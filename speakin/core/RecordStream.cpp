#include "RecordStream.h"
#include "SessionApi.h"
#include "SessionApiObj.h"
#include "CryptUtil.h"

namespace speakin_mobi {
namespace sdk {

RecordStream::RecordStream(SessionApi *api,  const std::string &record_id, const std::string &trace_id)
    : m_api(api),
      m_record_id(record_id),
      m_trace_id(trace_id)
{

}

RecordStream::~RecordStream()
{

}

ApiError RecordStream::write(const char *data,int len,int index)
{
    SessionApiObj::CUploadRecordPartRequest req_data;
    req_data.record_id = m_record_id;
    req_data.index_id = index;
    req_data.data ="";
    req_data.data.append(data, len);
    SessionApiObj::CUploadRecordPartResponse rsp_data;
    return m_api->uploadRecordPart(req_data, rsp_data, m_trace_id);
}

ApiError RecordStream::done()
{
    SessionApiObj::CUploadRecordDoneRequest req_data;
    req_data.record_id = m_record_id;
    SessionApiObj::CUploadRecordDoneResponse rsp_data;
    return m_api->uploadRecordDone(req_data, rsp_data, m_trace_id);
}

ApiError RecordStream::cancel()
{
    SessionApiObj::CUploadRecordCancelRequest req_data;
    req_data.record_id = m_record_id;
    SessionApiObj::CUploadRecordCancelResponse rsp_data;
    return m_api->uploadRecordCancel(req_data, rsp_data, m_trace_id);
}

}
}
