/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_V4_IMPL_H
#define _VDSUITE_USER_PAF_MATH_WIN32_V4_IMPL_H

#include <stdint.h>
#include <stddef.h>
#include <vectormath.h>
#include <paf/math/math.h>
#include <paf/math/ngp/v4.h>
#include <paf/math/ngp/v1.h>
#include <paf/math/ngp/v2.h>
#include <paf/math/ngp/v3.h>

namespace paf {
	namespace math {

		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_0000() { return v4i(0, 0, 0, 0); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_0001() { return v4i(0, 0, 0, 1); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_0010() { return v4i(0, 0, 1, 0); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_0011() { return v4i(0, 0, 1, 1); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_0100() { return v4i(0, 1, 0, 0); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_0101() { return v4i(0, 1, 0, 1); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_0110() { return v4i(0, 1, 1, 0); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_0111() { return v4i(0, 1, 1, 1); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_1000() { return v4i(1, 0, 0, 0); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_1001() { return v4i(1, 0, 0, 1); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_1010() { return v4i(1, 0, 1, 0); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_1011() { return v4i(1, 0, 1, 1); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_1100() { return v4i(1, 1, 0, 0); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_1101() { return v4i(1, 1, 0, 1); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_1110() { return v4i(1, 1, 1, 0); }
		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::_1111() { return v4i(1, 1, 1, 1); }

		SCE_VECTORMATH_ALWAYS_INLINE v4i::v4i(int a_x, int a_y, int a_z, int a_w) : _x(a_x), _y(a_y), _z(a_z), _w(a_w) {}
		SCE_VECTORMATH_ALWAYS_INLINE v4i::v4i() : v4i(0, 0, 0, 0) {}

		SCE_VECTORMATH_ALWAYS_INLINE void v4i::set_x(int value) { _x = value; }
		SCE_VECTORMATH_ALWAYS_INLINE void v4i::set_y(int value) { _y = value; }
		SCE_VECTORMATH_ALWAYS_INLINE void v4i::set_z(int value) { _z = value; }
		SCE_VECTORMATH_ALWAYS_INLINE void v4i::set_w(int value) { _w = value; }

		SCE_VECTORMATH_ALWAYS_INLINE int v4i::x() const { return _x; }
		SCE_VECTORMATH_ALWAYS_INLINE int v4i::y() const { return _y; }
		SCE_VECTORMATH_ALWAYS_INLINE int v4i::z() const { return _z; }
		SCE_VECTORMATH_ALWAYS_INLINE int v4i::w() const { return _w; }

		SCE_VECTORMATH_ALWAYS_INLINE v4i& v4i::operator+=(v4i rhs)
		{
			_x += rhs._x;
			_y += rhs._y;
			_z += rhs._z;
			_w += rhs._w;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4i& v4i::operator-=(v4i rhs)
		{
			_x -= rhs._x;
			_y -= rhs._y;
			_z -= rhs._z;
			_w -= rhs._w;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4i& v4i::operator*=(v4i rhs)
		{
			_x *= rhs._x;
			_y *= rhs._y;
			_z *= rhs._z;
			_w *= rhs._w;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4i& v4i::operator*=(int value)
		{
			_x *= value;
			_y *= value;
			_z *= value;
			_w *= value;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4i& v4i::operator/=(int value)
		{
			if (value != 0) {
				_x /= value;
				_y /= value;
				_z /= value;
				_w /= value;
			}
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v4i::operator==(const v4i& rhs) const
		{
			return _x == rhs._x && _y == rhs._y && _z == rhs._z && _w == rhs._w;
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v4i::operator!=(const v4i& rhs) const
		{
			return !(*this == rhs);
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v4i::operator<(const v4i& rhs) const
		{
			return (_x < rhs._x) || (_x == rhs._x && _y < rhs._y) ||
				(_x == rhs._x && _y == rhs._y && _z < rhs._z) ||
				(_x == rhs._x && _y == rhs._y && _z == rhs._z && _w < rhs._w);
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v4i::operator>(const v4i& rhs) const
		{
			return !(*this < rhs) && !(*this == rhs);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::operator-(const v4i& rhs) const
		{
			return v4i(_x - rhs._x, _y - rhs._y, _z - rhs._z, _w - rhs._w);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::operator+(const v4i& rhs) const
		{
			return v4i(_x + rhs._x, _y + rhs._y, _z + rhs._z, _w + rhs._w);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::operator*(const v4i& rhs) const
		{
			return v4i(_x * rhs._x, _y * rhs._y, _z * rhs._z, _w * rhs._w);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::operator*(int value) const
		{
			return v4i(_x * value, _y * value, _z * value, _w * value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::operator/(int value) const
		{
			if (value != 0)
				return v4i(_x / value, _y / value, _z / value, _w / value);
			else
				return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::min(v4i other) const
		{
			return v4i((_x < other._x) ? _x : other._x,
				(_y < other._y) ? _y : other._y,
				(_z < other._z) ? _z : other._z,
				(_w < other._w) ? _w : other._w);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4i v4i::max(v4i other) const
		{
			return v4i((_x > other._x) ? _x : other._x,
				(_y > other._y) ? _y : other._y,
				(_z > other._z) ? _z : other._z,
				(_w > other._w) ? _w : other._w);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::_0000()
		{
			return v4(0.0f, 0.0f, 0.0f, 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::_0001()
		{
			return v4(0.0f, 0.0f, 0.0f, 1.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::_0010()
		{
			return v4(0.0f, 0.0f, 1.0f, 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::_0011()
		{
			return v4(0.0f, 0.0f, 1.0f, 1.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::_0100()
		{
			return v4(0.0f, 1.0f, 0.0f, 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::_0101()
		{
			return v4(0.0f, 1.0f, 0.0f, 1.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::_1000()
		{
			return v4(1.0f, 0.0f, 0.0f, 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::_1001()
		{
			return v4(1.0f, 0.0f, 0.0f, 1.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::_1010()
		{
			return v4(1.0f, 0.0f, 1.0f, 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::_1110()
		{
			return v4(1.0f, 1.0f, 1.0f, 0.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::_1111()
		{
			return v4(1.0f, 1.0f, 1.0f, 1.0f);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::rand0(uint32_t *seed)
		{
			return v4(math::rand0(seed), math::rand0(seed), math::rand0(seed), math::rand0(seed));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4::v4(sce::Vectormath::Simd::Aos::Vector4 value) : _impl(value)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v4::v4(float value) : _impl(value)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v4::v4(float xvalue, float yvalue, float zvalue, float wvalue) : _impl(xvalue, yvalue, zvalue, wvalue)
		{

		}

		SCE_VECTORMATH_ALWAYS_INLINE v4::v4()
		{

		}

		template<typename T>
		SCE_VECTORMATH_ALWAYS_INLINE v4::v4(T xvalue, T yvalue, T zvalue, T wvalue)
		{
			T::vector_is_1D();
			_impl.setX(xvalue.f());
			_impl.setY(yvalue.f());
			_impl.setZ(zvalue.f());
			_impl.setW(wvalue.f());
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v4::set_w(float value)
		{
			_impl.setW(value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v4::set_w(v1 value)
		{
			_impl.setW(value.getImpl());
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v4::set_x(float value)
		{
			_impl.setX(value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v4::set_x(v1 value)
		{
			_impl.setX(value.getImpl());
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v4::set_y(float value)
		{
			_impl.setY(value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v4::set_y(v1 value)
		{
			_impl.setY(value.getImpl());
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v4::set_z(float value)
		{
			_impl.setZ(value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v4::set_z(v1 value)
		{
			_impl.setZ(value.getImpl());
		}

		SCE_VECTORMATH_ALWAYS_INLINE void v4::set_at(size_t sce_paf_index, float value)
		{
			_impl.setElem(sce_paf_index, value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE float *v4::float_ptr()
		{
			return (float *)&_impl;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4& v4::operator/=(float value)
		{
			_impl /= value;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4& v4::operator/=(v4 value)
		{
			_impl = sce::Vectormath::Simd::Aos::divPerElem(_impl, value._impl);
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4& v4::operator-=(v4 value)
		{
			_impl -= value._impl;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4& v4::operator*=(float value)
		{
			_impl *= value;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4& v4::operator*=(v4 value)
		{
			_impl = sce::Vectormath::Simd::Aos::mulPerElem(_impl, value._impl);
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4& v4::operator+=(v4 value)
		{
			_impl += value._impl;
			return *this;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::sce_paf_abs() const
		{
			return v4(sce::Vectormath::Simd::Aos::absPerElem(_impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::x(v1 value) const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(value.getImpl(), _impl.getY(), _impl.getZ(), _impl.getW()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v4::x() const
		{
			return v1(_impl.getX());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::y(v1 value) const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getX(), value.getImpl(), _impl.getZ(), _impl.getW()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v4::y() const
		{
			return v1(_impl.getY());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::z(v1 value) const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getX(), _impl.getY(), value.getImpl(), _impl.getW()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v4::z() const
		{
			return v1(_impl.getZ());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::w(v1 value) const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getX(), _impl.getY(), _impl.getZ(), value.getImpl()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v4::w() const
		{
			return v1(_impl.getW());
		}

		SCE_VECTORMATH_ALWAYS_INLINE float v4::at(size_t sce_paf_index) const
		{
			return _impl[sce_paf_index];
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::xy(v2 value) const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(value.getImpl(), _impl.getZ(), _impl.getW()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v4::xy() const
		{
			return v2(_impl.getXY());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::xz(v2 value) const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(value.getImpl().getX(), _impl.getY(), value.getImpl().getY(), _impl.getW()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v4::xz() const
		{
			return v2((float)_impl.getX(), (float)_impl.getZ());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::yw(v2 value) const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getX(), value.getImpl().getX(), _impl.getZ(), value.getImpl().getY()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v4::yw() const
		{
			return v2((float)_impl.getY(), (float)_impl.getW());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::yz(v2 value) const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getX(), value.getImpl().getX(), value.getImpl().getY(), _impl.getW()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v4::yz() const
		{
			return v2((float)_impl.getY(), (float)_impl.getZ());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::zw(v2 value) const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getX(), _impl.getY(), value.getImpl().getX(), value.getImpl().getY()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v2 v4::zw() const
		{
			return v2((float)_impl.getZ(), (float)_impl.getW());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::xyz(v3 value) const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(value.getImpl(), _impl.getW()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v3 v4::xyz() const
		{
			return v3(_impl.getXYZ());
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v4::dot(v4 other) const
		{
			return v1(sce::Vectormath::Simd::Aos::dot(_impl, other._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v1 v4::len() const
		{
			return v1(sce::Vectormath::Simd::Aos::length(_impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::min(v4 other) const
		{
			return v4(sce::Vectormath::Simd::Aos::minPerElem(_impl, other._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::max(v4 other) const
		{
			return v4(sce::Vectormath::Simd::Aos::maxPerElem(_impl, other._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::rcp() const
		{
			return v4(sce::Vectormath::Simd::Aos::recipPerElem(_impl));
		}

		/*
		SCE_VECTORMATH_ALWAYS_INLINE bool v4::isAn() const
		{

		}
		*/

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::unit() const
		{
			return *this * len().rcp();
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::wzyx() const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getW(), _impl.getZ(), _impl.getY(), _impl.getX()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::xyxy() const
		{
			sce::Vectormath::Simd::Aos::Vector2 xy = _impl.getXY();
			return v4(sce::Vectormath::Simd::Aos::Vector4(xy, xy));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::xyz0() const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getXYZ(), 0.0f));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::xyz1() const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getXYZ(), 1.0f));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::xyzw() const
		{
			return v4(_impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::xyzx() const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getXY(), _impl.getZ(), _impl.getX()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::xyzy() const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getXY(), _impl.getZ(), _impl.getY()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::yxwz() const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getY(), _impl.getX(), _impl.getW(), _impl.getZ()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::yxxx() const
		{
			sce::Vectormath::Simd::floatInVec x = _impl.getX();
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getY(), x, x, x));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::yxxy() const
		{
			sce::Vectormath::Simd::floatInVec x = _impl.getX();
			sce::Vectormath::Simd::floatInVec y = _impl.getY();
			return v4(sce::Vectormath::Simd::Aos::Vector4(y, x, x, y));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::yxyx() const
		{
			sce::Vectormath::Simd::floatInVec x = _impl.getX();
			sce::Vectormath::Simd::floatInVec y = _impl.getY();
			return v4(sce::Vectormath::Simd::Aos::Vector4(y, x, y, x));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::yxyy() const
		{
			sce::Vectormath::Simd::floatInVec y = _impl.getY();
			return v4(sce::Vectormath::Simd::Aos::Vector4(y, _impl.getX(), y, y));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::yzyy() const
		{
			sce::Vectormath::Simd::floatInVec y = _impl.getY();
			return v4(sce::Vectormath::Simd::Aos::Vector4(y, _impl.getZ(), y, y));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::yzyz() const
		{
			sce::Vectormath::Simd::floatInVec y = _impl.getY();
			sce::Vectormath::Simd::floatInVec z = _impl.getZ();
			return v4(sce::Vectormath::Simd::Aos::Vector4(y, z, y, z));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::zwxy() const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getZ(), _impl.getW(), _impl.getX(), _impl.getY()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::zxxx() const
		{
			sce::Vectormath::Simd::floatInVec x = _impl.getX();
			return v4(sce::Vectormath::Simd::Aos::Vector4(_impl.getZ(), x, x, x));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::zxxz() const
		{
			sce::Vectormath::Simd::floatInVec x = _impl.getX();
			sce::Vectormath::Simd::floatInVec z = _impl.getZ();
			return v4(sce::Vectormath::Simd::Aos::Vector4(z, x, x, z));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::zzxx() const
		{
			sce::Vectormath::Simd::floatInVec x = _impl.getX();
			sce::Vectormath::Simd::floatInVec z = _impl.getZ();
			return v4(sce::Vectormath::Simd::Aos::Vector4(z, z, x, x));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::zzxz() const
		{
			sce::Vectormath::Simd::floatInVec z = _impl.getZ();
			return v4(sce::Vectormath::Simd::Aos::Vector4(z, z, _impl.getX(), z));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::zzyy() const
		{
			sce::Vectormath::Simd::floatInVec y = _impl.getY();
			sce::Vectormath::Simd::floatInVec z = _impl.getZ();
			return v4(sce::Vectormath::Simd::Aos::Vector4(z, z, y, y));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::zzyz() const
		{
			sce::Vectormath::Simd::floatInVec z = _impl.getZ();
			return v4(sce::Vectormath::Simd::Aos::Vector4(z, z, _impl.getY(), z));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::clamp(v4 min, v4 max) const
		{
			return v4(sce::Vectormath::Simd::Aos::clampPerElem(_impl, min._impl, max._impl));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::cross(v4 other) const
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(sce::Vectormath::Simd::Aos::cross(_impl.getXYZ(), other._impl.getXYZ()), 0.0f));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::floor() const
		{
			sce::Vectormath::Simd::Aos::Vector4 vec(
				sce::Vectormath::Simd::floorf(_impl.getX()),
				sce::Vectormath::Simd::floorf(_impl.getY()),
				sce::Vectormath::Simd::floorf(_impl.getZ()),
				sce::Vectormath::Simd::floorf(_impl.getW()));
			return v4(vec);
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v4::isNull() const
		{
			return sce::Vectormath::Simd::Aos::allElemEqual(_impl, sce::Vectormath::Simd::Aos::Vector4(0.0f));
		}

		/*
		SCE_VECTORMATH_ALWAYS_INLINE bool v4::isUnit() const
		{

		}
		*/

		SCE_VECTORMATH_ALWAYS_INLINE v1 v4::lensqr() const
		{
			return dot(*this);
		}

		/*
		SCE_VECTORMATH_ALWAYS_INLINE uint32_t v4::to8888() const
		{

		}
		*/

		/*
		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::anyPerp() const
		{

		}
		*/

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::insert_x(float value) const
		{
			sce::Vectormath::Simd::Aos::Vector4 ret = _impl;
			ret.setX(value);
			return ret;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::insert_y(float value) const
		{
			sce::Vectormath::Simd::Aos::Vector4 ret = _impl;
			ret.setY(value);
			return ret;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::insert_z(float value) const
		{
			sce::Vectormath::Simd::Aos::Vector4 ret = _impl;
			ret.setZ(value);
			return ret;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::insert_w(float value) const
		{
			sce::Vectormath::Simd::Aos::Vector4 ret = _impl;
			ret.setW(value);
			return ret;
		}

		SCE_VECTORMATH_ALWAYS_INLINE float v4::extract_x() const
		{
			return _impl.getX();
		}

		SCE_VECTORMATH_ALWAYS_INLINE float v4::extract_y() const
		{
			return _impl.getY();
		}

		SCE_VECTORMATH_ALWAYS_INLINE float v4::extract_z() const
		{
			return _impl.getZ();
		}

		SCE_VECTORMATH_ALWAYS_INLINE float v4::extract_w() const
		{
			return _impl.getW();
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::operator/(v4 rhs) const
		{
			return v4(sce::Vectormath::Simd::Aos::divPerElem(_impl, rhs._impl));
		}

		template<typename T>
		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::operator/(T value) const
		{
			T::vector_is_1D();
			return v4(_impl / value.f());
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v4::operator==(v4 rhs) const
		{
			return sce::Vectormath::Simd::Aos::allElemEqual(_impl, rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::operator-(v4 rhs) const
		{
			return v4(_impl - rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::operator*(float value) const
		{
			return v4(_impl * value);
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::operator*(v4 rhs) const
		{
			return v4(sce::Vectormath::Simd::Aos::mulPerElem(_impl, rhs._impl));
		}

		template<typename T>
		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::operator*(T value) const
		{
			T::vector_is_1D();
			return v4(_impl * value.f());
		}

		SCE_VECTORMATH_ALWAYS_INLINE bool v4::operator!=(v4 rhs) const
		{
			if ((_impl.getX() != rhs._impl.getX()) || (_impl.getY() != rhs._impl.getY()) || (_impl.getZ() != rhs._impl.getZ()) || (_impl.getW() != rhs._impl.getW()))
			{
				return true;
			}
			return false;
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::operator-() const
		{
			return v4(
				(float)(0.0f - _impl.getX()),
				(float)(0.0f - _impl.getY()),
				(float)(0.0f - _impl.getZ()),
				(float)(0.0f - _impl.getW()));
		}

		SCE_VECTORMATH_ALWAYS_INLINE v4 v4::operator+(v4 rhs) const
		{
			return v4(_impl + rhs._impl);
		}

		SCE_VECTORMATH_ALWAYS_INLINE sce::Vectormath::Simd::Aos::Vector4& v4::getImpl()
		{
			return _impl;
		}

		static inline float dot3(v4 vec1, v4 vec2)
		{
			return sce::Vectormath::Simd::Aos::dot(vec1.getImpl().getXYZ(), vec2.getImpl().getXYZ());
		}

		static inline v4 normalize3(v4 vec)
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(sce::Vectormath::Simd::Aos::normalize(vec.getImpl().getXYZ()), vec.getImpl().getW()));
		}

		static inline v4 cross3(v4 vec1, v4 vec2)
		{
			return v4(sce::Vectormath::Simd::Aos::Vector4(sce::Vectormath::Simd::Aos::cross(vec1.getImpl().getXYZ(), vec2.getImpl().getXYZ()), vec1.getImpl().getW()));
		}
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_V4_IMPL_H */ 