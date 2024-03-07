firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ openssl version
OpenSSL 3.0.2 15 Mar 2022 (Library: OpenSSL 3.0.2 15 Mar 2022)

using AES256 to encrypt alice RSA private key.(-verbose mains output more detail.)
firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ openssl genrsa -verbose -aes256 -out alice_private.pem 2048 
Generating RSA key with 2048 bits
.....+.....+.........+.+..............+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*..+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*.+......+...+.....+......+....+..+.........+......+.............+.....+...+..........+........+.......+...............+...+.....+.+.....+.+.....+.......+..+.+........+....+.....+.......+.....+...+.............+........+....+.....+......+.+......+..+......+.+.....+.........+....+......+..+...+..........+..+....+.....................+..+...+.............+...........+....+.....+............+.........+....+..+.......+.....+...+.........+....+..+...+....+.....+......+...............+.+.....+.+...........................+...+..............+....+......+...+..+...+.......+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
...+...+......+.....+......+....+.....+.+............+..+.+...+.........+..+...+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*.+........+......+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*......+..+.+.....+....+...+.....+...+.......+...+........+.+.....+.........+.+.........+..+.......+..+.+.....+...............+.......+..+...+...+....+..........................+.......+..+.+..+.+..........................+.+........+....+..+....+.........+..+......+.........+...+.+.........+........+....+.....+....+..............+...+...+.+...+........+.............+.....+......+.+...+......+...+............+...+......+.....+.......+..+.+......+.....+.+..+...+............+.....................+....+.....+............+....+.....+.+...+...........+....+...+..+.+...........+...+...+.........+......+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
e is 65537 (0x010001)
Enter PEM pass phrase:
Verifying - Enter PEM pass phrase:


firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ ls -l alice_private.pem 
-rw------- 1 firmon firmon 1874  3月  7 22:28 alice_private.pem

!!!  the length of private key is 1708!
firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ cat alice_private.pem 
-----BEGIN ENCRYPTED PRIVATE KEY-----
MIIFLTBXBgkqhkiG9w0BBQ0wSjApBgkqhkiG9w0BBQwwHAQIuFCLa2+2di0CAggA
MAwGCCqGSIb3DQIJBQAwHQYJYIZIAWUDBAEqBBCgPniABmSpZhXbPXyUbr3NBIIE
0BoKY54NYISTxm5oOXl5x4z0kysHO+b1F+4gsf4juX3vGuJ86ApwkNKbFObOd1yj
rEZ1qIk83bNUv8dKvJJIU/ALrZY0nI0Z25mfI5vSk0ASSeHET6OZdiTNrxlYFkZf
ng1WzodPIe9CtKORyelpsjZ6s8msca7/Fx2pRH0l2VXJ831dH+j20FplkILz1XCX
To3nsg+Afgms32Fv48cdx4aaGBPVq5Mwu/v9ALAtSWBSRjUsVBzJq5WoUj+l7cvk
zUhlO0Zz0pa1DQBQwL99zsVOGECs4KLS4fHq46WNePj6skw6hwdif2Q02MOJXx8L
zfdq2zX/lLutfYOn1v7X1oRhtrLpfwP44VuVUBEi0gZGLfRwQR0Vi2mIXlVJksEd
P9DaZRoPZHL53THJDpx8DLXLSiVBS93a2OnzoHSdGz7c0IQH9f+k6RFPusCvHvrJ
aFFehyanMJoxtoSXAjS2pzIX03TIf2pluXA/0fM5Xv4u28/c9iHhtHS4gvdHqwmJ
FYMlzhkPQ6cxzSeZd95XnBLWYtJGGAI2G8on4sUJPX0cmNprNMRibZLft2gQFuu9
fdk2k7x6YxjRuY11Fzc1DGlNjYpqtdhhZmzraMSSOORzsH81zuboZYYcyr6bDI4s
S7UQK+hqRibCh1TnzH86PDeOtsL3p9YgUdw2qDVDek8LZVDdQn1EQr0krQRme3UP
5swg1azMeIvuH9e1p9KsqnYUD+AG72PBuYSX49HMIzwdLH57X9wWNwTYj42Sa89P
IdFXRuknBccNRH5GJrsvd7JbHdyJEHE2xaXeeQ4j2C08zqzTnB6N0Iqn69TPs5i+
EEZez8w8fXCENhG/ZdLJrGrKJfs1mvMpbaqa3InBDiEzi/F70ZJg42x3B2azfFsE
AnbadY/IDitCTI24EhhnxJdcf7RMa7DbSFJdS7hWUNwQ7BUUv61/noRkWSOSGofQ
hBm8YcGzpR9R8UPhMRsioHttrxE2TCa8M25bG1PHXULiCzK4XRNIiNlAFzVH/7Js
aypsgGo9CXsto5q2PjpyqCh2XNSb6VP9e2EiRpitO/ukkMMO62h38V6MVQexnVth
i9mX2uVhkgIJa2zEvMTTpH4ew3LTE76tM2X2ZPBdeU0UibiDYm8f3W5Ozu+IFyor
DamN8wwKrov2FnNVQwmjk2EdWQcmiNxUnqz5cVk6AuFJ0s806ucf8wK5DmbUbNhY
Hs4Lt+mWFt4qEBwckD2A0ZcZtEGbsc5XL/iT1ceIHchi2nmnYgZUZxgdGmzj2JSk
oIsg4TT0Gn9fytNZFAsSJCgYz83iofbxlL4Q5+sda5gjScRwy2LZfbEbMq5eLqXa
jYtcw+B3iwTdkhEHWrqvBbnKo0ORVE01Dp1lEkoqzuvyEwiYHmePeRPMmRjcInSZ
hHBL27PAKDYnC/DrxQ46peWLYMkXfnn4z9c40ocsCZRRwllls7PpG4KESWo0stef
rPkU1boYX3CwqRwsduhhtWhJXQdBdbGFsOH1Stu1IrklNVqiYxzgARGJ1GScof44
8h/Vuht5U5kfsWCrVcC7xFZdq0Pc+BzUPIzUgXwiJm6rKFR+vtWayBsEVoKNVTgY
LuowRciEK4a988qlDLWcQWkF6kfVCFcBsjFdrIZ2q5cb
-----END ENCRYPTED PRIVATE KEY-----

firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ file alice_private.pem 
alice_private.pem: ASCII text

    modulus: 模数 n
    publicExponent: 公指数 e，固定为 65537 (0x10001)
    privateExponent: 私钥指数 d
    prime1: 质数 p，用于计算 n
    prime2: 质数 q，用于计算 n
    exponent1: 用于加速 RSA 运算的中国剩余定理指数一
    exponent2: 用于加速 RSA 运算的中国剩余定理指数二
    coefficient: 用于加速 RSA 运算的中国剩余定理系数
--- amount nunmber of prime1 and prime2 are 258*2 = 516     516*4 = 2064  more then 2048 (16) 
-- using this command to get RSA private key details.
firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ openssl rsa -in alice_private.pem  -noout -text
Enter pass phrase for alice_private.pem:
Private-Key: (2048 bit, 2 primes)
modulus:
    00:a2:1c:2d:75:81:f6:82:e5:b5:a1:84:f4:f8:94:
    3e:19:00:89:e3:c3:92:74:a5:70:7f:f1:98:70:99:
    19:02:1e:8c:7a:3f:e3:b3:92:40:05:7a:f7:1a:28:
    4a:b1:c0:34:83:83:15:7d:d8:ae:c3:71:b0:96:7a:
    29:3e:af:7b:f5:ae:05:91:1d:8f:0a:25:01:33:13:
    99:ba:52:fa:b5:0c:59:78:74:88:0f:7b:e1:8a:e2:
    76:80:cb:da:ad:2e:4a:02:98:10:4c:36:d4:78:e3:
    35:c0:86:fb:e0:c5:a3:f9:28:60:a1:35:81:c1:d2:
    68:c5:20:42:bd:17:63:95:58:71:d0:d4:77:9a:ce:
    6a:09:92:20:83:56:ff:19:ff:9f:ff:d9:1c:a5:74:
    bc:2b:e2:9f:50:45:79:1a:76:0e:3f:0e:61:05:2a:
    cc:89:c2:90:7f:63:d2:3e:95:14:6b:6d:29:8c:00:
    82:6c:a5:bd:7a:6d:67:57:c7:0f:02:35:a0:e5:1d:
    c2:ef:57:26:24:b3:a1:a7:4e:67:9c:1e:57:63:8e:
    da:ec:c6:95:89:53:3b:99:6e:6c:c6:ad:3b:56:16:
    df:8a:68:81:57:2c:95:df:cf:d5:cf:9c:73:4e:77:
    62:22:96:ad:27:13:a0:7a:ce:33:13:c8:32:55:bd:
    a5:cd
