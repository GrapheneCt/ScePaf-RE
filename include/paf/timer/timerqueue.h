/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_TIMER_TIMERQUEUE_H
#define _VDSUITE_USER_PAF_TIMER_TIMERQUEUE_H

#include <stdint.h>
#include <paf/std/list>
#include <paf/timer/timerlistener.h>

namespace paf {

	class TimerQueue
	{
	public:

		TimerQueue() : m_total(0.0f)
		{

		}

		virtual ~TimerQueue()
		{
			ClearAll();
		}

		void Clear();

		void ClearAll();

		float DoTick(void *data1, void *data2);

		int32_t EraseFront(bool auto_delete);

		TimerListener *GetBack();

		TimerListener *GetFront();

		bool IsFinished();

		int32_t PushBack(TimerListener *t)
		{
			m_list.push_back(t);
			m_total += t->GetTotalTime();
			return 0;
		}

		int32_t PushFront(TimerListener *t)
		{
			m_list.push_front(t);
			m_total += t->GetTotalTime();
			return 0;
		}

		int32_t Size()
		{
			return m_list.size();
		}



	protected:
		list<TimerListener*> m_list;
		float m_total;
	};
}

#endif /* _VDSUITE_USER_PAF_TIMER_TIMERQUEUE_H */