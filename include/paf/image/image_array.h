/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_IMAGE_IMAGE_ARRAY_H
#define _VDSUITE_USER_PAF_IMAGE_IMAGE_ARRAY_H

#include <stddef.h>
#include <stdint.h>
#include <paf/paf_types.h>
#include <paf/image/image_types.h>
#include <paf/image/image_region.h>
#include <paf/image/image_attribute.h>

namespace paf {

	namespace memory {

		class HeapAllocator;
	}

	namespace image {

		class ImageArray
		{
		public:

			ImageArray(memory::HeapAllocator *allocator);

			~ImageArray();

			bool Init(uint32_t max_x, uint32_t max_y);

			bool Init(ImagePoint const& sce_paf_index);

			bool SetCLUTSize(const ImageAttribute *attr);

			bool Free();

			bool Alloc();

			bool Reset();

			bool SetLink();

			bool SetSize(uint32_t sce_paf_index, size_t size);

			bool SetSize(const ImageAttribute *attr);

			bool SetSize(ImagePoint const& sce_paf_index, SceUInt32 size);

			ImageArray& operator=(ImageArray const& s);

			ImagePoint GetArraySize() const;

			uint32_t GetMax() const;

			bool IsEmpty() const;

			ImageBuffer *GetBuffer(uint32_t sce_paf_index) const;

			ImageBuffer *GetBuffer(ImagePoint const& sce_paf_index) const;

			memory::HeapAllocator *GetHeapAllocator() const
			{
				return m_allocator;
			}

		private:

			ImageBuffer *m_array;
			memory::HeapAllocator *m_allocator;
			ImagePoint m_arraysize;
			bool m_needfree;
			bool m_empty;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_IMAGE_IMAGE_ATTRIBUTE_H */
