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

***

### 1.1.1 Architecture(As-Is)
1. APPLICATION
    - command line utility.
    - This components such as CA, ciphers, dgst, cms, genrsa, ecparam, genpkey, req etc.
    - use the openssl libraries to perform above tasks.
2. LIBSSL
    - used for TLS and DTLS, dependent on LIBCRYPTO
    - LIBSSL uses LIBCRYPTO to preform various SSL TLS related cryptographic tasks
3. LIBCRYPTO
    - Contains implementations for all supported cryptographic algorithms and operations.(Core library)
    - It also contaions implementations for protocols such as CMS or OCSP
4. ENGINE
    - Privides enhancements to LIBCRYPTO
    - Engine are used as an extension to LIBCRYPTO(They may contaion algorithms and features that are not natively supported by openssl)

### 3.0 Architecture(To-Be)
1. Applications
    - CA, ciphers, dgst, cms, genrsa, ecparam, genpkey, req etc.
    - no changes with 1.1.1
2. Common Services(API)
    - BIO, EVP, ASN.1, X.509, PEM
    - interfaces which helps in building an application.
    - BIO can be used to basic input ouput operations instead of writing your own logic.
    - EVP provides high level functions for various cryptographic operations.
3. Protocol
    - TLS, DTLS, CMS, OCSP, TS, CMP
    - Also support certificate management protocol.
4. Legacy API
    - Old deprecated functions not part of EVP.
    - Just for provide backwards compatibility.
5. Core
    - Passes a cryptographic request to a Provider.
6. Providers
    - Provider is separate unit. Application load provider depend on which they need.
    - Provides implementations for various cryptographic operations and algorithms.
    - Will be replacing the Engine interface(1.1.1).
    - Can also be used by a third-party to provide their own implementation.
    - OpenSSL 3.0 has five of its own providers.
  
#### Providers
1. Default
    - Default provider of OpenSSL loaded as default.(Default provider gets loaded when no other provider is specified by an application)
    - Exists inside libcrypto library.
    - Has access to all algotithms provided by OpenSSL.
2. Legacy
    - Has a collection of old algotithms which are considered no longer use or insecure.
    - Provides backwards compatibility.
    - Examples are MD4, Blowfish, DES.
3. FIPS
    - Has a collection of FIPS validated algorithms.
    - Used for FIPS 140-2 compliance.
    - FIPS provider used a separate module.
4. Base
    - Has implementation for all non-cryptographic algorithms.
    - Contains algorithms to serialize and deserialize keys.
    - Should be loaded if the Default provider is not loaded.
5. Null
    - Has no implementation for any kind of algorithms.
    - Built into libcrypto library.
    - Ensures default provider is not used in anyway.

---
Installed openssl3 by apt have only one modules legacy.so

