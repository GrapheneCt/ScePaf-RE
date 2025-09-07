/*
	ScePaf-RE Project
*/

#ifndef _PAF_STD_STDLIB_H
#define _PAF_STD_STDLIB_H

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t(*sce_paf_report_memoryblocks_callback)(void* a1, size_t a2, int32_t a3, void *userdata);

void *sce_paf_memalign(size_t align, size_t length);
void sce_paf_free(void *ptr);
void *sce_paf_malloc(size_t size);
void* sce_paf_calloc(size_t num, size_t size);
void *sce_paf_realloc(void *ptr, size_t new_size);
size_t sce_paf_musable_size(void *ptr);
void sce_paf_mtrim();
void sce_paf_dump_heap_status();
void sce_paf_dump_heap_info(int32_t sort_policy);
int32_t sce_paf_report_memoryblocks(sce_paf_report_memoryblocks_callback callback, void *userdata);
int32_t sce_paf_check_memorybounds();

#define sce_paf_abs abs
#define sce_paf_atof atof
#define sce_paf_atoi atoi
#define sce_paf_atol atol
#define sce_paf_atoll atoll

#define sce_paf_rand rand
#define sce_paf_srand srand

#define sce_paf_strtol strtol
#define sce_paf_strtoll strtoll
#define sce_paf_strtoull strtoull
#define sce_paf_strtoul strtoul

#define sce_paf_qsort qsort
#define sce_paf_bsearch bsearch

#ifdef __cplusplus
}
#endif

#endif /* _PAF_STD_STDLIB_H */
