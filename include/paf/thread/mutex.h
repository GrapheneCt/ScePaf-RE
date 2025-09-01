/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_MUTEX_H
#define _VDSUITE_USER_PAF_THREAD_MUTEX_H

#include <stdint.h>
#ifdef __SNC__
#include <kernel/threadmgr.h>
#else
#include <psp2/kernel/threadmgr.h>
#endif

namespace paf {
	namespace thread {

		class Mutex
		{
		public:

			enum Option
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

			SceKernelLwMutexWork mutex;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_MUTEX_H */