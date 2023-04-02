/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMPRESS_COMPRESS_H
#define _VDSUITE_USER_PAF_COMPRESS_COMPRESS_H

#include <stdint.h>
#include <stddef.h>
#include <paf/common/shared_ptr.h>

namespace paf {

	class MemFile;

	namespace memory {

		class HeapAllocator;
	}

	namespace compress {

		enum CompressType
		{
			CompressType_None = 0,
			CompressType_Zlib = 1
		};

		extern common::SharedPtr<MemFile> Compress(const void *src, size_t srcsize, CompressType type = CompressType_Zlib, memory::HeapAllocator *allocator = NULL);
	}
}

#endif /* _VDSUITE_USER_PAF_COMPRESS_COMPRESS_H */