publicExponent: 65537 (0x10001)
privateExponent:
    11:12:41:91:45:d1:e5:5f:f6:5c:1f:89:c2:a1:ad:
    d6:69:31:9c:2c:2c:c0:9e:e9:75:77:c6:33:59:54:
    02:5e:a0:31:81:87:e3:91:ab:af:48:0f:3c:90:70:
    a9:3e:51:e9:65:84:fe:5f:32:ac:3f:4d:36:d3:7f:
    83:6b:ec:74:67:52:8b:c1:1e:9e:95:5e:06:78:72:
    70:66:2b:a3:a4:3c:c9:cc:0f:c5:fd:a8:37:3d:78:
    f8:40:3f:73:8c:53:db:e9:12:92:4c:15:dc:f3:24:
    66:75:70:91:ef:8e:40:7f:49:89:c0:7e:3d:20:80:
    ca:fd:86:39:ae:7c:5c:ae:2c:23:25:40:0d:f0:09:
    f1:ad:90:d3:0d:3a:c7:b1:5f:0e:45:a9:1a:cd:9e:
    55:e1:dd:bf:c1:1d:d8:e8:7e:68:e9:74:40:ed:fa:
    43:c2:7f:2f:55:1a:77:f2:3c:e7:13:a9:61:77:0a:
    eb:e2:96:b3:ca:fe:60:8e:8b:7b:a5:ef:18:ef:d9:
    c8:26:b9:53:f5:e1:ca:15:87:89:95:8c:9a:eb:90:
    60:9b:03:12:ff:27:45:01:d6:c1:fc:5e:e4:d5:c2:
    bf:9d:ae:df:af:0e:35:01:54:0b:11:82:5f:73:81:
    a8:f6:08:59:99:e9:e3:97:13:41:af:fa:a5:4d:ee:
    8b
prime1: amount is 258 
    00:bb:3d:26:a6:6b:9f:ae:42:3a:9c:ca:18:02:32:
    69:be:cb:89:a8:a7:e8:f5:cd:5d:93:2d:6b:65:b9:
    dc:81:aa:d0:2c:cc:ed:98:21:9a:93:93:8f:77:65:
    1f:fe:f8:49:5b:a3:25:8f:f1:45:37:47:0f:60:a4:
    9a:19:62:67:b7:8c:06:d7:f3:25:f8:89:1f:4e:4b:
    60:0b:aa:0e:9a:f0:73:66:56:1b:9e:00:9c:bc:1f:
    3e:0c:a7:0f:eb:97:0c:e1:3e:a4:9b:1e:43:02:23:
    0a:c4:fa:cc:dd:21:67:f4:c4:71:6a:3a:4d:76:b7:
    60:47:09:15:5e:52:c7:a4:47
prime2: amount is 258 
    00:dd:a4:99:04:d4:72:dc:22:76:1d:d2:e0:25:78:
    18:7e:ad:d1:fd:41:7e:28:0d:fb:84:d0:a3:ac:aa:
    32:ef:e1:ae:33:89:ab:45:aa:3f:35:e2:6a:67:ae:
    91:da:f5:da:c4:df:66:37:f1:25:ee:95:f9:08:7a:
    7f:f4:56:5c:cd:ff:15:97:cd:9a:43:b5:63:7b:a0:
    0f:4f:e7:8f:92:4b:4c:bd:d2:b9:e3:ee:0b:27:5b:
    23:45:8d:76:38:33:ee:df:fe:c7:cb:63:e3:41:b8:
    be:6c:9a:aa:41:1a:92:dd:0e:a0:f4:d1:df:20:99:
    e7:98:12:38:42:5f:56:d3:4b
