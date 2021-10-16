/**
	
	\file hash.h
    \brief Header of hashing library.
	\author Vincent Dallaire
	\version 1.0
*/

#ifndef HASH_H
#define HASH_H

#ifndef STATIC
	#define EXTERN
	#ifdef _WIN32
		#ifdef BUILD
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

/**
	\def SHA3_256_DIGEST_SIZE
    \brief Macro defining the length of the sha3-256 digest in bytes.
*/
#define SHA3_256_DIGEST_SIZE 256

/**
	\def SHA256_DIGEST_SIZE
    \brief Macro defining the length of the sha256 digest in bytes.
*/
#define SHA256_DIGEST_SIZE 256

/**
	\def SHA1_DIGEST_SIZE
    \brief Macro defining the length of the sha1 digest in bytes.
*/
#define SHA1_DIGEST_SIZE 20


/**
	\struct H
    \brief Structure that will be updated when calling begin, update and finish.
	
	It contains the hash values and the len of the message that will be initialized in begin
	and that will be updated when calling update and finish.
*/
struct H{
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

/**
	\fn void sha1begin(struct H* h)
    \brief Function to initialize the initial hash values and the message length to zero for the SHA-1 algorithm.
	\param h Structure allocated by the user to contain the intermediate hash values and the length of the message.
	\pre User must allocate an H struct properly.
*/
EXTERN ADDAPI void ADDCALL sha1begin(struct H* h);

/**
	\fn void sha1update(unsigned char* buf, unsigned long long len, struct H* h)
    \brief Function to update the intermediate hash values with some data for the SHA-1 algorithm.
	\param buf Buffer containing the data to hash and to update the intermediate hash values.
	\param len 64 bits integer that represents the length of buf in bytes
	\param h Structure allocated by the user to contain the intermediate hash values and the length of the message.
	\pre The len field must be a multiple of 64 bytes and must be the same as the length of the buffer. 
*/
EXTERN ADDAPI void ADDCALL sha1update(unsigned char* buf, unsigned long long len, struct H* h);

/**
	\fn void sha1finish(unsigned char* buf, unsigned long long len, struct H* h, unsigned char* digest)
    \brief Function to finish computing the hash for the SHA-1 algorithm.
		
		The function will pad the last block of data because it is required for the hashing algorithms.
		The function calls sha1update() underneath after padding the last block. You can thus call
		this function with the whole data instead of calling sha1update(). The update function is provided
		if the data to be hashed is too big to be held into RAM all at once.
		
	\param buf Buffer containing the data to hash and to update the intermediate hash values.
	\param len 64 bits integer that represents the length of the data in buf in bytes
	
		The len field can be different than the actual size of buf for this function. See preconditions for details.
		
	\param h Structure allocated by the user to contain the intermediate hash values and the length of the message.
	\param digest Byte array to hold the final hash of the data. This byte array should be 20 bytes long for the SHA-1 algorithm.
	\pre The len field must represent the size of the data remaining to hash.
	\pre The size of the buffer must be a multiple of 64 bytes unlike the len field which can possibly not be a mutliple of 64 bytes.
	
		This is to allow padding the last block without requiring to allocate data dynamically or without having a complex algorithm to
		pad the data within a statically allocated block.
		
	\post As output, the function updates the digest byte array to hold the final hash of the data.
*/
EXTERN ADDAPI void ADDCALL sha1finish(unsigned char* buf, unsigned long long len, struct H* h, unsigned char* digest);

#ifdef __cplusplus
}
#endif

#endif