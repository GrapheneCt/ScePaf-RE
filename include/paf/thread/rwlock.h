/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_RWLOCK_H
#define _VDSUITE_USER_PAF_THREAD_RWLOCK_H

#include <stdint.h>
#ifdef __SNC__
#include <scetypes.h>
#else
#include <psp2/types.h>
#endif

namespace paf {
	namespace thread {

		class RWLock
		{
		public:

			enum Option
			{
				Option_None = 0,
				Option_Default = 0
			};

			RWLock(const char *name, int32_t option = Option_Default);

			~RWLock();

			void LockShared();

			void UnlockShared();

			void LockExclusive();

			void UnlockExclusive();

		private:

			SceUID evf;
			int32_t counter;

		};
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_RWLOCK_H */