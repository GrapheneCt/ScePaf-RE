/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_CHAR_ENCODING_H
#define _VDSUITE_USER_PAF_COMMON_CHAR_ENCODING_H

#include <stdint.h>
#include <paf/std/string>

namespace paf {
	namespace common {

		extern int32_t Utf16ToUtf8(const wchar_t *utf16_str, string *utf8Str);
		extern int32_t Utf16ToUtf8(const wchar_t *utf16_str, string *utf8Str, int32_t flags);

		extern int32_t Utf16ToUtf8(wstring const& utf16Str, string *utf8Str);
		extern int32_t Utf16ToUtf8(wstring const& utf16Str, string *utf8Str, int32_t flags);

		extern int32_t Utf8ToUtf16(const char *utf8_str, wstring *utf16Str);
		extern int32_t Utf8ToUtf16(const char *utf8_str, wstring *utf16Str, int32_t flags);

		extern int32_t Utf8ToUtf16(string const& utf8Str, wstring *utf16Str);
		extern int32_t Utf8ToUtf16(string const& utf8Str, wstring *utf16Str, int32_t flags);
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_CHAR_ENCODING_H */
