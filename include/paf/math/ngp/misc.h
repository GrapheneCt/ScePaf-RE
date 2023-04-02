/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_MISC_H
#define _VDSUITE_USER_PAF_MATH_WIN32_MISC_H

#include <stdint.h>
#include <paf/std/math.h>
#include <paf/common/halt_assert.h>

namespace paf {
	namespace math {

		template<typename T>
		T min(const T& a, const T& b)
		{
			if (b <= a)
			{
				return b;
			}
			return a;
		}

		template<typename T>
		T max(const T& a, const T& b)
		{
			if (b <= a)
			{
				return a;
			}
			return b;
		}

		template<typename T>
		T clamp(const T& x, const T& mi, const T& ma)
		{
			T ret;
			ret = max<T>(x, mi);
			ret = min<T>(ret, ma);
			return ret;
		}

		float cos(float x)
		{
			return sce_paf_cosf(x);
		}

		float sin(float x)
		{
			return sce_paf_sinf(x);
		}

		float safe_atan2f(float x, float y)
		{
			return sce_paf_atan2f(x, y);
		}

		bool is_pow2(int i)
		{
			return ((i | 0x80000000U) & i - 1U) == 0;
		}

		float rand1(uint32_t *seed)
		{
			if (*seed == 0)
			{
				paf::common_internal::on_error();
			}
			*seed = *seed * 0x41a7;
			return (float)(*seed >> 9 | 0x40000000) - 3.0f;
		}

		float rand0(uint32_t *seed)
		{
			return (rand1(seed) + 1.0f) * 0.5f;
		}

		const float HALFPIE = 1.5708f;
		const float TWICEPIE = 6.28319f;
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_MISC_H */ 