/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_IMAGE_IMAGE_REGION_H
#define _VDSUITE_USER_PAF_IMAGE_IMAGE_REGION_H

#include <stdint.h>
#include <paf/paf_types.h>

namespace paf {
	namespace image {

		class ImageExtent
		{
		public:

			ImageExtent() : w(0), h(0)
			{

			}

			ImageExtent(int32_t _w, int32_t _h) : w(_w), h(_h)
			{

			}

			ImageExtent& operator+=(ImageExtent const& e)
			{
				w += e.w;
				h += e.h;
				return *this;
			}

			ImageExtent& operator-=(ImageExtent const& e)
			{
				w -= e.w;
				h -= e.h;
				return *this;
			}

			ImageExtent& operator/=(int32_t s)
			{
				w /= s;
				h /= s;
				return *this;
			}

			ImageExtent Clone() const
			{
				return ImageExtent(w, h);
			}

			bool IsEmpty() const
			{
				if ((w < 1) || (h < 1))
				{
					return true;
				}
				return false;
			}

			bool NotEmpty() const
			{
				if ((0 < w) && (0 < h))
				{
					return true;
				}
				return false;
			}

			bool operator!=(ImageExtent const& e) const
			{
				if ((w != e.w) || (h != e.h))
				{
					return true;
				}
				return false;
			}

			ImageExtent operator+(ImageExtent const& e) const
			{
				return ImageExtent(w + e.w, h + e.h);
			}

			ImageExtent operator-(ImageExtent const& e) const
			{
				return ImageExtent(w - e.w, h - e.h);
			}

			bool operator==(ImageExtent const& e) const
			{
				if ((w == e.w) && (h == e.h))
				{
					return true;
				}
				return false;
			}

			int32_t w;
			int32_t h;
		};

		class ImagePoint
		{
		public:

			ImagePoint() : x(0), y(0)
			{

			}

			ImagePoint(int32_t _x, int32_t _y) : x(_x), y(_y)
			{

			}

			ImagePoint& operator+=(ImagePoint const& p)
			{
				x += p.x;
				y += p.y;
				return *this;
			}

			ImagePoint& operator/=(int32_t s)
			{
				x /= s;
				y /= s;
				return *this;
			}

			bool operator<(ImagePoint const& p) const
			{
				if ((x < p.x) && (y < p.y))
				{
					return true;
				}
				return false;
			}

			bool operator==(ImagePoint const& p) const
			{
				if ((x == p.x) && (y == p.y))
				{
					return true;
				}
				return false;
			}

			bool operator>=(ImagePoint const& p) const
			{
				if ((p.x <= x) && (p.y <= y))
				{
					return true;
				}
				return false;
			}

			bool operator!=(ImagePoint const& p) const
			{
				if ((x != p.x) || (y != p.y))
				{
					return true;
				}
				return false;
			}

			int32_t x;
			int32_t y;
		};

		class ImageRect
		{
		public:

			ImageRect()
			{

			}

			ImageRect(ImagePoint const& p, ImageExtent const& e)
			{
				origin = p;
				extent = e;
			}

			ImageRect(ImageExtent const& e)
			{
				extent = e;
			}

			ImageRect(int32_t x, int32_t y, int32_t w, int32_t h) : origin(x, y), extent(w, h)
			{

			}

			//ImageRect& operator*=(ImageRect const& r);

			bool IsEmpty() const
			{
				return extent.IsEmpty();
			}

			bool NotEmpty() const
			{
				return extent.NotEmpty();
			}

			bool operator==(ImageRect const& r) const
			{
				if (((!IsEmpty()) && (!r.IsEmpty())) ||
					((origin == r.origin) &&
					(extent == r.extent)))
				{
					return true;
				}
				return false;
			}

			bool operator!=(ImageRect const& r) const
			{
				return !(*this == r);
			}

			ImagePoint origin;
			ImageExtent extent;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_IMAGE_IMAGE_REGION_H */
