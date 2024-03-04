/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_IMAGE_IMAGE_TYPES_H
#define _VDSUITE_USER_PAF_IMAGE_IMAGE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <paf/paf_types.h>

namespace paf {
	namespace image {

		enum ImageFormat
		{
			ImageFormat_None = 0,
			ImageFormat_Png = 1,
			ImageFormat_Jpg = 2,
			ImageFormat_Tif = 3,
			ImageFormat_Gif = 4,
			ImageFormat_Bmp = 5,
			ImageFormat_Gim = 6,
			ImageFormat_Dds = 7,
			ImageFormat_Gxt = 8
		};

		enum ImageXType
		{
			ImageXType_None = 0,
			ImageXType_HalfSize = 1,
			ImageXType_ConstantSize = 2
		};

		enum ImageYType
		{
			ImageYType_None = 0,
			ImageYType_Sequence = 1
		};

		enum ImageResizeType
		{
			ImageResizeType_None = 0,
			ImageResizeType_NearestNeighbor = 1,
			ImageResizeType_Linear = 2,
			ImageResizeType_BoxFilter = 3,
			ImageResizeType_BellFilter = 4,
			ImageResizeType_HermitFilter = 5,
			ImageResizeType_B_SplineFilter = 6,
			ImageResizeType_MitchellFilter = 7,
			ImageResizeType_Lanczos3Filter = 8
		};

		enum ImageFlipType
		{
			ImageFlipType_None = 0,
			ImageFlipType_LeftRight = 1,
			ImageFlipType_TopButtom = 2
		};

		enum ImageRotateType
		{
			ImageRotateType_None = 0,
			ImageRotateType_Degree90 = 1,
			ImageRotateType_Degree180 = 2,
			ImageRotateType_Degree270 = 3
		};

		enum ImageDecoderType
		{
			ImageDecoderType_None = 0,
			ImageDecoderType_SSDecoder = 1,
			ImageDecoderType_DefaultDecoder = 2,
			ImageDecoderType_OldDecoder = 3
		};

		enum ImageConvertModeType
		{
			ImageConvertModeType_Default = 0,
			ImageConvertModeType_LowQuality = 1,
			ImageConvertModeType_MediumQuality = 2,
			ImageConvertModeType_HighQuality = 3
		};

		class ImageBuffer
		{
		public:

			ImageBuffer() : buff(NULL), size(0)
			{

			}

			void *buff;
			size_t size;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_IMAGE_IMAGE_TYPES_H */
