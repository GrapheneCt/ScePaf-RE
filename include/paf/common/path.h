/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_PATH_H
#define _VDSUITE_USER_PAF_COMMON_PATH_H

#include <paf/std/string>

namespace paf {
	namespace common {
		namespace path {

			extern void Split(string const& path, string& base, string& file);

			extern void SplitExt(string const& path, string& filepath, string& ext);

			extern string Join(string const& filepath, string const& ext);
		}
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_STRING_UTIL_H */
