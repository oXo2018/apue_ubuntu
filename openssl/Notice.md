The `ldd program_name`command can help you view which dynamic link libraries a program needs, as well as the paths to these dynamic link libraries.

The `/usr/lib` directory is where most system-level shared library files are stroed in linux systems. These shared library files are typically dynamically linked by executable files at runtime to provide additional functionality. In this directory, you will find many files ending with `.so`, which are the shared library files. Shared library files contain functions and data that are shared for use by multiple programs.

`ldconfig` is a command in linux used to update the cache of dynamic linkers. In linux, dynamic link librares are stored in specifc directories, such as `lib` and `/usr/lib`. The `ldconfig` command scans these directories and creates a cache file containing information about these dynamic link libraries. This allows the systems to quickly locate the required dynamic link libraries when running programs, without needing to search the entire disk each time.

***

The `/etc/ld.so.conf.d` directory is used in linux systems to store configuration files for the dynamic linker. In this directory, each file corresponds to a configuration for the dynamic linker, and the file names typically end with `.conf`.

These configuration files are used to tell the dynamic linker which directories to search for dynamic linker libraries when a program is running. Each configuration file can specify one or more directories, and the dynamic linker will search these directories in the order specified in the file to find the dynamic link libraries.

Using the `/etc/ld.so.conf.d` directory makes it easy to manage the configuration of the dynamic linker. You can modify the search paths for dynamic link libraries by adding, removing, or editing configuration files, <font color="red"> without directly mofigying the `/etc/ld.so.conf` file. </font>

***
When you compile and install `Openssl 1.0` on the Linux platform, it will place the relevant files in `/usr/local/bin` and `/usr/local/lib`

Reference:
https://github.com/CyberHashira/Learn_OpenSSL


***

In OpenSSL, `pbkdf2` stands for Password-Based Key Derivation Funcion 2, which is a cryptographic function used to derive a key from a password and a salt. __Its purpose is to increase the strength of passwords, making them more resistant to brute-force attacks.__

In OpenSSL, you can use the `EVP_PKEY_derive_pbkdf2()` function to preform `pbkdf2` derivation. You need to specify the length of the derived key, the iteration count, the pseudo-random function, as well as the input password and salt.

***
In RSA encryption, PKCS#1 is the name of a set of public-key cryptography standards originally published by RSA Laboratories. PKCS#1 defines the standard methods for RSA encryption and signing, including formats for public keys, private keys, encryption, and signatures.

PKCS#1 defines the following functionalities:
1. RSA public key encryption: Specifies how to encrypt data using an RSA public key.
2. RSA private key decryption: Specifies how to decrypt encrypted data using an RSA private key.
3. RSA digital signatures: Specifies how to sign data using an RSA private key so that others can verify the signature's validity using the public key.
4. RSA digital signature verification: Specifies how to verify the validity of a signature using an RSA public key.

The PKCS#1 standard has undergone several version updates. The initial version was PKCS#1 v1.5, followed by PKCS#1 v2.0 and PKCS#1 v2.1. These versions differ in encryption, signing and other aspects, depending on the requirements of the application and security considerations.
