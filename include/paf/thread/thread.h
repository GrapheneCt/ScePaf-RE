/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_THREAD_THREAD_H
#define _VDSUITE_USER_PAF_THREAD_THREAD_H

#include <stdint.h>
#include <scetypes.h>
#include <kernel/types.h>
#include <paf/thread/threadid.h>

namespace paf {
	namespace thread {

		class Thread
		{
		public:

			class Option
			{
			public:

				Option();

				~Option() { };

				uint32_t attr;
				int32_t affinity;
				SceKernelMemBlockType stack_memory_type;

			};

			static SceInt32 ThreadFunc(SceSize sz, void *args);

			Thread(int32_t priority, uint32_t stack_size, const char *name, const Option *option = NULL);

			virtual ~Thread();

			virtual void EntryFunction() = 0;

			/**
			* Wait for thread completion. This function wraps sceKernelWaitThreadEnd()
			*
			*/
			void Join();

			/**
			* Change thread priority. This function wraps sceKernelChangeThreadPriority()
			*
			* @param[in] priority - New thread priority
			*
			*/
			void ChangePriority(int32_t priority);

			/**
			* Get thread ThreadID
			*
			* @return valid ThreadID on success, < 0 on error.
			*/
			ThreadID GetID();

			/**
			* Start thread
			*
			* @return 0 on success, < 0 on error.
			*/
			int32_t Start();

			/**
			* Check if thread is alive
			*
			* @return true if thread is alive, false otherwise.
			*/
			bool IsAlive();

			/**
			* Cancel thread
			*
			*/
			void Cancel();

			/**
			* Check if thread is canceled
			*
			* @return true if thread is canceled, false otherwise.
			*/
			bool IsCanceled();

		private:

			SceUID thid;
			bool started;
			bool alive;
			bool canceled;
		};

		extern void Sleep(int32_t milisec);
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_THREAD_H */