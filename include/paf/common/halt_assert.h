/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_HALT_ASSERT_H
#define _VDSUITE_USER_PAF_COMMON_HALT_ASSERT_H

#include <scetypes.h>

namespace paf {
	namespace common_internal {

		extern void on_error(void);

		extern void SetErrorCallBack(void(*)());
	}

	namespace common {

		__declspec (dllimport) void* _error_callback;
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_HALT_ASSERT_H */
