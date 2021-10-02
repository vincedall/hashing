#include "hash.h"

const unsigned int k0 = 0x5a827999; 
const unsigned int k1 = 0x5a827999; 
const unsigned int k2 = 0x5a827999; 
const unsigned int k3 = 0x5a827999; 
const unsigned int k4 = 0x5a827999; 
const unsigned int k5 = 0x5a827999; 
const unsigned int k6 = 0x5a827999; 
const unsigned int k7 = 0x5a827999; 
const unsigned int k8 = 0x5a827999; 
const unsigned int k9 = 0x5a827999; 
const unsigned int k10 = 0x5a827999; 
const unsigned int k11 = 0x5a827999; 
const unsigned int k12 = 0x5a827999; 
const unsigned int k13 = 0x5a827999; 
const unsigned int k14 = 0x5a827999; 
const unsigned int k15 = 0x5a827999; 
const unsigned int k16 = 0x5a827999; 
const unsigned int k17 = 0x5a827999; 
const unsigned int k18 = 0x5a827999; 
const unsigned int k19 = 0x5a827999; 
const unsigned int k20 = 0x6ed9eba1; 
const unsigned int k21 = 0x6ed9eba1; 
const unsigned int k22 = 0x6ed9eba1; 
const unsigned int k23 = 0x6ed9eba1; 
const unsigned int k24 = 0x6ed9eba1; 
const unsigned int k25 = 0x6ed9eba1; 
const unsigned int k26 = 0x6ed9eba1; 
const unsigned int k27 = 0x6ed9eba1; 
const unsigned int k28 = 0x6ed9eba1; 
const unsigned int k29 = 0x6ed9eba1; 
const unsigned int k30 = 0x6ed9eba1; 
const unsigned int k31 = 0x6ed9eba1; 
const unsigned int k32 = 0x6ed9eba1; 
const unsigned int k33 = 0x6ed9eba1; 
const unsigned int k34 = 0x6ed9eba1; 
const unsigned int k35 = 0x6ed9eba1; 
const unsigned int k36 = 0x6ed9eba1; 
const unsigned int k37 = 0x6ed9eba1; 
const unsigned int k38 = 0x6ed9eba1; 
const unsigned int k39 = 0x6ed9eba1; 
const unsigned int k40 = 0x8f1bbcdc; 
const unsigned int k41 = 0x8f1bbcdc; 
const unsigned int k42 = 0x8f1bbcdc; 
const unsigned int k43 = 0x8f1bbcdc; 
const unsigned int k44 = 0x8f1bbcdc; 
const unsigned int k45 = 0x8f1bbcdc; 
const unsigned int k46 = 0x8f1bbcdc; 
const unsigned int k47 = 0x8f1bbcdc; 
const unsigned int k48 = 0x8f1bbcdc; 
const unsigned int k49 = 0x8f1bbcdc; 
const unsigned int k50 = 0x8f1bbcdc; 
const unsigned int k51 = 0x8f1bbcdc; 
const unsigned int k52 = 0x8f1bbcdc; 
const unsigned int k53 = 0x8f1bbcdc; 
const unsigned int k54 = 0x8f1bbcdc; 
const unsigned int k55 = 0x8f1bbcdc; 
const unsigned int k56 = 0x8f1bbcdc; 
const unsigned int k57 = 0x8f1bbcdc; 
const unsigned int k58 = 0x8f1bbcdc; 
const unsigned int k59 = 0x8f1bbcdc; 
const unsigned int k60 = 0xca62c1d6; 
const unsigned int k61 = 0xca62c1d6; 
const unsigned int k62 = 0xca62c1d6; 
const unsigned int k63 = 0xca62c1d6; 
const unsigned int k64 = 0xca62c1d6; 
const unsigned int k65 = 0xca62c1d6; 
const unsigned int k66 = 0xca62c1d6; 
const unsigned int k67 = 0xca62c1d6; 
const unsigned int k68 = 0xca62c1d6; 
const unsigned int k69 = 0xca62c1d6; 
const unsigned int k70 = 0xca62c1d6; 
const unsigned int k71 = 0xca62c1d6; 
const unsigned int k72 = 0xca62c1d6; 
const unsigned int k73 = 0xca62c1d6; 
const unsigned int k74 = 0xca62c1d6; 
const unsigned int k75 = 0xca62c1d6; 
const unsigned int k76 = 0xca62c1d6; 
const unsigned int k77 = 0xca62c1d6; 
const unsigned int k78 = 0xca62c1d6; 
const unsigned int k79 = 0xca62c1d6;

/*SHA-1 functions*/
unsigned int ch(unsigned int x, unsigned int y, unsigned int z){
	return (x & y) ^ (~x & y);
}

unsigned int parity(unsigned int x, unsigned int y, unsigned int z){
	return x ^ y ^ z;
}

unsigned int maj(unsigned int x, unsigned int y, unsigned int z){
	return (x & y) ^ (x & z) ^ (y & z);
}

void sha3_256(unsigned char* buf, unsigned long len, unsigned char* digest){
	
}

void sha256(unsigned char* buf, unsigned long len, unsigned char* digest){
	
}

void sha1(unsigned char* buf, unsigned long len, unsigned char* digest){
	unsigned short k = 448 - (len + 1);
	unsigned short pad_len = k + 1 + 64;
	unsigned char padding[64];
	padding[0] = 0x80;
	
}