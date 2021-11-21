Author: Vincent Dallaire, Québec, Canada

This piece of software provides static and dynamic libraries to use SHA-1, SHA-256 and SHA3-256 hashing in C and C++ code.

This piece of software follows the FIPS-180-4 and the FIPS-202 specifications from the NIST agency. These specifications can be downloaded from internet.

This piece of software requires an x86-64 processor which has the AES-NI extension to its instruction set.

This application is simple and does one thing only. It is freestanding and doesn't do any system calls. All it does, is simple calculations and it attempts to make these faster using the AES-NI extension of the x86-64 processors.

To use the library, you can either download the precompiled libraries from this repository or compile your own. To compile the library on Windows you will need to install Visual Studio and use the MSVC compiler. To compile on Linux and MacOS simply use the scripts provided.

To use the **static library** from C or C++ code, you must define the STATIC macro before including the hash.h header.
Example:
```
#define STATIC
#include "hash.h"
```

To use the library from C or C++ source code, simply call the corresponding begin, update and finish methods of the hashing function you want to use.