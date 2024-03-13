#include <string>
#include <iostream>

class EcdsaDemo 
{
public:
    int generatekey();
    int sign();
    int verify();


private:
    std::string EC_public_key_file;
    std::string EC_private_key_file;
};