/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_PATH_H
#define _PAF_COMMON_PATH_H

#include <paf/std/stdcxx.h>

namespace paf {
	namespace common {
		namespace path {

			extern void Split(string const& path, string& base, string& file);

			extern void SplitExt(string const& path, string& filepath, string& ext);

			extern string Join(string const& filepath, string const& ext);
		}
	}
}

#endif /* _PAF_COMMON_PATH_H */
