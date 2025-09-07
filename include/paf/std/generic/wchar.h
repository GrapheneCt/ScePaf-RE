/*
	ScePaf-RE Project
*/

#ifndef _PAF_STD_WCHAR_H
#define _PAF_STD_WCHAR_H

#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

#define sce_paf_wcscat			wcscat
#define sce_paf_wcsncat			wcsncat
#define sce_paf_wcscpy			wcscpy
#define sce_paf_wcsncpy			wcsncpy

#define sce_paf_wcscasecmp		wcscasecmp
#define sce_paf_wcschr			wcschr
#define sce_paf_wcscmp			wcscmp
#define sce_paf_wcscspn			wcscspn
#define sce_paf_wcslen			wcslen
#define sce_paf_wcsncasecmp		wcsncasecmp
#define sce_paf_wcsncmp			wcsncmp
#define sce_paf_wcsnlen			wcsnlen
#define sce_paf_wcspbrk			wcspbrk
#define sce_paf_wcsrchr			wcsrchr
#define sce_paf_wcsspn			wcsspn
#define sce_paf_wcsstr			wcsstr

#define sce_paf_wmemchr			wmemchr
#define sce_paf_wmemcmp			wmemcmp
#define sce_paf_wmemcpy			wmemcpy
#define sce_paf_wmemmove		wmemmove
#define sce_paf_wmemset			wmemset

#define sce_paf_swprintf		swprintf
#define sce_paf_vswprintf		vswprintf

#ifdef __cplusplus
}
#endif

#endif /* _PAF_STD_WCHAR_H */
