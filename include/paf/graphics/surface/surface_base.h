/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_BASE_H
#define _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_BASE_H

#include <stdint.h>
#include <paf/paf_types.h>

namespace paf {
	namespace graph {

		class SurfaceListNode
		{
		protected:

			SurfaceListNode *m_prev;
			SurfaceListNode *m_next;
		};

		class SurfaceBase
		{
		public:

			int32_t PixelsToBytes(int32_t pixels) const;

		protected:

			ImageMode m_format;
			int32_t m_unk_08;
			const int32_t m_pixel_bits;

		private:

			static int32_t GetPixelBits(ImageMode format);

			static int32_t ConvertPixelFormat(ImageMode format);

			SurfaceBase(ImageMode _format, int32_t a2);

			virtual ~SurfaceBase();

			int32_t GetDevicePixelFormat();

			int32_t SetPixelFormat(ImageMode new_format);
		};
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_BASE_H */
