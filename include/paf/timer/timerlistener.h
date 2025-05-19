/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_TIMER_TIMERLISTENER_H
#define _VDSUITE_USER_PAF_TIMER_TIMERLISTENER_H

#include <paf/timer/timer.h>

namespace paf {

	class TimerListener
	{
	public:

		TimerListener(Timer *t, void *data)
		{
			m_timer = t;
			m_data = data;
		}

		virtual ~TimerListener()
		{
			delete m_timer;
		}


		virtual void OnTick(void *data1, void *data2)
		{

		}

		virtual void OnFinish(void *data1, void *data2)
		{

		}

		float DoTick(void *data1, void *data2);

		void ResetTimer();

		bool IsFinished()
		{
			if (m_timer == NULL)
			{
				return true;
			}
			return m_timer->IsAllFinished();
		}

		float GetTotalTime() const
		{
			if (m_timer == NULL)
			{
				return 0.0f;
			}
			return m_timer->GetTotalTime();
		}

		Timer *m_timer;
		void *m_data;
	};
}

#endif /* _VDSUITE_USER_PAF_TIMER_TIMERLISTENER_H */