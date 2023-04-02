/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_PAF_CDLG_H
#define _VDSUITE_USER_PAF_PAF_CDLG_H

#include <stdint.h>
#include <stddef.h>
#include <gxm.h>

namespace paf {
	namespace cdlg {

		class OnUpdateData
		{
		public:

			uint32_t fb_pitch;
			uint32_t fb_width;
			uint32_t fb_height;
			SceGxmColorFormat fb_format; // SceGxmColorFormat
			SceGxmColorSurfaceType fb_type; // SceGxmColorSurfaceType
			void *fb_addr; // color surface data addr
			void *fb_depth_addr; // 0
			SceGxmSyncObject *gxm_sync_object;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_PAF_CDLG_H */
