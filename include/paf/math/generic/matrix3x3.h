/*
	ScePaf-RE Project
*/

#ifndef _PAF_MATH_GENERIC_MATRIX3X3_H
#define _PAF_MATH_GENERIC_MATRIX3X3_H

#include <vectormath.h>
#include <paf/math/generic/v3.h>

namespace paf {
	namespace math {

		class matrix3x3
		{
		public:

			SCE_VECTORMATH_ALWAYS_INLINE matrix3x3()
			{

			}

			SCE_VECTORMATH_ALWAYS_INLINE matrix3x3(SCE_PAF_VECTORMATH::Aos::Matrix3 value) : _impl(value)
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

			SCE_PAF_VECTORMATH::Aos::Matrix3 _impl;
		};
	}
}

#endif /* _PAF_MATH_GENERIC_MATRIX3X3_H */ 