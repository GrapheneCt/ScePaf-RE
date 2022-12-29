/*
	Vita Development Suite Libraries git-9c2c72f1
*/

#ifndef _VDSUITE_USER_PAF_STDC_H
#define _VDSUITE_USER_PAF_STDC_H

#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>
#include <scetypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EOF			(-1)
#define WEOF		((unsigned int)(-1))

/**
 * std C functions
 */

int sce_paf_abs(int x);
int sce_paf_atoi(const char * str);
void *sce_paf_bzero(void *ptr, SceSize num);
void *sce_paf_memchr(const void *ptr, int value, SceSize num);
int sce_paf_memcmp(const void *ptr1, const void *ptr2, SceSize num);
int sce_paf_bcmp(const void *ptr1, const void *ptr2, SceSize num);
void *sce_paf_memcpy(void *destination, const void *source, SceSize num);
void *sce_paf_memmove(void *destination, const void *source, SceSize num);
void *sce_paf_bcopy(void *destination, const void *source, SceSize num);
void *sce_paf_memset(void *ptr, int value, SceSize num);
int sce_paf_snprintf(char *s, SceSize n, const char *format, ...);
int sce_paf_strcasecmp(const char *str1, const char *str2);
char *sce_paf_strchr(const char *str, int character);
int sce_paf_strcmp(const char *str1, const char *str2);
size_t sce_paf_strlen(const char *str);
int sce_paf_strncasecmp(const char *str1, const char *str2, SceSize num);
int sce_paf_strncmp(const char *str1, const char *str2, SceSize num);
char *sce_paf_strncpy(char *destination, const char *source, SceSize num);
char *sce_paf_strrchr(const char *str, int character);
char *sce_paf_strstr(const char *haystack, const char *needle);
void sce_paf_qsort(void *ptr, SceSize count, SceSize size, int(*comp)(const void *, const void *));

unsigned long int sce_paf_strtoul(const char* str, char** endptr, int base);

char *sce_paf_strtok(char *str, const char *delim);

int sce_paf_rand(void);
void sce_paf_srand(unsigned int seed);

/**
 * wchar functions
 */

/* __attribute__((__format__(__wprintf__, 3, 4))) */
int sce_paf_swprintf(wchar_t *buffer, size_t bufsz, const wchar_t *format, ...);

int sce_paf_vswprintf(wchar_t *buffer, size_t bufsz, const wchar_t *format, va_list vlist);

wint_t sce_paf_towlower(wint_t wc);

wchar_t *sce_paf_wcscat(wchar_t *dest, const wchar_t *src);
wchar_t *sce_paf_wcsncat(wchar_t *dest, const wchar_t *src, size_t count);
wchar_t *sce_paf_wcscpy(wchar_t *dest, const wchar_t *src);
wchar_t *sce_paf_wcsncpy(wchar_t *dest, const wchar_t *src, size_t count);

int sce_paf_wcscasecmp(const wchar_t *s1, const wchar_t *s2);
wchar_t *sce_paf_wcschr(const wchar_t *str, wchar_t ch);
int sce_paf_wcscmp(const wchar_t *lhs, const wchar_t *rhs);
size_t sce_paf_wcscspn(const wchar_t *dest, const wchar_t *src);
size_t sce_paf_wcslen(const wchar_t *str);
int sce_paf_wcsncasecmp(const wchar_t *s1, const wchar_t *s2, size_t n);
int sce_paf_wcsncmp(const wchar_t *lhs, const wchar_t *rhs, size_t count);
size_t sce_paf_wcsnlen(const wchar_t *s, size_t maxlen);
wchar_t *sce_paf_wcspbrk(const wchar_t *dest, const wchar_t *str);
wchar_t *sce_paf_wcsrchr(const wchar_t *str, wchar_t ch);
size_t sce_paf_wcsspn(const wchar_t *dest, const wchar_t *src);
wchar_t* sce_paf_wcsstr(const wchar_t* dest, const wchar_t* src);

wchar_t *sce_paf_wmemchr(const wchar_t *ptr, wchar_t ch, size_t count);
int sce_paf_wmemcmp(const wchar_t *lhs, const wchar_t *rhs, size_t count);
wchar_t *sce_paf_wmemcpy(wchar_t *dest, const wchar_t *src, size_t count);
wchar_t *sce_paf_wmemmove(wchar_t *dest, const wchar_t *src, size_t count);
wchar_t *sce_paf_wmemset(wchar_t* ptr, wchar_t wc, size_t count);

void *sce_paf_memalign(size_t align, size_t length);
void sce_paf_free(void *ptr);
void *sce_paf_malloc(size_t size);
void* sce_paf_calloc(size_t num, size_t size);

float sce_paf_ceilf(float arg);
float sce_paf_floorf(float arg);

int sce_paf_feof(FILE *stream);
int sce_paf_ferror(FILE * stream);
FILE * sce_paf_fopen(const char * filename, const char * mode);
int sce_paf_fclose(FILE * stream);
size_t sce_paf_fread(void * ptr, size_t size, size_t count, FILE * stream);
size_t sce_paf_fwrite(const void * ptr, size_t size, size_t count, FILE * stream);
int sce_paf_fseek(FILE * stream, long int offset, int origin);
void *sce_paf_realloc(void *ptr, size_t new_size);
long int sce_paf_ftell(FILE * stream);
int sce_paf_fgetc(FILE * stream);
char * sce_paf_strcpy(char * destination, const char * source);
char * sce_paf_strcat(char * destination, const char * source);
char * sce_paf_strncat(char *dest, const char *src, size_t n);
float sce_paf_roundf(float x);
float sce_paf_cosf(float x);
float sce_paf_logf(float x);
float sce_paf_expf(float x);
float sce_paf_sinf(float x);
float sce_paf_acosf(float x);
float sce_paf_atanf(float x);
float sce_paf_tanf(float x);
float sce_paf_powf(float base, float exponent);

long sce_paf_strtol(const char *str, char **str_end, int base);

double sce_paf_testf(double x, double y);

#ifdef __cplusplus
}
#endif

#endif /* _VDSUITE_USER_PAF_STDC_H */

