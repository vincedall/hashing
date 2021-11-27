#include <stdio.h>
#include "hash.h"
#include <fstream>
#include <string>

#pragma comment(lib, "hash.lib")

int main() {
	/*
		SHA-1 tests
	*/
	H h;
	unsigned char digest[20];
	unsigned char buf[10000] = { 0 };

	//buffer of 1 zero
	//5ba93c9db0cff93f52b521d7420e43f6eda2784f
	sha1begin(&h);
	sha1finish(buf, 1, &h, digest);
	for (unsigned int i = 0; i < 20; ++i) {
		printf("%02x", digest[i]);
	}
	printf("\n");

	//buffer of 55 zero bytes
	//8e8832c642a6a38c74c17fc92ccedc266c108e6c
	memset(buf, 0, 10000);
	sha1begin(&h);
	sha1finish(buf, 55, &h, digest);
	for (unsigned int i = 0; i < 20; ++i) {
		printf("%02x", digest[i]);
	}
	printf("\n");

	//buffer of 56 zero bytes
	//9438e360f578e12c0e0e8ed28e2c125c1cefee16
	memset(buf, 0, 10000);
	sha1begin(&h);
	sha1finish(buf, 56, &h, digest);
	for (unsigned int i = 0; i < 20; ++i) {
		printf("%02x", digest[i]);
	}
	printf("\n");

	//buffer of 64 zero bytes
	//c8d7d0ef0eedfa82d2ea1aa592845b9a6d4b02b7
	memset(buf, 0, 10000);
	sha1begin(&h);
	sha1finish(buf, 64, &h, digest);
	for (unsigned int i = 0; i < 20; ++i) {
		printf("%02x", digest[i]);
	}
	printf("\n");

	//buffer of 65 zero bytes
	//f0fa45906bd0f4c3668fcd0d8f68d4b298b30e5b
	memset(buf, 0, 10000);
	sha1begin(&h);
	sha1finish(buf, 65, &h, digest);
	for (unsigned int i = 0; i < 20; ++i) {
		printf("%02x", digest[i]);
	}
	printf("\n");

	//buffer of 5000 zero bytes using sha1finish
	//044ef48af264fd3e304ab9e64f9656f37af763a6
	memset(buf, 0, 10000);
	sha1begin(&h);
	sha1finish(buf, 5000, &h, digest);
	for (unsigned int i = 0; i < 20; ++i) {
		printf("%02x", digest[i]);
	}
	printf("\n");

	//buffer of 5000 zero bytes using sha1update
	//044ef48af264fd3e304ab9e64f9656f37af763a6
	memset(buf, 0, 10000);
	sha1begin(&h);
	sha1update(buf, 4992, &h);
	sha1finish(&buf[4992], 8, &h, digest);
	for (unsigned int i = 0; i < 20; ++i) {
		printf("%02x", digest[i]);
	}
	printf("\n");

	//Test with a small random file
	sha1begin(&h);
	std::ifstream in("c:\\users\\user\\desktop\\test1.txt", std::ios::binary);
	char buffer[10000] = { 0 };
	in.read(buffer, 10000);
	sha1finish((unsigned char*)buffer, in.gcount(), &h, digest);
	in.close();
	for (unsigned int i = 0; i < 20; ++i) {
		printf("%02x", digest[i]);
	}
	printf("\n");

	//Test with a big random file using sha1update
	sha1begin(&h);
	std::ifstream in2("c:\\users\\user\\desktop\\test2.txt", std::ios::binary);
	#define BUFFER_SIZE 128000
	char buffer1[BUFFER_SIZE];
	memset(buffer1, 0, 128000);
	in2.seekg(0, in2.end);
	int length = in2.tellg();
	in2.seekg(0, in2.beg);
	unsigned int iterations = length / BUFFER_SIZE;
	for (unsigned int i = 0; i < iterations; ++i) {
		in2.read(buffer1, BUFFER_SIZE);
		sha1update((unsigned char*)buffer1, BUFFER_SIZE, &h);
	}
	in2.read(buffer1, BUFFER_SIZE);
	sha1finish((unsigned char*)buffer1, in2.gcount(), &h, digest);
	in2.close();
	for (unsigned int i = 0; i < 20; ++i) {
		printf("%02x", digest[i]);
	}
	printf("\n");



	return 0;
}