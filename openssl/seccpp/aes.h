#include <string>
#include <iostream>

class AesDemo 
{
public:
    AesDemo();

    int encrypt();
    int decrypt();

private:
    unsigned char aes_key[32];
    unsigned char iv[16];
    std::string encrypted_file;
    std::string message_file;
};