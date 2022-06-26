/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WEB_MAP_VIEW_H
#define _VDSUITE_USER_PAF_WEB_MAP_VIEW_H

#include <kernel.h>
#include <gxm.h>

namespace paf {

	class WebMapView
	{
	public:

		class GraphicsContextOpt
		{
		public:

			SceGxmContext *gxmCtx;
			SceUInt32 width;
			SceUInt32 height;
		};

		//ScePafWebMapView_6E0719FB
		SceVoid InitGraphics();

		//ScePafWebMapView_273F200C
		SceVoid InitIPC();

		//ScePafWebMapView_5E7D0BE7
		static SceVoid Initialize();

		//ScePafWebMapView_DE7C5CBE
		static SceVoid Create(const char *name, SceUInt32 graphicsHeapSize, SceKernelMemBlockType graphicsHeapMemblockType, SceUInt32 a4, SceUInt32 a5);

		//ScePafWebMapView_C2581D7F
		static WebMapView *GetInstance();

		//ScePafWebMapView_EE99BD02
		static SceVoid CreateGraphicsContext(GraphicsContextOpt *pOpt);


	};

}

#endif /* _VDSUITE_USER_PAF_WEB_MAP_VIEW_H */

