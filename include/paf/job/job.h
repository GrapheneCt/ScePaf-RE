/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_JOB_JOB_H
#define _VDSUITE_USER_PAF_JOB_JOB_H

#include <stdint.h>
#include <scetypes.h>
#include <paf/std/string>
#include <paf/std/list>
#include <paf/common/shared_ptr.h>

namespace paf {
	namespace job {
		
		class DefaultPriority
		{
		public:

			DefaultPriority();

			/**
			* Get default DefaultPriority instance
			*
			* @return ::DefaultThreadPriority
			*/
			static DefaultPriority *Get();

			/**
			* Set default DefaultPriority instance
			*
			*/
			void Set();

			int32_t high;
			int32_t normal;
			int32_t low;

		};

		class JobItem
		{
		public:

			class Option
			{

			};

			enum Status
			{
				Status_None = 0,
				Status_Waiting = 1,
				Status_Running = 2,
				Status_Finished = 3,
			};

			JobItem(char const* name, Option const* option = NULL);

			virtual ~JobItem();

			virtual SceVoid Cancel();

			virtual SceVoid Run() = 0;

			virtual SceVoid Finish() = 0;

			bool IsCanceled() const;

		private:

			string name;
			Status status;
			int32_t result;
			bool canceled;
		};

		class JobQueue
		{
		public:

			class Option
			{
			public:

				Option();

				~Option() { };

				SceInt32 workerPriority;
				SceSize workerStackSize;
				SceUInt32 workerNum;
				thread::Thread::Option *workerOpt;

			};

			static void Init(const Option *option = NULL);

			static void Exit();

			static void CheckAllQueues();

			static uint32_t NumQueues();

			JobQueue(const char *_name, const Option *option = NULL);

			~JobQueue();

			int32_t Enqueue(common::SharedPtr<JobItem>& job_item);

			void WaitEmpty();

			void ChangePriority(int32_t priority);

			void CancelAllItems();

			void Check();

			uint32_t NumItems() const;

			__declspec (dllimport) static JobQueue default_queue;

			__declspec (dllimport) static list<JobQueue*> queue_list;

		private:

			string name;
			char work[0x20];
		};

	}
}

#endif /* _VDSUITE_USER_PAF_JOB_JOB_H */