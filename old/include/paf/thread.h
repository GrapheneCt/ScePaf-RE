/*
	Vita Development Suite Libraries git-9c2c72f1
*/

#ifndef _VDSUITE_USER_PAF_THREAD_H
#define _VDSUITE_USER_PAF_THREAD_H

#include <kernel.h>

namespace paf {
	namespace thread {

		class DefaultThreadPriority
		{
		public:

			DefaultThreadPriority();

			/**
			* Get default DefaultThreadPriority instance
			*
			* @return ::DefaultThreadPriority
			*/
			static DefaultThreadPriority *Get();

			/**
			* Set default DefaultThreadPriority instance
			*
			*/
			SceVoid Set();

			SceInt32 priority1;
			SceInt32 priority2;
			SceInt32 priority3;

		};

		class Thread
		{
		public:

			class Option
			{
			public:

				Option();

				~Option() { };

				SceUInt32 attr;
				SceInt32 cpuAffinityMask;
				SceKernelMemBlockType stackMemoryType;

			};

			Thread(SceInt32 initPriority, SceSize stackSize, const char *pName, const Option *opt = SCE_NULL);

			virtual ~Thread();

			virtual SceVoid EntryFunction() = 0;

			/**
			* Wait for thread completion. This function wraps sceKernelWaitThreadEnd()
			*
			*/
			SceVoid Join();

			/**
			* Change thread priority. This function wraps sceKernelChangeThreadPriority()
			*
			* @param[in] priority - New thread priority
			*
			*/
			SceVoid ChangePriority(SceInt32 priority);

			/**
			* Get thread UID
			*
			* @return valid SceUID on success, < 0 on error.
			*/
			SceUID GetID();

			/**
			* Start thread
			*
			* @return 0 on success, < 0 on error.
			*/
			SceInt32 Start();

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
			SceVoid Cancel();

			/**
			* Check if thread is canceled
			*
			* @return true if thread is canceled, false otherwise.
			*/
			bool IsCanceled();

			static SceInt32 PafThreadProc(SceSize argSize, ScePVoid pArgBlock);

		private:

			SceUChar8 m_work[0x14];

		};

		class Semaphore
		{
		public:

			Semaphore(const char *pName, SceInt32 initCount, SceInt32 maxCount, SceInt32 unused = 0);

			~Semaphore();

			/**
			* Wait for semaphore signal. This function wraps sceKernelWaitSema()
			*
			*/
			SceVoid Acquire();

			/**
			* Signal semaphore. This function wraps sceKernelSignalSema()
			*
			*/
			SceVoid Release();

		private:

			SceUID m_uid;

		};

		class Mutex
		{
		public:

			Mutex(const char *pName, SceInt32 isFifo);

			~Mutex();

			SceVoid Lock();

			bool TryLock();

			SceVoid Unlock();

		private:

			SceInt64 m_work[4];

		};

		class RMutex
		{
		public:

			RMutex(const char *pName, SceInt32 isFifo);

			~RMutex();

			SceVoid Lock();

			bool TryLock();

			SceVoid Unlock();

		private:

			SceInt64 m_work[4];

		};

		class Cond
		{
		public:

			Cond(Mutex& mutex, const char *pName, SceInt32 isFifo);

			~Cond();

			bool Wait(SceInt32 timeoutMsec = 0);

			SceVoid Notify();

			SceVoid NotifyAll();

		private:

			SceInt32 m_work[5];

		};

		class RWLock
		{
		public:

			RWLock(const char *pName, SceInt32 unused = 0);

			~RWLock();

			SceVoid LockShared();

			SceVoid UnlockShared();

			SceVoid LockExclusive();

			SceVoid UnlockExclusive();

		private:

			SceUID evf;
			SceInt32 counter;

		};

		class CallQueue
		{
		public:

			typedef void(*CallQueueEntryFunction)(void *pArgBlock);

			CallQueue(const char *pName);

			~CallQueue();

			SceVoid WaitEmpty();

			SceVoid Enqueue(const char *pName, CallQueueEntryFunction entry, ScePVoid pArgBlock);

			SceVoid Check();

			SceUInt32 GetSize();

		private:

			SceUChar8 m_work[0x30];

		};

		class SyncCall
		{
		public:

			typedef void(*SyncCallEntryFunction)(void *pArgBlock);

			SyncCall(const char *pName);

			~SyncCall();

			SceVoid Enqueue(SyncCallEntryFunction entry, ScePVoid pArgBlock);

			SceVoid Check();

		private:

			SceUChar8 m_work[0x10];

		};

		extern SceVoid SetMainThread(SceInt32 threadNum = 0);

		extern SceUID GetMainThread(SceInt32 threadNum = 0);

		extern bool IsMainThread(SceInt32 threadNum = 0);

		extern SceVoid Sleep(SceInt32 msec);

		//VARIABLES

		__declspec (dllimport) SyncCall s_mainThreadSyncCall;

		__declspec (dllimport) CallQueue s_mainThreadQueue;

		__declspec (dllimport) RMutex s_mainThreadMutex;
	}

	namespace job {

		class JobItem
		{
		public:

			JobItem(const char *pName);

			virtual ~JobItem();

			virtual SceVoid Cancel();

			virtual SceVoid Run() = 0;

			virtual SceVoid Finish() = 0;

			bool IsCanceled();

			paf::string name;

		private:

			SceUChar8 m_work[0x10];

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

			static SceVoid Init(JobQueue::Option *opt);

			static SceVoid Exit();

			JobQueue(const char *pName, const Option *opt = SCE_NULL);

			~JobQueue();

			SceInt32 Enqueue(common::SharedPtr<JobItem>& queueItem);

			SceVoid WaitEmpty();

			SceUInt32 GetSize();

			SceVoid ChangeWorkerPriority(SceInt32 priority);

			SceVoid Finish();

			SceVoid Check();

			paf::string name;

		private:

			SceUChar8 m_work[0x20];

		};

		//VARIABLES

		__declspec (dllimport) JobQueue *s_defaultJobQueue;
	}
}

#endif /* _VDSUITE_USER_PAF_THREAD_H */
