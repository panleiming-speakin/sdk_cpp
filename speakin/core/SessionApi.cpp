#include "SessionApi.h"

namespace speakin_mobi {
namespace sdk {

SessionApi::SessionApi(const string &app_id, const string &app_secret, const string &url, bool skip_crypt)
    : BaseApi(app_id, SESSION_ID, app_secret, url, skip_crypt)
{

}

SessionApi::~SessionApi()
{

}
RecordStream SessionApi::openUploadRecordStream(const string &recordId, const std::string &trace_id) {
    return RecordStream(this, recordId, trace_id);
}

ApiError SessionApi::regist(SessionApiObj::CRegisterRequest &req_data, SessionApiObj::CRegisterResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/session/register?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError SessionApi::verify(SessionApiObj::CVerifyRequest &req_data, SessionApiObj::CVerifyResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/session/verify?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError SessionApi::identity(SessionApiObj::CIdentityRequest &req_data, SessionApiObj::CIdentityResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/session/identity?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}


ApiError SessionApi::startRecord(SessionApiObj::CStartRecordRequest &req_data, SessionApiObj::CStartRecordResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/session/record/start?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError SessionApi::uploadRecordPart(SessionApiObj::CUploadRecordPartRequest &req_data, SessionApiObj::CUploadRecordPartResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/session/record/upload_part?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError SessionApi::uploadRecordDone(SessionApiObj::CUploadRecordDoneRequest &req_data, SessionApiObj::CUploadRecordDoneResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/session/record/done?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

ApiError SessionApi::uploadRecordCancel(SessionApiObj::CUploadRecordCancelRequest &req_data, SessionApiObj::CUploadRecordCancelResponse &rsp_data, const std::string &trace_id)
{
    string  url = "/v1/session/record/cancel?traceId=" + trace_id;
    ApiError err = callApi(url, req_data, rsp_data);
    return err;
}

}
}
