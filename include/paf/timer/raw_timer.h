/*
	ScePaf-RE Project
*/

#ifndef _PAF_TIMER_RAW_TIMER_H
#define _PAF_TIMER_RAW_TIMER_H

#include <stddef.h>
#include <stdint.h>
#include <paf/common/averaged_value.h>

typedef uint64_t TimeType;

namespace paf {

	extern TimeType get_time_internal();

	class RawTimer
	{
	public:

		RawTimer(size_t _Ave = 0) : m_val(_Ave), m_start_flag(false)
		{
			m_start = get_time_internal();
		}

		void start()
		{
			m_start = get_time_internal();
			m_start_flag = true;
		}

		void end()
		{
			if (m_start_flag)
			{
				m_val += seconds();
				m_start_flag = false;
			}
		}

		float seconds() const
		{
			return (float)(get_time_internal() - m_start) / 1000000.0f;
		}

		float milliseconds() const
		{
			return (float)(get_time_internal() - m_start) / 1000.0f;
		}

		float average() const
		{
			return m_val;
		}

	private:

		TimeType m_start;
		common::AveragedValue<float> m_val;
		bool m_start_flag;
	};
}

#endif /* _PAF_TIMER_RAW_TIMER_H */