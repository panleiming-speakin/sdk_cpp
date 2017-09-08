#include <iostream>
#include <stdio.h>
#include "SdkSetting.h"
#include "Api.h"
#include "SessionApi.h"
#include "UserApi.h"
#include "ApiTypes.h"

using namespace speakin_mobi::sdk;

/**
 * @brief apiTest 全局接口demo
 */
void apiDemo()
{
    std::string ip = "http://api3.speakin.mobi";                 /* 服务器ip 、域名 */
    std::string app_id = "speakin_test";                         /* app id */
    std::string app_secret = "mr1imt1etu7ryets9eoergua87h0pa4n"; /* app key */

    bool skip_crypt = false; /* 是否跳过加密 */
    speakin_mobi::sdk::Api api(app_id, app_secret, ip, skip_crypt);

    /* 列出所有可用的声纹模型 */
    speakin_mobi::sdk::ApiObj::CListModuleRequest moduleReq;
    speakin_mobi::sdk::ApiObj::CListModuleResponse moduleRsp;
    speakin_mobi::sdk::ApiError err = api.listModule(moduleReq, moduleRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "modules count: " << moduleRsp.module_list.size() << std::endl;
    std::list<speakin_mobi::sdk::ApiObj::CModule>::iterator iter;
    for(iter=moduleRsp.module_list.begin(); iter!=moduleRsp.module_list.end(); iter++) {
        std::cout << "voice_lang: " << iter->voice_lang
                  <<", voice_rate:"<< iter->voice_rate
                  << ", voice_bit_count:" << iter->voice_bit_count
                  << std::endl;
    }

    /* 开始一个新的会话 */
    speakin_mobi::sdk::ApiObj::CStartSessionRequest sessionReq;
    sessionReq.user_id = "xx";
    sessionReq.can_verify = true;
    sessionReq.can_identity = true;
    sessionReq.can_register = true;
    sessionReq.ttl = 10000;

    ApiObj::CStartSessionResponse sessionRsp;
    err = api.startSession(sessionReq, sessionRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "StartSession: "
              << sessionRsp.session_id<<","
              << sessionRsp.session_secret << ","
              << sessionRsp.expire_time_stamp << std::endl;

    /* 日志追溯 */
    speakin_mobi::sdk::ApiObj::CQueryTraceRequest queryTraceReq;
    queryTraceReq.offset =0;
    queryTraceReq.limit = 1000;
    speakin_mobi::sdk::ApiObj::CQueryTraceResponse queryTraceRsp;
    err = api.queryTrace(queryTraceReq, queryTraceRsp, "xxxyyyzzz");
    if(err.has_error()) {
       std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "QueryTrace: "
              << queryTraceRsp.total_count << ","
              << queryTraceRsp.log_content << std::endl;
}
/**
 * @brief userApiDemo 用户接口demo
 */
void userApiDemo() {
    std::string ip = "http://api3.speakin.mobi";                 /* 服务器ip 、域名 */
    std::string app_id = "speakin_test";                         /* app id */
    std::string app_secret = "mr1imt1etu7ryets9eoergua87h0pa4n"; /* app key */

    bool skip_crypt = true; /* 是否跳过加密 */
    speakin_mobi::sdk::UserApi user_api(app_id, app_secret, ip, skip_crypt); /* 获取 user_api */

    /* 设置sdk用户 */
    UserApiObj::CSetAppUserRequest setUserReq;
    setUserReq.user_id = "xx";
    setUserReq.user_type = user_type_name[PEOPLE]; /* user_type 用户类型有 "DEV","PEOPLE","VIRTUAL" */
    setUserReq.valid = true;
    setUserReq.access_all_app_user = false;        /* 是否允许app里的所有用户 */
    speakin_mobi::sdk::UserApiObj::CSetAppUserResponse setUserRsp;
    speakin_mobi::sdk::ApiError err = user_api.setAppUser(setUserReq, setUserRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "SetAppUser success!"<< std::endl;

    /* 设置sdk设备 */
    UserApiObj::CSetAppUserRequest setDevUserReq;
    setDevUserReq.user_id = "dev01";
    setDevUserReq.user_type = user_type_name[DEV]; /* user_type 用户类型有 "DEV","PEOPLE","VIRTUAL" */
    setDevUserReq.valid = true;
    setDevUserReq.access_all_app_user = false; /* 是否允许app里的所有用户，如果是false，则在identify时只会比对该用户的子用户组, 建议为false */
    speakin_mobi::sdk::UserApiObj::CSetAppUserResponse setDevUserRsp;
    err = user_api.setAppUser(setDevUserReq, setDevUserRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "SetAppUser success!"<< std::endl;


    /* 获取用户 */
    UserApiObj::CGetAppUserRequest getUserReq;
    getUserReq.user_id = "xx";
    UserApiObj::CGetAppUserResponse getUserRsp;
    err = user_api.getAppUser(getUserReq, getUserRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "GetAppUser: "
              << getUserRsp.user_id<<","
              << getUserRsp.user_type << ","
              << (getUserRsp.valid?"true":"false") << ","
              << (getUserRsp.access_all_app_user?"true":"false") << std::endl;

    /* 设置子用户 */
    UserApiObj::CAddChildAppUserRequest addChiledReq;
    addChiledReq.user_id = "dev01";
    addChiledReq.child_user_id = "xx";
    UserApiObj::CAddChildAppUserResponse addChildRsp;
    err = user_api.addChildAppUser(addChiledReq, addChildRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "AddChildAppUser success!"<< std::endl;

    /* 获取子用户数量 */
    UserApiObj::CGetChildAppUserCountRequest getChildCountReq;
    getChildCountReq.user_id = "dev01";
    UserApiObj::CGetChildAppUserCountResponse getChildCountRsp;
    err = user_api.getChildAppUserCount(getChildCountReq, getChildCountRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "ChildAppUserCount:"<< getChildCountRsp.count << std::endl;

    /* 列出子用户 */
    UserApiObj::CListChildAppUserRequest listChildReq;
    listChildReq.user_id = "dev01";
    listChildReq.offset = 0;
    listChildReq.limit = 10;
    UserApiObj::CListChildAppUserResponse listChildRsp;
    err = user_api.listChildAppUser(listChildReq, listChildRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "count:"<<listChildRsp.child_user_id_list.size() << std::endl;
    std::list<string>::iterator iter;
    std::cout << "[ ";
    for(iter=listChildRsp.child_user_id_list.begin(); iter!=listChildRsp.child_user_id_list.end(); iter++) {
        string user_id = iter->c_str();
        std::cout << user_id << " ";
    }
    std::cout << "]" << std::endl;

    /* 检查是否包含子用户 */
    UserApiObj::CContainChildAppUserRequest ContainReq;
    ContainReq.user_id = "dev01";
    ContainReq.child_user_id = "xx";
    UserApiObj::CContainChildAppUserResponse ContainRsp;
    err = user_api.containChildAppUser(ContainReq, ContainRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "ContainChildAppUser:" << (ContainRsp.contain?"true":"false") << std::endl;

    /* 移除子用户 */
    UserApiObj::CRemoveChildAppUserRequest req;
    req.user_id = "dev01";
    req.child_user_id = "xx";
    UserApiObj::CRemoveChildAppUserResponse rsp;
    err = user_api.removeChildAppUser(req, rsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "RemoveChildAppUser success!"<< std::endl;

    /* 设置子用户 */
    UserApiObj::CAddChildAppUserRequest addChiledReq2;
    addChiledReq2.user_id = "dev01";
    addChiledReq2.child_user_id = "xx";
    UserApiObj::CAddChildAppUserResponse addChildRsp2;
    err = user_api.addChildAppUser(addChiledReq2, addChildRsp2);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "AddChildAppUser success!"<< std::endl;

}

speakin_mobi::sdk::ApiError upload(speakin_mobi::sdk::SessionApi &session_api,
                                   speakin_mobi::sdk::TARGET_ACTION action,
                                   const std::string file_name,
                                   std::string &recoderId)
{
    ApiError err;
    SessionApiObj::CStartRecordRequest start_req;
    start_req.target_action = target_action_name[action]; /* 类型 "REGISTER","VERIFY", "IDENTITY" 对应着注册、验证、识别 */
    start_req.voice_bit_count = 16;                       /*  模型通过 全局接口 listModule得到 */
    start_req.voice_rate = 16000;                         /* 模型通过 全局接口 listModule得到 */
    start_req.voice_lang = "common-short";                /* 模型通过 全局接口 listModule得到 */
    start_req.data_format = data_format_name[WAV];        /* 格式类型有 "WAV","PCM" */

    SessionApiObj::CStartRecordResponse start_rsp;
    err = session_api.startRecord(start_req, start_rsp);
    if(err.has_error()) {
        return err;
    }

    RecordStream rs = session_api.openUploadRecordStream(start_rsp.record_id);
    /* 文件分块上传(可乱序上传、只要确保index是从1开始递增) */
    FILE *fp;
    fp = fopen(file_name.c_str(),"rb");
    if(fp) {
        char buf[40960];
        int ret;
        int index = 1;
        while(1) {
            ret = fread(buf,1,40960,fp);
            if(ret == 0) {
                break;
            }
            err = rs.write(buf, ret, index++);
            if(err.has_error()) {
                return err;
            }
        }
        fclose(fp);
    }
    else {
        std::cout << "openfile failed!"<< std::endl;
        err.setError("Open file","open file failed");
        return err;
    }

    err = rs.done();
    if(err.has_error()) {
        return err;
    }
    recoderId = start_rsp.record_id;
    return err;
}
/**
 * @brief sessionApiDemo 会话接口demo
 */
void sessionApiDemo() {
    std::string ip = "http://api3.speakin.mobi";                 /* 服务器ip 、域名 */
    std::string app_id = "speakin_test";                         /* app id */
    std::string app_secret = "mr1imt1etu7ryets9eoergua87h0pa4n"; /* app key */

    bool skip_crypt = true; /* 是否跳过加密 */
    speakin_mobi::sdk::Api api(app_id, app_secret, ip, skip_crypt);

    /* 开始一个新的会话 */
    speakin_mobi::sdk::ApiObj::CStartSessionRequest sessionReq;
    sessionReq.user_id = "xx";
    sessionReq.can_verify = true;
    sessionReq.can_identity = true;
    sessionReq.can_register = true;
    sessionReq.ttl = 7200;
    speakin_mobi::sdk::ApiObj::CStartSessionResponse sessionRsp;
    speakin_mobi::sdk::ApiError err = api.startSession(sessionReq, sessionRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    speakin_mobi::sdk::SessionApi session_api(sessionRsp.session_id, sessionRsp.session_secret, ip, false);

    string record_id;
    /* 上传文件, 用于注册 */
    err = upload(session_api, REGISTER, "test_resources/SI_device1_409_HM_digital_01.wav", record_id);
    if(err.has_error()) {
        std::cout << "upload failed: " <<err.error() << std::endl;
        return;
    }

    /* 注册 */
    SessionApiObj::CRegisterRequest registerReq;
    registerReq.record_id_list.push_back(record_id);
    SessionApiObj::CRegisterResponse registerRsp;
    err = session_api.regist(registerReq, registerRsp);
    if(err.has_error()) {
        std::cout << "register failed:" << err.error() << std::endl;
        return;
    }
    std::cout << "Register success!"<< std::endl;

    /* 验证 */
    err = upload(session_api, VERIFY, "test_resources/SI_device1_409_HM_digital_01.wav", record_id);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    SessionApiObj::CVerifyRequest verifyReq;
    verifyReq.record_id = record_id;
    SessionApiObj::CVerifyResponse verifyRsp;
    err = session_api.verify(verifyReq, verifyRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "verify result:"<< (verifyRsp.result?"true":"false")
              << " score:" << verifyRsp.score
              << " threshold_score:" << verifyRsp.threshold_score << std::endl;

    /* 识别
     *    开始一个设备的会话
     */
    speakin_mobi::sdk::ApiObj::CStartSessionRequest devSessionReq;
    devSessionReq.user_id = "dev01";
    devSessionReq.can_verify = true;
    devSessionReq.can_identity = true;
    devSessionReq.can_register = true;
    devSessionReq.ttl = 7200;
    speakin_mobi::sdk::ApiObj::CStartSessionResponse devSessionRsp;
    err = api.startSession(devSessionReq, devSessionRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    speakin_mobi::sdk::SessionApi dev_session_api(devSessionRsp.session_id, devSessionRsp.session_secret, ip, false);
    /* 上传文件 */
    err = upload(dev_session_api, IDENTITY, "test_resources/SI_device1_409_HM_digital_01.wav", record_id);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    /* 开始识别 */
    SessionApiObj::CIdentityRequest identifyReq;
    identifyReq.record_id = record_id;
    identifyReq.filter_user = true;
    identifyReq.filter_user_id_list.push_back("xx");
    identifyReq.filter_user_id_list.push_back("yy");
    SessionApiObj::CIdentityResponse identifyRsp;
    err = dev_session_api.identity(identifyReq, identifyRsp);
    if(err.has_error()) {
        std::cout << err.error() << std::endl;
        return;
    }
    std::cout << "user_id_list:"<< identifyRsp.user_id_list.size()<< std::endl;
    std::list<string>::iterator iter;
    std::cout << "[ ";
    for(iter=identifyRsp.user_id_list.begin(); iter!=identifyRsp.user_id_list.end(); iter++) {
        string user_id = iter->c_str();
        std::cout << user_id << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "score_diff_list:"<< identifyRsp.score_diff_list.size()<< std::endl;
    std::list<double>::iterator score_iter;
    std::cout << "[ ";
    for(score_iter=identifyRsp.score_diff_list.begin(); score_iter!=identifyRsp.score_diff_list.end(); score_iter++) {
        std::cout << *score_iter << " ";
    }
    std::cout << "]" << std::endl;

}

int main()
{
    bool result = speakin_mobi::sdk::curlGlobalInit();
    if(result == false) {
        std::cout << "speakin_mobi::sdk::curlGlobalInit failed" << std::endl;
    }
    speakin_mobi::sdk::setGlobalCurlOptTimeout(0);
    speakin_mobi::sdk::setGlobalCurlOptConnectTimeOut(0);

    /* 用户接口demo */
    userApiDemo();

    /* 全局接口demo */
    apiDemo();

    /* 会话接口demo */
    sessionApiDemo();

    speakin_mobi::sdk::curlGlobalCleanup();
    return 0;
}



