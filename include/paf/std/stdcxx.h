/*
	ScePaf-RE Project
*/

#ifndef _PAF_STD_STDCXX_H
#define _PAF_STD_STDCXX_H

#if defined(__SNC__) || defined(__vita__)

#include <paf/std/ngp/stdcxx_bridge>
#include <paf/std/ngp/algorithm>
#include <paf/std/ngp/functional>
#include <paf/std/ngp/iosfwd>
#include <paf/std/ngp/memory>
#include <paf/std/ngp/list>
#include <paf/std/ngp/utility>
#if defined(__SNC__)
#include <paf/std/ngp/xtree> ///< Needed for paf::map implementation with SNC
#endif
#include <paf/std/ngp/map>
#include <paf/std/ngp/vector>
#include <paf/std/ngp/string>
#include <paf/std/ngp/stdc>

#elif defined(_WIN32)

#include <paf/std/generic/memory>
#include <list>
#include <map>
#include <vector>
#include <string>
#include <paf/std/generic/stdc>
#include <paf/std/generic/stdcxx_bridge>

#else
#error Current target platform is not supported or no target platform defined
#endif

#endif /* _PAF_STD_STDCXX_H */
