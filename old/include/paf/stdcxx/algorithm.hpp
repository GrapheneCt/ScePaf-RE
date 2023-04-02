#ifndef _VDSUITE_USER_PAF_STDCXX_ALGORITHM_H
#define _VDSUITE_USER_PAF_STDCXX_ALGORITHM_H

#include <algorithm>

namespace paf {
	template<class _RanIt,
		class _Pr> inline
		void sort(_RanIt _First, _RanIt _Last, _Pr _Pred)
	{
		std::sort(_First, _Last, _Pred);
	};

	template<class _RanIt> inline
		void sort(_RanIt _First, _RanIt _Last)
	{
		std::sort(_First, _Last);
	}
}

#endif