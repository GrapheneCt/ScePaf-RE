/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_CALLQUEUE_H
#define _VDSUITE_USER_PAF_THREAD_CALLQUEUE_H

#include <stdint.h>
#include <paf/thread/mutex.h>
#include <paf/paf_types.h>

namespace paf {
	namespace thread {

		class CallQueue
		{
		public:

			typedef void(*Function)(void *userdata);

			CallQueue(const char *_name);

			~CallQueue();

			void WaitEmpty();

			void Enqueue(const char *name, Function entry, void *userdata);

			void Check();

			uint32_t NumItems();

			SCE_PAF_IMPORTED_FROM_PRX static CallQueue main_thread_callqueue;

		private:

			Mutex mutex;
			char request_queue[16];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_CALLQUEUE_H */