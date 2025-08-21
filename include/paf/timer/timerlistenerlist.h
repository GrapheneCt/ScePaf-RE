/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_TIMER_TIMERLISTENERLIST_H
#define _VDSUITE_USER_PAF_TIMER_TIMERLISTENERLIST_H

#include <paf/std/list>
#include <paf/thread/rmutex.h>

namespace paf {

	class TimerListener;

	class TimerListenerList
	{
	public:

		class ListenerParam
		{
		public:

			ListenerParam(TimerListener *listener, bool interval, void *data1, void *data2);

		private:

			TimerListener* m_listener;
			void* m_data1;
			void* m_data2;
			bool m_interval;
		};

		TimerListenerList();

		~TimerListenerList()
		{

		}

		void Init();

		void Exit();

		void Update();

		void Register(ListenerParam const& param);

		void Unregister(TimerListener *listener);

		__declspec (dllimport) static TimerListenerList *s_default_list;

	private:

		list<ListenerParam> m_list;
		list<ListenerParam>::iterator m_iterator;
		bool m_iterator_updated;
		thread::RMutex m_list_mutex;
	};
}

#endif /* _VDSUITE_USER_PAF_TIMER_TIMERLISTENERLIST_H */