/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_CACHE_CACHE_MANAGER_H
#define _VDSUITE_USER_PAF_CACHE_CACHE_MANAGER_H

#include <stdint.h>
#include <stddef.h>
#include <paf/std/memory>
#include <paf/std/list>
#include <paf/cache/cache_base.h>

namespace paf {

	namespace job {

		class JobQueue;
	}

	namespace graph {

		class SurfacePool;
	}

	namespace cache {

		class CacheManagerImpl;

		class CacheManager
		{
		public:

			typedef bool(*CancelFunc)(void *userdata);
			typedef bool(*CheckCache)(CacheBase*);

			enum JobQueueType
			{
				JOBQ_TYPE_LOCAL = 0,
				JOBQ_TYPE_NET = 1,
				JOBQ_TYPE_OPERATING = 2,
				JOBQ_TYPE_MAX = 255
			};

			class Params
			{
			public:

				string name;
				memory::HeapAllocator *longlife_heap;
				memory::HeapAllocator *instant_heap;
				memory::HeapAllocator *cache_instance_heap;		// NULL
				uint8_t longlife_heap_align_size;				// 4
				uint8_t instant_heap_align_size;				// 4
				graph::SurfacePool *surface_pool;
				CancelFunc cancel_func;
				void *cancel_userdata;
				bool cache_longlife_heap;
				bool image_cache_divide_thread;
				int32_t unk_2C; // 0
				int32_t unk_30; // 0
				uint8_t unk_34; // 1 -> 0
				uint8_t unk_35; // 0
				uint8_t unk_36; // 0 -> 1
				int32_t unk_38; // 0
				int32_t unk_3C; // 0
				uint32_t local_job_prio;
				uint32_t net_job_prio;
				uint32_t operating_job_prio;
			};

			static CacheManager *GetCacheManager(string const& name);

			static size_t GetCacheManagerCount();

			static job::JobQueue *GetJobQueue(JobQueueType t);

			static job::JobQueue *GetJobQueue(string const& path, job::JobQueue *q);

			static int32_t GetTicks()
			{
				return m_ticks;
			}

			CacheManager(const Params *param);

			virtual ~CacheManager();

			int32_t GetQueuedJobCount();

			string& GetName() const;

			int32_t GetCacheCount();

			void Touch();

			int32_t CreateCache(string const& path, intrusive_ptr<CacheBase>& ptr, const CacheBase::Option *option, job::JobQueue *q);

			int32_t FindCache(string const& path, intrusive_ptr<CacheBase>& ptr);

			void RequestShutdown();

			int32_t CreateDefaultJobQueue(Params const *params);

			int32_t DestroyDefaultJobQueue();

		private:

			CacheManagerImpl *m_impl;
			int32_t m_unk_08;

			__declspec (dllimport) static job::JobQueue *m_jobq_local;
			__declspec (dllimport) static job::JobQueue *m_jobq_net;
			__declspec (dllimport) static job::JobQueue *m_jobq_operating;
			__declspec (dllimport) static list<CacheManager*> m_cache_list;
			__declspec (dllimport) static int32_t m_ticks;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_CACHE_CACHE_MANAGER_H */
