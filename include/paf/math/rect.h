/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MATH_RECT_H
#define _VDSUITE_USER_PAF_MATH_RECT_H

#include <paf/math/ngp/v2.h>
#include <paf/math/ngp/v4.h>

namespace paf {
	namespace math {

		class rect
		{
		public:

			static rect _0000();
			static rect _0011();

			rect();
			rect(rect const& obj);
			rect(v2 const& center, v2 const& size);
			rect(float xvalue, float yvalue, float wvalue, float hvalue);

			virtual ~rect()
			{

			}

			void set(v2 const& center, v2 const& size);
			void set(float xvalue, float yvalue, float wvalue, float hvalue);
			void set(rect const& obj);

			void set_center(float xvalue, float yvalue);
			void set_center(v2 const& xyvalue);
			void set_size(float wvalue, float hvalue);
			void set_size(v2 const& whvalue);
			void set_center_x(float xvalue);
			void set_center_y(float yvalue);
			void set_width(float wvalue);
			void set_height(float hvalue);
			void set_left(float xvalue);
			void set_right(float xvalue);
			void set_top(float yvalue);
			void set_bottom(float yvalue);

			void move(float xvalue, float yvalue);
			void move(v2 const& xyvalue);

			void align_left(float xvalue);
			void align_right(float xvalue);
			void align_top(float yvalue);
			void align_bottom(float yvalue);

			bool hit(rect const& obj);
			bool is_in_rect(rect const& obj);
			bool is_point_in_rect(float xvalue, float yvalue);
			bool is_point_in_rect(v2 const& xyvalue);

			void clear();

			rect& operator=(rect const& rhs);

			rect get() const;
			v2 center() const;
			v2 size() const;
			v4 get_xywh() const;
			v4 get_LTRB() const;
			v4 get_TLBR() const;

			float center_x() const;
			float center_y() const;
			float width() const;
			float height() const;
			float left() const;
			float right() const;
			float top() const;
			float bottom() const;

			v2 left_top() const;
			v2 left_bottom() const;
			v2 right_top() const;
			v2 right_bottom() const;

			float get_area() const;

			bool operator==(rect const& rhs) const;
			bool operator!=(rect const& rhs) const;

		private:

			float _x_center;
			float _y_center;
			float _h;
			float _w;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_MATH_RECT_H */ 