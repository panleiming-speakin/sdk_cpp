#ifndef APITYPES_H
#define APITYPES_H

#include <string>
#include <map>

namespace speakin_mobi {
namespace sdk {

enum ID_TYPE {
    APP_ID=0,
    SESSION_ID,
    ID_TYPE_COUNT,
};

static const char id_type_name[ID_TYPE_COUNT][32] = {
    "APP_ID",
    "SESSION_ID",
};

enum USER_TYPE {
    DEV=0,
    PEOPLE,
    VIRTUAL,
    USER_TYPE_COUNT,
};

static const char user_type_name[USER_TYPE_COUNT][32] = {
    "DEV",
    "PEOPLE",
    "VIRTUAL",
};

enum DATA_FORMAT {
    WAV=0,
    PCM,
    DATA_FORMAT_COUNT,
};

static const char data_format_name[DATA_FORMAT_COUNT][32] = {
    "WAV",
    "PCM",
};

enum TARGET_ACTION {
    REGISTER=0,
    VERIFY,
    IDENTITY,
    TARGET_ACTION_COUNT,
};

static const char target_action_name[TARGET_ACTION_COUNT][32] = {
    "REGISTER", /* 声纹注册 */
    "VERIFY",   /* 声纹验证 1:1 */
    "IDENTITY", /* 声纹匹配（识别） 1:N*/
};

}
}

#endif // APITYPES_H
