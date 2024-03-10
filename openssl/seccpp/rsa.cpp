#include "rsa.h"
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <iostream>
#include <fstream>


int RsaDemo::generatekey()
{
    OpenSSL_add_all_algorithms();

    // create an EVP_KEY object
    EVP_PKEY* pkey = EVP_PKEY_new();
    if (pkey == nullptr)
    {
        std::cerr << "Error creating EVP_PKEY object. " << std::endl;
        return 1;
    }

    // generate RSA key pair
    // the second parameter is ENGINE *e  (set nullptr means default value)
    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, nullptr);
    if(EVP_PKEY_keygen_init(ctx) <= 0){
        std::cerr << "Error initializing key generation." << std::endl;
        return 1;
    }

    if(EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 2048) <= 0){
        std::cerr << "Error setting key length. " << std::endl;
        return 1;
    }

    if (EVP_PKEY_keygen(ctx, &pkey) <= 0){
        std::cerr << "Error genetaring key pair." << std::endl;
        return 1;
    }
    EVP_PKEY_CTX_free(ctx);
    

    // save public and private key to file
    this->RSA_private_key_file = "rsa/rsa_private_key.pem";
    this->RSA_public_key_file = "rsa/rsa_public_key.pem";
    
    std::cout << RSA_public_key_file << std::endl;

    FILE* public_key_file = fopen(RSA_public_key_file.c_str(), "w");
    if (!PEM_write_PUBKEY(public_key_file, pkey)){
        std::cerr << "Error writing public key." << std::endl;
        return 1;
    }
    fclose(public_key_file);
    

    /*
        1: file desriptor
        2: RSA key pair
        3: encrypt algorithm (nullptr means non-encrypt)
        4: password callback function (nullptr means don't use password)
        5: 
        6: encrypt parameter 
        7: callback function (print the error information)
    */
    FILE* private_key_file = fopen(RSA_private_key_file.c_str(), "w");
    if(!PEM_write_PrivateKey(private_key_file, pkey, nullptr, nullptr, 0, nullptr, nullptr)){
        std::cerr << "Error writing private key." << std::endl;
        return 1;
    }
    fclose(private_key_file);

    EVP_PKEY_free(pkey);

    return 0;

}

int RsaDemo::printPublicDetails()
{
    FILE* key_file = fopen(RSA_public_key_file.c_str(), "r");
    EVP_PKEY* evp_key = PEM_read_PUBKEY(key_file, nullptr, nullptr, nullptr);
    fclose(key_file);

    if (evp_key)
    {   
        RSA* rsa_public_key = EVP_PKEY_get1_RSA(evp_key);
        if (rsa_public_key)
        {
            // get n and e
            const BIGNUM* n;
            const BIGNUM* e;
            RSA_get0_key(rsa_public_key, &n, &e, nullptr);

            char* n_hex = BN_bn2hex(n);
            char* e_hex = BN_bn2hex(e);

            std::cout << "RSA Public Key Details: " << std::endl;
            std::cout << "N: " << n_hex << std::endl;
            std::cout << "E: " << e_hex << std::endl;

            //save public details information to file
            std::ofstream output_file("rsa/rsa_public_key_details.txt", std::ios::out);
            output_file << "RSA Public Key Details: " << std::endl;
            output_file << "N: modules" << std::endl << n_hex << std::endl;
            output_file << "E: " << std::endl << e_hex << std::endl;

            output_file.close();

            OPENSSL_free(n_hex);
            OPENSSL_free(e_hex);
            RSA_free(rsa_public_key);
            return 0;
        }
        EVP_PKEY_free(evp_key);
        return -1;
    }
    
    return -1;
}

