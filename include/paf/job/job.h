/*
	ScePaf-RE Project
*/

#ifndef _PAF_JOB_JOB_H
#define _PAF_JOB_JOB_H

#include <stdint.h>
#include <paf/std/stdcxx.h>
#include <paf/common/shared_ptr.h>
#include <paf/thread/thread.h>
#include <paf/thread/semaphore.h>
#include <paf/paf_types.h>

namespace paf {
	namespace job {
		
		class DefaultPriority
		{
		public:

			DefaultPriority();

			DefaultPriority(int32_t high, int32_t normal, int32_t low);

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

			enum Status : int32_t
			{
				Status_None = 0,
				Status_Waiting = 1,
				Status_Running = 2,
				Status_Finished = 3,
			};

			JobItem(char const* name, Option const* option = NULL);

			virtual ~JobItem();

			virtual void Cancel();

			virtual int32_t Run() = 0;

			virtual void Finish(int32_t result) = 0;

			void SetResult(int32_t res)
			{
				m_result = res;
			}

			void SetStatus(Status st)
			{
				m_status = st;
			}

			Status GetStatus() const
			{
				return m_status;
			}

			int32_t GetResult() const
			{
				return m_result;
			}

			bool IsCanceled() const;

		private:

			string m_name;
			Status m_status;
			int32_t m_result;
			bool m_canceled;
		};

		class JobQueue
		{
		public:

			class Option
			{
			public:

				Option();

				~Option() { };

				int32_t priority;
				size_t stack_size;
				uint32_t num_thread;
				thread::Thread::Option *worker_opt;
			};

			static JobQueue *DefaultQueue()
			{
				return default_queue;
			}

			static void Init(const Option *option = NULL);

			static void Exit();

			static void CheckAllQueues();

			static size_t NumQueues();

			JobQueue(const char *_name, const Option *option = NULL);

			~JobQueue();

			int32_t Enqueue(common::SharedPtr<JobItem>& job_item);

			void WaitEmpty();

			void ChangePriority(int32_t priority);

			void CancelAllItems();

			void Check();

			size_t NumItems() const;

			SCE_PAF_IMPORTED_FROM_PRX static list<JobQueue*> queue_list;

		private:

			SCE_PAF_IMPORTED_FROM_PRX static JobQueue *default_queue;

			class JobThread : public thread::Thread
			{
			public:

				JobThread(int32_t _priority, size_t _stack_size, const char *_name, thread::Thread::Option *_opt) :
					paf::thread::Thread(_priority, _stack_size, _name, _opt),
					m_sema("ScePafJobThread", 0, 1, 0)
				{

				}

				~JobThread()
				{

				}

				void EntryFunction();

				void Cancel()
				{
					Thread::Cancel();
					m_sema.Release();
				}

				void SetItem(common::SharedPtr<JobItem>& job_item)
				{
					m_item = job_item;
					m_sema.Release();
				}

				bool IsBusy() const
				{
					return (m_item.get());
				}

			private:

				thread::Semaphore m_sema;
				common::SharedPtr<JobItem> m_item;
			};

			string m_name;
			bool m_calling_finish;
			list<JobThread *> m_thread_list;
			list<common::SharedPtr<JobItem>> m_item_list;
			list<common::SharedPtr<JobItem>>::iterator m_iter;
		};
	}
}

#endif /* _PAF_JOB_JOB_H */