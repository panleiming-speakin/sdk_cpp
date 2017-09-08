#include "CryptUtil.h"
#include <string.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <openssl/sha.h>
#include <openssl/crypto.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

namespace speakin_mobi {
namespace sdk {

void encrypt(const char* in, int inl, char *out, int &len,const char * key, unsigned char *iv)
{
    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);

    EVP_EncryptInit_ex(&ctx, EVP_aes_256_cbc(), NULL,(unsigned char *)key, iv);

    len = 0;
    int outl = 0;

    EVP_EncryptUpdate(&ctx, (unsigned char *)out + len, &outl, (unsigned char *)in + len, inl);
    len+=outl;

    /* pkcs5padding */
    EVP_EncryptFinal_ex(&ctx, (unsigned char *)out + len, &outl);
    len+=outl;

    EVP_CIPHER_CTX_cleanup(&ctx);
}

void decrypt(const char* in, int inl, char *out, int& len,const char *key, unsigned char *iv)
{
    EVP_CIPHER_CTX ctx;

    EVP_CIPHER_CTX_init(&ctx);

    EVP_DecryptInit_ex(&ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key, iv);
    len = 0;
    int outl = 0;

    EVP_DecryptUpdate(&ctx, (unsigned char*)out+len, &outl, (unsigned char*)in+len, inl);
    len += outl;

    EVP_DecryptFinal_ex(&ctx, (unsigned char*)out+len, &outl);
    len+=outl;
    out[len]=0;
    EVP_CIPHER_CTX_cleanup(&ctx);
}


string CryptUtil::aesCrypt(const string &key, string &plain_string)
{
    int plain_length = plain_string.length();
    char *cipher_buf = (char *)malloc(plain_length + 32);
    memset(cipher_buf, 0, plain_length+32);
    int ciphertext_base64_len;

    unsigned char iv[16];
    RAND_pseudo_bytes(iv, 16); /* 产生随机iv */

    encrypt(plain_string.c_str(),plain_length,
            cipher_buf,
            ciphertext_base64_len,
            key.c_str(),
            iv);

    string cipherString((char *)iv,16);
    cipherString.append(cipher_buf,ciphertext_base64_len);
    free(cipher_buf);
    return cipherString;
}

string CryptUtil::aesDecrypt(const string &key, string &dec_input)
{
    int cipher_length = dec_input.length();
    char *plain_buf = (char *)malloc(cipher_length);
    int plain_length;
    unsigned char iv[16];
    memcpy(iv, dec_input.c_str(),16);
    decrypt(dec_input.c_str() + 16, cipher_length -16, plain_buf, plain_length, key.c_str(), iv);
    string plainString(plain_buf, plain_length);
    free(plain_buf);
    return plainString;
}

void CryptUtil::aesDecrypt(const string &key, string &dec_input, string &dec_out)
{
    int cipher_length = dec_input.length();
    char *plain_buf = (char *)malloc(cipher_length);
    int plain_length;
    unsigned char iv[16];
    memcpy(iv, dec_input.c_str(),16);
    decrypt(dec_input.c_str() + 16, cipher_length -16, plain_buf, plain_length, key.c_str(), iv);
    dec_out="";
    dec_out.append(plain_buf, plain_length);
    free(plain_buf);
}


string Sha1Util::sha1(const string &data)
{
    unsigned char md[SHA_DIGEST_LENGTH];
    SHA1((unsigned char *)data.c_str(), data.length(), md);
    string output = string((char *)md,SHA_DIGEST_LENGTH);
    return output;
}

}
}
