#include "CBson.h"
#include <bson.h>
#include "Utils.h"

namespace speakin_mobi {
namespace sdk {


static std::string bsonToString(bson_t *b)
{
    return string((char *)bson_get_data(b),b->len);
}


CBson::CBson()
{
    m_doc= bson_new();
}

CBson::CBson(const string &data)
    : m_doc(NULL)
{
    m_doc = bson_new_from_data((const uint8_t *)data.c_str(),data.length());
    if(m_doc) {
        m_hasError = !bson_iter_init(&m_iter, m_doc);
    } else {
        m_hasError = true;
    }
}

CBson::~CBson()
{
    if(m_doc) {
        bson_destroy(m_doc);
    }
}

bool CBson::setData(const string &data)
{
    if(m_doc) {
        bson_destroy(m_doc);
    }

    m_doc = bson_new_from_data((const uint8_t *)data.c_str(),data.length());
    if(m_doc) {
        m_hasError = !bson_iter_init(&m_iter, m_doc);
    } else {
        m_hasError = true;
    }
    return m_hasError;
}

bool CBson::setData(const uint8_t *data, uint32_t data_len)
{
    if(m_doc) {
        bson_destroy(m_doc);
    }

    m_doc = bson_new_from_data(data, data_len);
    if(m_doc) {
        m_hasError = !bson_iter_init(&m_iter, m_doc);
    } else {
        m_hasError = true;
    }
    return m_hasError;
}

std::string CBson::getData()
{
    return bsonToString(m_doc);
}

void CBson::printfAsJson()
{
    char *json=bson_as_json(m_doc, NULL);
    printf("%s\n",json);
    bson_free(json);
}

bson_t *CBson::doc() const
{
    return m_doc;
}

void CBson::appendBsonValueBinary(const string &key, const string &value)
{
    BSON_APPEND_BINARY(m_doc, key.c_str(),BSON_SUBTYPE_BINARY,(const uint8_t *)value.c_str(), value.length());
}

void CBson::appendBsonValue(const string &key, bool value)
{
    BSON_APPEND_BOOL(m_doc, key.c_str(), (value? true: false));
}

void CBson::appendBsonValue(const string &key, const string &value)
{
    BSON_APPEND_UTF8(m_doc, key.c_str(), value.c_str());
}

void CBson::appendBsonValue(const string &key, const char *value)
{
    BSON_APPEND_UTF8(m_doc, key.c_str(), value);
}

void CBson::appendBsonValue(const string &key, int value)
{
    BSON_APPEND_INT32(m_doc, key.c_str(), value);
}

void CBson::appendBsonValue(const string &key, long long value)
{
    BSON_APPEND_INT64(m_doc, key.c_str(), value);
}

void CBson::appendBsonValue(const string &key, list<string> value)
{
    bson_t child;
    BSON_APPEND_ARRAY_BEGIN (m_doc, key.c_str(), &child);

    char buf[16];
    const char *numkey;
    list<string>::iterator iter;
    int i=0;
    for(iter = value.begin(); iter != value.end(); iter++) {
        bson_uint32_to_string (i, &numkey, buf, sizeof buf);
        BSON_APPEND_UTF8(&child, numkey, iter->c_str());
        i++;
    }
    bson_append_array_end (m_doc, &child);
}

bool CBson::getBsonValue(const string &key, bool &value)
{
    bson_iter_t iter = m_iter;
    if (bson_iter_find (&iter, key.c_str()) &&
            bson_iter_value(&iter)->value_type == BSON_TYPE_BOOL ){
        value = bson_iter_value(&iter)->value.v_bool;
        return true;
    }
    return false;
}

bool CBson::getBsonValue(const string &key, string &value)
{
    bson_iter_t iter = m_iter;
    if (bson_iter_find (&iter, key.c_str()) &&
            bson_iter_value(&iter)->value_type == BSON_TYPE_UTF8 ){
        value = string(bson_iter_value(&iter)->value.v_utf8.str,bson_iter_value(&iter)->value.v_utf8.len);
        return true;
    }
    return false;

}

bool CBson::getBsonValue(const string &key, double &value)
{
    bson_iter_t iter = m_iter;
    if (bson_iter_find (&iter, key.c_str()) &&
            bson_iter_value(&iter)->value_type == BSON_TYPE_DOUBLE ){
        value = bson_iter_value(&iter)->value.v_double;
        return true;
    }
    return false;
}

bool CBson::getBsonValue(const string &key, int &value)
{
    bson_iter_t iter = m_iter;
    if (bson_iter_find (&iter, key.c_str()) &&
            bson_iter_value(&iter)->value_type == BSON_TYPE_INT32 ){
        value = bson_iter_value(&iter)->value.v_int32;
        return true;
    }
    return false;
}

bool CBson::getBsonValue(const string &key, long long &value)
{
    bson_iter_t iter = m_iter;
    if (bson_iter_find (&iter, key.c_str()) &&
            bson_iter_value(&iter)->value_type == BSON_TYPE_INT64 ){
        value = bson_iter_value(&iter)->value.v_int64;
        return true;
    }
    return false;
}

bool CBson::getBsonValue(const string &key, uint64_t &value)
{
    bson_iter_t iter = m_iter;
    if (bson_iter_find (&iter, key.c_str()) &&
            bson_iter_value(&iter)->value_type == BSON_TYPE_INT64 ){
        value = bson_iter_value(&iter)->value.v_int64;
        return true;
    }
    return false;
}

bool CBson::getBsonValue(const string &key, CBson &bson)
{
    uint32_t doc_len;
    const uint8_t *doc= NULL;
    bson_iter_t iter = m_iter;
    if (bson_iter_find (&iter, key.c_str()) &&
            bson_iter_value(&iter)->value_type == BSON_TYPE_DOCUMENT ){
        bson_iter_document(&iter, &doc_len, &doc);
        bson.setData(doc, doc_len);
        return !bson.hasError();
    }
    return false;
}

bool CBson::getBsonArray(const string &key, list<string> &value)
{
    bson_iter_t sub_iter;
    if (bson_iter_find (&m_iter, key.c_str())  &&
            (BSON_ITER_HOLDS_DOCUMENT (&m_iter) ||
             BSON_ITER_HOLDS_ARRAY (&m_iter)) &&
            bson_iter_recurse (&m_iter, &sub_iter)) {
        while (bson_iter_next (&sub_iter)) {
            if(bson_iter_value(&sub_iter)->value_type == BSON_TYPE_UTF8 ){
                value.push_back(string(bson_iter_value(&sub_iter)->value.v_utf8.str,bson_iter_value(&sub_iter)->value.v_utf8.len));
            }
        }
        return true;
    }
    return false;
}

bool CBson::getBsonBinary(const string &key, string &value)
{
    const uint8_t *doc= NULL;
    bson_iter_t iter = m_iter;
    if (bson_iter_find (&iter, key.c_str()) &&
            bson_iter_value(&iter)->value_type == BSON_TYPE_BINARY){
        uint32_t len;
        const uint8_t *data;
        bson_subtype_t t = BSON_SUBTYPE_BINARY;
        bson_iter_binary(&iter, &t, &len, &data);
        value = "";
        value.append((const char*)data, len);
        return true;
    }
    return false;
}

bool CBson::getBsonArray(const string &key, CBsonList &value)
{
    bson_iter_t sub_iter;
    if (bson_iter_find (&m_iter, key.c_str())  &&
            (BSON_ITER_HOLDS_DOCUMENT (&m_iter) ||
             BSON_ITER_HOLDS_ARRAY (&m_iter)) &&
            bson_iter_recurse (&m_iter, &sub_iter)) {
        while (bson_iter_next (&sub_iter)) {
            if(bson_iter_value(&sub_iter)->value_type == BSON_TYPE_DOCUMENT ){
                uint32_t doc_len;
                const uint8_t *doc= NULL;
                bson_iter_document(&sub_iter, &doc_len, &doc);
                value.insert(doc, doc_len);
            }
        }
        return true;
    }
    return false;
}

bool CBson::hasError() const
{
    return m_hasError;
}

bson_t *CBson::getDoc() const
{
    return m_doc;
}

CBsonList::CBsonList()
{

}

CBsonList::~CBsonList()
{
    int size = m_vector.size();
    for(int i=0; i<size; i++) {
        delete m_vector[i];
    }
}

bool CBsonList::insert(const uint8_t *data, uint32_t data_len)
{
    CBson *b = new CBson();
    b->setData(data, data_len);
    m_vector.insert(m_vector.end(),b);
    return true;
}

CBson *CBsonList::operator [](int i)
{
    return m_vector[i];
}

int CBsonList::size()
{
    return m_vector.size();
}

}
}
