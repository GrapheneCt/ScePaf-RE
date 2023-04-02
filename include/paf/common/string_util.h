/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_STRING_UTIL_H
#define _VDSUITE_USER_PAF_COMMON_STRING_UTIL_H

#include <stdint.h>
#include <stddef.h>
#include <paf/std/string>
#include <paf/std/list>
#include <paf/std/map>
#include <paf/common/char_encoding.h>

namespace paf {
	namespace common {

		class String
		{
		public:

			String();

			String(const char *str);

			String(const wchar_t *str);

			String(string const& src);

			String(wstring const& src);

			~String();

			SceVoid Split(char delimiter);

			SceVoid Split(string const& delimiter);

			SceVoid SetFormattedString(char const* format, ...);

			SceVoid SetFormattedString(wchar_t const* format, ...);

			String& operator+=(String const& rhs);

			String& operator+(String const& rhs);

			bool operator==(String const& s);

			bool operator!=(String const& s);

			wstring GetWString() const;

			string GetString() const;

		private:

			string m_string;
			wstring m_wstring;
		};

		namespace string_util {

			extern string ToString(const void *x, size_t size);

			void ToString(string& str, wstring const& wstr)
			{
				Utf16ToUtf8(wstr, &str);
			}

			string ToString(wstring const& wstr)
			{
				string str;
				Utf16ToUtf8(wstr, &str);
				return str;
			}

			void ToWString(wstring& wstr, string const& str)
			{
				Utf8ToUtf16(str, &wstr);
			}

			wstring ToWString(string const& str)
			{
				wstring wstr;
				Utf8ToUtf16(str, &wstr);
				return wstr;
			}

			extern void tokenize(token_list_t& tokens, string const& src, size_t pos, char delim);

			extern void mapping(token_map_t& map, string const& src, size_t pos, char token_delim, char key_delim);

			extern void dissolve(token_list_t& tokens, string const& src, size_t pos, char delim, char term);
		}
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_STRING_UTIL_H */
