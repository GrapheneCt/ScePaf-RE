/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_STATIC_STACK_H
#define _VDSUITE_USER_PAF_COMMON_STATIC_STACK_H

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
				_stack[0] = default_value;
			}

			bool empty() const
			{
				return (_size == 0);
			}

			void pop()
			{
				if (1 < _size)
				{
					_size--;
				}
			}

			void push()
			{
				if (_size < CAPACITY)
				{
					_stack[_size] = *top();
					_size++;
				}
			}

			T& top()
			{
				return _stack + (_size - 1);
			}

			T& top() const
			{
				return _stack + (_size - 1);
			}

		private:

			size_t _size;
			T _stack[CAPACITY];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_STATIC_STACK_H */
