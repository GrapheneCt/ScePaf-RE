/*
	ScePaf-RE Project
*/

#ifndef _PAF_STD_SETJMP_H
#define _PAF_STD_SETJMP_H

#include <setjmp.h>

#ifdef __cplusplus
extern "C" {
#endif

#define sce_paf_longjmp longjmp
#define sce_paf_setjmp setjmp

#ifdef __cplusplus
}
#endif

#endif /* _PAF_STD_SETJMP_H */
