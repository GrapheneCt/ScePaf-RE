/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_V2_IMPL_H
#define _VDSUITE_USER_PAF_MATH_WIN32_V2_IMPL_H

#include <vectormath.h>
#include <paf/math/math.h>
#include <paf/math/ngp/v2.h>
#include <paf/math/ngp/v1.h>
#include <paf/math/ngp/v3.h>
#include <paf/math/ngp/v4.h>

namespace paf {
	namespace math {

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::_00()
		{
			return v2i(0, 0);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::_01()
		{
			return v2i(0, 1);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::_10()
		{
			return v2i(1, 0);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::_11()
		{
			return v2i(1, 1);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i::v2i(int a_x, int a_y)
		{
			_x = a_x;
			_y = a_y;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i::v2i()
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE void v2i::set_x(int value)
		{
			_x = value;
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v2i::set_y(int value)
		{
			_y = value;
		}

		SCE_VECTORMATH_ALWAYS_INLINE int v2i::x() const
		{
			return _x;
		}

		SCE_VECTORMATH_ALWAYS_INLINE int v2i::y() const
		{
			return _y;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i& v2i::operator+=(v2i rhs)
		{
			_x += rhs._x;
			_y += rhs._y;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i& v2i::operator-=(v2i rhs)
		{
			_x -= rhs._x;
			_y -= rhs._y;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i& v2i::operator*=(v2i rhs)
		{
			_x *= rhs._x;
			_y *= rhs._y;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i& v2i::operator*=(int value)
		{
			_x *= value;
			_y *= value;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i& v2i::operator/=(int value)
		{
			_x /= value;
			_y /= value;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v2i::operator==(const v2i& rhs) const
		{
			if ((_x == rhs._x) && (_y == rhs._y))
			{
				return true;
			}
			return false;
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v2i::operator!=(const v2i& rhs) const
		{
			return !(*this == rhs);
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v2i::operator<(const v2i& rhs) const
		{
			return (_x < rhs._x) || ((_x == rhs._x) && (_y < rhs._y));
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v2i::operator>(const v2i& rhs) const
		{
			return (_x > rhs._x) || ((_x == rhs._x) && (_y > rhs._y));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::operator-(const v2i& rhs) const
		{
			return v2i(_x - rhs._x, _y - rhs._y);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::operator+(const v2i& rhs) const
		{
			return v2i(_x + rhs._x, _y + rhs._y);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::operator>>(const v2i& rhs) const
		{
			return v2i(_x >> (rhs._y & 0xff), _y >> (rhs._y & 0xff));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::operator*(const v2i& rhs) const
		{
			return v2i(_x * rhs._x, _y * rhs._y);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::operator*(int value) const
		{
			return v2i(_x * value, _y * value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::operator/(int value) const
		{
			return v2i(_x / value, _y / value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::min(v2i other) const
		{
			return v2i((_x < other._x) ? _x : other._x, (_y < other._y) ? _y : other._y);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2i v2i::max(v2i other) const
		{
			return v2i((_x > other._x) ? _x : other._x, (_y > other._y) ? _y : other._y);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::_00()
		{
			return v2(0.0f, 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::_01()
		{
			return v2(0.0f, 1.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::_10()
		{
			return v2(1.0f, 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::_11()
		{
			return v2(1.0f, 1.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::Rotation(float a_angle)
		{
			sce::Vectormath::Simd::floatInVec sc(a_angle);
			sce::Vectormath::Simd::Aos::Vector2 vec(0.0f, 0.0f);
			return v2(sce::Vectormath::Simd::Aos::rotate(sc, vec));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2::v2(sce::Vectormath::Simd::Aos::Vector2 value) : _impl(value)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v2::v2(float value) : _impl(value)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v2::v2(float xvalue, float yvalue) : _impl(xvalue, yvalue)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v2::v2(v2i value) : _impl((float)value.x(), (float)value.y())
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v2::v2()
		{

		}

		template<typename T>
		SCE_VECTORMATH_ALWAYS_INLINE v2::v2(T xvalue, T yvalue)
		{
			T::vector_is_1D();
			_impl.setX(xvalue.f());
			_impl.setY(yvalue.f());
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v2::set_x(float value)
		{
			_impl.setX(value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v2::set_y(float value)
		{
			_impl.setY(value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v2::set_x(v1 value)
		{
			_impl.setX(value.getImpl());
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v2::set_y(v1 value)
		{
			_impl.setY(value.getImpl());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2& v2::operator/=(float value)
		{
			_impl /= value;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2& v2::operator-=(v2 rhs)
		{
			_impl -= rhs._impl;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2& v2::operator*=(v2 rhs)
		{
			_impl = sce::Vectormath::Simd::Aos::mulPerElem(_impl, rhs._impl);
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2& v2::operator+=(v2 rhs)
		{
			_impl += rhs._impl;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::sce_paf_abs() const
		{
			return v2(sce::Vectormath::Simd::Aos::absPerElem(_impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::x(v1 value) const
		{
			return v2(sce::Vectormath::Simd::Aos::Vector2(value.getImpl(), _impl.getY()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v2::x() const
		{
			return v1(_impl.getX());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::y(v1 value) const
		{
			return v2(sce::Vectormath::Simd::Aos::Vector2(_impl.getX(), value.getImpl()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v2::y() const
		{
			return v1(_impl.getY());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::xx() const
		{
			return v2(_impl.getX());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::yx() const
		{
			return v2(sce::Vectormath::Simd::Aos::Vector2(_impl.getY(), _impl.getX()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::yy() const
		{
			return v2(_impl.getY());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v2::dot(v2 other) const
		{
			return v1(sce::Vectormath::Simd::Aos::dot(_impl, other._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v2::len() const
		{
			return v1(sce::Vectormath::Simd::Aos::length(_impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::min(v2 other) const
		{
			return v2(sce::Vectormath::Simd::Aos::minPerElem(_impl, other._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::max(v2 other) const
		{
			return v2(sce::Vectormath::Simd::Aos::maxPerElem(_impl, other._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v2::xy0() const
		{
			return v3(_impl.getX(), _impl.getY(), 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v2::xy1() const
		{
			return v3(_impl.getX(), _impl.getY(), 1.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::perp() const
		{
			return v2(sce::Vectormath::Simd::Aos::perp(_impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::unit() const
		{
			return *this * len().rcp();
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v2::xy00() const
		{
			return v4(_impl.getX(), _impl.getY(), 0.0f, 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v2::xy01() const
		{
			return v4(_impl.getX(), _impl.getY(), 0.0f, 1.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::clamp(v2 min, v2 max) const
		{
			return v2(sce::Vectormath::Simd::Aos::clampPerElem(_impl, min._impl, max._impl));
		}

		/*
		SCE_VECTORMATH_ALWAYS_INLINE bool v2::equal(float epsilon) const
		{
			
		}
		*/

		SCE_VECTORMATH_ALWAYS_INLINE bool v2::isNull() const
		{
			return sce::Vectormath::Simd::Aos::allElemEqual(_impl, sce::Vectormath::Simd::Aos::Vector2(0.0f));
		}

		SCE_VECTORMATH_ALWAYS_INLINE float v2::extract_x() const
		{
			return _impl.getX();
		}

		SCE_VECTORMATH_ALWAYS_INLINE float v2::extract_y() const
		{
			return _impl.getY();
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::operator/(float value) const
		{
			return v2(_impl / value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::operator/(v2 rhs) const
		{
			return v2(sce::Vectormath::Simd::Aos::divPerElem(_impl, rhs._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v2::operator==(v2 rhs) const
		{
			return sce::Vectormath::Simd::Aos::allElemEqual(_impl, rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::operator-(float value) const
		{
			return v2(_impl - sce::Vectormath::Simd::Aos::Vector2(value));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::operator-(v2 rhs) const
		{
			return v2(_impl - rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::operator*(float value) const
		{
			return v2(_impl * value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::operator*(v2 rhs) const
		{
			return v2(sce::Vectormath::Simd::Aos::mulPerElem(_impl, rhs._impl));
		}

		template<typename T>
		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::operator*(T value) const
		{
			T::vector_is_1D();
			return v2(_impl * value.f());
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v2::operator!=(v2 rhs) const
		{
			if ((_impl.getX() != rhs._impl.getX()) || (_impl.getY() != rhs._impl.getY()))
			{
				return true;
			}
			return false;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::operator-() const
		{
			return v2(
				(float)(0.0f - _impl.getX()),
				(float)(0.0f - _impl.getY()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v2::operator+(v2 rhs) const
		{
			return v2(_impl + rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE sce::Vectormath::Simd::Aos::Vector2& v2::getImpl()
		{
			return _impl;
		}
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_V2_IMPL_H */ 