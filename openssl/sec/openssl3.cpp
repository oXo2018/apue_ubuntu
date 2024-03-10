#include <iostream>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <string>

std::string sha256(const std::string str)
{

    EVP_MD_CTX *mdctx; // like a seesion 
    const EVP_MD *md; // set algorithm
    unsigned char hash[SHA256_DIGEST_LENGTH];

    md = EVP_sha256();
    mdctx = EVP_MD_CTX_new(); // create a new session

    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, str.c_str(), str.size());
    EVP_DigestFinal_ex(mdctx, hash, NULL);
    EVP_MD_CTX_free(mdctx);

    EVP_PKEY_generate

    
    std::string hashStr;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        char hex[3];
        sprintf(hex, "%02x", hash[i]);
        hashStr += hex;
    } 

    return hashStr;
}


int main()
{
    std::string input = "hello world";
    std::string hash = sha256(input);
    std::cout << "SHA256 hash of 'hello world': " << hash << std::endl;
    return 0;
}