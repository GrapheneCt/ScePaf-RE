/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_CALL_LIST_H
#define _VDSUITE_USER_PAF_COMMON_CALL_LIST_H

#include <paf/thread/rmutex.h>

namespace paf {

	namespace thread {

		class Mutex;
	}

	namespace common {

		class CallList
		{
		public:

			typedef void(*Function)(void *userdata);

			CallList();

			virtual ~CallList() = 0;

			int32_t GetNum();

			void Register(Function entry, void *userdata);

			int32_t Unregister(Function entry, void *userdata);

			void Update(paf::thread::Mutex *extMtx);

		private:

			char m_unk00[0x18];
			thread::RMutex m_item_mtx;
		};

		namespace MainThreadCallList {

			typedef void(*Function)(void *userdata);

			extern void Register(Function func, void *userdata);

			extern void Unregister(Function func, void *userdata);
		}
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_CALL_LIST_H */
