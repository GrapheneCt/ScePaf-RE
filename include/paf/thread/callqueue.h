/*
	ScePaf-RE Project
*/

#ifndef _PAF_THREAD_CALLQUEUE_H
#define _PAF_THREAD_CALLQUEUE_H

#include <stdint.h>
#include <paf/std/stdcxx.h>
#include <paf/thread/mutex.h>
#include <paf/paf_types.h>

namespace paf {
	namespace thread {

		class CallQueue
		{
		public:

			typedef void(*Function)(void *userdata);

			static CallQueue *MainThreadCallQueue()
			{
				return &main_thread_callqueue;
			}

			CallQueue(const char *_name);

			~CallQueue();

			void WaitEmpty();

			void Enqueue(const char *name, Function entry, void *userdata = NULL);

			void Check();

			size_t NumItems();

		private:

			SCE_PAF_IMPORTED_FROM_PRX static CallQueue main_thread_callqueue;

			struct Request
			{
				string name;
				Function func;
				void *arg;
			};

			Mutex m_mutex;
			list<Request> m_request_queue;
		};
	}
}

#endif /* _PAF_THREAD_CALLQUEUE_H */