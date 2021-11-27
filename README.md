Author: Vincent Dallaire, Québec, Canada

This piece of software provides static and dynamic libraries to use SHA-1, SHA-256 and SHA3-256 hashing in C and C++ code.

This piece of software follows the FIPS-180-4 and the FIPS-202 specifications from the NIST agency. These specifications can be downloaded from internet.

This application is simple and does one thing only. It is freestanding and doesn't do any system calls. All it does, is simple calculations and it attempts to make these faster using the SHA extension of the x86-64 processors.

To use the library, you can either download the precompiled libraries from this repository or compile your own. To compile the library on Windows you will need to install Visual Studio and use the MSVC compiler. To compile on Linux and MacOS simply use the scripts provided. To use the dll on Windows, you need to **link your program with the import library** (hash.lib) and **place the dll into your executable's directory**.

To use the **static library** from C or C++ code, you must **define the STATIC macro before including the hash.h header**. For example:
```
#define STATIC
#include "hash.h"
```
To use the library from C or C++ source code, simply call the corresponding begin, update and finish functions of the hashing algorithm you want to use.

For the SHA-1 algorithm, you have the following functions:
```
void sha1begin(struct H* h);
void sha1update(unsigned char* buf, unsigned long long len, struct H* h);
void sha1finish(unsigned char* buf, unsigned long long len, struct H* h, unsigned char* digest);
```
The sha1begin function takes an H struct comprising the hash values and the length in bits of the message. The sha1update function takes a buffer which is either a portion of the message or the full message. The len field is the length of the buffer in bytes. It must be a **multiple of 64 bytes** for SHA-1. This requirement is to make sure that the library doesn't have to do system calls to allocate memory. The sha1finish function is used to do the final padding of the message and returns the digest in the digest argument. The digest argument must have a **length of 20 bytes** for SHA-1. The len field of the sha1finish() function **doesn't** have to be a multiple of 64 bytes but the actual **length of the buffer must be a multiple of 64 bytes**. Again, this is to prevent the library from having to do memory related system calls for padding the message.

More to come when the other algorithms are implemented...