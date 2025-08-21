/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_COND_H
#define _VDSUITE_USER_PAF_THREAD_COND_H

#include <stdint.h>
#include <kernel/threadmgr.h>

namespace paf {
	namespace thread {

		class Mutex;

		class Cond
		{
		public:

			enum Option
			{
				Option_None = 0,
				Option_FIFO = 1,
				Option_Default = 0
			};

			Cond(Mutex& mutex, const char *name, int32_t option = Option_Default);

			~Cond();

			bool Wait(int32_t timeout_msec = 0);

			void Notify();

			void NotifyAll();

		private:

			Mutex* mutex;
			SceKernelLwCondWork cond;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_COND_H */