```shell
firmon@ubt:/usr/lib/x86_64-linux-gnu/ossl-modules$ ls
legacy.so

firmon@ubt:/usr/lib/x86_64-linux-gnu/ossl-modules$ openssl list -providers
Providers:
  default
    name: OpenSSL Default Provider
    version: 3.0.2
    status: active

// Download the openssl source code and execute below command to generate the makefile
firmon@ubt:~/openssl-3.0.13$ ./config --prefix=/opt/openssl --openssldir=/opt/openssl enable-fips

// then build the source code
firmon@ubt:~/openssl-3.0.13$ make -j

// install everything include all binaries, the header files, the help docs, the SSL directories and else.
firmon@ubt:~/openssl-3.0.13$ sudo make install

// install only necessary files.(just going to install the software components such as the binaries, the header files engines and the modules which directory will not include FIPS)
firmon@ubt:~/openssl-3.0.13$ sudo make install_sw

// install only openssl app.
firmon@ubt:~/openssl-3.0.13$ sudo make install_runtime

// install fips module
firmon@ubt:~/openssl-3.0.13$ sudo make install_fips

firmon@ubt:~/openssl-3.0.13$ sudo make install_sw && sudo make install_fips && sudo make install_ssldirs

firmon@ubt:~/openssl-3.0.13$ tree /opt/openssl/
/opt/openssl/
├── bin
│   ├── c_rehash
│   └── openssl
├── certs
├── ct_log_list.cnf
├── ct_log_list.cnf.dist
├── fipsmodule.cnf
├── include
│   └── openssl
│       ├── aes.h
│       ├── asn1err.h
│       ├── asn1.h
│       ├── asn1_mac.h
│       ├── asn1t.h
│       ├── asyncerr.h
│       ├── async.h
│       ├── bioerr.h
│       ├── bio.h
│       ├── blowfish.h
│       ├── bnerr.h
│       ├── bn.h
│       ├── buffererr.h
│       ├── buffer.h
│       ├── camellia.h
│       ├── cast.h
│       ├── cmac.h
│       ├── cmperr.h
│       ├── cmp.h
│       ├── cmp_util.h
│       ├── cmserr.h
│       ├── cms.h
│       ├── comperr.h
│       ├── comp.h
│       ├── conf_api.h
│       ├── conferr.h
│       ├── conf.h
│       ├── configuration.h
│       ├── conftypes.h
│       ├── core_dispatch.h
│       ├── core.h
│       ├── core_names.h
│       ├── core_object.h
│       ├── crmferr.h
│       ├── crmf.h
│       ├── cryptoerr.h
│       ├── cryptoerr_legacy.h
│       ├── crypto.h
│       ├── cterr.h
│       ├── ct.h
│       ├── decodererr.h
│       ├── decoder.h
│       ├── des.h
│       ├── dherr.h
│       ├── dh.h
│       ├── dsaerr.h
│       ├── dsa.h
│       ├── dtls1.h
│       ├── ebcdic.h
│       ├── ecdh.h
│       ├── ecdsa.h
│       ├── ecerr.h
│       ├── ec.h
│       ├── encodererr.h
│       ├── encoder.h
│       ├── engineerr.h
│       ├── engine.h
│       ├── e_os2.h
│       ├── err.h
│       ├── esserr.h
│       ├── ess.h
│       ├── evperr.h
│       ├── evp.h
│       ├── fipskey.h
│       ├── fips_names.h
│       ├── hmac.h
│       ├── httperr.h
│       ├── http.h
│       ├── idea.h
│       ├── kdferr.h
│       ├── kdf.h
│       ├── lhash.h
│       ├── macros.h
│       ├── md2.h
│       ├── md4.h
│       ├── md5.h
│       ├── mdc2.h
│       ├── modes.h
│       ├── objectserr.h
│       ├── objects.h
│       ├── obj_mac.h
│       ├── ocsperr.h
│       ├── ocsp.h
│       ├── opensslconf.h
│       ├── opensslv.h
│       ├── ossl_typ.h
│       ├── param_build.h
│       ├── params.h
│       ├── pem2.h
│       ├── pemerr.h
│       ├── pem.h
│       ├── pkcs12err.h
│       ├── pkcs12.h
│       ├── pkcs7err.h
│       ├── pkcs7.h
│       ├── proverr.h
│       ├── provider.h
│       ├── prov_ssl.h
│       ├── randerr.h
│       ├── rand.h
│       ├── rc2.h
│       ├── rc4.h
│       ├── rc5.h
│       ├── ripemd.h
│       ├── rsaerr.h
│       ├── rsa.h
│       ├── safestack.h
│       ├── seed.h
│       ├── self_test.h
│       ├── sha.h
│       ├── srp.h
│       ├── srtp.h
│       ├── ssl2.h
│       ├── ssl3.h
│       ├── sslerr.h
│       ├── sslerr_legacy.h
│       ├── ssl.h
│       ├── stack.h
│       ├── storeerr.h
│       ├── store.h
│       ├── symhacks.h
│       ├── tls1.h
│       ├── trace.h
│       ├── tserr.h
│       ├── ts.h
│       ├── txt_db.h
│       ├── types.h
│       ├── uierr.h
│       ├── ui.h
│       ├── whrlpool.h
│       ├── x509err.h
│       ├── x509.h
│       ├── x509v3err.h
│       ├── x509v3.h
│       └── x509_vfy.h
├── lib64
│   ├── engines-3
│   │   ├── afalg.so
│   │   ├── capi.so
│   │   ├── loader_attic.so
│   │   └── padlock.so
│   ├── libcrypto.a
│   ├── libcrypto.so -> libcrypto.so.3
│   ├── libcrypto.so.3
│   ├── libssl.a
│   ├── libssl.so -> libssl.so.3
│   ├── libssl.so.3
│   ├── ossl-modules
│   │   ├── fips.so
│   │   └── legacy.so
│   └── pkgconfig
│       ├── libcrypto.pc
│       ├── libssl.pc
│       └── openssl.pc
├── misc
│   ├── CA.pl
│   ├── tsget -> tsget.pl
│   └── tsget.pl
├── openssl.cnf
├── openssl.cnf.dist
└── private

10 directories, 160 files


// uninstall the installed file
firmon@ubt:/opt/openssl$ sudo make uninstall_sw && sudo make uninstall_fips && sudo make uninstall_ssldirs


firmon@ubt:/opt/openssl/certs$ /opt/openssl/bin/openssl version -a
/opt/openssl/bin/openssl: /lib/x86_64-linux-gnu/libcrypto.so.3: version 'OPENSSL_3.0.9' not found (required by /opt/openssl/bin/openssl)

// fix the error 
firmon@ubt:/opt/openssl/certs$ export LD_LIBRARY_PATH=/opt/openssl/lib64/

firmon@ubt:/opt/openssl/certs$ vim ~/.profile
// add blow commands.
export PATH=/opt/openssl/bin:$PATH
export LD_LIBRARY_PATH=/opt/openssl/lib64
firmon@ubt:/opt/openssl/certs$ source ~/.profile

```

