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

const unsigned long mod = 4294967296;

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

void sha1begin(H* h){
	h[0] = 0x67452301;
	h[1] = 0xefcdab89;
	h[2] = 0x98badcfe;
	h[3] = 0x10325476;
	h[4] = 0xc3d2e1f0;
}

void sha1update(unsigned char* buf, unsigned long len, H* h){
	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int c = 0;
	unsigned int d = 0;
	unsigned int e = 0;
	
	unsigned int n = len / 16;
	
	unsigned int w[80];
	
	unsigned int T = 0;
	
	for (unsigned int i = 0; i < n; i++){
		for (unsigned int t = 0; t < 80; t++){
			if (t < 16){
				unsigned int integer = (buf[t] << 24) | (buf[t + 1] << 16) | (buf[t + 2] << 8) | buf[t + 3];
				w[t] = integer;
			}else{
				w[t] = leftrotate(w[t - 3] ^ w[t - 8] ^ w[t - 14] ^ w[t-16], 1);
			}
		}
		
		a = h[0];
		b = h[1];
		c = h[2];
		d = h[3];
		e = h[4];
		
		for (unsigned int t = 0; t < 80; t++{
			if (t < 20){
				T = leftrotate(a, 5) + ch(b, c, d) + e + k[t] + w[t];
			}else if (t > 19 && t < 40){
				T = leftrotate(a, 5) + parity(b, c, d) + e + k[t] + w[t];
			}else if (t > 39 && t < 60){
				T = leftrotate(a, 5) + maj(b, c, d) + e + k[t] + w[t];
			}else{
				T = leftrotate(a, 5) + parity(b, c, d) + e + k[t] + w[t];
			}
			
			e = d;
			
			d = c;
			
			c = leftrotate(b, 30);
			
			b = a;
			
			a  = T;
			
			h[0] = a + h[0];
			h[1] = b + h[1];
			h[2] = c + h[2];
			h[3] = d + h[3];
			h[4] = e + h[4];
		}
	}
}

sha1finish(unsigned char* buf, unsigned long len, H* h){
	/*
	unsigned short k = 448 - (len + 1);
	unsigned short pad_len = k + 1 + 64;
	unsigned char padding[64];
	padding[0] = 0x80;
	*/
}




