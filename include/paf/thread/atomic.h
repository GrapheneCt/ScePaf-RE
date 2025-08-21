/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_ATOMIC_H
#define _VDSUITE_USER_PAF_THREAD_ATOMIC_H

#include <stdint.h>
#include <sce_atomic.h>

namespace paf {
	namespace thread {
		namespace atomic {

			static inline int32_t dec32(volatile int32_t* ptr)
			{
				return sceAtomicDecrement32(ptr);
			}

			static inline int32_t inc32(volatile int32_t* ptr)
			{
				return sceAtomicIncrement32(ptr);
			}
		}
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_ATOMIC_H */