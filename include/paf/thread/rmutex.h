/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_RMUTEX_H
#define _VDSUITE_USER_PAF_THREAD_RMUTEX_H

#include <kernel/threadmgr.h>

namespace paf {
	namespace thread {

		class RMutex
		{
		public:

			enum Option
			{
				Option_None = 0,
				Option_FIFO = 1,
				Option_Default = 0
			};

			RMutex(const char *name, int32_t option = Option_Default);

			~RMutex();

			void Lock();

			bool TryLock();

			void Unlock();

			__declspec (dllimport) static RMutex main_thread_mutex;

		private:

			SceKernelLwMutexWork mutex;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_RMUTEX_H */