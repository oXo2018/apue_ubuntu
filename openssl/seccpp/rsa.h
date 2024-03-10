
#include <string>
#include <iostream>

class RsaDemo 
{
public:
    int generatekey();
    int encrypt();
    int decrypt();
    int sign();
    int verify();
    int getKeyDetail();

    int printPrivateDetails();
    int printPublicDetails();

private:
    std::string RSA_public_key_file;
    std::string RSA_private_key_file;
};
