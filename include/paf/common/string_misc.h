/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_STRING_MISC_H
#define _VDSUITE_USER_PAF_COMMON_STRING_MISC_H

#include <stddef.h>
#include <stdint.h>
#include <paf/std/string>
#include <paf/std/stdio.h>

namespace paf {
	namespace common {

		extern string Subst(string const& text, string const& from, string const& to, size_t pos);

		extern bool Rmatch(string const& path, string const& str);

		extern string FormatBytesize(size_t bytesize, int32_t padding);

		extern string FormatString(char const* format, ...);

		template <typename T>
		extern T FromString(char const* buf, size_t size);

		template <typename T>
		static inline T FromString(string const& value)
		{
			return FromString<T>(value.c_str(), value.length());
		}

		extern string ToString(float value, bool c_style, bool sane_fraction, bool paf_print_workaround);

		static inline string ToString(bool value)
		{
			if (value)
			{
				return "true";
			}
			return "false";
		}

		static inline string ToString(float value)
		{
			return ToString(value, false, true, true);
		}

		static inline string ToString(int32_t value)
		{
			char buf[64];
			sce_paf_snprintf(buf, sizeof(buf), "%i", value);
			return buf;
		}

		static inline string ToString(uint32_t value)
		{
			char buf[64];
			sce_paf_snprintf(buf, sizeof(buf), "%u", value);
			return buf;
		}

		static inline string ToString(const void *value)
		{
			return FormatString("0x%p", value);
		}

		/**
		 * Possible opt:
		 * "P" - path
		 * "F" - filename
		 * "E" - extensions
		 * Possible opt combinations:
		 * "PFE", "PF", "FE"
		 */
		extern string StripFilename(string const& path, string const& opt);

		static inline int32_t digit_to_int(char c)
		{
			if ((c < '0') || ('9' < c))
			{
				return 0;
			}
			return c - 0x30;
		}

		static void eat_trailing_fraction_zeros(char *buf)
		{
			char chara = *buf;
			int32_t p1 = -1;
			int32_t p2 = -1;
			int32_t i = 0;
			while (chara != '\0')
			{
				if (buf[i] == '.')
				{
					p1 = i;
				}
				if (buf[i] == 'e')
				{
					p2 = i;
				}
				i++;
				chara = buf[i];
			}
			if (((p2 == -1) && (1 < i)) && (p1 != -1))
			{
				while ((i--, p1 < i && (buf[i] == '0')))
				{
					buf[i] = '\0';
				}
				if ((p1 == i) && (p1 != 0))
				{
					buf[i] = '\0';
				}
			}
		}
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_STRING_MISC_H */
