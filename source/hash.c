#include "hash.h"

inline unsigned int leftrotate(unsigned int x, unsigned int offset) {
	return (x << offset) | (x >> (32 - offset));
}

void sha1begin(struct H* h) {
	h->h0 = 0x67452301;
	h->h1 = 0xefcdab89;
	h->h2 = 0x98badcfe;
	h->h3 = 0x10325476;
	h->h4 = 0xc3d2e1f0;
	h->mlen = 0;
}

void sha1update(unsigned char* buf, unsigned long long len, struct H* h) {
	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int c = 0;
	unsigned int d = 0;
	unsigned int e = 0;
	unsigned int n = len / 64;
	unsigned int w[80];
	unsigned int T = 0;
	h->mlen += len * 8;

	for (unsigned int i = 0; i < n; ++i) {
		unsigned long start = i * 64;

		unsigned char* cdest = (unsigned char*)&w[0];
		unsigned char* csrc = (unsigned char*)&buf[start];
		for (unsigned int i = 0; i < 64; i += 4) {
			cdest[i] = csrc[i + 3];
			cdest[i + 1] = csrc[i + 2];
			cdest[i + 2] = csrc[i + 1];
			cdest[i + 3] = csrc[i];
		}

		for (unsigned int t = 16; t < 80; t++) {
			w[t] = leftrotate(w[t - 3] ^ w[t - 8] ^ w[t - 14] ^ w[t - 16], 1);
		}

		a = h->h0;
		b = h->h1;
		c = h->h2;
		d = h->h3;
		e = h->h4;

		for (unsigned int t = 0; t < 80; t++) {
			if (t < 20) {
				T = leftrotate(a, 5) + ((b & c) ^ (~b & d)) + e + 0x5a827999 + w[t];
			}
			else if (t > 19 && t < 40) {
				T = leftrotate(a, 5) + (b ^ c ^ d) + e + 0x6ed9eba1 + w[t];
			}
			else if (t > 39 && t < 60) {
				T = leftrotate(a, 5) + ((b & c) ^ (b & d) ^ (c & d)) + e + 0x8f1bbcdc + w[t];
			}
			else {
				T = leftrotate(a, 5) + (b ^ c ^ d) + e + 0xca62c1d6 + w[t];
			}
			e = d;
			d = c;
			c = leftrotate(b, 30);
			b = a;
			a = T;
		}
		h->h0 = a + h->h0;
		h->h1 = b + h->h1;
		h->h2 = c + h->h2;
		h->h3 = d + h->h3;
		h->h4 = e + h->h4;
	}
}

void sha1finish(unsigned char* buf, unsigned long long len, struct H* h, unsigned char* digest) {
	unsigned char padding[64];
	unsigned int pad = 0;
	h->mlen += len * 8;
	unsigned long long lenmod64 = len % 64;
	if (lenmod64 > 55 || lenmod64 == 0) {
		for (unsigned int i = 0; i < 64; ++i) {
			padding[i] = 0;
		}
		pad = 1;
		padding[56] = h->mlen >> 56;
		padding[57] = h->mlen >> 48;
		padding[58] = h->mlen >> 40;
		padding[59] = h->mlen >> 32;
		padding[60] = h->mlen >> 24;
		padding[61] = h->mlen >> 16;
		padding[62] = h->mlen >> 8;
		padding[63] = h->mlen;
	}
	else {
		buf[len + (64 - lenmod64 - 8)] = h->mlen >> 56;
		buf[len + (64 - lenmod64 - 7)] = h->mlen >> 48;
		buf[len + (64 - lenmod64 - 6)] = h->mlen >> 40;
		buf[len + (64 - lenmod64 - 5)] = h->mlen >> 32;
		buf[len + (64 - lenmod64 - 4)] = h->mlen >> 24;
		buf[len + (64 - lenmod64 - 3)] = h->mlen >> 16;
		buf[len + (64 - lenmod64 - 2)] = h->mlen >> 8;
		buf[len + (64 - lenmod64 - 1)] = h->mlen;
	}

	if (lenmod64 == 0) {
		padding[0] = 0x80;
	}
	else {
		buf[len] = 0x80;
	}

	if (lenmod64 == 0) {
		sha1update(buf, len, h);
	}
	else {
		sha1update(buf, len + (64 - (lenmod64)), h);
	}

	if (pad == 1) {
		sha1update(padding, 64, h);
	}

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
