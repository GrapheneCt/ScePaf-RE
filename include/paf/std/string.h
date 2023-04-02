/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_STD_STRING_H
#define _VDSUITE_USER_PAF_STD_STRING_H

#include <../../stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t sce_paf_strlen(const char *str);
int sce_paf_strcasecmp(const char *str1, const char *str2);
char *sce_paf_strchr(const char *str, int character);
int sce_paf_strcmp(const char *str1, const char *str2);
int sce_paf_strncasecmp(const char *str1, const char *str2, size_t num);
int sce_paf_strncmp(const char *str1, const char *str2, size_t num);
char *sce_paf_strncpy(char *destination, const char *source, size_t num);
char *sce_paf_strrchr(const char *str, int character);
char *sce_paf_strstr(const char *haystack, const char *needle);
char *sce_paf_strtok(char *str, const char *delim);
char *sce_paf_strtok_r(char *str, const char *delim, char **saveptr);
char * sce_paf_strcpy(char * destination, const char * source);
char * sce_paf_strcat(char * destination, const char * source);
char * sce_paf_strncat(char *dest, const char *src, size_t n);
size_t sce_paf_strcspn(const char *str1, const char *str2);
size_t sce_paf_strlcat(char *dst, const char *src, size_t size);
size_t sce_paf_strlcpy(char *dst, const char *src, size_t size);
char * sce_paf_strpbrk(const char *str1, const char *str2);
size_t sce_paf_strspn(const char * str1, const char * str2);

void *sce_paf_memset(void *ptr, int value, size_t num);
void *sce_paf_memset32(void *ptr, int value, size_t num);
void *sce_paf_memcpy(void *destination, const void *source, size_t num);
void *sce_paf_memmove(void *destination, const void *source, size_t num);
void *sce_paf_memchr(const void *ptr, int value, size_t num);
int sce_paf_memcmp(const void *ptr1, const void *ptr2, size_t num);
void *sce_paf_bzero(void *ptr, size_t num);
int sce_paf_bcmp(const void *ptr1, const void *ptr2, size_t num);
void *sce_paf_bcopy(void *destination, const void *source, size_t num);

#ifdef __cplusplus
}
#endif

#endif /* _VDSUITE_USER_PAF_STD_STRING_H */
