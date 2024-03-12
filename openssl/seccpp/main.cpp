#include <iostream>
#include "rsa.h"
#include "aes.h"
#include <openssl/evp.h>
#include <fstream>
#include <openssl/rand.h>
#include <openssl/hmac.h>

int sha()
{
    EVP_MD_CTX  *ctx;
    const EVP_MD* md;
    
    // create and init context
    ctx = EVP_MD_CTX_new();
    md = EVP_sha256();
    EVP_DigestInit_ex(ctx, md, NULL);

    // hash data(updata)
    std::string message(200,'a');
    EVP_DigestUpdate(ctx, message.c_str(), message.length());

    // hash data(final)
    unsigned char hash_data[2048];
    unsigned int output_len;
    EVP_DigestFinal_ex(ctx, hash_data, &output_len);

    // clean and free context
    EVP_MD_CTX_free(ctx);

    // save hash data to file
    std::ofstream output_file("./sha/sha_hash.bin", std::ios::out | std::ios::binary);
    output_file.write(reinterpret_cast<const char*>(hash_data), output_len);
    output_file.close();

    return 0;
}

int hmac()
{
    // generate a key
    const size_t key_len = 32; // 32 char == 32*8=256 bit
    unsigned char hmac_key[key_len];
    RAND_bytes(hmac_key, key_len);

    HMAC_CTX* ctx = HMAC_CTX_new();
    HMAC_Init_ex(ctx, hmac_key, key_len, EVP_sha256(), nullptr);
    std::string message(200, 'a');
    HMAC_Update(ctx, reinterpret_cast<const unsigned char*>(message.c_str()), message.length());
    unsigned int output_len;
    unsigned char output_data[2048];
    HMAC_Final(ctx, output_data, &output_len);
    HMAC_CTX_free(ctx);

    // save hash data to file
    std::ofstream output_file("./hmac/hmac_hash.bin", std::ios::out | std::ios::binary);
    output_file.write(reinterpret_cast<const char*>(output_data), output_len);
    output_file.close();

    // save key data to file
    std::ofstream output_key_file("./hmac/hmac_key.txt", std::ios::out);
    output_key_file.write(reinterpret_cast<const char*>(hmac_key), key_len);
    output_key_file.close();

    return 0;

}

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

    sha();
    hmac();
    
}


