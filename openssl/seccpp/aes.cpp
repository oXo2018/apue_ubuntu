#include <openssl/evp.h>
#include <openssl/rand.h>
#include <iostream>
#include <fstream>
#include <cstring>

#include "aes.h"

AesDemo::AesDemo()
{
    RAND_bytes(this->aes_key, sizeof(this->aes_key));
    RAND_bytes(this->iv, sizeof(this->iv));
    this->encrypted_file = "./aes/aes_encrypted_data.bin";
    this->message_file = "./aes/aes_message_data.txt";
}

int AesDemo::encrypt()
{
    EVP_CIPHER_CTX* ctx;
    
    // create and init context
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, this->aes_key, this->iv);

    // encrypt data (update)
    unsigned char ciphertext[4096] = {0};
    int consume_out;
    std::string message = std::string(200, 'a');
    EVP_EncryptUpdate(ctx, ciphertext, &consume_out, reinterpret_cast<const unsigned char*>(message.c_str()), message.length());
    int ciphertext_final_len;
    ciphertext_final_len = consume_out;

    // encrypt data (final)
    EVP_EncryptFinal_ex(ctx, ciphertext + consume_out, &consume_out);
    ciphertext_final_len += consume_out;

    // clean and free context
    EVP_CIPHER_CTX_free(ctx);

    std::cout << ciphertext_final_len << std::endl;
    // save encypted data to file
    std::ofstream output_file(this->encrypted_file, std::ios::out | std::ios::binary);
    output_file.write(reinterpret_cast<const char*>(ciphertext), ciphertext_final_len);
    output_file.close();

    std::cout << "Aes data encrypted successfully." << std::endl;
    return 0;
}

int AesDemo::decrypt()
{
    std::ifstream input_file(this->encrypted_file, std::ios::in | std::ios::binary);
    std::string encrypted_data((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    input_file.close();

    // create and init context
    EVP_CIPHER_CTX* ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, this->aes_key, this->iv);

    unsigned char message_out[4096] = {0};
    int consume_out;
    // decrypt data (updata)
    EVP_DecryptUpdate(ctx, message_out, &consume_out, reinterpret_cast<const unsigned char *>(encrypted_data.c_str()), encrypted_data.length());
    int message_out_final;
    message_out_final = consume_out;

    // decrypt data (final)
    EVP_DecryptFinal_ex(ctx, message_out + message_out_final, &consume_out);
    message_out_final += consume_out;

    // save decypted data to file
    std::ofstream output_file(this->message_file, std::ios::out);
    output_file.write(reinterpret_cast<const char*>(message_out), message_out_final);
    output_file.close();

    std::cout << "Aes data decrypted successfully." << std::endl;
    return 0;

}