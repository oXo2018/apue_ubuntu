#include <openssl/evp.h>
#include <openssl/ec.h>
#include <openssl/pem.h>
#include <iostream>
#include <fstream>

#include "ecdsa.h"

int EcdsaDemo::generatekey()
{
    this->EC_private_key_file = "./ec/ec_private_key.pem";
    this->EC_public_key_file = "./ec/ec_public_key.pem";

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
    if (!ctx)
    {
        std::cerr << "Failed to create EVP_PKEY_CTX" << std::endl;
        return -1;
    }

    if (EVP_PKEY_keygen_init(ctx) <= 0)
    {
        std::cerr << "Failed to initalize key generation" << std::endl;
        return -1;
    }

    // #define NID_X9_62_prime256v1            415
    if (EVP_PKEY_CTX_set_ec_paramgen_curve_nid(ctx, NID_X9_62_prime256v1) <= 0)
    {
        std::cerr << "Failed to set curve for key generation";
        EVP_PKEY_CTX_free(ctx);
        return -1;
    }

    EVP_PKEY* pkey = NULL;
    if (EVP_PKEY_keygen(ctx, &pkey) <= 0)
    {
        std::cerr << "Failed to generate ECDSA key pair." << std::endl;
        EVP_PKEY_CTX_free(ctx);
        return -1;
    }
    std::cout << "Generate ECDSA key pair successfully" << std::endl;
    EVP_PKEY_CTX_free(ctx);

    // save private key to file
    FILE* private_key_file_ptr = fopen(this->EC_private_key_file.c_str(), "w");
    if (!private_key_file_ptr)
    {
        std::cerr << "Failed to open private key file" << std::endl;
        EVP_PKEY_free(pkey);
        return -1;
    }
    PEM_write_PrivateKey(private_key_file_ptr, pkey, NULL, NULL, 0, NULL, NULL);
    fclose(private_key_file_ptr);

    // save private key details to file
    BIO* private_key_details_file_ptr = BIO_new_file("./ec/ec_private_key_details.txt", "w");
    if (!private_key_details_file_ptr)
    {
        std::cerr << "Failed to open private key details file" << std::endl;
        EVP_PKEY_free(pkey);
        return -1;
    }
    EVP_PKEY_print_private(private_key_details_file_ptr, pkey, 0, NULL);
    BIO_free(private_key_details_file_ptr);

    // save public key to file
    FILE* public_key_file_ptr = fopen(this->EC_public_key_file.c_str(), "w");
    if (!public_key_file_ptr)
    {
        std::cerr << "Failed to open private key file" << std::endl;
        EVP_PKEY_free(pkey);
        return -1;
    }
    PEM_write_PUBKEY(public_key_file_ptr, pkey);
    fclose(public_key_file_ptr);

    // save public key details to file
    BIO* public_key_details_file_ptr = BIO_new_file("./ec/ec_public_key_details.txt", "w");
    if (!public_key_details_file_ptr)
    {
        std::cerr << "Failed to open public key details file" << std::endl;
        EVP_PKEY_free(pkey);
        return -1;
    }
    EVP_PKEY_print_public(public_key_details_file_ptr, pkey, 0, NULL);
    BIO_free(public_key_details_file_ptr);
    
    EVP_PKEY_free(pkey);
    return 0;
}



int EcdsaDemo::sign()
{   

     // read private key
    FILE* private_key_file_ptr = fopen(this->EC_private_key_file.c_str(), "r");

    if(!private_key_file_ptr){
        std::cerr << "Failed to open private key file" << std::endl;
        fclose(private_key_file_ptr);
        return -1;
    }
    
    EVP_PKEY* private_key = PEM_read_PrivateKey(private_key_file_ptr, NULL, NULL, NULL);
    fclose(private_key_file_ptr);
    if(!private_key)
    {
        std::cerr << "Failed to read private key" << std::endl;
        EVP_PKEY_free(private_key);
        return -1;
    }

    std::string message = std::string(200,'a');
    unsigned char signature[4096] = {0};
    unsigned int signature_length;
    
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if(!ctx)
    {
        std::cerr << "Failed to create EVP_MD_CTX" << std::endl;
        return -1;
    }

    if(!EVP_SignInit(ctx, EVP_sha256())){
        std::cerr << "Failed to initialize signing context" << std::endl;
        EVP_MD_CTX_free(ctx);
        return -1;
    }

    if(!EVP_SignUpdate(ctx, message.c_str(), message.length())){
        std::cerr << "Failed to update signing context" << std::endl;
        EVP_MD_CTX_free(ctx);
        return -1;
    }

    if (!EVP_SignFinal(ctx, signature, &signature_length, private_key))
    {
        std::cerr << "Failed to final signing context" << std::endl;
        EVP_MD_CTX_free(ctx);
        return -1;
    }
    EVP_MD_CTX_free(ctx);
    

    // save signature to file
    std::ofstream output_file("./ec/ec_signed.bin", std::ios::out | std::ios::binary);
    output_file.write(reinterpret_cast<const char*>(signature), signature_length);
    output_file.close();
    std::cout << "ECDSA sign successfully" << std::endl;

    return 0;
}

int EcdsaDemo::verify()
{
    // read public key from file
    FILE* public_key_file_ptr = fopen(this->EC_public_key_file.c_str(), "r");
    if(!public_key_file_ptr){
        std::cerr << "Failed to open public key file" << std::endl;
        fclose(public_key_file_ptr);
        return -1;
    }
    
    EVP_PKEY* public_key = PEM_read_PUBKEY(public_key_file_ptr, NULL, NULL, NULL);
    fclose(public_key_file_ptr);
    if(!public_key)
    {
        std::cerr << "Failed to read public key" << std::endl;
        EVP_PKEY_free(public_key);
        return -1;
    }

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if(!ctx)
    {
        std::cerr << "Failed to create EVP_MD_CTX" << std::endl;
        return -1;
    }

    if (!EVP_VerifyInit(ctx, EVP_sha256()))
    {
        std::cerr << "Failed to initialize verification context" << std::endl;
        EVP_MD_CTX_free(ctx);
        return -1;
    }
    
    std::string message = std::string(200,'a');
    if (!EVP_VerifyUpdate(ctx, message.c_str(), message.length())){
        std::cerr << "Failed to update verification context" << std::endl;
        EVP_MD_CTX_free(ctx);
        return -1;
    }

    std::ifstream input_file("./ec/ec_signed.bin", std::ios::in | std::ios::binary);
    std::string input_string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    
    if(EVP_VerifyFinal(ctx, reinterpret_cast<const unsigned char*>(input_string.c_str()), input_string.length(), public_key)){
        std::cout << "verified successfully." << std::endl;
        EVP_MD_CTX_free(ctx);
        return 0;
    }else{
        std::cerr << "Failed to final verification context" << std::endl;
        EVP_MD_CTX_free(ctx);
        return -1;
    }

    /*
        firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/seccpp/ec$ stat -c "%s bytes" ./ec_signed.bin 
        72 bytes
    */
}