/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_GRAPHMEM_GRAPHMEM_H
#define _VDSUITE_USER_PAF_GRAPHICS_GRAPHMEM_GRAPHMEM_H

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

		enum DeviceType
		{
			DeviceType_SystemMemory,
			DeviceType_VideoMemory,
			DeviceType_SharedMemory
		};

		enum ModeType
		{
			ModeType_Normal = 0,
			ModeType_CommonDialog = 1
		};

		class Option
		{
		public:

			enum MemoryType
			{
				MemoryType_Default,
				MemoryType_Tool,
				MemoryType_Phycont
			};

			enum GpuMapType
			{
				GpuMapType_Default,
				GpuMapType_VertexUsse,
				GpuMapType_FragmentUsse,
				GpuMapType_NoMap
			};

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

#endif /* _VDSUITE_USER_PAF_GRAPHICS_GRAPHMEM_GRAPHMEM_H */
