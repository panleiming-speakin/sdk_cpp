#include "Utils.h"
#include <sys/timeb.h>
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <sstream>

namespace speakin_mobi {
namespace sdk {

// 产生一个当前的毫秒,这个毫秒其实就是自1970年1月1日0时起的毫秒数
long long getCurrentTimeMillis()
{
    struct timeb t1;
    ftime(&t1);
    long long t = (long long)t1.time * 1000 + t1.millitm;
    return t;
}

}
}
