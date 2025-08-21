#ifndef _PAF_STD_STDIO_H
#define _PAF_STD_STDIO_H

#include <../../stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EOF			(-1)
#define WEOF		((unsigned int)(-1))

typedef struct sce_paf_FILE {
	int32_t type;
	int32_t fd;
	uint32_t status;
	int32_t unget_char;
	int32_t seek_offset;
	int32_t buff_attr;
	int32_t buff_off;
	int32_t buff_len;
} sce_paf_FILE;

int sce_paf_snprintf(char *s, size_t n, const char *format, ...);

int sce_paf_feof(sce_paf_FILE *stream);
int sce_paf_ferror(sce_paf_FILE * stream);
sce_paf_FILE * sce_paf_fopen(const char * sce_paf_FILEname, const char * mode);
int sce_paf_fclose(sce_paf_FILE * stream);
size_t sce_paf_fread(void * ptr, size_t size, size_t count, sce_paf_FILE * stream);
size_t sce_paf_fwrite(const void * ptr, size_t size, size_t count, sce_paf_FILE * stream);
int sce_paf_fseek(sce_paf_FILE * stream, long int offset, int origin);
long int sce_paf_ftell(sce_paf_FILE * stream);
int sce_paf_fgetc(sce_paf_FILE * stream);
int sce_paf_fputc(int c, sce_paf_FILE *stream);
int sce_paf_fflush(sce_paf_FILE *stream);

#ifdef __cplusplus
}
#endif

#endif /* _PAF_STD_WCHAR_H */
