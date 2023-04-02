/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_CACHE_CACHE_MANAGER_IMPL_H
#define _VDSUITE_USER_PAF_CACHE_CACHE_MANAGER_IMPL_H

#include <stdint.h>
#include <stddef.h>
#include <paf/paf_types.h>
#include <paf/std/map>
#include <paf/std/vector>
#include <paf/std/string>
#include <paf/thread/rmutex.h>
#include <paf/cache/cache_base.h>
#include <paf/cache/cache_manager.h>

namespace paf {

	namespace job {

		class JobQueue;
	}

	namespace memory {

		class HeapAllocator;
	}

	namespace graph {

		class SurfacePool;
	}

	namespace cache {

		class CacheJobRunner;
		class CacheManagerImpl;

		class CacheManagerImpl
		{
		public:

			static void ClearCacheAll(CacheManagerImpl *man);

			static thread::RMutex& GetMutex()
			{
				return m_rmutex;
			}

			CacheManagerImpl(const CacheManager::Params *param);

			virtual ~CacheManagerImpl();

			int32_t RemoveCache(CacheBase *base);

			bool CheckCacheAll(CacheManager::CheckCache func, CacheBase **base);

			uint32_t GetCacheCount();

			void SetShutdownFlag(bool f);

			void FreeLongLifeHeap(void *addr);

			void FreeInstantHeap(void *addr);

			void *AllocLongLifeHeap(size_t size);

			void *AllocInstantHeap(size_t size);

			int32_t EnqueueCache(CacheBase *base, uint32_t sce_paf_index);

			int32_t AddCache(CacheBase *base, job::JobQueue *job0, job::JobQueue *job1);

			memory::HeapAllocator *GetCacheInstanceHeap()
			{
				return m_cache_instance_heap;
			}

			memory::HeapAllocator *GetInstantHeap()
			{
				return m_instant_heap;
			}

			memory::HeapAllocator *GetLongLifeHeap()
			{
				return m_longlife_heap;
			}

			size_t GetInstantHeapAlignSize()
			{
				return m_instant_align_size;
			}

			CacheManager::CancelFunc GetCancelCallBack()
			{
				return m_cancel_func;
			}

			void *GetCancelCallBackData()
			{
				return m_cancel_userdata;
			}

			bool GetImageCacheDivideThreadFlag()
			{
				return m_image_cache_divide_thread;
			}

			bool GetShutdownFlag()
			{
				return m_is_shutdown;
			}

			graph::SurfacePool *GetSurfacePool()
			{
				return m_surface_pool;
			}

			string& GetName()
			{
				return m_name;
			}

		private:

			memory::HeapAllocator *m_longlife_heap;
			memory::HeapAllocator *m_instant_heap;
			memory::HeapAllocator *m_cache_instance_heap;
			size_t m_longlife_align_size;
			size_t m_instant_align_size;
			string m_name;
			map<string, vector<void*>> m_caches;
			bool(*m_cancel_func)(void *);
			void *m_cancel_userdata;
			int32_t m_unk_38;
			int32_t m_unk_3C;
			bool m_unk_40;
			bool m_is_shutdown;
			bool m_cache_longlife_heap;
			int32_t m_unk_44;
			bool m_image_cache_divide_thread;
			uint32_t m_http_file_open_flag;
			uint32_t m_https_flag;
			graph::SurfacePool *m_surface_pool;

			__declspec (dllimport) static thread::RMutex m_rmutex;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_CACHE_CACHE_MANAGER_IMPL_H */
