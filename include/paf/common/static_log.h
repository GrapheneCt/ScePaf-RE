/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_STATIC_LOG_H
#define _PAF_COMMON_STATIC_LOG_H

#include <stdint.h>
#include <stddef.h>
#include <paf/common/halt_assert.h>
#include <paf/math/math.h>
#include <paf/std/stdc.h>

namespace paf {
	namespace common {

		class StaticLog
		{
		public:

			template <typename T>
			StaticLog(T& r) : m_pos(0), m_size(0)
			{
				m_buffer = r.front();
				m_capacity = r.size() - 1;
				SCE_PAF_ASSERT(" *** error ", NULL, m_capacity != 0);
				clear('\0');
			}

			~StaticLog()
			{

			}

			size_t col() const
			{
				size_t ncol = 0;
				for (int32_t cpos = m_pos; (-1 < cpos) && (m_buffer[cpos] != '\n'); cpos--)
				{
					ncol++;
				}
				return ncol;
			}

			char *c_str() const
			{
				m_buffer[m_capacity] = '\0';
				return m_buffer;
			}

			void nchars(char c, size_t n)
			{
				size_t i = 0;
				while ((i < n && (m_pos < m_capacity)))
				{
					m_buffer[m_pos] = c;
					i++;
					m_pos++;
				}
			}

			void pad(char c, int32_t column)
			{
				nchars(c, math::max<int32_t>(0, column - col()));
			}

			void clear(char c)
			{
				size_t i = 0;
				if (m_capacity != 0)
				{
					do
					{
						m_buffer[i] = c;
						i++;
					} while (i != m_capacity);
				}
				m_pos = 0;
				m_size = 0;
				m_tmp[0] = '\0';
				m_buffer[m_capacity] = '\0';
			}

			StaticLog& operator<<(const char *value)
			{
				int32_t i = 0;
				while ((value[i] != '\0' && (m_pos < m_capacity)))
				{
					m_buffer[m_pos] = value[i];
					i++;
					m_pos++;
				}
				return *this;
			}

			StaticLog& operator<<(int32_t value)
			{
				sce_paf_snprintf(m_tmp, sizeof(m_tmp), "%i", value);
				*this << m_tmp;
				return *this;
			}

			StaticLog& operator<<(uint32_t value)
			{
				sce_paf_snprintf(m_tmp, sizeof(m_tmp), "%u", value);
				*this << m_tmp;
				return *this;
			}

			StaticLog& operator<<(float value)
			{
				sce_paf_snprintf(m_tmp, sizeof(m_tmp), "%f", value);
				*this << m_tmp;
				return *this;
			}

			StaticLog& operator<<(const void *value)
			{
				sce_paf_snprintf(m_tmp, sizeof(m_tmp), "0x%p", value);
				*this << m_tmp;
				return *this;
			}

			StaticLog& operator<<(string const& value)
			{
				*this << value.c_str();
				return *this;
			}

		private:

			size_t m_pos;
			size_t m_size;
			char m_tmp[128];
			char *m_buffer;
			size_t m_capacity;
		};
	}
}

#endif /* _PAF_COMMON_STATIC_LOG_H */
