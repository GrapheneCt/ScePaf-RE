/*
	ScePaf-RE Project
*/

#ifndef _PAF_MATH_GENERIC_QUATERNION_H
#define _PAF_MATH_GENERIC_QUATERNION_H

#include <vectormath.h>
#include <paf/math/generic/v4.h>

namespace paf {
	namespace math {

		class matrix;

		class quaternion
		{
		public:

			/*
			static quaternion Slerp(quaternion q0i, quaternion q1i, float t, float epsilon);

			static quaternion FromEulerAnglesZYX(v3 angles);
			static quaternion FromEulerAnglesYXZ(v3 angles);
			static quaternion FromEulerAnglesXZY(v3 angles);
			static quaternion FromEulerAnglesXYZ(v3 angles);
			static quaternion FromEulerAnglesYZX(v3 angles);
			static quaternion FromEulerAnglesZXY(v3 angles);
			*/

			SCE_VECTORMATH_ALWAYS_INLINE static quaternion Identity()
			{
				return quaternion(SCE_PAF_VECTORMATH::Aos::Quat::identity());
			}

			//Shortest(paf::math::quaternion, paf::math::quaternion&);

			/*
			quaternion(paf::math::matrix const& mat);
			*/

			SCE_VECTORMATH_ALWAYS_INLINE quaternion(float xvalue, float yvalue, float zvalue, float wvalue) : _impl(xvalue, yvalue, zvalue, wvalue)
			{

			}

			SCE_VECTORMATH_ALWAYS_INLINE quaternion(v4 vec) : _impl(vec.getImpl())
			{

			}

			SCE_VECTORMATH_ALWAYS_INLINE quaternion(SCE_PAF_VECTORMATH::Aos::Quat value) : _impl(value)
			{

			}

			/*
			void toAxisAngle(paf::math::v3& axis, float& angle);
			matrix toMatrix(float epsilon) const;

			quaternion inverse() const;
			quaternion log(float epsilon) const;
			quaternion exp(float epsilon) const;
			*/

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
				return SCE_PAF_VECTORMATH::Aos::allElemEqual((SCE_PAF_VECTORMATH::Aos::Vector4)_impl, (SCE_PAF_VECTORMATH::Aos::Vector4)rhs._impl);
			}

			SCE_VECTORMATH_ALWAYS_INLINE quaternion operator*(quaternion value) const
			{
				return quaternion(_impl * value._impl);
			}

			SCE_VECTORMATH_ALWAYS_INLINE v1 dot(quaternion value) const
			{
				return v1(SCE_PAF_VECTORMATH::Aos::dot(_impl, value._impl));
			}

			SCE_VECTORMATH_ALWAYS_INLINE v1 norm() const
			{
				return v1(SCE_PAF_VECTORMATH::Aos::norm(_impl));
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

			SCE_PAF_VECTORMATH::Aos::Quat _impl;
		};
	}
}

#endif /* _PAF_MATH_GENERIC_QUATERNION_H */ 