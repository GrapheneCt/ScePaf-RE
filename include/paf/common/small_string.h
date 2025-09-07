/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_SMALL_STRING_H
#define _PAF_COMMON_SMALL_STRING_H

#include <stdint.h>
#include <paf/std/stdc.h>
#include <paf/math/math.h>

namespace paf {
	namespace common {

		class String16
		{
		public:

			String16()
			{

			}

			String16(String16 const& src)
			{
				m_data[0] = src.m_data[0];
				m_data[1] = src.m_data[1];
				m_data[2] = src.m_data[2];
				m_data[3] = src.m_data[3];
			}

			String16(const char *src)
			{
				copy_from(src);
			}

			~String16()
			{

			}

			void copy_from(const char *src)
			{
				clear();
				uint32_t minlen = math::min<uint32_t>(sce_paf_strlen(src), 0xF);
				uint32_t i = 0;
				if (minlen != 0)
				{
					do
					{
						*(char *)((uintptr_t)m_data + i) = src[i];
						i++;
					} while (i < minlen);
				}
				*(char *)((uintptr_t)m_data + i) = 0;
				return;
			}

			void clear()
			{
				m_data[0] = 0;
				m_data[1] = 0;
				m_data[2] = 0;
				m_data[3] = 0;
			}

			char *c_str() const
			{
				return (char *)m_data;
			}

		private:

			uint32_t m_data[4];
		};
	}
}

#endif /* _PAF_COMMON_SMALL_STRING_H */
