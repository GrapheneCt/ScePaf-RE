/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_AVERAGED_VALUE_H
#define _PAF_COMMON_AVERAGED_VALUE_H

#include <stdint.h>

namespace paf {
	namespace common {

		template <typename T>
		class AveragedValue
		{
		public:

			AveragedValue(size_t _Ave)
			{
				m_sum = (T)0;
				m_avg = 1;
				if (_Ave != 0)
				{
					m_avg = _Ave;
				}
				m_count = 0;
				m_last_avg = (T)0;
				m_local_min = (T)0;
				m_local_max = (T)0;
			}

			~AveragedValue()
			{

			}

			AveragedValue& operator+=(T const& _Value)
			{
				if (m_count == 0)
				{
					m_sum = _Value;
					m_local_min = _Value;
					m_local_max = _Value;
				}
				else
				{
					m_sum += _Value;
					if (_Value < m_local_min)
					{
						m_local_min = _Value;
					}
					if (_Value > m_local_max)
					{
						m_local_max = _Value;
					}
				}
				m_count++;
				if (m_count == m_avg)
				{
					m_last_avg = m_sum / m_avg;
					m_count = 0;
				}
				return *this;
			}

			operator float() const
			{
				return m_last_avg;
			}

		private:

			T m_sum;
			size_t m_avg;
			size_t m_count;
			float m_last_avg;
			T m_local_min;
			T m_local_max;
		};
	}
}

#endif /* _PAF_COMMON_AVERAGED_VALUE_H */
