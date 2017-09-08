#include "SdkSetting.h"
#include "HttpCurl.h"

namespace speakin_mobi {
namespace sdk {

bool curlGlobalInit()
{
    return HttpCurl::globalInit();
}

void setGlobalCurlOptTimeout(int timeout)
{
    HttpCurl::setCurlOptTimeout(timeout);
}

void setGlobalCurlOptConnectTimeOut(int timeout)
{
    HttpCurl::setCurlOptConnectTimeOut(timeout);
}

void curlGlobalCleanup()
{
    HttpCurl::globalCleanup();
}

}
}
