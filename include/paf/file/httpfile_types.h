/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_FILE_HTTPFILE_TYPES_H
#define _VDSUITE_USER_PAF_FILE_HTTPFILE_TYPES_H

#include <stdint.h>
#include <paf/paf_types.h>
#include <paf/datetime/datetime.h>

namespace paf {

	class HttpFileStat
	{
	public:

		int32_t				st_mode;
		uint32_t			st_attr;
		off_t				st_size;
		datetime::DateTime	st_ctime;
		datetime::DateTime	st_atime;
		datetime::DateTime	st_mtime;
	};
}

#endif /* _VDSUITE_USER_PAF_FILE_HTTPFILE_TYPES_H */
