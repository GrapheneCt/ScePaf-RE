/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_STD_WCTYPE_H
#define _VDSUITE_USER_PAF_STD_WCTYPE_H

#include <../../wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

wint_t __wcstolower(wint_t wc);
#define sce_paf_towlower __wcstolower

#ifdef __cplusplus
}
#endif

#endif /* _VDSUITE_USER_PAF_STD_WCTYPE_H */
