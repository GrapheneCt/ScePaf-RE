/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_TIMER_RAW_TIMER_H
#define _VDSUITE_USER_PAF_TIMER_RAW_TIMER_H

#include <stddef.h>
#include <stdint.h>
#include <paf/common/averaged_value.h>

typedef uint64_t TimeType;

namespace paf {
	
	extern TimeType get_time_internal();

	class RawTimer
	{
	public:

		RawTimer(size_t _Ave) : _val(_Ave), _start_flag(false)
		{
			_start = get_time_internal();
		}

		void start()
		{
			_start = get_time_internal();
			_start_flag = true;
		}

		void end()
		{
			if (_start_flag)
			{
				_val += seconds();
				_start_flag = false;
			}
		}

		float seconds() const
		{
			return (get_time_internal() - _start) / 1000000.0f;
		}

		float milliseconds() const
		{
			return seconds() * 1000.0f;
		}

	private:

		TimeType _start;
		common::AveragedValue<float> _val;
		bool _start_flag;
	};
}

#endif /* _VDSUITE_USER_PAF_TIMER_RAW_TIMER_H */