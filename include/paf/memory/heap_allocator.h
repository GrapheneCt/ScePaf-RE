/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_HEAP_ALLOCATOR_H
#define _VDSUITE_USER_PAF_HEAP_ALLOCATOR_H

#include <stdint.h>
#include <stddef.h>
#include <paf/std/__stdc__.h>
#include <paf/memory/allocator.h>
#include <paf/thread/mutex.h>

namespace paf {
	namespace memory {

		class HeapInfo
		{
		public:

			int32_t num_of_free;
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
			virtual char *GetName() const;
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

			void sce_paf_musable_size(void *ptr);

			void sce_paf_dump_heap_status();

			void sce_paf_dump_heap_info(int32_t sort_policy);

			int32_t sce_paf_report_memoryblocks(sce_paf_report_memoryblocks_callback callback, void *userdata);

			int32_t sce_paf_check_memoryleaks(void *addr1, void *addr2);

			int32_t sce_paf_check_memorybounds();

			int32_t CheckMemoryBounds(void *ptr);

			void QueryInfo(HeapInfo *info);

		private:

			void* heap_id;
			void* heap_addr;
			size_t heap_size;
			char heap_name[32];
			bool memory_attached;
			bool heap_disable_dbgprint;
			bool heap_disable_assert_on_alloc_failure;
			thread::Mutex mutex;
			SceUID memblk_id;
			uint32_t heap_memblk_type;
		};

		static inline HeapAllocator *GetGlobalHeapAllocator()
		{
			return (HeapAllocator *)::GetGlobalHeapAllocator();
		}
	}
}

#endif /* _VDSUITE_USER_PAF_HEAP_ALLOCATOR_H */