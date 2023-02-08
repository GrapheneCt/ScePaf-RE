#ifndef _VDSUITE_USER_PAF_STDCXX_VECTOR_H
#define _VDSUITE_USER_PAF_STDCXX_VECTOR_H

#include <vector>

namespace paf {
	template<class _Ty,
		class _Alloc = paf::allocator<_Ty> >
		class vector : public std::vector<_Ty, _Alloc>
	{

	};
}

#endif