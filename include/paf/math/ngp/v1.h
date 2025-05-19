/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_V1_H
#define _VDSUITE_USER_PAF_MATH_WIN32_V1_H

#include <vectormath.h>

namespace paf {
	namespace math {

		class v4;

		class v1i
		{
		public:
			static v1i _0();
			static v1i _1();

			v1i(int a_x);
			v1i();

			void set_x(int value);
			int x() const;

			v1i& operator+=(const v1i& rhs);
			v1i& operator-=(const v1i& rhs);
			v1i& operator*=(const v1i& rhs);
			v1i& operator*=(int value);
			v1i& operator/=(int value);

			bool operator==(const v1i& rhs) const;
			bool operator!=(const v1i& rhs) const;
			bool operator<(const v1i& rhs) const;
			bool operator>(const v1i& rhs) const;

			v1i operator-(const v1i& rhs) const;
			v1i operator+(const v1i& rhs) const;
			v1i operator*(const v1i& rhs) const;
			v1i operator*(int value) const;
			v1i operator/(int value) const;

		private:

			int _x;
		};

		class v1
		{
		public:

			static void vector_is_1D();

			v1(sce::Vectormath::Simd::floatInVec value);

			v1(float value);

			v1 sce_paf_abs() const;

			float f() const;

			v1 rcp() const;

			v1 acos() const;

			v1 sqrt() const;

			v1 clamp(v1 value1, v1 value2) const;

			v4 splat() const;

			bool isNull() const;

			v1 operator/(v1 rhs) const;

			bool operator==(v1 rhs) const;

			bool operator>=(v1 rhs) const;

			bool operator>(v1 rhs) const;

			bool operator<(v1 rhs) const;

			v1 operator-(v1 rhs) const;

			v1 operator*(v1 rhs) const;

			bool operator!=(v1 rhs) const;

			v1 operator-() const;

			v1 operator+(v1 rhs);

			v1 operator+();

			sce::Vectormath::Simd::floatInVec& getImpl();

		private:

			sce::Vectormath::Simd::floatInVec _impl;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_V1_H */ 