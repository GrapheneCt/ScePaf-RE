/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_CALL_LIST_H
#define _PAF_COMMON_CALL_LIST_H

#include <stdint.h>
#include <paf/std/stdcxx.h>
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

			~CallList()
			{

			}

			uint32_t GetNum();

			void Register(Function entry, void *userdata = NULL);

			void Unregister(Function entry, void *userdata = NULL);

			void Update(paf::thread::Mutex *extMtx);

		private:

			class CallItem
			{
			public:

				CallItem(Function entry, void *userdata) : m_func(entry), m_data(userdata)
				{

				}

				Function m_func;
				void *m_data;
			};

			list<CallItem> m_list;
			list<CallItem>::const_iterator m_iterator;
			bool m_iterator_updated;
			thread::RMutex m_item_mtx;
		};

		namespace MainThreadCallList {

			typedef void(*Function)(void *userdata);

			extern void Register(Function func, void *userdata = NULL);

			extern void Unregister(Function func, void *userdata = NULL);
		}
	}
}

#endif /* _PAF_COMMON_CALL_LIST_H */
