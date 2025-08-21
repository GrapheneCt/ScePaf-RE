/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_QUATERNION_H
#define _VDSUITE_USER_PAF_MATH_WIN32_QUATERNION_H

#include <vectormath.h>
#include <paf/math/ngp/v4.h>

namespace paf {
	namespace math {

		class matrix;

		class quaternion
		{
		public:

			static quaternion Slerp(quaternion q0i, quaternion q1i, float t, float epsilon);

			static quaternion FromEulerAnglesZYX(v3 angles);
			static quaternion FromEulerAnglesYXZ(v3 angles);
			static quaternion FromEulerAnglesXZY(v3 angles);
			static quaternion FromEulerAnglesXYZ(v3 angles);
			static quaternion FromEulerAnglesYZX(v3 angles);
			static quaternion FromEulerAnglesZXY(v3 angles);

			SCE_VECTORMATH_ALWAYS_INLINE static quaternion Identity()
			{
				return quaternion(sce::Vectormath::Simd::Aos::Quat::identity());
			}

			//Shortest(paf::math::quaternion, paf::math::quaternion&);

			quaternion(paf::math::matrix const& mat);

			SCE_VECTORMATH_ALWAYS_INLINE quaternion(float xvalue, float yvalue, float zvalue, float wvalue) : _impl(xvalue, yvalue, zvalue, wvalue)
			{

			}

			SCE_VECTORMATH_ALWAYS_INLINE quaternion(v4 vec) : _impl(vec.getImpl())
			{

			}

			SCE_VECTORMATH_ALWAYS_INLINE quaternion(sce::Vectormath::Simd::Aos::Quat value) : _impl(value)
			{

			}

			void toAxisAngle(paf::math::v3& axis, float& angle);
			matrix toMatrix(float epsilon) const;

			quaternion inverse() const;
			quaternion log(float epsilon) const;
			quaternion exp(float epsilon) const;

			SCE_VECTORMATH_ALWAYS_INLINE void set_x(float value)
			{
				_impl.setX(value);
			}

			SCE_VECTORMATH_ALWAYS_INLINE void set_y(float value)
			{
				_impl.setY(value);
			}

			SCE_VECTORMATH_ALWAYS_INLINE void set_z(float value)
			{
				_impl.setZ(value);
			}

			SCE_VECTORMATH_ALWAYS_INLINE void set_w(float value)
			{
				_impl.setW(value);
			}

			//quaternion unit() const

			SCE_VECTORMATH_ALWAYS_INLINE bool operator==(quaternion rhs) const
			{
				return sce::Vectormath::Simd::Aos::allElemEqual((sce::Vectormath::Simd::Aos::Vector4)_impl, (sce::Vectormath::Simd::Aos::Vector4)rhs._impl);
			}

			SCE_VECTORMATH_ALWAYS_INLINE quaternion operator*(quaternion value) const
			{
				return quaternion(_impl * value._impl);
			}

			SCE_VECTORMATH_ALWAYS_INLINE v1 dot(quaternion value) const
			{
				return v1(sce::Vectormath::Simd::Aos::dot(_impl, value._impl));
			}

			SCE_VECTORMATH_ALWAYS_INLINE v1 norm() const
			{
				return v1(sce::Vectormath::Simd::Aos::norm(_impl));
			}

			SCE_VECTORMATH_ALWAYS_INLINE quaternion operator*(float value) const
			{
				return quaternion(_impl * value);
			}

			SCE_VECTORMATH_ALWAYS_INLINE quaternion& operator*=(float value)
			{
				_impl *= value;
				return *this;
			}

			SCE_VECTORMATH_ALWAYS_INLINE quaternion operator+(quaternion value) const
			{
				return quaternion(_impl + value._impl);
			}

		private:

			sce::Vectormath::Simd::Aos::Quat _impl;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_QUATERNION_H */ 