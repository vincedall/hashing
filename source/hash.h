#ifndef HASH_H
#define HASH_H

#ifndef STATIC
	#define EXTERN
	#ifdef _WIN32
		#ifdef HASH_EXPORTS
			#define ADDAPI __declspec(dllexport)
		#else
			#define ADDAPI __declspec(dllimport)
		#endif
		#define ADDCALL __cdecl
	#else
		#define ADDAPI
		#define ADDCALL
	#endif
#else
	#define ADDAPI
	#define ADDCALL
	#define EXTERN extern
#endif

#define SHA3_256_DIGEST_SIZE 256
#define SHA256_DIGEST_SIZE 256
#define SHA1_DIGEST_SIZE 20

struct H {
	unsigned int h0;
	unsigned int h1;
	unsigned int h2;
	unsigned int h3;
	unsigned int h4;
	unsigned long long mlen;
};

#ifdef __cplusplus
extern "C"
{
#endif

	EXTERN ADDAPI void ADDCALL sha1begin(struct H* h);
	EXTERN ADDAPI void ADDCALL sha1update(unsigned char* buf, unsigned long long len, struct H* h);
	EXTERN ADDAPI void ADDCALL sha1finish(unsigned char* buf, unsigned long long len, struct H* h, unsigned char* digest);

#ifdef __cplusplus
}
#endif

#endif