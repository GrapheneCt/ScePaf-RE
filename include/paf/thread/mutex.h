/*
	ScePaf-RE Project
*/

#ifndef _PAF_THREAD_MUTEX_H
#define _PAF_THREAD_MUTEX_H

#include <stdint.h>
#if defined(__SNC__)
#include <kernel/threadmgr.h>
#define SCE_PAF_MUTEX_TYPE SceKernelLwMutexWork
#elif defined(__vita__)
#include <psp2/kernel/threadmgr.h>
#define SCE_PAF_MUTEX_TYPE SceKernelLwMutexWork
#elif defined(_WIN32)
#include <Windows.h>
#define SCE_PAF_MUTEX_TYPE CRITICAL_SECTION
#else
#error Current target platform is not supported or no target platform defined
#endif

namespace paf {
	namespace thread {

		class Mutex
		{
		public:

			enum Option : int32_t
			{
				Option_None = 0,
				Option_FIFO = 1,
				Option_Default = 0
			};

			Mutex(const char *name, int32_t option = Option_Default);

			~Mutex();

			void Lock();

			bool TryLock();

			void Unlock();

		private:

			friend class Cond;

			SCE_PAF_MUTEX_TYPE m_mutex;
		};

		class MutexLock
		{
		public:

			MutexLock(Mutex *_mutex)
			{
				m_mutex = _mutex;
				m_mutex->Lock();
			}

			~MutexLock()
			{
				m_mutex->Unlock();
			}

		private:

			Mutex *m_mutex;
		};
	}
}

#endif /* _PAF_THREAD_MUTEX_H */