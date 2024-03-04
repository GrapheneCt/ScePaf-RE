/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_STATIC_LOG_H
#define _VDSUITE_USER_PAF_COMMON_STATIC_LOG_H

#include <stdint.h>
#include <stddef.h>
#include <paf/common/halt_assert.h>
#include <paf/math/math.h>
#include <paf/std/stdio.h>

namespace paf {
	namespace common {

		class StaticLog
		{
		public:

			template <typename T>
			StaticLog(T& r) : _pos(0), _size(0)
			{
				_buffer = r.front();
				_capacity = r.size() - 1;
				if (_capacity == 0)
				{
					paf::common_internal::on_error();
				}
				clear('\0');
			}

			~StaticLog()
			{

			}

			size_t col() const
			{
				size_t ncol = 0;
				for (int32_t cpos = _pos; (-1 < cpos) && (_buffer[cpos] != '\n'); cpos--)
				{
					ncol++;
				}
				return ncol;
			}

			char *c_str() const
			{
				_buffer[_capacity] = '\0';
				return _buffer;
			}

			void nchars(char c, size_t n)
			{
				size_t i = 0;
				while ((i < n && (_pos < _capacity)))
				{
					_buffer[_pos] = c;
					i++;
					_pos++;
				}
			}

			void pad(char c, int32_t column)
			{
				nchars(c, math::max<int32_t>(0, column - col()));
			}

			void clear(char c)
			{
				size_t i = 0;
				if (_capacity != 0)
				{
					do
					{
						_buffer[i] = c;
						i++;
					} while (i != _capacity);
				}
				_pos = 0;
				_size = 0;
				_tmp[0] = '\0';
				_buffer[_capacity] = '\0';
			}

			StaticLog& operator<<(const char *value)
			{
				int32_t i = 0;
				while ((value[i] != '\0' && (_pos < _capacity)))
				{
					_buffer[_pos] = value[i];
					i++;
					_pos++;
				}
				return *this;
			}

			StaticLog& operator<<(int32_t value)
			{
				sce_paf_snprintf(_tmp, sizeof(_tmp), "%i", value);
				*this << _tmp;
				return *this;
			}

			StaticLog& operator<<(uint32_t value)
			{
				sce_paf_snprintf(_tmp, sizeof(_tmp), "%u", value);
				*this << _tmp;
				return *this;
			}

			StaticLog& operator<<(float value)
			{
				sce_paf_snprintf(_tmp, sizeof(_tmp), "%f", value);
				*this << _tmp;
				return *this;
			}

			StaticLog& operator<<(const void *value)
			{
				sce_paf_snprintf(_tmp, sizeof(_tmp), "0x%p", value);
				*this << _tmp;
				return *this;
			}

			StaticLog& operator<<(string const& value)
			{
				*this << value.c_str();
				return *this;
			}

		private:

			size_t _pos;
			size_t _size;
			char _tmp[128];
			char *_buffer;
			size_t _capacity;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_STATIC_LOG_H */
