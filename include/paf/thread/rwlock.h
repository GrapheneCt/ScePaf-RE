/*
	ScePaf-RE Project
*/

#ifndef _PAF_THREAD_RWLOCK_H
#define _PAF_THREAD_RWLOCK_H

#include <stdint.h>
#if defined(__SNC__)
#include <scetypes.h>
#define SCE_PAF_RWLOCK_TYPE SceUID
#elif defined(__vita__)
#include <psp2/types.h>
#define SCE_PAF_RWLOCK_TYPE SceUID
#elif defined(_WIN32)
#include <Windows.h>
#define SCE_PAF_RWLOCK_TYPE SRWLOCK
#else
#error Current target platform is not supported or no target platform defined
#endif

namespace paf {
	namespace thread {

		class RWLock
		{
		public:

			enum Option : int32_t
			{
				Option_None = 0,
				Option_Default = 0
			};

			RWLock(const char *name, int32_t option = Option_Default);

			~RWLock();

			void LockShared();

			void UnlockShared();

			void LockExclusive();

			void UnlockExclusive();

		private:

			SCE_PAF_RWLOCK_TYPE m_evf;
			int32_t m_counter;
		};
	}
}

#endif /* _PAF_THREAD_RWLOCK_H */