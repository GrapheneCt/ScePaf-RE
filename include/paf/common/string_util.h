/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_STRING_UTIL_H
#define _PAF_COMMON_STRING_UTIL_H

#include <stdint.h>
#include <stddef.h>
#include <paf/std/stdcxx.h>
#include <paf/common/char_encoding.h>

namespace paf {

	typedef class paf::list<paf::string> token_list_t;

	typedef class paf::map<paf::string, paf::string> token_map_t;

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

			String& Split(char delimiter);

			String& Split(string const& delimiter);

			void SetFormattedString(char const* format, ...);

			void SetFormattedString(wchar_t const* format, ...);

			String& operator+=(String const& rhs);

			String operator+(String const& rhs);

			bool operator==(String const& s);

			bool operator!=(String const& s);

			String& operator=(string const& s)
			{
				m_wstring.clear();
				m_string = s;
				return *this;
			}

			String& operator=(wstring const& s)
			{
				m_string.clear();
				m_wstring = s;
				return *this;
			}

			wstring GetWString() const;

			string GetString() const;

		private:

			string m_string;
			wstring m_wstring;
		};

		namespace string_util {

			extern string ToString(const void *x, size_t size);

			static inline void ToString(string& str, wstring const& wstr)
			{
				Utf16ToUtf8(wstr, &str);
			}

			static inline string ToString(wstring const& wstr)
			{
				string str;
				Utf16ToUtf8(wstr, &str);
				return str;
			}

			static inline void ToWString(wstring& wstr, string const& str)
			{
				Utf8ToUtf16(str, &wstr);
			}

			static inline wstring ToWString(string const& str)
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

#endif /* _PAF_COMMON_STRING_UTIL_H */
