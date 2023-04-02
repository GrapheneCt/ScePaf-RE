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

			virtual ~MemoryAllocator()
			{

			}
		};
	}
}

#endif /* _VDSUITE_USER_PAF_MEMORY_ALLOCATOR_H */
