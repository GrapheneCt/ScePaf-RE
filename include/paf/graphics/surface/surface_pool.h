/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_POOL_H
#define _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_POOL_H

#include <stdint.h>
#include <stddef.h>
#include <paf/memory/heap_allocator.h>

namespace paf {
	namespace graph {

		class SurfacePoolAllocator
		{
		public:

			SurfacePoolAllocator();

			virtual ~SurfacePoolAllocator()
			{

			}

			virtual void *Allocate(size_t align_bytes, size_t size) = 0;
			virtual void Free(void *ptr) = 0;
			virtual size_t GetFreeSize() = 0;
			virtual int32_t CheckMemoryBounds(void *ptr) = 0;
			virtual void DumpFreeChunk() = 0;
		};

		class SurfacePoolAllocator_Heap
		{
		public:

			SurfacePoolAllocator_Heap(void *addr, size_t size, const char *heap_name, const memory::HeapAllocator::Option *option) : m_heap(NULL)
			{
				m_heap = new memory::HeapAllocator(addr, size, heap_name, option);
			}

			virtual ~SurfacePoolAllocator_Heap()
			{
				delete m_heap;
			}

			virtual void *Allocate(size_t align_bytes, size_t size)
			{
				return m_heap->sce_paf_memalign(align_bytes, size);
			}

			virtual void Free(void *ptr)
			{
				m_heap->sce_paf_free(ptr);
			}

			virtual size_t GetFreeSize()
			{
				return m_heap->GetFreeSize();
			}

			virtual int32_t CheckMemoryBounds(void *ptr)
			{
				return m_heap->CheckMemoryBounds(ptr);
			}

			virtual void DumpFreeChunk()
			{

			}

		private:

			memory::HeapAllocator *m_heap;
		};

		class SurfacePool
		{
		public:

			enum MemoryType
			{
				MemoryType_Normal,
				MemoryType_SharedHost,
				MemoryType_SharedClient,
			};

			class Option
			{
			public:

				void *pool_addr;
				int32_t pool_size;
				char *pool_name;
				paf::memory::HeapAllocator::Option *heap_allocator_option;
				paf::memory::HeapAllocator::Option *fast_allocator_option;
				MemoryType type;
			};

			static SurfacePool *FindPool(const char *name);

			static int32_t GetIndex(SurfacePool *pool);

			static SurfacePool *GetPool(int32_t sce_paf_index);

			SurfacePool(const Option *option);

			SurfacePool(void *pool_addr, int32_t pool_size, const char *pool_name, const memory::HeapAllocator::Option *option = NULL, MemoryType poolType = MemoryType_Normal);

			virtual ~SurfacePool();

			virtual void *Allocate(int32_t align_bytes, int32_t surf_size);
			virtual void Free(void *mem);
			virtual size_t GetFreeSize();

		private:

			SurfacePoolAllocator *m_allocator;
			void *m_addr;
			size_t m_size;
			char *m_name;
			MemoryType m_type;
			SceUID m_shared_uid;
			void *m_shared_addr;
			size_t m_count;
			size_t m_max_usage;
			thread::Mutex m_mutex;

			__declspec (dllimport) static thread::Mutex m_list_mutex;
			__declspec (dllimport) static list<SurfacePool*> m_pool_list;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_POOL_H */
