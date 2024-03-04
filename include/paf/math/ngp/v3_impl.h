/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_V3_IMPL_H
#define _VDSUITE_USER_PAF_MATH_WIN32_V3_IMPL_H

#include <vectormath.h>
#include <paf/math/math.h>
#include <paf/math/ngp/v3.h>
#include <paf/math/ngp/v1.h>
#include <paf/math/ngp/v2.h>
#include <paf/math/ngp/v4.h>

namespace paf {
	namespace math {

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::_000()
		{
			return v3(0.0f, 0.0f, 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::_001()
		{
			return v3(0.0f, 0.0f, 1.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3::v3(sce::Vectormath::Simd::Aos::Vector3 value) : _impl(value)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v3::v3(float value) : _impl(value)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v3::v3(float xvalue, float yvalue, float zvalue) : _impl(xvalue, yvalue, zvalue)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v3::v3()
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE void v3::set_x(float value)
		{
			_impl.setX(value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v3::set_x(v1 value)
		{
			_impl.setX(value.getImpl());
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v3::set_y(float value)
		{
			_impl.setY(value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v3::set_y(v1 value)
		{
			_impl.setY(value.getImpl());
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v3::set_z(float value)
		{
			_impl.setZ(value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v3::set_z(v1 value)
		{
			_impl.setZ(value.getImpl());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3& v3::operator/=(float value)
		{
			_impl /= value;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3& v3::operator*=(float value)
		{
			_impl *= value;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::sce_paf_abs() const
		{
			return v3(sce::Vectormath::Simd::Aos::absPerElem(_impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::x(v1 value) const
		{
			return v3(sce::Vectormath::Simd::Aos::Vector3(value.getImpl(), _impl.getY(), _impl.getZ()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v3::x() const
		{
			return v1(_impl.getX());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::y(v1 value) const
		{
			return v3(sce::Vectormath::Simd::Aos::Vector3(_impl.getX(), value.getImpl(), _impl.getZ()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v3::y() const
		{
			return v1(_impl.getY());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v3::z() const
		{
			return v1(_impl.getZ());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v3::xy() const
		{
			return v2(_impl.getXY());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::cos() const
		{
			return v3(sce::Vectormath::Simd::cosf(_impl.getX()), sce::Vectormath::Simd::cosf(_impl.getY()), sce::Vectormath::Simd::cosf(_impl.getZ()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::sin() const
		{
			return v3(sce::Vectormath::Simd::sinf(_impl.getX()), sce::Vectormath::Simd::sinf(_impl.getY()), sce::Vectormath::Simd::sinf(_impl.getZ()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v3::dot(v3 other) const
		{
			return v1(sce::Vectormath::Simd::Aos::dot(_impl, other._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v3::len() const
		{
			return v1(sce::Vectormath::Simd::Aos::length(_impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::min(v3 other) const
		{
			return v3(sce::Vectormath::Simd::Aos::minPerElem(_impl, other._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::max(v3 other) const
		{
			return v3(sce::Vectormath::Simd::Aos::maxPerElem(_impl, other._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::unit() const
		{
			return *this * len().rcp();
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v3::xyz0() const
		{
			return v4(_impl.getX(), _impl.getY(), _impl.getZ(), 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v3::xyz1() const
		{
			return v4(_impl.getX(), _impl.getY(), _impl.getZ(), 1.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v3::xyzw(v1 value) const
		{
			return v4((float)_impl.getX(), (float)_impl.getY(), (float)_impl.getZ(), (float)value.getImpl());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::cross(v3 other) const
		{
			return v3(sce::Vectormath::Simd::Aos::cross(_impl, other._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::insert_x(float value) const
		{
			sce::Vectormath::Simd::Aos::Vector3 ret = _impl;
			ret.setX(value);
			return ret;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::insert_y(float value) const
		{
			sce::Vectormath::Simd::Aos::Vector3 ret = _impl;
			ret.setY(value);
			return ret;
		}

		SCE_VECTORMATH_ALWAYS_INLINE float v3::extract_x() const
		{
			return _impl.getX();
		}

		SCE_VECTORMATH_ALWAYS_INLINE float v3::extract_y() const
		{
			return _impl.getY();
		}

		SCE_VECTORMATH_ALWAYS_INLINE float v3::extract_z() const
		{
			return _impl.getZ();
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::operator/(float value) const
		{
			return v3(_impl / value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::operator/(v3 rhs) const
		{
			return v3(sce::Vectormath::Simd::Aos::divPerElem(_impl, rhs._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::operator-(v3 rhs) const
		{
			return v3(_impl - rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::operator*(float value) const
		{
			return v3(_impl * value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::operator*(v3 rhs) const
		{
			return v3(sce::Vectormath::Simd::Aos::mulPerElem(_impl, rhs._impl));
		}

		template<typename T>
		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::operator*(T value) const
		{
			T::vector_is_1D();
			return v3(_impl * value.f());
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v3::operator!=(v3 rhs) const
		{
			if ((_impl.getX() != rhs._impl.getX()) || (_impl.getY() != rhs._impl.getY()) || (_impl.getZ() != rhs._impl.getZ()))
			{
				return true;
			}
			return false;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::operator-() const
		{
			return v3(0.0f - _impl.getX(), 0.0f - _impl.getY(), 0.0f - _impl.getZ());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v3::operator+(v3 rhs) const
		{
			return v3(_impl + rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE sce::Vectormath::Simd::Aos::Vector3& v3::getImpl()
		{
			return _impl;
		}
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_V3_IMPL_H */ 