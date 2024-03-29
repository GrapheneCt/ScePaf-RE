﻿/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_IMAGE_IMAGE_H
#define _VDSUITE_USER_PAF_IMAGE_IMAGE_H

#include <stddef.h>
#include <stdint.h>
#include <paf/paf_types.h>
#include <paf/image/image_types.h>
#include <paf/image/image_region.h>
#include <paf/image/image_array.h>
#include <paf/image/image_attribute.h>

namespace paf {

	namespace memory {

		class HeapAllocator;
	}

	namespace image {

		typedef bool(*DecodeCancelFunc)(void *userdata);

		namespace filter {

			extern void ResizeHalf(void *dstbuf, const void *srcbuf, int32_t dstpitch, int32_t srcpitch, int32_t srcwidth, int32_t srcheight);

			extern bool ResizeHalf(ImageBuffer *dstimage, const ImageBuffer *srcimage, int32_t dstpitch, int32_t srcpitch, ImageExtent ext, ImageMode mode);

			extern void ResizeQuarter(void *dstbuf, const void *srcbuf, int32_t dstpitch, int32_t srcpitch, int32_t srcwidth, int32_t srcheight);

			extern bool ResizeQuarter(ImageBuffer *dstimage, const ImageBuffer *srcimage, int32_t dstpitch, int32_t srcpitch, ImageExtent ext, ImageMode mode);

			extern bool Resize(
				ImageBuffer *dstimage,
				const ImageBuffer *srcimage,
				int32_t dstpitch,
				int32_t srcpitch,
				ImageExtent ext,
				ImageMode mode,
				ImageFormat format,
				ImageExtent dstext,
				ImageResizeType type,
				memory::HeapAllocator *allocator);

			extern bool Copy(ImageBuffer *dstimage, const ImageBuffer *srcimage, int32_t dstpitch, int32_t srcpitch, ImageExtent ext, ImageMode mode, ImageFormat format);

			extern bool CopyWithEdge(
				ImageBuffer *dstimage,
				const ImageBuffer *srcimage,
				const ImageBuffer *srcclut,
				int32_t dstpitch,
				int32_t srcpitch,
				ImageExtent ext,
				ImageMode mode,
				ImageFormat format,
				uint32_t extlines);

			extern bool FadeWithEdge(
				ImageBuffer *dstimage,
				const ImageBuffer *srcimage,
				int32_t dstpitch,
				int32_t srcpitch,
				ImageExtent ext,
				ImageMode mode,
				ImageFormat format);

			extern bool Flip(
				ImageBuffer *dstimage,
				const ImageBuffer *srcimage,
				int32_t dstpitch,
				int32_t srcpitch,
				ImageExtent ext,
				ImageMode mode,
				ImageFormat format,
				ImageFlipType type);

			extern bool Rotate(
				ImageBuffer *dstimage,
				const ImageBuffer *srcimage,
				int32_t dstpitch,
				int32_t srcpitch,
				ImageExtent ext,
				ImageMode mode,
				ImageFormat format,
				ImageRotateType type);

			extern bool Sharpen(
				ImageBuffer *dstimage,
				const ImageBuffer *srcimage,
				int32_t dstpitch,
				int32_t srcpitch,
				ImageExtent ext,
				ImageMode mode,
				ImageFormat format,
				float amount,
				int32_t threshold,
				memory::HeapAllocator *allocator);

			extern bool Transparentize(
				ImageBuffer *dstimage,
				const ImageBuffer *srcimage,
				int32_t dstpitch,
				int32_t srcpitch,
				ImageExtent ext,
				ImageMode mode,
				ImageFormat format,
				float alpha);

			/*
			extern bool ConvertMode(
				ImageBuffer *dstimage,
				const ImageBuffer *srcimage,
				const ImageBuffer *srcclut,
				int32_t dstpitch,
				int32_t srcpitch,
				ImageExtent ext,
				???
				ImageMode mode,
				ImageFormat format,
				ImageMode dstmode,
				ImageConvertModeType type = ImageConvertModeType_Default);
			*/
		}

		class ImageSource
		{
		public:

			ImageSource()
			{

			}

