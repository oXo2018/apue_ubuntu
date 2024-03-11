#include <iostream>
#include "rsa.h"
#include "aes.h"


int main()
{
    RsaDemo rsademo = RsaDemo(); 
    rsademo.generatekey();
    rsademo.printPublicDetails();
    rsademo.printPrivateDetails();
    rsademo.encrypt();
    rsademo.decrypt();
    rsademo.sign();
    rsademo.verify();

    AesDemo aesdemo;
    aesdemo.encrypt();
    aesdemo.decrypt();

    
}


