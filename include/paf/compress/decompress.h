/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMPRESS_DECOMPRESS_H
#define _PAF_COMPRESS_DECOMPRESS_H

#include <stdint.h>
#include <stddef.h>

namespace paf {

	namespace compress {

		enum DecompressType : int32_t
		{
			DecompressType_None = 0,
			DecompressType_Zlib = 1
		};

		extern int32_t Decompress(void *dst, size_t dstsize, const void *src, size_t srcsize, DecompressType type = DecompressType_Zlib);
	}
}

#endif /* _PAF_COMPRESS_DECOMPRESS_H */
