/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_STATIC_STACK_H
#define _PAF_COMMON_STATIC_STACK_H

#include <stddef.h>
#include <paf/common/halt_assert.h>

namespace paf {
	namespace common {

		template <typename T, size_t CAPACITY>
		class StaticStack
		{
		public:

			StaticStack(T default_value)
			{
				m_stack[0] = default_value;
			}

			bool empty() const
			{
				return (m_size == 0);
			}

			void pop()
			{
				if (1 < m_size)
				{
					m_size--;
				}
			}

			void push()
			{
				if (m_size < CAPACITY)
				{
					m_stack[m_size] = *top();
					m_size++;
				}
			}

			T& top()
			{
				return m_stack + (m_size - 1);
			}

			T& top() const
			{
				return m_stack + (m_size - 1);
			}

		private:

			size_t m_size;
			T m_stack[CAPACITY];
		};
	}
}

#endif /* _PAF_COMMON_STATIC_STACK_H */
