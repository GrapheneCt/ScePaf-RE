/*
	ScePaf-RE Project
*/

#ifndef _PAF_TIMER_TIMERLISTENERLIST_H
#define _PAF_TIMER_TIMERLISTENERLIST_H

#include <paf/std/stdcxx.h>
#include <paf/thread/rmutex.h>
#include <paf/paf_types.h>

namespace paf {

	class TimerListener;

	class TimerListenerList
	{
	public:

		class ListenerParam
		{
		public:

			ListenerParam(TimerListener *_listener, bool _interval, void *_data1, void *_data2);

			TimerListener* listener;
			void* data1;
			void* data2;
			bool interval;
		};

		static TimerListenerList *DefaultList()
		{
			return s_default_list;
		}

		static void Init();

		static void Exit();

		TimerListenerList();

		~TimerListenerList()
		{

		}

		void Update();

		void Register(ListenerParam const& param);

		void Unregister(TimerListener *listener);

	private:

		SCE_PAF_IMPORTED_FROM_PRX static TimerListenerList *s_default_list;

		list<ListenerParam> m_list;
		list<ListenerParam>::iterator m_iterator;
		bool m_iterator_updated;
		thread::RMutex m_list_mutex;
	};
}

#endif /* _PAF_TIMER_TIMERLISTENERLIST_H */