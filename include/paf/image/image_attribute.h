/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_IMAGE_IMAGE_ATTRIBUTE_H
#define _VDSUITE_USER_PAF_IMAGE_IMAGE_ATTRIBUTE_H

#include <stddef.h>
#include <stdint.h>
#include <paf/paf_types.h>
#include <paf/image/image_types.h>
#include <paf/image/image_region.h>

namespace paf {
	namespace image {

		class ImageAttribute
		{
		public:

			static size_t GetPixelSize(ImageMode mode);

			static uint32_t CalcMemSize(uint32_t width, uint32_t height, uint16_t pitchalign, uint16_t heightalign, ImageMode mode, ImageFormat format);

			ImageAttribute();

			~ImageAttribute();

			size_t GetPixelSizeInBits() const;

			size_t GetPixelSizeInBytes() const;

			size_t GetCLUTPixelSizeInBits() const;

			size_t GetCLUTPixelSizeInBytes() const;

			ImageExtent GetExtent(uint32_t sce_paf_index) const;

			size_t GetMemPitch(uint32_t sce_paf_index) const;

			uint32_t GetMemHeight(uint32_t sce_paf_index) const;

			uint32_t GetMemSize(uint32_t sce_paf_index) const;

			uint32_t GetCLUTSize() const
			{
				return m_clutsize;
			}

			ImageFormat GetFormat() const
			{
				return m_format;
			}

			ImageMode GetMode() const
			{
				return m_mode;
			}

			ImageMode GetCLUTMode() const
			{
				return m_clutmode;
			}

			ImageOrder GetOrder() const
			{
				return m_order;
			}

			ImageResizeType GetResizeType() const
			{
				return m_resizetype;
			}

			ImageXType GetXType()
			{
				return m_xtype;
			}

			ImageYType GetYType()
			{
				return m_ytype;
			}

			uint16_t GetPitchAlign() const
			{
				return m_pitchalign;
			}

			uint16_t GetHeightAlign() const
			{
				return m_heightalign;
			}

		private:

			ImageMode m_mode;
			ImageMode m_clutmode;
			ImageOrder m_order;
			uint32_t m_clutsize;
			ImageExtent m_originalextent;
			ImageExtent m_extent;
			ImageRect m_clip;
			ImageRect m_subrect;
			ImageFormat m_format;
			ImageXType m_xtype;
			ImageYType m_ytype;
			uint16_t m_pitchalign;
			uint16_t m_heightalign;
			ImageResizeType m_resizetype;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_IMAGE_IMAGE_ATTRIBUTE_H */
