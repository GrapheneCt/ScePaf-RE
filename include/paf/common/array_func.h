/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_ARRAY_FUNC_H
#define _VDSUITE_USER_PAF_COMMON_ARRAY_FUNC_H

#include <stdint.h>

namespace paf {
	namespace common {

		template <typename T>
		class ArrayFunc
		{
		public:

			ArrayFunc(T* a_data, size_t a_capacity, size_t a_size)
			{
				assign(a_data, a_capacity, a_size);
			}

			~ArrayFunc()
			{

			}

			assign(T* a_data, size_t a_capacity, size_t a_size)
			{
				m_buffer = a_data;
				m_size = a_capacity;
				m_capacity = a_size;
			}

			T* at(size_t index)
			{
				return m_buffer + index;
			}

			T* front()
			{
				return m_buffer;
			}

			void push_back(T value)
			{
				size_t old_size = m_size;
				m_size++;
				T* to_fill = m_buffer + old_size;
				*to_fill = value;
			}

			size_t size() const
			{
				return m_size;
			}

		private:

			T* m_buffer;
			size_t m_size;
			size_t m_capacity;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_ARRAY_FUNC_H */
