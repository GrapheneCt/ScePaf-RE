/*
	ScePaf-RE Project
*/

#ifndef _PAF_THREAD_THREAD_H
#define _PAF_THREAD_THREAD_H

#include <stdint.h>
#if defined(__SNC__)
#include <scetypes.h>
#include <kernel/types.h>
#define SCE_PAF_THREAD_TYPE SceUID
#elif defined(__vita__)
#include <psp2/types.h>
#include <psp2/kernel/sysmem.h>
#define SCE_KERNEL_CPU_MASK_SHIFT						(16)
#define SCE_KERNEL_COMMON_QUEUE_LOWEST_PRIORITY			(191)
#define SCE_KERNEL_COMMON_QUEUE_HIGHEST_PRIORITY		(128)
#define SCE_KERNEL_DEFAULT_PRIORITY						(0x10000100)
#define SCE_KERNEL_INDIVIDUAL_QUEUE_LOWEST_PRIORITY		(127)
#define SCE_KERNEL_INDIVIDUAL_QUEUE_HIGHEST_PRIORITY	(64)
#define SCE_PAF_THREAD_TYPE SceUID
#elif defined(_WIN32)
#include <Windows.h>
#define SCE_PAF_THREAD_TYPE HANDLE
#else
#error Current target platform is not supported or no target platform defined
#endif

#include <paf/thread/threadid.h>

namespace paf {
	namespace thread {

		class Thread
		{
		public:

			static constexpr int32_t Priority_Default = -1;

#if defined(__SNC__) || defined(__vita__)

			enum
			{
				Affinity_Core0 = SCE_KERNEL_CPU_MASK_USER_0,
				Affinity_Core1 = SCE_KERNEL_CPU_MASK_USER_1,
				Affinity_Core2 = SCE_KERNEL_CPU_MASK_USER_2,
				Affinity_Core3 = (0x08 << SCE_KERNEL_CPU_MASK_SHIFT),
				Affinity_All = SCE_KERNEL_CPU_MASK_USER_ALL
			};

			enum
			{
				Priority_Lowest = SCE_KERNEL_COMMON_QUEUE_LOWEST_PRIORITY,
				Priority_BelowNormal = SCE_KERNEL_COMMON_QUEUE_HIGHEST_PRIORITY,
				Priority_Normal = SCE_KERNEL_DEFAULT_PRIORITY,
				Priority_AboveNormal = SCE_KERNEL_INDIVIDUAL_QUEUE_LOWEST_PRIORITY,
				Priority_Highest = SCE_KERNEL_INDIVIDUAL_QUEUE_HIGHEST_PRIORITY
			};

			static int32_t ThreadFunc(size_t sz, void *args);

#elif defined(_WIN32)

			enum
			{
				Affinity_Core0,
				Affinity_Core1,
				Affinity_Core2,
				Affinity_Core3,
				Affinity_All = 0xFFFFFFFF
			};

			enum
			{
				Priority_Lowest = THREAD_PRIORITY_LOWEST,
				Priority_BelowNormal = THREAD_PRIORITY_BELOW_NORMAL,
				Priority_Normal = THREAD_PRIORITY_NORMAL,
				Priority_AboveNormal = THREAD_PRIORITY_ABOVE_NORMAL,
				Priority_Highest = THREAD_PRIORITY_HIGHEST
			};

			static DWORD WINAPI ThreadFunc(LPVOID arg);
#endif

			class Option
			{
			public:

				Option(uint32_t _attr, int32_t _affinity, uint32_t _stack_memory_type) : attr(_attr), affinity(_affinity), stack_memory_type(_stack_memory_type) { }

				Option();

				~Option() { }

				uint32_t attr;
				int32_t affinity;
				uint32_t stack_memory_type;

			};

			Thread(int32_t priority, size_t stack_size, const char *name, const Option *option = NULL);

			virtual ~Thread();

			virtual void EntryFunction() = 0;

			/**
			* Wait for thread completion
			*
			*/
			void Join();

			/**
			* Change thread priority
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

			SCE_PAF_THREAD_TYPE m_thid;
			bool m_started;
			bool m_alive;
			bool m_canceled;
		};

		extern void Sleep(int32_t milisec);
	}
}

#endif /* _PAF_THREAD_THREAD_H */