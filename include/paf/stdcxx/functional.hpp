#ifndef _VDSUITE_USER_PAF_STDCXX_FUNCTIONAL_H
#define _VDSUITE_USER_PAF_STDCXX_FUNCTIONAL_H

#include <functional>

namespace paf {
	template<class _Ty = void>
	struct less : public std::less<_Ty>
	{

	};
}

#endif