/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_SEMAPHORE_H
#define _VDSUITE_USER_PAF_THREAD_SEMAPHORE_H

#include <stdint.h>
#include <scetypes.h>

namespace paf {
	namespace thread {

		class Semaphore
		{
		public:

			enum Option
			{
				Option_None = 0,
				Option_Default = 0
			};

			Semaphore(const char *name, int32_t init_count, int32_t max_count, int32_t option = Option_None);

			~Semaphore();

			/**
			* Wait for semaphore signal. This function wraps sceKernelWaitSema()
			*
			*/
			void Acquire();

			/**
			* Signal semaphore. This function wraps sceKernelSignalSema()
			*
			*/
			void Release();

		private:

			SceUID sema;

		};
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_SEMAPHORE_H */