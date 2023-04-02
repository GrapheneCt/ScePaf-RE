/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_V3_H
#define _VDSUITE_USER_PAF_MATH_WIN32_V3_H

#include <vectormath.h>

namespace paf {
	namespace math {

		class v1;
		class v2;
		class v4;

		class v3
		{
		public:

			static v3 _000();

			static v3 _001();

			v3(sce::Vectormath::Simd::Aos::Vector3 value);

			v3(float value);

			v3(float xvalue, float yvalue, float zvalue);

			v3();

			void set_x(float value);

			void set_x(v1 value);

			void set_y(float value);

			void set_y(v1 value);

			void set_z(float value);

			void set_z(v1 value);

			v3& operator/=(float value);

			v3& operator*=(float value);

			v3 sce_paf_abs() const;
			
			v3 x(v1 value) const;

			v1 x() const;

			v3 y(v1 value) const;

			v1 y() const;

			v1 z() const;

			v2 xy() const;

			v3 cos() const;

			v3 sin() const;

			v1 dot(v3 other) const;

			v1 len() const;

			v3 min(v3 other) const;

			v3 max(v3 other) const;

			v3 unit() const;

			v4 xyz0() const;

			v4 xyz1() const;

			v4 xyzw(v1 value) const;

			v3 cross(v3 other) const;

			v3 insert_x(float value) const;

			v3 insert_y(float value) const;

			float extract_x() const;

			float extract_y() const;

			float extract_z() const;

			v3 operator/(float value) const;

			v3 operator/(v3 rhs) const;

			v3 operator-(v3 rhs) const;

			v3 operator*(float value) const;

			v3 operator*(v3 rhs) const;

			template<typename T>
			v3 operator*(T value) const;

			bool operator!=(v3 rhs) const;

			v3 operator-() const;

			v3 operator+(v3 rhs) const;

			sce::Vectormath::Simd::Aos::Vector3& getImpl();

		private:

			sce::Vectormath::Simd::Aos::Vector3 _impl;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_V3_H */ 