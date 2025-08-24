/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_HALT_ASSERT_H
#define _VDSUITE_USER_PAF_COMMON_HALT_ASSERT_H

#include <stdbool.h>
#include <paf/paf_types.h>

namespace paf {
	namespace common_internal {

		extern void on_error(void);

		extern void SetErrorCallBack(void(*)());

		extern bool printf_enabled();
	}

	namespace common {

		SCE_PAF_IMPORTED_FROM_PRX extern void* _error_callback;
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_HALT_ASSERT_H */
