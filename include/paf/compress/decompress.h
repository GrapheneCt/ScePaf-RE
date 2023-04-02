/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMPRESS_DECOMPRESS_H
#define _VDSUITE_USER_PAF_COMPRESS_DECOMPRESS_H

#include <stdint.h>
#include <stddef.h>

namespace paf {

	namespace compress {

		enum DecompressType
		{
			DecompressType_None = 0,
			DecompressType_Zlib = 1
		};

		extern int32_t Decompress(void *dst, size_t dstsize, const void *src, size_t srcsize, DecompressType type = DecompressType_Zlib);
	}
}

#endif /* _VDSUITE_USER_PAF_COMPRESS_DECOMPRESS_H */
