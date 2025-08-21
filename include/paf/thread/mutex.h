﻿/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_MUTEX_H
#define _VDSUITE_USER_PAF_THREAD_MUTEX_H

#include <kernel/threadmgr.h>

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