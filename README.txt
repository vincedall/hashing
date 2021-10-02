Author: Vincent Dallaire, Québec, Canada

This piece of software provides static and dynamic libraries to use SHA3-256
hashing in C and C++ code. This is different and stronger than SHA2-256 commonly
called sha256.

This piece of software follows the FIPS-202 specification from the NIST agency. This
specification can be downloaded from internet.

This piece of software requires an x86-64 processor which has the AES-NI
extension to its instruction set.

This application is simple and does one thing only. It is freestanding and doesn't do
any system calls. All it does, is simple calculations and it attempts to make these faster using
the AES-NI extension of the x86-64 processors.