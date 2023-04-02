/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_ENUM_FLAG_H
#define _VDSUITE_USER_PAF_COMMON_ENUM_FLAG_H

#include <stdint.h>

namespace paf {
	namespace common {

		template <typename T>
		class EnumFlag
		{
		public:

			EnumFlag() : m_mask(0)
			{

			}

			~EnumFlag()
			{

			}

			EnumFlag<T>& operator<<(T type)
			{
				m_mask |= 1 << (type & 0xFF);
				return *this;
			}

			EnumFlag<T>& operator>>(T type)
			{
				m_mask &= ~(1 << (type & 0xFF));
				return *this;
			}

			bool is_set(T type) const
			{
				return (m_mask & 1 << (type & 0xFF)) != 0;
			}

		private:

			uint32_t m_mask;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_ENUM_FLAG_H */
