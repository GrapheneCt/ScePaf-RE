#ifndef _VDSUITE_USER_PAF_STDCXX_MAP_H
#define _VDSUITE_USER_PAF_STDCXX_MAP_H

#include <map>

namespace paf {
	template<class _Kty,
		class _Ty,
		class _Pr = paf::less<_Kty>,
		class _Alloc = paf::allocator<paf::pair<const _Kty, _Ty>>>
		class map : public std::map<_Kty, _Ty, _Pr, _Alloc>
	{

	};
}

#endif