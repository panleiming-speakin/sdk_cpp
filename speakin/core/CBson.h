#ifndef CBSON_H
#define CBSON_H

#include <string>
#include <vector>
#include <list>
#include <bson.h>

namespace speakin_mobi {
namespace sdk {

using namespace std;

using std::string;
using std::vector;
using std::list;

class CBson;

class CBsonList {
public:
    CBsonList();
    ~CBsonList();
    bool insert(const uint8_t *data, uint32_t data_len);
    CBson* operator [](int i);
    int size();

private:
    vector<CBson*> m_vector;
};


class CBson
{
public:
    CBson();
    CBson(const string &data);
    ~CBson();

    bool setData(const string &data);
    bool setData(const uint8_t *data, uint32_t data_len);
    string getData();
    void printfAsJson();

    bson_t *doc() const;
    void appendBsonValueBinary(const string &key, const string &value);
    void appendBsonValue(const string &key, bool value);
    void appendBsonValue(const string &key, const string &value);
    void appendBsonValue(const string &key, const char *value);
    void appendBsonValue(const string &key, int value);
    void appendBsonValue(const string &key, long long value);
    void appendBsonValue(const string &key, list<string> value);


    bool getBsonValue(const string &key, bool &value);
    bool getBsonValue(const string &key, string &value);
    bool getBsonValue(const string &key, double &value);
    bool getBsonValue(const string &key, int &value);
    bool getBsonValue(const string &key, long long &value);
    bool getBsonValue(const string &key, uint64_t &value);

    bool getBsonValue(const string &key, CBson &bson);
    bool getBsonArray(const string &key, list<string> &value);
    bool getBsonArray(const string &key, CBsonList &value);
    bool getBsonBinary(const string &key, string &value);

    bool hasError() const;

    bson_t *getDoc() const;

private:
    bson_t *m_doc;
    bson_iter_t m_iter;
    bool m_hasError;
};

}
}
#endif // CBSON_H
