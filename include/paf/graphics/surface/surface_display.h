/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_DISPLAY_H
#define _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_DISPLAY_H

#include <stddef.h>
#include <stdint.h>
#ifdef __SNC__
#include <scetypes.h>
#else
#include <psp2/types.h>
#endif
#include <paf/paf_types.h>
#include <paf/graphics/surface/surface_base.h>
#include <paf/graphics/surface/surface_screen.h>

namespace paf {
	namespace graph {

		class DisplaySurface : public ScreenSurface
		{
		public:

			enum FrameBufferMode
			{
				FrameBuffer_Normal = 0,
				FrameBuffer_Shared_Create = 1,
				FrameBuffer_Shared_Share = 2,
				FrameBuffer_Shared_OffScreen = 3,
				FrameBuffer_Given = 4
			};

			static void displayCallback(const void *data);

			static SceUID GetFbId();

			virtual ~DisplaySurface();

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
			virtual int32_t unkFun_3C();
			virtual int32_t unkFun_40();

			int32_t GetOutputPort();

			int32_t SetFrameBufferMode(FrameBufferMode fb_mod);

			int32_t ReleaseFrameBuffer(FrameBufferMode mode);

			__declspec (dllimport) static ScreenSurface *s_offscreen;

		private:

			char m_unk_C8[0xC0];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_DISPLAY_H */