int RsaDemo::printPrivateDetails()
{
    FILE* key_file = fopen(RSA_private_key_file.c_str(), "r");
    EVP_PKEY* evp_key =  PEM_read_PrivateKey(key_file, nullptr, nullptr, nullptr);
    fclose(key_file);

    if (evp_key)
    {   
        RSA* rsa_private_key = EVP_PKEY_get1_RSA(evp_key);
        if (rsa_private_key)
        {
            // get n and e
            const BIGNUM* n;
            const BIGNUM* e;
            const BIGNUM* d;
            RSA_get0_key(rsa_private_key, &n, &e, &d);
            const BIGNUM* p;
            const BIGNUM* q;
            const BIGNUM* dmp1; // d mod (p-1)
            const BIGNUM* dmq1; // d mod (q-1)
            const BIGNUM* iqmp; // q^-1 mod p
            RSA_get0_factors(rsa_private_key, &p, &q);
            RSA_get0_crt_params(rsa_private_key, &dmp1, &dmq1, &iqmp);


            char* n_hex = BN_bn2hex(n);
            char* e_hex = BN_bn2hex(e);
            char* d_hex = BN_bn2hex(d);
            char* p_hex = BN_bn2hex(p);
            char* q_hex = BN_bn2hex(q);
            char* dmp1_hex = BN_bn2hex(dmp1);
            char* dmq1_hex = BN_bn2hex(dmq1);
            char* iqmp_hex = BN_bn2hex(iqmp);

            std::cout << "RSA Private Key Details: " << std::endl;
            std::cout << "N: modules: " << n_hex << std::endl;
            std::cout << "E: " << e_hex << std::endl;
            std::cout << "D: private key: " << d_hex << std::endl;
            std::cout << "P: " << p_hex << std::endl;
            std::cout << "Q: " << q_hex << std::endl;
            std::cout << "D mod (P-1): " << dmp1_hex << std::endl;
            std::cout << "D mod (Q-1): " << dmq1_hex << std::endl;
            std::cout << "Q^-1 mod P: " << iqmp_hex << std::endl;


            //save public details information to file
            std::ofstream output_file("rsa/rsa_private_key_details.txt", std::ios::out);
            output_file << "RSA Public Key Details: " << std::endl;
            output_file << "N: modules" << std::endl << n_hex << std::endl;
            output_file << "E: " << std::endl << e_hex << std::endl;
            output_file << "D: private key: " << std::endl  << d_hex << std::endl;
            output_file << "P: " << std::endl  << p_hex << std::endl;
            output_file << "Q: " << std::endl  << q_hex << std::endl;
            output_file << "D mod (P-1): " << std::endl  << dmp1_hex << std::endl;
            output_file << "D mod (Q-1): " << std::endl  << dmq1_hex << std::endl;
            output_file << "Q^-1 mod P: " << std::endl  << iqmp_hex << std::endl;
            output_file.close();

            OPENSSL_free(n_hex);
            OPENSSL_free(e_hex);
            OPENSSL_free(d_hex);
            OPENSSL_free(p_hex);
            OPENSSL_free(q_hex);
            OPENSSL_free(dmp1_hex);
            OPENSSL_free(dmq1_hex);
            OPENSSL_free(iqmp_hex);
            RSA_free(rsa_private_key);
            return 0;
        }
        EVP_PKEY_free(evp_key);
        return -1;
    }
    
    return -1;
}

int RsaDemo::encrypt()
{
    FILE* key_file = fopen(RSA_public_key_file.c_str(), "r");
    EVP_PKEY* evp_key = PEM_read_PUBKEY(key_file, nullptr, nullptr, nullptr);
    fclose(key_file);

    if (evp_key)
    {
        RSA* rsa_public_key = EVP_PKEY_get1_RSA(evp_key);
        if (rsa_public_key)
        {
            std::string message = std::string(200,'a');
            unsigned char message_encrypted[4096] = {0};
            int encrypted_length = RSA_public_encrypt(message.length(), reinterpret_cast<const unsigned char*>(message.c_str()), message_encrypted, rsa_public_key, RSA_PKCS1_PADDING);
            if (encrypted_length != -1)
            {
                // encrypt success!
                // hexdump -C rsa_encrypted_message.bin 
                std::ofstream output_file("./rsa/rsa_encrypted_message.bin", std::ios::out | std::ios::binary);
                output_file.write(reinterpret_cast<const char*>(message_encrypted), encrypted_length);
                output_file.close();
                std::cout << "Data encrypted successfully." << std::endl;
                RSA_free(rsa_public_key);
                EVP_PKEY_free(evp_key);
                return 0;
            }else{
                std::cerr << "Encryption failed." << std::endl;
                RSA_free(rsa_public_key);
                EVP_PKEY_free(evp_key);
                return -1;
            }

        }
        
        return -1;
    }
    return -1;
}

int RsaDemo::decrypt()
{
    FILE* key_file = fopen(RSA_private_key_file.c_str(), "r");
    EVP_PKEY* evp_key = PEM_read_PrivateKey(key_file, nullptr, nullptr, nullptr);
    fclose(key_file);

    if(evp_key)
    {
        RSA* rsa_private_key = EVP_PKEY_get1_RSA(evp_key);
        if (rsa_private_key)
        {
            // load RSA privatre key successfully.
            std::ifstream input_file("./rsa/rsa_encrypted_message.bin", std::ios::in | std::ios::binary);
            std::string encrypted_data((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
            unsigned char decrypted_data[4096] = {0};
            int decrypted_length = RSA_private_decrypt(encrypted_data.length(), reinterpret_cast<const unsigned char*>(encrypted_data.c_str()), decrypted_data, rsa_private_key, RSA_PKCS1_PADDING);
            if(decrypted_length != -1){
                // decrypt successfully! and save to file.
                std::ofstream output_file("./rsa/rsa_decrypted_message.txt", std::ios::out);
                output_file.write(reinterpret_cast<const char*>(decrypted_data), decrypted_length);
                output_file.close();
                std::cout << "Data decrypted successfully." << std::endl;

                RSA_free(rsa_private_key);
                EVP_PKEY_free(evp_key);
                return 0;
            }else{
                std::cerr << "Decryption failed. " << std::endl;
                RSA_free(rsa_private_key);
                EVP_PKEY_free(evp_key);
                return -1;
            }

        }else{
            RSA_free(rsa_private_key);
            EVP_PKEY_free(evp_key);
            return -1;
        }
        
    }
    EVP_PKEY_free(evp_key);
    return -1;
}