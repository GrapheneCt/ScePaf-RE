/*
	ScePaf-RE Project
*/

#ifndef _PAF_PAF_CDLG_H
#define _PAF_PAF_CDLG_H

#include <stdint.h>
#include <stddef.h>
#if defined(__SNC__)
#include <gxm.h>
#elif defined(__vita__)
#include <psp2/gxm.h>
#endif

namespace paf {
	namespace cdlg {

		class OnUpdateData
		{
		public:

			uint32_t fb_pitch;
			uint32_t fb_width;
			uint32_t fb_height;
			SceGxmColorFormat fb_format;
			SceGxmColorSurfaceType fb_type;
			void *fb_addr; // color surface data addr
			void *fb_depth_addr; // 0
			SceGxmSyncObject *gxm_sync_object;
		};
	}
}

#endif /* _PAF_PAF_CDLG_H */
