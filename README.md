Author: Vincent Dallaire, Québec, Canada

This piece of software provides static and dynamic libraries to use SHA-1, SHA-256 and SHA3-256 hashing in C and C++ code.

This piece of software follows the FIPS-180-4 and the FIPS-202 specifications from the NIST agency. These specifications can be downloaded from internet.

This piece of software requires an x86-64 processor which has the AES-NI extension to its instruction set.

This application is simple and does one thing only. It is freestanding and doesn't do any system calls. All it does, is simple calculations and it attempts to make these faster using the AES-NI extension of the x86-64 processors.

To use the library, you can either download the precompiled libraries from this repository or compile your own using the scripts provided. There are scripts for Linux (tested on Ubuntu), Mac and Windows 10.

To use the library from C or C++ source code, simply call the corresponding begin, update and finish methods of the hashing function you want to use. 

For example, to use SHA-1 hashing simply call ```void sha1begin(struct H* h)``` with an H struct pointer (the initial hash values) as argument. Then, call ```void sha1update(unsigned char* buf, unsigned long len, struct H* h)``` with blocks of data. The **len field must be a multiple of 64 bytes and be the same as the length of the buffer** for SHA-1 (please read the *very short* documentation for the block size multiple corresponding to each hashing functions). Lastly, call ```void sha1finish(unsigned char* buf, unsigned long len, struct H* h, unsigned char* digest)```. For sha1finish(), the len field can possibly not be a multiple of 64 bytes but the buf buffer **must have a length that is a multiple of 64 bytes**. The size of the buffer can possible not be the same as the len field.

Code example:
```
#define SHA1_DIGEST_SIZE 20
struct H h;
unsigned char digest[SHA1_DIGEST_SIZE];
sha1begin(&h); //call begin to set the initial hash values
sha1update(buf, 1024, &h); //call update as much times as needed with data
sha1update(buf, 1024, &h);
sha1update(buf, 1024, &h);
sha1finish(buf, 55, &h, digest); //call finish with the last block of data
```
Alternatively, you can call sha1finish with the whole data if it can fit into RAM at once. The sha1update method is called by sha1finish underneath. It is provided for padding the last block of data. The sha1update method is provided for the convenience of not having to bring all data into RAM before hashing. For example, if hashing a large file, the data cannot be brought into RAM at once completely. The corresponding update method for the required hashing algorithm must thus be called with chunks of data of any size (as long as their length is a multiple of 64 bytes). The requirement that the length be a multiple of 64 bytes is to simplify the library and to make it much faster. The library doesn't have to do any malloc() call or any system call because the task is left to the user of the library. This makes hashing calculations very fast and efficient.