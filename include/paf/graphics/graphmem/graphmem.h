/*
	ScePaf-RE Project
*/

#ifndef _PAF_GRAPHICS_GRAPHMEM_GRAPHMEM_H
#define _PAF_GRAPHICS_GRAPHMEM_GRAPHMEM_H

#include <stdint.h>
#include <stddef.h>
#include <paf/common/shared_ptr.h>
#include <paf/memory/heap_allocator.h>

namespace paf {
	namespace GraphMem {

		class GraphHeapAllocator : public memory::HeapAllocator
		{
		public:

			GraphHeapAllocator(void *_heap_addr, size_t _heap_size, const char *_heap_name);

			virtual ~GraphHeapAllocator();
		};

		enum DeviceType : int32_t
		{
			DeviceType_SystemMemory,
			DeviceType_VideoMemory,
			DeviceType_SharedMemory
		};

		enum ModeType : int32_t
		{
			ModeType_Normal = 0,
			ModeType_CommonDialog = 1
		};

		class Option
		{
		public:

			enum MemoryType : int32_t
			{
				MemoryType_Default,
				MemoryType_Tool,
				MemoryType_Phycont
			};

			enum GpuMapType : int32_t
			{
				GpuMapType_Default,
				GpuMapType_VertexUsse,
				GpuMapType_FragmentUsse,
				GpuMapType_NoMap
			};

			Option()
			{
				type = MemoryType_Default;
				memblock_option = NULL;
				gpu_map_type = GpuMapType_Default;
				gpu_map_attrib = 1 | 2;
				gpu_usse_offset = 0;
				reserved = 0;
			}

			MemoryType type;
			SceKernelAllocMemBlockOpt *memblock_option;
			GpuMapType gpu_map_type;
			uint32_t gpu_map_attrib;
			uint32_t gpu_usse_offset;
			uint32_t reserved;
		};

		extern void *AllocOSMemory(DeviceType device_type, size_t size, const char *name, Option* option = NULL);

		extern void FreeOSMemory(DeviceType device_type, void *p);

		extern void Exit();

		extern common::WeakPtr<GraphHeapAllocator> SystemMemoryHeap();

		extern common::WeakPtr<GraphHeapAllocator> VideoMemoryHeap();
	}
}

#endif /* _PAF_GRAPHICS_GRAPHMEM_GRAPHMEM_H */
