#ifndef _VDSUITE_USER_PAF_STDCXX_STD_OVERRIDE_H
#define _VDSUITE_USER_PAF_STDCXX_STD_OVERRIDE_H

namespace std {
	static void _Xlength_error(char const*)
	{

	}

	static void _Xout_of_range(char const*)
	{

	}

	static void* memmove(void* dest, const void* src, size_t count)
	{
		return sce_paf_memmove(dest, src, count);
	}
}

#endif