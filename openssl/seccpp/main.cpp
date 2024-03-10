#include <iostream>
#include "rsa.h"


int main()
{
    RsaDemo rsademo = RsaDemo(); ;
    rsademo.generatekey();
    rsademo.printPublicDetails();
    rsademo.printPrivateDetails();
    rsademo.encrypt();
    rsademo.decrypt();
}


