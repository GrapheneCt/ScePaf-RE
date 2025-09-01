/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_ATOMIC_H
#define _VDSUITE_USER_PAF_THREAD_ATOMIC_H

#include <stdint.h>
#ifdef __SNC__
#include <sce_atomic.h>
#else
#include <psp2/kernel/cpu.h>
#endif

namespace paf {
	namespace thread {
		namespace atomic {

			static inline int32_t dec32(volatile int32_t* ptr)
			{
#ifdef __SNC__
				return sceAtomicDecrement32(ptr);
#else
				return sceKernelAtomicGetAndAdd32((SceInt32 *)ptr, ~0);
#endif
			}

			static inline int32_t inc32(volatile int32_t* ptr)
			{
#ifdef __SNC__
				return sceAtomicIncrement32(ptr);
#else
				return sceKernelAtomicGetAndAdd32((SceInt32 *)ptr, 1);
#endif
			}
		}
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_ATOMIC_H */