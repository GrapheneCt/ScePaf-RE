/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_THREADID_H
#define _VDSUITE_USER_PAF_THREAD_THREADID_H

#include <stdint.h>
#ifdef __SNC__
#include <scetypes.h>
#else
#include <psp2/types.h>
#endif

typedef SceUID ThreadID;

namespace paf {
	namespace thread {
		namespace ThreadIDCache {

			enum Type
			{
				Type_Main,
				Type_MAX
			};

			extern void SetCurrentType(Type type);

			extern ThreadID Get(Type type);

			extern bool Check(Type type = Type_Main);
		}
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_THREADID_H */