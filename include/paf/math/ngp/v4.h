/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_WIN32_V4_H
#define _VDSUITE_USER_PAF_MATH_WIN32_V4_H

#include <stdint.h>
#include <stddef.h>
#include <vectormath.h>

namespace paf {
	namespace math {

		class v1;
		class v2;
		class v3;

		class v4i
		{
		public:

			static v4i _0000();
			static v4i _0001();
			static v4i _0010();
			static v4i _0011();
			static v4i _0100();
			static v4i _0101();
			static v4i _0110();
			static v4i _0111();
			static v4i _1000();
			static v4i _1001();
			static v4i _1010();
			static v4i _1011();
			static v4i _1100();
			static v4i _1101();
			static v4i _1110();
			static v4i _1111();

			v4i(int a_x, int a_y, int a_z, int a_w);
			v4i();

			void set_x(int value);
			void set_y(int value);
			void set_z(int value);
			void set_w(int value);

			int x() const;
			int y() const;
			int z() const;
			int w() const;

			v4i& operator+=(v4i rhs);
			v4i& operator-=(v4i rhs);
			v4i& operator*=(v4i rhs);
			v4i& operator*=(int value);
			v4i& operator/=(int value);

			bool operator==(const v4i& rhs) const;
			bool operator!=(const v4i& rhs) const;
			bool operator<(const v4i& rhs) const;
			bool operator>(const v4i& rhs) const;

			v4i operator-(const v4i& rhs) const;
			v4i operator+(const v4i& rhs) const;
			v4i operator*(const v4i& rhs) const;
			v4i operator*(int value) const;
			v4i operator/(int value) const;

			v4i min(v4i other) const;
			v4i max(v4i other) const;

		private:

			int _x;
			int _y;
			int _z;
			int _w;
		};

		class v4
		{
		public:

			static v4 _0000();

			static v4 _0001();

			static v4 _0010();

			static v4 _0011();

			static v4 _0100();

			static v4 _0101();

			static v4 _1000();

			static v4 _1001();

			static v4 _1010();

			static v4 _1110();

			static v4 _1111();

			static v4 rand0(uint32_t *seed);

			v4(sce::Vectormath::Simd::Aos::Vector4 value);

			v4(float value);

			v4(float xvalue, float yvalue, float zvalue = 0.0f, float wvalue = 0.0f);

			v4();

			template<typename T>
			v4(T xvalue, T yvalue, T zvalue, T wvalue);

			void set_w(float value);

			void set_w(v1 value);

			void set_x(float value);

			void set_x(v1 value);

			void set_y(float value);

			void set_y(v1 value);

			void set_z(float value);

			void set_z(v1 value);

			void set_at(size_t sce_paf_index, float value);

			v4& operator/=(float value);

			v4& operator/=(v4 value);

			v4& operator-=(v4 value);

			v4& operator*=(float value);

			v4& operator*=(v4 value);

			v4& operator+=(v4 value);

			v4 sce_paf_abs() const;

			v4 x(v1 value) const;

			v1 x() const;

			v4 y(v1 value) const;

			v1 y() const;

			v4 z(v1 value) const;

			v1 z() const;

			v4 w(v1 value) const;

			v1 w() const;

			float at(size_t sce_paf_index) const;

			v4 xy(v2 value) const;

			v2 xy() const;

			v4 xz(v2 value) const;

			v2 xz() const;

			v4 yw(v2 value) const;

			v2 yw() const;
			
			v4 yz(v2 value) const;

			v2 yz() const;

			v4 zw(v2 value) const;

			v2 zw() const;

			v4 xyz(v3 value) const;

			v3 xyz() const;

			v1 dot(v4 other) const;

			v1 len() const;

			v4 min(v4 other) const;

			v4 max(v4 other) const;

			v4 rcp() const;

			/*
			bool isAn() const;
			*/

			v4 unit() const;

			v4 wzyx() const;

			v4 xyxy() const;

			v4 xyz0() const;

			v4 xyz1() const;

			v4 xyzw() const;

			v4 xyzx() const;

			v4 xyzy() const;

			v4 yxwz() const;

			v4 yxxx() const;

			v4 yxxy() const;

			v4 yxyx() const;

			v4 yxyy() const;

			v4 yzyy() const;

			v4 yzyz() const;

			v4 zwxy() const;

			v4 zxxx() const;

			v4 zxxz() const;

			v4 zzxx() const;

			v4 zzxz() const;

			v4 zzyy() const;

			v4 zzyz() const;

			v4 clamp(v4 min, v4 max) const;

			v4 cross(v4 other) const;

			v4 floor() const;

			bool isNull() const;

			/*
			bool isUnit() const;
			*/

			v1 lensqr() const;

			/*
			uint32_t to8888() const;
			*/

			/*
			v4 anyPerp() const;
			*/

			v4 insert_x(float value) const;

			v4 insert_y(float value) const;

			v4 insert_z(float value) const;

			v4 insert_w(float value) const;

			float extract_x() const;

			float extract_y() const;

			float extract_z() const;

			float extract_w() const;

			float *float_ptr();

			v4 operator/(v4 rhs) const;

			template<typename T>
			v4 operator/(T value) const;

			bool operator==(v4 rhs) const;

			v4 operator-(v4 rhs) const;

			v4 operator*(float value) const;

			v4 operator*(v4 rhs) const;

			template<typename T>
			v4 operator*(T value) const;

			bool operator!=(v4 rhs) const;

			v4 operator-() const;

			v4 operator+(v4 rhs) const;

			sce::Vectormath::Simd::Aos::Vector4& getImpl();

		private:

			sce::Vectormath::Simd::Aos::Vector4 _impl;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_WIN32_V4_H */ 