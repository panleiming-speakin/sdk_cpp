#ifndef BASEOBJ_H
#define BASEOBJ_H

#include <string>

namespace speakin_mobi {
namespace sdk {

class BaseReqObj
{
public:
    virtual std::string getData() const = 0;
};

class BaseRspObj
{
public:
    virtual bool setData(const std::string &data) = 0;
};

}
}

#endif // BASEOBJ_H
