#include <stdio.h>
#include <string.h>
#include "hash.h"

//23232323232323232323232323232323232323232323232323232323232323232323232323232323232323232323232323232323232323
//hash = 57ec415bbdb5a7402f129972619cd1277ac236ce

int main(){
	unsigned char buf[64] = {
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x23,
		0x23, 0x23, 0x23, 0x80,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0xb8
	};
	struct H h;
	unsigned char digest[20];
	sha1begin(&h);
	sha1update(buf, 64, &h);
	sha1finish(NULL, 0, &h, digest);
	
	for (int i = 0; i < 20; i++){
		printf("%x", digest[i]);
	}
	
	sleep(50000);
	return 0;
}