			virtual bool GetHeader(ImageFormat format, ImageAttribute **attr, ImageArray *images, ImageArray *cluts) = 0;
			virtual bool LoadImage(ImageAttribute *attr, ImageArray *images, ImageArray *cluts, bool delete_flag, DecodeCancelFunc cancelfunc, void *userdata) = 0;
			virtual int32_t GetErrorType() = 0;
			virtual bool SetErrorType(int32_t type) = 0;

			virtual ~ImageSource()
			{

			}

		};

		class ImageOperation : public ImageSource
		{
		public:

			virtual bool GetHeader(ImageFormat format, ImageAttribute **attr, ImageArray *images, ImageArray *cluts);
			virtual bool LoadImage(ImageAttribute *attr, ImageArray *images, ImageArray *cluts, bool delete_flag, DecodeCancelFunc cancelfunc, void *userdata);
			virtual int32_t GetErrorType();
			virtual bool SetErrorType(int32_t type);
			virtual ~ImageOperation();
			virtual bool Init(const ImageAttribute *srcattr, const ImageArray *srcimages, const ImageArray *srccluts, ImageAttribute *dstattr, ImageArray *dstimages, ImageArray *dstcluts);
			virtual bool OperateImage(ImagePoint const& sce_paf_index, const ImageAttribute *srcattr, const ImageBuffer *srcimage, const ImageBuffer *srcclut, ImageAttribute *dstattr, ImageBuffer *dstimage, ImageArray *dstclut) = 0;

		protected:

			memory::HeapAllocator *m_allocator;
			Image *m_parent;
			int32_t m_errortype;
		};

		class Image
		{
		public:

			static ImageFormat DetectFormat(void *addr, size_t size);

			static ImageFormat DetectFormat(const char *filename, off_t offset, size_t size);

			static ImageFormat DetectFormat(common::SharedPtr<File> file, off_t offset, size_t size);

			static ImageFormat DetectFormat(common::SharedPtr<Buffer> buf);

			static common::SharedPtr<Image> Open(const char *filename, memory::HeapAllocator *allocator, ImageFormat format, off_t offset, size_t size);

			static common::SharedPtr<Image> Open(void *addr, size_t size, memory::HeapAllocator *allocator, ImageFormat format);

			static common::SharedPtr<Image> Open(common::SharedPtr<File> file, memory::HeapAllocator *allocator, ImageFormat format, off_t offset, size_t size);

			static common::SharedPtr<Image> Open(common::SharedPtr<Buffer> buffptr, memory::HeapAllocator *allocator, ImageFormat format);

			// Supported ImageMode: ImageMode_RGBA8888, ImageMode_BGRA8888
			static int32_t SaveAsPng(const char *filename, const void *addr, uint32_t pitch, ImageExtent const& ext, ImageMode mode, uint32_t io_mode, memory::HeapAllocator *allocator = NULL);

			// Supported ImageMode: ImageMode_RGBA8888, ImageMode_BGRA8888, ImageMode_DXT1, ImageMode_DXT3, ImageMode_DXT5
			static int32_t SaveAsDds(const char *filename, const void *addr, uint32_t pitch, ImageExtent const& ext, ImageMode mode, uint32_t io_mode, memory::HeapAllocator *allocator = NULL);

			static int32_t SaveAsDds(void *dst, uint32_t max_size, const void *addr, uint32_t pitch, ImageExtent const& ext, ImageMode mode);

			// Supported ImageMode: ImageMode_RGBA8888, ImageMode_BGRA8888
			static int32_t SaveAsBmp(const char *filename, const void *addr, uint32_t pitch, ImageExtent const& ext, ImageMode mode, uint32_t io_mode, memory::HeapAllocator *allocator = NULL);

			Image(memory::HeapAllocator *allocator) : m_images(allocator), m_cluts(allocator)
			{
				m_imagesrc = NULL;
				m_imageattr = NULL;
				m_cancelfunc = NULL;
				m_cancelfunc_userdata = NULL;
				m_openext_mem_addr = NULL;
				m_openext_mem_size = 0;
				m_openext_mem_allocator = NULL;
			}

			~Image();

			class Resolution
			{
			public:

