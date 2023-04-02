/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_JOB_CALL_QUEUE_H
#define _VDSUITE_USER_PAF_COMMON_JOB_CALL_QUEUE_H

#include <stdint.h>
#include <paf/thread/mutex.h>

namespace paf {

	namespace job {

		class JobQueue;
	}

	namespace thread {

		class CallQueue;
	}

	namespace common {

		class JobCallQueue
		{
		public:

			typedef void(*Function)(void *userdata);

			JobCallQueue(paf::string const& name, paf::job::JobQueue *job_queue);

			~JobCallQueue();

			void WaitEmpty();

			int32_t NumItems();

			void Enqueue(const char *name, Function func, void *userdata);

			void Check();

		private:

			string m_name;
			paf::job::JobQueue *m_job_queue;
			paf::thread::Mutex m_mutex;
			paf::thread::CallQueue *m_call_queue;
			char reserved[4];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_JOB_CALL_QUEUE_H */
