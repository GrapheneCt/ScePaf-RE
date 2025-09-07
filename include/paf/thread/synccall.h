/*
	ScePaf-RE Project
*/

#ifndef _PAF_THREAD_SYNCCALL_H
#define _PAF_THREAD_SYNCCALL_H

#include <stdint.h>
#include <paf/paf_types.h>
#if defined(__SNC__)
#include <scetypes.h>
#define SCE_PAF_SYNCCALL_TYPE SceUID
#elif defined(__vita__)
#include <psp2/types.h>
#define SCE_PAF_SYNCCALL_TYPE SceUID
#elif defined(_WIN32)
#include <Windows.h>
class MultiBitEventFlag;
#define SCE_PAF_SYNCCALL_TYPE MultiBitEventFlag*
#else
#error Current target platform is not supported or no target platform defined
#endif

namespace paf {
	namespace thread {

		class SyncCall
		{
		public:

			typedef int32_t(*Function)(void *userdata);

			static SyncCall *MainThreadSyncCall()
			{
				return &main_thread_synccall;
			}

			SyncCall(const char *name);

			~SyncCall();

			int32_t Call(Function entry, void *userdata = NULL);

			void Check();

		private:

			SCE_PAF_IMPORTED_FROM_PRX static SyncCall main_thread_synccall;

			SCE_PAF_SYNCCALL_TYPE m_evf;
			Function m_func;
			void *m_arg;
			int32_t m_result;
		};
	}
}

#endif /* _PAF_THREAD_SYNCCALL_H */