/*
	ScePaf-RE Project
*/

#ifndef _PAF_THREAD_ATOMIC_H
#define _PAF_THREAD_ATOMIC_H

#include <stdint.h>
#if defined(__SNC__)
#include <sce_atomic.h>
#elif defined(__vita__)
#include <psp2/kernel/cpu.h>
#elif defined(_WIN32)
#include <Windows.h>
#else
#error Current target platform is not supported or no target platform defined
#endif

namespace paf {
	namespace thread {
		namespace atomic {

			static inline int32_t dec32(volatile int32_t* ptr)
			{
#if defined(__SNC__)
				return sceAtomicDecrement32(ptr);
#elif defined(__vita__)
				return sceKernelAtomicGetAndAdd32((SceInt32 *)ptr, ~0);
#elif defined(_WIN32)
				int32_t prev = *ptr;
				InterlockedDecrement((long volatile *)ptr);
				return prev;
#endif
			}

			static inline int32_t inc32(volatile int32_t* ptr)
			{
#if defined(__SNC__)
				return sceAtomicIncrement32(ptr);
#elif defined(__vita__)
				return sceKernelAtomicGetAndAdd32((SceInt32 *)ptr, 1);
#elif defined(_WIN32)
				int32_t prev = *ptr;
				InterlockedIncrement((long volatile *)ptr);
				return prev;
#endif
			}
		}
	}
}

#endif /* _PAF_THREAD_ATOMIC_H */