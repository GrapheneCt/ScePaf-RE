/*
	ScePaf-RE Project
*/

#ifndef _PAF_FILE_HTTPFILE_TYPES_H
#define _PAF_FILE_HTTPFILE_TYPES_H

#include <stdint.h>
#include <paf/paf_types.h>
#include <paf/datetime/datetime.h>

namespace paf {

	struct HttpFileStat
	{
		int32_t				st_mode;
		uint32_t			st_attr;
		int64_t				st_size;
		datetime::DateTime	st_ctime;
		datetime::DateTime	st_atime;
		datetime::DateTime	st_mtime;
	};
}

#endif /* _PAF_FILE_HTTPFILE_TYPES_H */