				SceUInt32 width;
				SceUInt32 height;
			};

			common::SharedPtr<Image> CopyWithEdge(uint32_t extlines);

			common::SharedPtr<Image> FadeWithEdge();

			common::SharedPtr<Image> Transparentize(float alpha);

			common::SharedPtr<Image> Blur(float sigma);

			common::SharedPtr<Image> Sharpen(float amount, int32_t threshold);

			common::SharedPtr<Image> Copy();

			common::SharedPtr<Image> Flip(ImageFlipType type);

			common::SharedPtr<Image> Resize(ImageExtent const& extent, ImageResizeType type);

			common::SharedPtr<Image> Rotate(ImageRotateType type);

			common::SharedPtr<Image> ConvertMode(ImageMode mode, ImageConvertModeType type = ImageConvertModeType_Default);

			//ScePafMisc_3CA35598
			//common::SharedPtr<Image> Paste();

			common::SharedPtr<Image> Crop(ImageRect const& crop);

			common::SharedPtr<Image> ResizeWithConvertMode(ImageExtent const& extent, ImageResizeType resize_type, ImageMode mode, ImageConvertModeType type = ImageConvertModeType_Default);

			common::SharedPtr<Image> RoundCorner(int32_t a1, int32_t a2);

			common::SharedPtr<Image> Blend(common::SharedPtr<Image> const& other);

			bool Load(bool delete_flag);

			bool UnLoad();

			int32_t GetErrorType();

			int32_t GetDecErrorType() const;

			bool SetErrorType(int32_t error);

			bool SetDecErrorType(int32_t error);

			bool SetPitchAlign(size_t pitchAlign);

			bool SetHeightAlign(uint32_t heightAlign);

			bool CheckAlignArgument(int32_t align);

			ImageBuffer ToCLUTBuffer(bool delete_flag);

			ImageBuffer ToBuffer(bool delete_flag);

			bool SetArrayPos(ImagePoint& point);

			bool SetArrayPosCLUT(ImagePoint& point);

			bool SetDecExtent(ImageExtent const& extent, ImageResizeType type);

			bool SetDecSubRect(ImageRect const& rect);

			bool SetDecodeCancelFunc(DecodeCancelFunc cancelfunc, void *userdata);

			bool SetClip(ImageRect const& clipRect);

			ImageRect GetSubRect() const;

			ImagePoint GetArrayPos() const;

			ImagePoint GetArrayPosCLUT() const;

			ImageMode GetCLUTMode() const;

			ImageMode GetMode() const;

			uint32_t GetCLUTSize() const;

			size_t GetMemPitch(uint32_t sce_paf_index = 0) const;

			uint32_t GetMemHeight(uint32_t sce_paf_index = 0) const;

			size_t GetPitchAlign() const;

			uint32_t GetHeightAlign() const;

			ImagePoint GetCLUTArraySize() const;

			ImagePoint GetArraySize() const;

			ImageExtent GetOriginalExtent() const;

			ImageExtent GetExtent() const;

			ImageRect GetClip() const;

			ImageFormat GetFormat() const;

			ImageOrder GetOrder() const;

			ImageXType GetXType() const;

			ImageYType GetYType() const;

			bool CheckCLUT() const;

			ImageAttribute *GetAttribute() const
			{
				return m_imageattr;
			}

			const ImageArray& GetCLUT() const
			{
				return m_cluts;
			}

			const ImageArray& GetImage() const
			{
				return m_images;
			}

			bool HasImage() const
			{
				if (m_images.IsEmpty() && m_cluts.IsEmpty())
				{
					if (m_imagesrc == NULL)
					{
						return false;
					}
					else
					{
						return true;
					}
				}
				return true;
			}

		private:

			ImageSource *m_imagesrc;
			ImageArray m_images;
			ImageArray m_cluts;
			ImageAttribute *m_imageattr;
			ImagePoint m_current;
			ImagePoint m_current_clut;
			DecodeCancelFunc m_cancelfunc;
			void *m_cancelfunc_userdata;
			void *m_openext_mem_addr;
			size_t m_openext_mem_size;
			memory::HeapAllocator *m_openext_mem_allocator;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_IMAGE_IMAGE_H */
