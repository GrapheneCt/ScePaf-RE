/*
	ScePaf-RE Project
*/

#ifndef _PAF_THREAD_THREADID_H
#define _PAF_THREAD_THREADID_H

#include <stdint.h>
#if defined(__SNC__)
#include <scetypes.h>
typedef SceUID ThreadID;
#elif defined(__vita__)
#include <psp2/types.h>
typedef SceUID ThreadID;
#elif defined(_WIN32)
#include <Windows.h>
typedef DWORD ThreadID;
#else
#error Current target platform is not supported or no target platform defined
#endif

namespace paf {
	namespace thread {
		namespace ThreadIDCache {

			enum Type : int32_t
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

#endif /* _PAF_THREAD_THREADID_H */