exponent1:
    00:a9:c7:9f:5e:54:44:ac:dc:7d:0d:62:eb:36:42:
    c4:44:2f:87:99:98:f7:d2:ba:ef:58:df:5c:7d:17:
    75:6d:56:98:01:a7:a8:e1:c3:c6:c8:7e:8b:1e:b6:
    61:b6:ef:28:85:a1:80:13:ef:b0:d5:98:e7:c6:b8:
    3a:cb:3d:c1:d2:5b:74:71:28:97:8b:af:ba:e5:61:
    cf:ab:83:fe:4e:5c:2e:27:e3:78:93:62:f6:bc:56:
    90:0b:25:09:78:94:b5:27:21:88:5c:e7:a9:d7:2c:
    33:3d:be:35:39:66:6b:3f:35:49:aa:0b:47:e6:98:
    0d:03:1c:a7:75:aa:16:41:4d
exponent2:
    07:75:0b:44:f3:54:ed:fd:26:d6:38:0b:1c:97:9e:
    d3:5c:4b:cd:66:8f:b5:0f:4b:60:1b:98:f6:2d:3f:
    cb:7c:5f:5d:12:8b:b5:ab:55:b7:1d:68:11:16:f9:
    87:51:70:4b:e1:6c:52:03:86:10:31:f1:90:0c:77:
    13:a4:78:38:e2:15:3a:e7:4b:02:6e:2e:eb:b0:e5:
    f2:fd:4a:82:54:90:3f:6e:c0:9c:5f:9c:f6:75:05:
    89:c8:89:aa:b8:6c:98:12:bd:6c:25:6f:36:fd:dd:
    42:50:2d:dc:44:e5:9e:14:68:eb:f3:c7:bb:14:12:
    8b:b6:49:38:4a:76:e4:63
coefficient:
    04:2c:c7:71:db:e6:90:83:e0:11:01:2e:4f:8f:06:
    ac:9e:09:17:8c:87:fd:9a:fb:37:1f:9f:01:2d:dc:
    17:59:26:f2:55:6f:af:25:e1:34:28:fe:36:5e:29:
    d2:fc:f0:4d:b7:c7:9f:3a:75:31:3b:23:8a:0f:a2:
    66:f6:86:ae:ce:20:a1:5f:e6:d2:b8:e3:2b:41:e3:
    cf:06:73:44:ed:f0:7e:86:86:33:30:22:e1:bc:29:
    56:ca:83:76:38:66:ab:86:cb:29:2b:9d:1d:b6:f6:
    f7:7f:b6:4e:c4:a9:d6:43:08:a0:26:8b:9f:88:7e:
    7b:87:3d:b3:a9:7d:3e:e1

--- export RSA public key
firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ openssl rsa -in alice_private.pem -pubout > alice_public.pem
Enter pass phrase for alice_private.pem:
writing RSA key

firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ cat alice_public.pem 
-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAohwtdYH2guW1oYT0+JQ+
GQCJ48OSdKVwf/GYcJkZAh6Mej/js5JABXr3GihKscA0g4MVfdiuw3GwlnopPq97
9a4FkR2PCiUBMxOZulL6tQxZeHSID3vhiuJ2gMvarS5KApgQTDbUeOM1wIb74MWj
+ShgoTWBwdJoxSBCvRdjlVhx0NR3ms5qCZIgg1b/Gf+f/9kcpXS8K+KfUEV5GnYO
Pw5hBSrMicKQf2PSPpUUa20pjACCbKW9em1nV8cPAjWg5R3C71cmJLOhp05nnB5X
Y47a7MaViVM7mW5sxq07VhbfimiBVyyV38/Vz5xzTndiIpatJxOges4zE8gyVb2l
zQIDAQAB
-----END PUBLIC KEY-----

-- to get RSA public details.
firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ openssl rsa -in alice_public.pem -pubin -text -noout
Public-Key: (2048 bit)
Modulus:
    00:a2:1c:2d:75:81:f6:82:e5:b5:a1:84:f4:f8:94:
    3e:19:00:89:e3:c3:92:74:a5:70:7f:f1:98:70:99:
    19:02:1e:8c:7a:3f:e3:b3:92:40:05:7a:f7:1a:28:
    4a:b1:c0:34:83:83:15:7d:d8:ae:c3:71:b0:96:7a:
    29:3e:af:7b:f5:ae:05:91:1d:8f:0a:25:01:33:13:
    99:ba:52:fa:b5:0c:59:78:74:88:0f:7b:e1:8a:e2:
    76:80:cb:da:ad:2e:4a:02:98:10:4c:36:d4:78:e3:
    35:c0:86:fb:e0:c5:a3:f9:28:60:a1:35:81:c1:d2:
    68:c5:20:42:bd:17:63:95:58:71:d0:d4:77:9a:ce:
    6a:09:92:20:83:56:ff:19:ff:9f:ff:d9:1c:a5:74:
    bc:2b:e2:9f:50:45:79:1a:76:0e:3f:0e:61:05:2a:
    cc:89:c2:90:7f:63:d2:3e:95:14:6b:6d:29:8c:00:
    82:6c:a5:bd:7a:6d:67:57:c7:0f:02:35:a0:e5:1d:
    c2:ef:57:26:24:b3:a1:a7:4e:67:9c:1e:57:63:8e:
    da:ec:c6:95:89:53:3b:99:6e:6c:c6:ad:3b:56:16:
    df:8a:68:81:57:2c:95:df:cf:d5:cf:9c:73:4e:77:
    62:22:96:ad:27:13:a0:7a:ce:33:13:c8:32:55:bd:
    a5:cd
