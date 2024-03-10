#include <iostream>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <string>

std::string sha256(const std::string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

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