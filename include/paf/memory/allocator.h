/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MEMORY_ALLOCATOR_H
#define _VDSUITE_USER_PAF_MEMORY_ALLOCATOR_H

#include <stdint.h>
#include <stddef.h>

namespace paf {
	namespace memory {

		enum AllocationBlockType
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
			virtual char *GetName() const = 0;
			virtual void GetRange(void **membase, size_t *size) const = 0;
			virtual size_t GetFreeSize() = 0;

			virtual ~MemoryAllocator()
			{

			}
		};
	}
}

#endif /* _VDSUITE_USER_PAF_MEMORY_ALLOCATOR_H */