Exponent: 65537 (0x10001)

-- using public key to encrypt message
firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ openssl pkeyutl -encrypt -inkey alice_public.pem -pubin -in message.txt -out message.enc 

-- the file content is garbled characters
firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ cat message.enc 
����/�q.�m��B�8��u@�Ss/jc�O��t)��.N���`��
                                         2��b�#"�g�'0n�r�%����ڹg�G'i[��ϗ�-G�<�p�C��U;�����/o����m.�x3BĮἻ%�P��=�������@������`�cO'������׼~!Vw�������if�I���+p�kd���Ǌy���(
                                                                                                                                                                        M�(�p׳Y�D�8(�[����=T��c��)MeɬЅ<�%#�K��wK�

-- using hexdump read message.enc file
firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ hexdump -C message.enc
00000000  1a d0 e5 18 9a 2f 92 71  2e 89 1c 6d 9a c6 42 be  |...../.q...m..B.|
00000010  38 97 e6 75 40 e7 53 14  73 2f 6a 63 98 1b d5 b0  |8..u@.S.s/jc....|
00000020  4f 8c 93 7f 74 29 87 ed  2e 4e aa e7 c0 60 bc 9b  |O...t)...N...`..|
00000030  0c 32 b9 c2 62 b7 23 22  eb b6 67 98 27 30 6e aa  |.2..b.#"..g.'0n.|
00000040  72 d9 25 e1 f7 cb d5 da  b9 67 e5 47 27 69 5b fa  |r.%......g.G'i[.|
00000050  a6 cf 97 ef 17 0e 2d 47  06 f0 3c f5 70 bc 7f 43  |......-G..<.p..C|
00000060  96 fe 55 3b b0 ef c8 c4  ef 87 2f 6f b0 c4 d1 f0  |..U;....../o....|
00000070  0e 6d 2e d0 78 33 42 c4  ae 11 e1 bc bb 25 ef ad  |.m..x3B......%..|
00000080  50 9c 89 3d fd b0 86 9e  85 cf 1a 19 40 aa 81 b1  |P..=........@...|
00000090  b0 e2 c9 60 f3 1f 63 4f  27 a7 82 06 00 ae f8 a7  |...`..cO'.......|
000000a0  e9 95 d7 bc 7e 21 56 77  88 a3 89 99 88 bc c2 69  |....~!Vw.......i|
000000b0  66 d2 49 15 f2 1a cb 2b  70 ce 6b 64 9e c1 9a c7  |f.I....+p.kd....|
000000c0  8a 79 a6 f9 1f 95 9b 08  01 28 0c 4d f3 28 c0 70  |.y.......(.M.(.p|
000000d0  d7 b3 59 f2 44 e2 38 03  28 d4 5b db dc 01 f3 dd  |..Y.D.8.(.[.....|
000000e0  3d 54 db 07 c0 19 63 aa  c5 7f 29 4d 0e 65 c9 ac  |=T....c...)M.e..|
000000f0  d0 85 3c b8 15 25 23 ec  4b eb e0 be 77 4b bd 16  |..<..%#.K...wK..|
00000100

-- using private key to decrypt message.
firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/alice$ openssl rsautl -decrypt -inkey alice_private.pem -in message.enc 
The command rsautl was deprecated in version 3.0. Use 'pkeyutl' instead.
Enter pass phrase for alice_private.pem:
this is a message file for RSA Encryption.
