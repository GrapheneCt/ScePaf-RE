/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_SMALL_STRING_H
#define _VDSUITE_USER_PAF_COMMON_SMALL_STRING_H

#include <stdint.h>
#include <paf/std/string.h>
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
				_data[0] = src._data[0];
				_data[1] = src._data[1];
				_data[2] = src._data[2];
				_data[3] = src._data[3];
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
				int32_t i = 0;
				if (minlen != 0)
				{
					do {
						*(char *)((int)_data + i) = src[i];
						i++;
					} while (i < minlen);
				}
				*(char *)((int)_data + i) = 0;
				return;
			}

			void clear()
			{
				_data[0] = 0;
				_data[1] = 0;
				_data[2] = 0;
				_data[3] = 0;
			}

			char *c_str() const
			{
				return (char *)_data;
			}

		private:

			uint32_t _data[4];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_SMALL_STRING_H */
