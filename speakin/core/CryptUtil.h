/**
 * Created by yuminghao on 2017-06-01
 */

#ifndef CRYPTUTIL_H
#define CRYPTUTIL_H

#include <string>
using namespace std;

namespace speakin_mobi {
namespace sdk {

namespace CryptUtil {
    string aesCrypt(const string &key, string &plain_string);
    string aesDecrypt(const string &key, string &dec_input);
    void aesDecrypt(const string &key, string &dec_input, string &dec_out);
}

namespace Sha1Util {
    string sha1(const string &data);
}

}
}

#endif // CRYPTUTIL_H
