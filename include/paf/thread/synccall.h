/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_SYNCCALL_H
#define _VDSUITE_USER_PAF_THREAD_SYNCCALL_H

#include <stdint.h>
#ifdef __SNC__
#include <scetypes.h>
#else
#include <psp2/types.h>
#endif
#include <paf/paf_types.h>

namespace paf {
	namespace thread {

		class SyncCall
		{
		public:

			typedef int32_t(*Function)(void *userdata);

			SyncCall(const char *name);

			~SyncCall();

			void Call(Function entry, void *userdata);

			void Check();

			SCE_PAF_IMPORTED_FROM_PRX static SyncCall main_thread_synccall;

		private:

			SceUID evf;
			char work[0x0C];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_SYNCCALL_H */