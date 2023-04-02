/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_AVERAGED_VALUE_H
#define _VDSUITE_USER_PAF_COMMON_AVERAGED_VALUE_H

#include <stdint.h>

namespace paf {
	namespace common {

		template <typename T>
		class AveragedValue
		{
		public:

			AveragedValue(size_t _Ave)
			{
				_sum = (T)0;
				_avg = 1;
				if (_Ave != 0)
				{
					_avg = _Ave;
				}
				_count = 0;
				_last_avg = (T)0;
				_local_min = (T)0;
				_local_max = (T)0;
			}

			~AveragedValue()
			{

			}

			AveragedValue& operator+=(T const& _Value)
			{
				if (_count == 0)
				{
					_sum = _Value;
					_local_min = _Value;
					_local_max = _Value;
				}
				else
				{
					_sum += _Value;
					if (_Value < _local_min)
					{
						_local_min = _Value;
					}
					if (_Value > _local_max)
					{
						_local_max = _Value;
					}
				}
				_count++;
				if (_count == _avg)
				{
					_last_avg = _sum / _avg;
					_count = 0;
				}
			}

			operator float() const
			{
				return _last_avg;
			}

		private:

			T _sum;
			size_t _avg;
			size_t _count;
			float _last_avg;
			T _local_min;
			T _local_max;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_AVERAGED_VALUE_H */
