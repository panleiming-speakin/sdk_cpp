#ifndef SESSIONAPI_H
#define SESSIONAPI_H

#include <string>
#include "BaseApi.h"
#include "SessionApiObj.h"
#include "RecordStream.h"

namespace speakin_mobi {
namespace sdk {

class SessionApi : public BaseApi
{
public:
    explicit SessionApi(const std::string &app_id, const std::string &app_secret, const std::string &url, bool skip_crypt = false);
    ~SessionApi();

    RecordStream openUploadRecordStream(const std::string &recordId, const std::string &trace_id="");
    ApiError regist(SessionApiObj::CRegisterRequest &req_data, SessionApiObj::CRegisterResponse &rsp_data, const std::string &trace_id="");
    ApiError verify(SessionApiObj::CVerifyRequest &req_data, SessionApiObj::CVerifyResponse &rsp_data, const std::string &trace_id="");
    ApiError identity(SessionApiObj::CIdentityRequest &req_data, SessionApiObj::CIdentityResponse &rsp_data, const std::string &trace_id="");
    /* 开始上传文件 */
    ApiError startRecord(SessionApiObj::CStartRecordRequest &req_data, SessionApiObj::CStartRecordResponse &rsp_data, const std::string &trace_id="");
    ApiError uploadRecordPart(SessionApiObj::CUploadRecordPartRequest &req_data, SessionApiObj::CUploadRecordPartResponse &rsp_data, const std::string &trace_id="");
    ApiError uploadRecordDone(SessionApiObj::CUploadRecordDoneRequest &req_data, SessionApiObj::CUploadRecordDoneResponse &rsp_data, const std::string &trace_id="");
    ApiError uploadRecordCancel(SessionApiObj::CUploadRecordCancelRequest &req_data, SessionApiObj::CUploadRecordCancelResponse &rsp_data, const std::string &trace_id="");
};

}
}

#endif // SESSIONAPI_H
