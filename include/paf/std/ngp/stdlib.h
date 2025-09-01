#ifndef _PAF_STD_STDLIB_H
#define _PAF_STD_STDLIB_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void *sce_paf_memalign(size_t align, size_t length);
void sce_paf_free(void *ptr);
void *sce_paf_malloc(size_t size);
void* sce_paf_calloc(size_t num, size_t size);
void *sce_paf_realloc(void *ptr, size_t new_size);
size_t sce_paf_musable_size(void *ptr);

int sce_paf_abs(int x);
double sce_paf_atof(const char *nptr);
int sce_paf_atoi(const char * str);
long int sce_paf_atol(const char *str);
long long int sce_paf_atoll(const char *str);

int sce_paf_rand(void);
void sce_paf_srand(unsigned int seed);

long sce_paf_strtol(const char *str, char **str_end, int base);
long long sce_paf_strtoll(const char *str, char **str_end, int base);
unsigned long long int sce_paf_strtoull(const char* str, char** endptr, int base);
unsigned long int sce_paf_strtoul(const char* str, char** endptr, int base);

void sce_paf_qsort(void *ptr, size_t count, size_t size, int(*comp)(const void *, const void *));
void* sce_paf_bsearch(const void *key, const void *ptr, size_t count, size_t size, int(*comp)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif /* _PAF_STD_STDLIB_H */
