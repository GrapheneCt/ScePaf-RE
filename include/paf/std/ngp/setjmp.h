#ifndef _PAF_STD_SETJMP_H
#define _PAF_STD_SETJMP_H

#include <../../setjmp.h>

#ifdef __cplusplus
extern "C" {
#endif

void sce_paf_longjmp(jmp_buf env, int status);
int sce_paf_setjmp(jmp_buf env);

#ifdef __cplusplus
}
#endif

#endif /* _PAF_STD_SETJMP_H */
