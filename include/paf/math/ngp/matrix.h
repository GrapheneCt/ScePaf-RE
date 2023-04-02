/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_MATRIX_H
#define _VDSUITE_USER_PAF_MATH_WIN32_MATRIX_H

#include <stddef.h>
#include <vectormath.h>
#include <paf/math/ngp/v3.h>
#include <paf/math/ngp/v4.h>
#include <paf/common/halt_assert.h>
#include <paf/std/string>

namespace paf {
	namespace math {

		class quaternion;

		class matrix
		{
		public:

			static matrix Frustum(float l, float r, float b, float t, float n, float f);

			static matrix Ortho(float l, float r, float b, float t, float n, float f);
			static matrix Ortho(v3 min, v3 max);

			//EE135486
			//static matrix Shadow(paf::math::v4 ground, paf::math::v4 light);

			//static matrix Translation_x_Scale(v3, v3);

			static matrix LookAt(v4 eye, v4 center, v4 up, float epsilon);

			SCE_VECTORMATH_ALWAYS_INLINE static matrix Perspective(float fovy, float aspect, float n, float f)
			{
				return matrix(sce::Vectormath::Simd::Aos::Matrix4::perspective(fovy, aspect, n, f));
			}

			SCE_VECTORMATH_ALWAYS_INLINE static matrix Translation(v4 vec)
			{
				return matrix(sce::Vectormath::Simd::Aos::Matrix4::translation(vec.getImpl().getXYZ()));
			}

			SCE_VECTORMATH_ALWAYS_INLINE static matrix Translation(v3 vec)
			{
				return matrix(sce::Vectormath::Simd::Aos::Matrix4::translation(vec.getImpl()));
			}

			SCE_VECTORMATH_ALWAYS_INLINE static matrix Identity()
			{
				return matrix(sce::Vectormath::Simd::Aos::Matrix4::identity());
			}

			SCE_VECTORMATH_ALWAYS_INLINE static matrix RotationX(float angle)
			{
				return matrix(sce::Vectormath::Simd::Aos::Matrix4::rotationX(angle));
			}

			SCE_VECTORMATH_ALWAYS_INLINE static matrix RotationY(float angle)
			{
				return matrix(sce::Vectormath::Simd::Aos::Matrix4::rotationY(angle));
			}

			SCE_VECTORMATH_ALWAYS_INLINE static matrix RotationZ(float angle)
			{
				return matrix(sce::Vectormath::Simd::Aos::Matrix4::rotationZ(angle));
			}

			SCE_VECTORMATH_ALWAYS_INLINE static matrix Scale(v3 vec)
			{
				return matrix(sce::Vectormath::Simd::Aos::Matrix4::scale(vec.getImpl()));
			}

			SCE_VECTORMATH_ALWAYS_INLINE static matrix Zero()
			{
				return matrix(sce::Vectormath::Simd::Aos::Matrix4::zero());
			}

			matrix(quaternion quat);

			SCE_VECTORMATH_ALWAYS_INLINE matrix(v4 xcol, v4 ycol, v4 zcol, v4 wcol) : _impl(xcol.getImpl(), ycol.getImpl(), zcol.getImpl(), wcol.getImpl())
			{

			}

			SCE_VECTORMATH_ALWAYS_INLINE matrix(sce::Vectormath::Simd::Aos::Matrix4 value) : _impl(value)
			{

			}

			SCE_VECTORMATH_ALWAYS_INLINE matrix()
			{

			}

			SCE_VECTORMATH_ALWAYS_INLINE ~matrix()
			{

			}

			matrix inverse3() const;
			matrix inverse1() const;
			matrix inverse() const;

			matrix transpose() const;

			bool isCoordSys(float) const;
			matrix fixedCoordSys() const;
			string getCoordSysError();

			v3 extractEulerAnglesXYZ() const;
			v3 extractEulerAnglesXZY() const;
			v3 extractEulerAnglesYXZ() const;
			v3 extractEulerAnglesYZX() const;
			v3 extractEulerAnglesZXY() const;
			v3 extractEulerAnglesZYX() const;

			/*
			SCE_VECTORMATH_ALWAYS_INLINE float determinant3() const
			{
				
			}
			*/

			SCE_VECTORMATH_ALWAYS_INLINE v4& operator[](size_t sce_paf_index)
			{
				return (v4&)_impl[sce_paf_index];
			}

			SCE_VECTORMATH_ALWAYS_INLINE v4 x() const
			{
				return v4(_impl.getCol0());
			}

			SCE_VECTORMATH_ALWAYS_INLINE v4 y() const
			{
				return v4(_impl.getCol1());
			}

			SCE_VECTORMATH_ALWAYS_INLINE v4 z() const
			{
				return v4(_impl.getCol2());
			}

			SCE_VECTORMATH_ALWAYS_INLINE v4 w() const
			{
				return v4(_impl.getCol3());
			}

			SCE_VECTORMATH_ALWAYS_INLINE v4 operator*(v4 value) const
			{
				return v4(_impl * value.getImpl());
			}

			SCE_VECTORMATH_ALWAYS_INLINE matrix operator*(matrix const& value) const
			{
				return matrix(_impl * value._impl);
			}

			SCE_VECTORMATH_ALWAYS_INLINE void set_x(v4 value)
			{
				_impl.setCol0(value.getImpl());
			}

			SCE_VECTORMATH_ALWAYS_INLINE void set_y(v4 value)
			{
				_impl.setCol1(value.getImpl());
			}

			SCE_VECTORMATH_ALWAYS_INLINE void set_z(v4 value)
			{
				_impl.setCol2(value.getImpl());
			}

			SCE_VECTORMATH_ALWAYS_INLINE void set_w(v4 value)
			{
				_impl.setCol3(value.getImpl());
			}

			SCE_VECTORMATH_ALWAYS_INLINE matrix& operator*=(matrix const& rhs)
			{
				_impl *= rhs._impl;
				return *this;
			}

			SCE_VECTORMATH_ALWAYS_INLINE float *float_ptr() const
			{
				return (float *)&_impl;
			}

			SCE_VECTORMATH_ALWAYS_INLINE v4 operator[](size_t sce_paf_index) const
			{
				return v4(_impl[sce_paf_index]);
			}

			SCE_VECTORMATH_ALWAYS_INLINE sce::Vectormath::Simd::Aos::Matrix4& getImpl()
			{
				return _impl;
			}

		private:

			sce::Vectormath::Simd::Aos::Matrix4 _impl;
		};

		namespace math_matrix {

			extern string GetCoordSysError();
		}
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_MATRIX_H */ 