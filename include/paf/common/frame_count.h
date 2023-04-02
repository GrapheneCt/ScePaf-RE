/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_FRAME_COUNT_H
#define _VDSUITE_USER_PAF_COMMON_FRAME_COUNT_H

#include <stdint.h>

namespace paf {
	namespace common {
		namespace internal {

			extern void IncrFrameCount();

			extern void ResetFrameCount();
		}

		extern uint32_t FrameCount();
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_FRAME_COUNT_H */
