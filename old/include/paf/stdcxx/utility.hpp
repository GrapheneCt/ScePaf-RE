#ifndef _VDSUITE_USER_PAF_STDCXX_UTILITY_H
#define _VDSUITE_USER_PAF_STDCXX_UTILITY_H

#include <utility>

namespace paf {
	template<class _Ty1,
		class _Ty2>
		struct pair : public std::pair<_Ty1, _Ty2>
	{

	};
}

#endif