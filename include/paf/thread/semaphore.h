/*
	ScePaf-RE Project
*/

#ifndef _PAF_THREAD_SEMAPHORE_H
#define _PAF_THREAD_SEMAPHORE_H

#include <stdint.h>
#if defined(__SNC__)
#include <scetypes.h>
#define SCE_PAF_SEMAPHORE_TYPE SceUID
#elif defined(__vita__)
#include <psp2/types.h>
#define SCE_PAF_SEMAPHORE_TYPE SceUID
#elif defined(_WIN32)
#include <Windows.h>
#define SCE_PAF_SEMAPHORE_TYPE HANDLE
#else
#error Current target platform is not supported or no target platform defined
#endif

namespace paf {
	namespace thread {

		class Semaphore
		{
		public:

			enum Option : int32_t
			{
				Option_None = 0,
				Option_Default = 0
			};

			Semaphore(const char *name, int32_t init_count, int32_t max_count, int32_t option = Option_None);

			~Semaphore();

			void Acquire();

			void Release();

		private:

			SCE_PAF_SEMAPHORE_TYPE m_sema;
		};
	}
}

#endif /* _PAF_THREAD_SEMAPHORE_H */