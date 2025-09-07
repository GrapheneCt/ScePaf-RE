/*
	ScePaf-RE Project
*/

#ifndef _PAF_STD_ASSERT_H
#define _PAF_STD_ASSERT_H

#include <paf/std/generic/stdlib.h>
#include <paf/std/generic/stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef NDEBUG

#define assert(expr) \
if (!(expr)) { \
	abort(); \
}

#else

#define assert(expr) \
if (!(expr)) { \
	sce_paf_printf("%s:%d: %s: Assertion `%s\' failed.\n", __FILE__, __LINE__, __FUNCDNAME__, #expr); \
	abort(); \
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* _PAF_STD_ASSERT_H */
