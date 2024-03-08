/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_V1_IMPL_H
#define _VDSUITE_USER_PAF_MATH_WIN32_V1_IMPL_H

#include <vectormath.h>
#include <paf/std/math.h>
#include <paf/math/math.h>
#include <paf/math/ngp/v1.h>
#include <paf/math/ngp/v4.h>

namespace paf {
	namespace math {

		SCE_VECTORMATH_ALWAYS_INLINE void v1::vector_is_1D()
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i v1i::_0()
		{
			return v1i(0);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i v1i::_1()
		{
			return v1i(1);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i::v1i(int a_x) : _x(a_x)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i::v1i() : _x(0)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE void v1i::set_x(int value)
		{
			_x = value;
		}

		SCE_VECTORMATH_ALWAYS_INLINE int v1i::x() const
		{
			return _x;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i& v1i::operator+=(const v1i& rhs)
		{
			_x += rhs._x;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i& v1i::operator-=(const v1i& rhs)
		{
			_x -= rhs._x;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i& v1i::operator*=(const v1i& rhs)
		{
			_x *= rhs._x;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i& v1i::operator*=(int value)
		{
			_x *= value;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i& v1i::operator/=(int value)
		{
			_x /= value;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v1i::operator==(const v1i& rhs) const
		{
			return (_x == rhs._x);
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v1i::operator!=(const v1i& rhs) const
		{
			return !(*this == rhs);
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v1i::operator<(const v1i& rhs) const
		{
			return (_x < rhs._x);
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v1i::operator>(const v1i& rhs) const
		{
			return (_x > rhs._x);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i v1i::operator-(const v1i& rhs) const
		{
			return v1i(_x - rhs._x);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i v1i::operator+(const v1i& rhs) const
		{
			return v1i(_x + rhs._x);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i v1i::operator*(const v1i& rhs) const
		{
			return v1i(_x * rhs._x);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i v1i::operator*(int value) const
		{
			return v1i(_x * value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1i v1i::operator/(int value) const
		{
			return v1i(_x / value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1::v1(float value) : _impl(value)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v1::v1(sce::Vectormath::Simd::floatInVec value) : _impl(value)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v1::sce_paf_abs() const
		{
			return sce::Vectormath::Simd::fabsf(_impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE float v1::f() const
		{
			return _impl.getAsFloat();
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v1::rcp() const
		{
			return sce::Vectormath::Simd::recipf(_impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v1::acos() const
		{
			return sce::Vectormath::Simd::acosf(_impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v1::sqrt() const
		{
			return sce::Vectormath::Simd::sqrtf(_impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v1::clamp(v1 value1, v1 value2) const
		{
			return sce::Vectormath::Simd::clamp(_impl, value1._impl, value2._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v1::splat() const
		{
			return v4(_impl.getAsFloat());
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v1::isNull() const
		{
			return (_impl == 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v1::operator/(v1 rhs) const
		{
			return v1(_impl / rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v1::operator==(v1 rhs) const
		{
			return _impl == rhs._impl;
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v1::operator>=(v1 rhs) const
		{
			return (rhs._impl <= _impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v1::operator>(v1 rhs) const
		{
			return (rhs._impl < _impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v1::operator<(v1 rhs) const
		{
			return (_impl < rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v1::operator-(v1 rhs) const
		{
			return v1(_impl - rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v1::operator*(v1 rhs) const
		{
			return v1(_impl * rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v1::operator!=(v1 rhs) const
		{
			return (_impl != rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v1::operator-() const
		{
			return v1(0.0f - _impl.getAsFloat());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v1::operator+(v1 rhs)
		{
			return v1(_impl + rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v1::operator+()
		{
			return v1(_impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE sce::Vectormath::Simd::floatInVec& v1::getImpl()
		{
			return _impl;
		}
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_V1_IMPL_H */ 