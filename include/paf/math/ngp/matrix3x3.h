/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_MATRIX3X3_H
#define _VDSUITE_USER_PAF_MATH_WIN32_MATRIX3X3_H

#include <vectormath.h>
#include <paf/math/ngp/v3.h>

namespace paf {
	namespace math {

		class matrix3x3
		{
		public:

			SCE_VECTORMATH_ALWAYS_INLINE matrix3x3()
			{

			}

			SCE_VECTORMATH_ALWAYS_INLINE matrix3x3(sce::Vectormath::Simd::Aos::Matrix3 value) : _impl(value)
			{

			}

			SCE_VECTORMATH_ALWAYS_INLINE ~matrix3x3()
			{

			}

			SCE_VECTORMATH_ALWAYS_INLINE void set_x(v3 value)
			{
				_impl.setCol0(value.getImpl());
			}

			SCE_VECTORMATH_ALWAYS_INLINE void set_y(v3 value)
			{
				_impl.setCol1(value.getImpl());
			}

			SCE_VECTORMATH_ALWAYS_INLINE void set_z(v3 value)
			{
				_impl.setCol2(value.getImpl());
			}

			SCE_VECTORMATH_ALWAYS_INLINE matrix3x3 operator*(matrix3x3 value) const
			{
				return matrix3x3(_impl * value._impl);
			}

		private:

			sce::Vectormath::Simd::Aos::Matrix3 _impl;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_MATRIX3X3_H */ 