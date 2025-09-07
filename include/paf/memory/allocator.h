/*
	ScePaf-RE Project
*/

#ifndef _PAF_MEMORY_ALLOCATOR_H
#define _PAF_MEMORY_ALLOCATOR_H

#include <stdint.h>
#include <stddef.h>

namespace paf {
	namespace memory {

		enum AllocationBlockType : int32_t
		{
			AllocationBlockType_User = 0,
			AllocationBlockType_User_Cdlg = 1
		};

		class MemoryAllocator
		{
		public:

			MemoryAllocator()
			{

			}

			virtual uint32_t GetType() const = 0;
			virtual AllocationBlockType GetBlockType() const = 0;
			virtual const char *GetName() const = 0;
			virtual void GetRange(void **membase, size_t *size) const = 0;
			virtual size_t GetFreeSize() = 0;

			virtual ~MemoryAllocator()
			{

			}
		};
	}
}

#endif /* _PAF_MEMORY_ALLOCATOR_H */
