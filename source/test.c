#include <stdio.h>
#include "hash.h"

int main(){
	unsigned char* buf;
	int len = 3;
	unsigned char digest[20];
	int result = sha3_256(buf, len, digest);
	printf("result: %d", result);
	sleep(50000);
	return 0;
}