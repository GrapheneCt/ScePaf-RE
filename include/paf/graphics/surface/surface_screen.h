/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_SCREEN_H
#define _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_SCREEN_H

#include <stddef.h>
#include <stdint.h>
#ifdef __SNC__
#include <gxm.h>
#else
#include <psp2/gxm.h>
#endif
#include <paf/paf_types.h>
#include <paf/graphics/surface/surface_base.h>
#include <paf/graphics/surface/surface.h>

namespace paf {
	namespace graph {

		class SurfacePool;

		class ScreenSurface : public Surface
		{
		public:

			static SceGxmContext *GetRawContext();

			static void SetRawContext(SceGxmContext *gxm_context);

			ScreenSurface(int32_t width, int32_t height, ImageMode color_fmt, ImageOrder color_order, int32_t num_page, ImageMode depth_fmt, ImageOrder depth_order, void *fb, SurfaceType surf_type);

			ScreenSurface(SurfacePool *pool, int width, int height, ImageMode color_fmt, ImageOrder color_order, int num_page, ImageMode depth_fmt, ImageOrder depth_order, SurfaceType surf_type);

			virtual ~ScreenSurface();

			virtual int32_t unkFun_0C();
			virtual int32_t unkFun_10();
			virtual int32_t unkFun_14();
			virtual void Swap();
			virtual int32_t BeginScene();
			virtual int32_t EndScene();
			virtual void *Lock(int32_t lockArea = 0); // Returns pointer to surface memory
			virtual void  Unlock();
			virtual int32_t unkFun_2C();
			virtual int32_t GenTexture();
			virtual int32_t unkFun_34(); //Begin()
			virtual int32_t unkFun_38(); //End()

			uint32_t ConvertColorSurfaceFormat(ImageMode format);

			uint32_t ConvertColorSurfaceOrder(ImageOrder order);

			uint32_t ConvertDepthFormat(ImageMode format);

			uint32_t GetColorSurfaceFormat();

			uint32_t GetColorSurfaceOrder();

			uint32_t GetDepthFormat();

			uint32_t GetDepthSize(int32_t width, int32_t height, ImageMode format, ImageOrder order);

			SceGxmColorSurface *GetRawColorSurface(int32_t page);

			int32_t InitColorSurface();

			int32_t InitDepthSurface();

		protected:

			SceGxmColorSurface *m_color_surface;
			SceGxmRenderTarget *m_render_target;
			SceGxmDepthStencilSurface *m_depth_stencil;
			bool m_has_rt;
			int32_t m_unk_A4;
			int32_t m_unk_A8;
			int32_t m_output_register_size;
			int32_t m_unk_B0;
			int32_t m_unk_B4;
			int32_t m_multisample_mode;
			uint8_t m_scale_mode;
			int32_t m_unk_C0;
			void *m_depth_buffer;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_SCREEN_H */
