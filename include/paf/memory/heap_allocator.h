/*
	ScePaf-RE Project
*/

#ifndef _PAF_HEAP_ALLOCATOR_H
#define _PAF_HEAP_ALLOCATOR_H

#include <stdint.h>
#include <stddef.h>
#include <paf/std/stdc.h>
#include <paf/memory/allocator.h>
#include <paf/thread/mutex.h>

#if defined(__SNC__)
#include <scetypes.h>
#define SCE_PAF_MEMBLOCK_TYPE SceUID
#elif defined(__vita__)
#include <psp2/types.h>
#define SCE_PAF_MEMBLOCK_TYPE SceUID
#elif defined(_WIN32)
#define SCE_PAF_MEMBLOCK_TYPE void*
#else
#error Current target platform is not supported or no target platform defined
#endif

namespace paf {
	namespace memory {

		class HeapInfo
		{
		public:

			size_t num_of_free;
			size_t total_free_size;
		};

		class HeapAllocator : public MemoryAllocator
		{
		public:

			class Option
			{
			public:

				uint32_t entry_max;
				size_t warning_size;
				bool disable_dbgprint;
				bool disable_assert_on_alloc_failure;
				AllocationBlockType memblk_type;
				uint32_t alignment;
			};

			HeapAllocator(void *_heap_addr, size_t _heap_size, const char *_heap_name, const Option *option = NULL);

			virtual uint32_t GetType() const;
			virtual AllocationBlockType GetBlockType() const;
			virtual const char *GetName() const;
			virtual void GetRange(void **membase, size_t *size) const;
			virtual size_t GetFreeSize();

			virtual ~HeapAllocator();

			void sce_paf_free(void *ptr);

			void sce_paf_free_d(void *ptr, const char *filename = NULL, int32_t lineno = 0, int32_t type = 0);

			void sce_paf_mtrim();

			void *sce_paf_calloc(size_t nitems, size_t size);

			void *sce_paf_calloc_d(size_t nitems, size_t size, const char *filename = NULL, int32_t lineno = 0, int32_t type = 0);

			void *sce_paf_malloc(size_t size);

			void *sce_paf_malloc_d(size_t size, const char *filename = NULL, int32_t lineno = 0, int32_t type = 0);

			void *sce_paf_realloc(void *ptr, size_t size);

			void *sce_paf_realloc_d(void *ptr, size_t size, const char *filename = NULL, int32_t lineno = 0, int32_t type = 0);

			void *sce_paf_memalign(size_t alignment, size_t size);

			void *sce_paf_memalign_d(size_t alignment, size_t size, const char *filename = NULL, int32_t lineno = 0, int32_t type = 0);

			size_t sce_paf_musable_size(void *ptr);

			void sce_paf_dump_heap_status();

			void sce_paf_dump_heap_info(int32_t sort_policy);

			int32_t sce_paf_report_memoryblocks(sce_paf_report_memoryblocks_callback callback, void *userdata);

			int32_t sce_paf_check_memoryleaks(void *addr1, void *addr2);

			int32_t sce_paf_check_memorybounds();

			int32_t CheckMemoryBounds(void *ptr);

			void QueryInfo(HeapInfo *info);

		private:

			void* m_heap_id;
			void* m_heap_addr;
			size_t m_heap_size;
			char m_heap_name[32];
			bool m_memory_attached;
			bool m_heap_disable_dbgprint;
			bool m_heap_disable_assert_on_alloc_failure;
			thread::Mutex m_mutex;
			SCE_PAF_MEMBLOCK_TYPE m_memblk_id;
			paf::memory::AllocationBlockType m_heap_memblk_type;
		};
	}
}

#endif /* _PAF_HEAP_ALLOCATOR_H */