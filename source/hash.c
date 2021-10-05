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
};

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
    return (x << offset) | (x >> (32 - offset));
}

void sha3_256(unsigned char* buf, unsigned long len, unsigned char* digest){
	
}

void sha256(unsigned char* buf, unsigned long len, unsigned char* digest){
	
}

void sha1begin(struct H* h){
	h->h0 = 0x67452301;
	h->h1 = 0xefcdab89;
	h->h2 = 0x98badcfe;
	h->h3 = 0x10325476;
	h->h4 = 0xc3d2e1f0;
}

void sha1update(unsigned char* buf, unsigned long len, struct H* h){
	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int c = 0;
	unsigned int d = 0;
	unsigned int e = 0;
	unsigned int n = len / 64;
	unsigned int w[80];
	unsigned int T = 0;
	
	for (unsigned int i = 0; i < n; i++){
		for (unsigned int t = 0; t < 80; t++){
			if (t < 16){
				unsigned int index = t * 4;
				unsigned int integer = (buf[index] << 24) | (buf[index + 1] << 16) | (buf[index + 2] << 8) | buf[index + 3];
				w[t] = integer;
			}else{
				w[t] = leftrotate(w[t - 3] ^ w[t - 8] ^ w[t - 14] ^ w[t-16], 1);
			}
		}
		a = h->h0;
		b = h->h1;
		c = h->h2;
		d = h->h3;
		e = h->h4;
		for (unsigned int t = 0; t < 80; t++){
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
			h->h0 = a + h->h0 ;
			h->h1  = b + h->h1 ;
			h->h2  = c + h->h2 ;
			h->h3  = d + h->h3;
			h->h4  = e + h->h4 ;
		}
	}
}

void sha1finish(unsigned char* buf, unsigned long len, struct H* h, unsigned char* digest){
	/*unsigned short k = 448 - (len + 1);
	unsigned short pad_len = k + 1 + 64;
	unsigned char padding[64];
	padding[0] = 0x80;*/
	
	digest[0] = h->h0 >> 24;
	digest[1] = h->h0 >> 16;
	digest[2] = h->h0 >> 8;
	digest[3] = h->h0;
	
	digest[4] = h->h1 >> 24;
	digest[5] = h->h1 >> 16;
	digest[6] = h->h1 >> 8;
	digest[7] = h->h1;
	
	digest[8] = h->h2 >> 24;
	digest[9] = h->h2 >> 16;
	digest[10] = h->h2 >> 8;
	digest[11] = h->h2;
	
	digest[12] = h->h3 >> 24;
	digest[13] = h->h3 >> 16;
	digest[14] = h->h3 >> 8;
	digest[15] = h->h3;
	
	digest[16] = h->h4 >> 24;
	digest[17] = h->h4 >> 16;
	digest[18] = h->h4 >> 8;
	digest[19] = h->h4;
}




