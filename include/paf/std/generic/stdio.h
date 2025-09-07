/*
	ScePaf-RE Project
*/

#ifndef _PAF_STD_STDIO_H
#define _PAF_STD_STDIO_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define sce_paf_FILE FILE

#define sce_paf_snprintf snprintf
#define sce_paf_vsnprintf vsnprintf

#define sce_paf_feof feof
#define sce_paf_ferror ferror
#define sce_paf_fopen fopen
#define sce_paf_fclose fclose
#define sce_paf_fread fread
#define sce_paf_fwrite fwrite
#define sce_paf_fseek fseek
#define sce_paf_ftell ftell
#define sce_paf_fgetc fgetc
#define sce_paf_fputc fputc
#define sce_paf_fflush fflush

#define sce_paf_printf printf

#ifdef __cplusplus
}
#endif

#endif /* _PAF_STD_STDIO_H */
