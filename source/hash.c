#include "hash.h"

const unsigned int k[80] = {
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x5a827999, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x6ed9eba1, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0x8f1bbcdc, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6, 
	0xca62c1d6
}

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

unsigned int leftrotate(unsigned int x, unsigned int offset){
    return ( x << offset ) | ( x >> (32 - offset));
}

void sha3_256(unsigned char* buf, unsigned long len, unsigned char* digest){
	
}

void sha256(unsigned char* buf, unsigned long len, unsigned char* digest){
	
}

void sha1(unsigned char* buf, unsigned long len, unsigned char* digest){
	/*
	unsigned short k = 448 - (len + 1);
	unsigned short pad_len = k + 1 + 64;
	unsigned char padding[64];
	padding[0] = 0x80;
	*/
	unsigned int h0 = 0x67452301;
	unsigned int h1 = 0xefcdab89;
	unsigned int h2 = 0x98badcfe;
	unsigned int h3 = 0x10325476;
	unsigned int h4 = 0xc3d2e1f0;
	
	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int c = 0;
	unsigned int d = 0;
	unsigned int e = 0;
	
	unsigned int n = len / 512;
	
	unsigned int w[80];
	
	unsigned long mod = 4294967296; //2^32
	
	for (unsigned int i = 0; i < n; i++){
		for (unsigned int t = 0; t < 80; t++){
			if (t < 16){
				w[t] = 
			}
		}
	}
}




