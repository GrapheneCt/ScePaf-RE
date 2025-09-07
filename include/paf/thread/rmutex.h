/*
	ScePaf-RE Project
*/

#ifndef _PAF_THREAD_RMUTEX_H
#define _PAF_THREAD_RMUTEX_H

#include <stdint.h>
#include <paf/paf_types.h>
#if defined(__SNC__)
#include <kernel/threadmgr.h>
#define SCE_PAF_RMUTEX_TYPE SceKernelLwMutexWork
#elif defined(__vita__)
#include <psp2/kernel/threadmgr.h>
#define SCE_PAF_RMUTEX_TYPE SceKernelLwMutexWork
#elif defined(_WIN32)
#include <Windows.h>
#define SCE_PAF_RMUTEX_TYPE CRITICAL_SECTION
#else
#error Current target platform is not supported or no target platform defined
#endif

namespace paf {
	namespace thread {

		class RMutex
		{
		public:

			enum Option : int32_t
			{
				Option_None = 0,
				Option_FIFO = 1,
				Option_Default = 0
			};

			static RMutex *MainThreadMutex()
			{
				return &main_thread_mutex;
			}

			RMutex(const char *name, int32_t option = Option_Default);

			~RMutex();

			void Lock();

			bool TryLock();

			void Unlock();

		private:

			SCE_PAF_IMPORTED_FROM_PRX static RMutex main_thread_mutex;

			SCE_PAF_RMUTEX_TYPE m_mutex;
		};

		class RMutexLock
		{
		public:

			RMutexLock(RMutex *_rmutex)
			{
				m_rmutex = _rmutex;
				m_rmutex->Lock();
			}

			~RMutexLock()
			{
				m_rmutex->Unlock();
			}

		private:

			RMutex *m_rmutex;
		};
	}
}

#endif /* _PAF_THREAD_RMUTEX_H */