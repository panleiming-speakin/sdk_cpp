#ifndef SDKCURL_H
#define SDKCURL_H

namespace speakin_mobi {
namespace sdk {

/**
 * @brief curlGlobalInit 在主线程只调用一次，实际调用 curl_global_init(CURL_GLOBAL_ALL)，
 * @return 成功:true 失败:false
 *
 * 注意：
 *     该函数非线程安全
 *     如果已经调用过 curl_global_init(CURL_GLOBAL_ALL)，则不需要调用该初始化函数
 *     如果没有调用过 curl_global_init(CURL_GLOBAL_ALL)， 则需要在主线程中调用该函数一次
 */
bool curlGlobalInit();

/**
 * @brief curl_global_cleanup 实际上调用的是 curl_global_cleanup
 *
 * 注意:
 *    该函数非线程安全
 */
void curlGlobalCleanup();

/**
 * @brief setGlobalCurlOptTimeout 设置http请求的最大超时时间
 * @param timeout 超时时间，单位秒
 *
 * 注意:
 *     该函数线程安全
 *     设置为0，超时时间为无限长
 *     设置后， sdk使用该时间为http请求的最大超时时间
 */
void setGlobalCurlOptTimeout(int timeout);

/**
 * @brief setGlobalCurlOptConnectTimeOut 设置http连接的超时时间
 * @param timeout 超时时间，单位秒
 *
 * 注意：
 *     该函数线程安全
 *     Set to zero to switch to the default built-in connection timeout - 300 seconds
 *     设置后，sdk使用该时间为http的连接超时时间
 */
void setGlobalCurlOptConnectTimeOut(int timeout);

}
}

#endif // SDKCURL_H
