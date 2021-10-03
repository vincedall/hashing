#include <stdio.h>
#include "hash.h"

int main(){
	unsigned char* buf;
	int len = 3;
	unsigned char digest[20];
	sha1(buf, len, digest);
	sleep(50000);
	return 0;
}