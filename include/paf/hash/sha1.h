/*
	ScePaf-RE Project
*/

#ifndef _PAF_HASH_SHA1_H
#define _PAF_HASH_SHA1_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SHA1Context {
    uint32_t Intermediate_Hash[5];
    uint32_t Length_Low;
    uint32_t Length_High;
    int16_t Message_Block_Index;
    uint8_t Message_Block[64];
	int32_t Computed;
	int32_t Corrupted;
} SHA1Context;

enum
{
	shaSuccess = 0,
	shaNull,            /* Null pointer parameter */
	shaInputTooLong,    /* input data too long */
	shaStateError       /* called Input after Result */
};

#define SHA1HashSize 20

int32_t SHA1Input(SHA1Context *context, const uint8_t *message_array, size_t length);
void SHA1PadMessage(SHA1Context *context);
void SHA1ProcessMessageBlock(SHA1Context *context);
int32_t SHA1Reset(SHA1Context *context);
int32_t SHA1Result(SHA1Context *context, uint8_t message_digest[SHA1HashSize]);


#ifdef __cplusplus
}
#endif

#endif /* _PAF_HASH_SHA1_H */
