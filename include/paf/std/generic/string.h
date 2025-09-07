/*
	ScePaf-RE Project
*/

#ifndef _PAF_STD_STRING_H
#define _PAF_STD_STRING_H

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define sce_paf_strlen			strlen
#define sce_paf_strcasecmp		strcasecmp
#define sce_paf_strchr			strchr
#define sce_paf_strcmp			strcmp
#define sce_paf_strncasecmp		strncasecmp
#define sce_paf_strncmp			strncmp
#define sce_paf_strncpy			strncpy
#define sce_paf_strrchr			strrchr
#define sce_paf_strstr			strstr
#define sce_paf_strtok			strtok
#define sce_paf_strtok_r		strtok_r
#define sce_paf_strcpy			strcpy
#define sce_paf_strcat			strcat
#define sce_paf_strncat			strncat
#define sce_paf_strcspn			strcspn
#define sce_paf_strlcat			strlcat
#define sce_paf_strlcpy			strlcpy
#define sce_paf_strpbrk			strpbrk
#define sce_paf_strspn			strspn

#define sce_paf_memset			memset
//#define sce_paf_memset32		memset32
#define sce_paf_memcpy			memcpy
#define sce_paf_memmove			memmove
#define sce_paf_memchr			memchr
#define sce_paf_memcmp			memcmp
#define sce_paf_bzero(x, y)		memset(x, 0, y)
#define sce_paf_bcmp(x, y, z)	memcmp(x, y, z)
#define sce_paf_bcopy(x, y, z)	memcpy(y, x, z)

#ifdef __cplusplus
}
#endif

#endif /* _PAF_STD_STRING_H */
