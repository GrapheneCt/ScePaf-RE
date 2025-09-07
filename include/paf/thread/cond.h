/*
	ScePaf-RE Project
*/

#ifndef _PAF_THREAD_COND_H
#define _PAF_THREAD_COND_H

#include <stdint.h>
#if defined(__SNC__)
#include <kernel/threadmgr.h>
#define SCE_PAF_COND_TYPE SceKernelLwCondWork
#elif defined(__vita__)
#include <psp2/kernel/threadmgr.h>
#define SCE_PAF_COND_TYPE SceKernelLwCondWork
#elif defined(_WIN32)
#include <Windows.h>
#define SCE_PAF_COND_TYPE CONDITION_VARIABLE
#else
#error Current target platform is not supported or no target platform defined
#endif

namespace paf {
	namespace thread {

		class Mutex;

		class Cond
		{
		public:

			enum Option : int32_t
			{
				Option_None = 0,
				Option_FIFO = 1,
				Option_Default = 0
			};

			enum
			{
				NoError = 0,
				Timeout = 1
			};

			Cond(Mutex& mutex, const char *name, int32_t option = Option_Default);

			~Cond();

			int32_t Wait(int32_t timeout_msec = 0);

			void Notify();

			void NotifyAll();

		private:

			Mutex* m_mutex;
			SCE_PAF_COND_TYPE m_cond;
		};
	}
}

#endif /* _PAF_THREAD_COND_H */