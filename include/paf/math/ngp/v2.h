/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_V2_H
#define _VDSUITE_USER_PAF_MATH_WIN32_V2_H

#include <vectormath.h>

namespace paf {
	namespace math {

		class v1;
		class v3;
		class v4;

		class v2i
		{
		public:

			static v2i _00();

			static v2i _01();

			static v2i _10();

			static v2i _11();

			v2i(int a_x, int a_y);

			v2i();

			void set_x(int value);

			void set_y(int value);

			int x() const;

			int y() const;

			v2i& operator+=(v2i rhs);

			v2i& operator-=(v2i rhs);

			v2i& operator*=(v2i rhs);

			v2i& operator*=(int value);

			v2i& operator/=(int value);

			bool operator==(const v2i& rhs) const;

			bool operator!=(const v2i& rhs) const;

			bool operator<(const v2i& rhs) const;

			bool operator>(const v2i& rhs) const;

			v2i operator-(const v2i& rhs) const;

			v2i operator+(const v2i& rhs) const;

			v2i operator>>(const v2i& rhs) const;

			v2i operator*(const v2i& rhs) const;

			v2i operator*(int value) const;

			v2i operator/(int value) const;

			v2i min(v2i other) const;

			v2i max(v2i other) const;

		private:

			int _x;
			int _y;
		};

		class v2
		{
		public:

			static v2 _00();

			static v2 _01();

			static v2 _10();

			static v2 _11();

			static v2 Rotation(float a_angle);

			v2(sce::Vectormath::Simd::Aos::Vector2 value);

			v2(float value);

			v2(float xvalue, float yvalue);

			v2(v2i value);

			v2();

			template<typename T>
			v2(T xvalue, T yvalue);

			void set_x(float value);

			void set_y(float value);

			void set_x(v1 value);

			void set_y(v1 value);

			v2& operator/=(float value);

			v2& operator-=(v2 rhs);

			v2& operator*=(v2 rhs);

			v2& operator+=(v2 rhs);

			v2 sce_paf_abs() const;

			v2 x(v1 value) const;

			v1 x() const;

			v2 y(v1 value) const;

			v1 y() const;

			v2 xx() const;

			v2 yx() const;

			v2 yy() const;

			v1 dot(v2 other) const;

			v1 len() const;

			v2 min(v2 other) const;

			v2 max(v2 other) const;

			v3 xy0() const;

			v3 xy1() const;

			v2 perp() const;

			v2 unit() const;

			v4 xy00() const;

			v4 xy01() const;

			v2 clamp(v2 min, v2 max) const;

			//bool equal(float epsilon) const;

			bool isNull() const;

			float extract_x() const;

			float extract_y() const;

			v2 operator/(float value) const;

			v2 operator/(v2 rhs) const;

			bool operator==(v2 rhs) const;

			v2 operator-(float value) const;

			v2 operator-(v2 rhs) const;

			v2 operator*(float value) const;

			v2 operator*(v2 rhs) const;

			template<typename T>
			v2 operator*(T value) const;

			bool operator!=(v2 rhs) const;

			v2 operator-() const;

			v2 operator+(v2 rhs) const;

			sce::Vectormath::Simd::Aos::Vector2& getImpl();

		private:

			sce::Vectormath::Simd::Aos::Vector2 _impl;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_V2_H */ 