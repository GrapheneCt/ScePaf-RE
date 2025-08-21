/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_SYNCCALL_H
#define _VDSUITE_USER_PAF_THREAD_SYNCCALL_H

#include <stdint.h>
#include <scetypes.h>

namespace paf {
	namespace thread {

		class SyncCall
		{
		public:

			typedef void(*Function)(void *userdata);

			SyncCall(const char *name);

			~SyncCall();

			void Enqueue(Function entry, void *userdata);

			void Check();

			__declspec (dllimport) static SyncCall main_thread_synccall;

		private:

			SceUID evf;
			char work[0x0C];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_SYNCCALL_H */