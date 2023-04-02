/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_STD___STDC___H
#define _VDSUITE_USER_PAF_STD___STDC___H

#include <../../stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t(*sce_paf_report_memoryblocks_callback)(void*, size_t, int32_t, void *userdata);

void *GetGlobalHeapAllocator();

#ifdef __cplusplus
}
#endif

#endif /* _VDSUITE_USER_PAF_STD___STDC___H */
