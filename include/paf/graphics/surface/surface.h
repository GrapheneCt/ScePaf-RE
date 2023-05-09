/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_H
#define _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_H

#include <stddef.h>
#include <stdint.h>
#include <gxm.h>
#include <paf/paf_types.h>
#include <paf/std/memory>
#include <paf/thread/mutex.h>
#include <paf/thread/rmutex.h>
#include <paf/common/shared_ptr.h>
#include <paf/graphics/surface/surface_base.h>
#include <paf/image/image_types.h>
#include <paf/image/image_region.h>

namespace paf {

	class File;

	namespace memory {

		class HeapAllocator;
	}

	namespace image {

		class Image;
	}

	namespace graph {

		class SurfacePool;

		class SurfaceCLUT : public SurfaceBase, protected SurfaceListNode
		{
		public:

			static void DeactivateSurfacePool(SurfacePool *pool);

			SurfaceCLUT(SurfacePool *pool, ImageMode format, int32_t num_entry);

			SurfaceCLUT(ImageMode format, void *clut, int32_t num_entry);

			virtual ~SurfaceCLUT();

			int32_t ActivateCLUT();

			int32_t Release();

			int32_t UnsafeRelease()
			{
				sceAtomicDecrement32AcqRel(&m_ref_count);
				return m_ref_count;
			};

			int32_t AddRef();

			int32_t GetCLUTSize() const;

			void *GetCLUT() const
			{
				return m_clut;
			}

			void *operator new(size_t size);

			void operator delete(void*);

		protected:

			int32_t m_ref_count;
			int32_t m_unk_1C;
			void *m_clut;
			int32_t m_unk_24;

			__declspec (dllimport) static thread::Mutex m_lock_mutex;
			__declspec (dllimport) static SurfaceListNode m_surface_list;
		};

		class Surface : public SurfaceBase, protected SurfaceListNode
		{
		public:

			enum FrameBufferType
			{
				FRAME_BUFFER_LATEST = 0,
				FRAME_BUFFER_RENDERING = 1
			};

			enum TextureFilter
			{
				NEAREST = 0,
				LINEAR = 1,
				NEAREST_MIPMAP_NEAREST = 2,
				LINEAR_MIPMAP_NEAREST = 3,
				NEAREST_MIPMAP_LINEAR = 4,
				LINEAR_MIPMAP_LINEAR = 5,
			};

			enum TextureWrap
			{
				CLAMP = 0,
				REPEAT = 1,
				CLAMP_TO_EDGE = 2,
				MIRRORED_REPEAT = 3,
				MIRROR = 4,
				MIRROR_CLAMP = 5,
				REPEAT_IGNORE_BORDER = 6,
				CLAMP_IGNORE_BORDER = 7,
				CLAMP_FULL_BORDER = 8,
				CLAMP_HALF_BORDER = 9,
			};

			enum SurfaceType
			{
				TypeTexture = 0,
				TypeScreen = 1,
				TypeDisplay = 2,
			};

			enum MemClass
			{
				Fixed = 0,
				Permanent = 1,
				Unallocated = 2
			};

			enum PageMode
			{
				Refer = 0,
				Render = 1
			};

			class Texture
			{
			public:

				SceGxmTexture *texture;
			};

			class LoadOption
			{
			public:

				LoadOption()
				{
					decode_heap = NULL;
					data_load_heap = NULL;
					unk_08 = 0;
					error = 0;
					sce_paf_memset(unk_10, 0, sizeof(unk_10));
					unk_68 = true;
					resize_type = ImageResizeType_NearestNeighbor;
					read_size = 0;
					read_offset = 0;
					direct_load = false;
					rotate_type = ImageRotateType_None;
					flip_type = ImageFlipType_None;
					image_order = ImageOrder_NONE;
					unk_88 = 0;
					unk_8C = 0;
					unk_90 = 0;
					unk_94 = false;
				}

				//TODO: fill struct
				/*
				memory::HeapAllocator *decode_heap;
				memory::HeapAllocator *data_load_heap;
				int32_t unk_08;
				int32_t error;
				void *data_buff;
				off_t size;
				void*(*cb_alloc_heap)(size_t, bool *, void *);
				void *alloc_heap_userdata;
				void(*cb_free_heap)(void *, void *);
				void *free_heap_userdata;
				void(*cb_alloc_surface)(intrusive_ptr<Surface> *, SurfacePool *, common::SharedPtr<image::Image> *, int32_t, int32_t, void *);
				void * alloc_surface_userdata;
				bool(*cancel_func)(void *);
				void *cancel_userdata;
				image::ImageRect sub_rect;
				image::ImageExtent scale;
				ImageResizeType resize_type;
				size_t read_size;
				size_t read_offset;
				//bool direct_load;
				//ImageRotateType rotate_type;
				//ImageFlipType flip_type;
				//ImageOrder image_order;
				//int32_t reserved;
				*/

				memory::HeapAllocator *decode_heap;
				memory::HeapAllocator *data_load_heap;
				int32_t unk_08;
				int32_t error;
				char unk_10[0x58];
				bool unk_68;
				ImageResizeType resize_type;
				size_t read_size;
				size_t read_offset;
				bool direct_load;
				ImageRotateType rotate_type;
				ImageFlipType flip_type;
				ImageOrder image_order;
				int32_t unk_88;
				int32_t unk_8C;
				int32_t unk_90;
				bool unk_94;
			};

			static void DeactivateSurfacePool(SurfacePool *pool);

			static int32_t DecodeImage(SurfacePool *pool, LoadOption *option, intrusive_ptr<Surface>& surf, common::SharedPtr<image::Image> image_org);

			static int32_t DecodeImage(SurfacePool *pool, LoadOption *option, intrusive_ptr<Surface>& surf, void *buf, size_t size);

			static void FastMemcpy(void *dst, const void *src, int32_t n);

			static int16_t GetAdjustHeight(SurfacePool *pool, int32_t height);

			static int16_t GetAdjustWidth(SurfacePool *pool, int32_t width);

			static uint32_t GetN(uint32_t value);

			static int32_t IsAllocatableSurfacePool(SurfacePool *pool, size_t size, size_t align_bytes);

			static intrusive_ptr<Surface> Load(SurfacePool *pool, common::SharedPtr<File> src, LoadOption *option = NULL);

			static intrusive_ptr<Surface> Load(SurfacePool *pool, void *buf, off_t size, LoadOption *option);

			//static intrusive_ptr<Surface> Load(SurfacePool *pool, void *buf, off_t size, uint32_t ununsed = 0, LoadOption *option = NULL);

			Surface(SurfacePool *pool, int32_t width, int32_t height, ImageMode format, ImageOrder order, int32_t num_page, int32_t num_level, bool unk_base_08);

			Surface(int32_t width, int32_t height, ImageMode format, ImageOrder order, int32_t num_page, void *bp, int32_t line_bytes, int32_t num_level, bool unk_base_08);

			Surface(SurfacePool *pool, int32_t width, int32_t height, ImageMode format, ImageOrder order, int32_t num_page, int32_t align_bytes, int32_t line_bytes, int32_t num_level, bool unk_base_08);

			virtual ~Surface();

			virtual int32_t unkFun_0C();
			virtual int32_t unkFun_10();
			virtual int32_t unkFun_14();
			virtual void Swap();
			virtual int32_t BeginScene();
			virtual int32_t EndScene();
			virtual void *Lock(int32_t lockArea = 0); // Returns pointer to surface memory
			virtual void  Unlock();
			virtual int32_t unkFun_2C();
			virtual int32_t GenTexture();

			int32_t ActivatePage(int32_t page);

			int32_t ActivateTexture(uint32_t map_type, float offset_u, float offset_v, float scale_u, float scale_v);

			int32_t AttachCLUT(intrusive_ptr<SurfaceCLUT> const& clut);

			int32_t ConvertSwizzleFormat(void *dst, const void *src, int32_t width, int32_t height);

			void ConvertTiledFormat(void *dst, const void *src, int32_t width, int32_t height);

			int32_t Copy(int32_t page, const void *src, ImageOrder src_order, int32_t line_bytes, int32_t level);

			int32_t Copy(int32_t dst_page, intrusive_ptr<Surface> const& src, int32_t src_page);

			int32_t Copy(void *dst, const void *src, ImageOrder src_order, int32_t line_bytes);

			int32_t Copy_(int32_t page, const void *src, ImageOrder src_order, int32_t line_bytes, int32_t level);

			int32_t Copy_YUV420PX(int32_t page, const void *src, ImageOrder src_order, int32_t line_bytes, int32_t level);

			int32_t CreateMipmap();

			void DelayedRelease();

			void DeleteTexture();

			void DetachCLUT();

			int32_t DuplicateBoundary(uint8_t *page_ptr);

			int32_t FillPadding(int32_t page, const void *color, int32_t level);

			int32_t FloorLog2(int32_t value);

			void FreeMemory();

			int32_t GenTexture(Texture *tex, void *addr);

			void GenTextureAll();

			int32_t GetCopyHeight(int32_t pixel_align, int32_t level);

			uint32_t GetLodBias();

			int32_t GetPageIndex(FrameBufferType t, int32_t *sce_paf_index);

			SceGxmTexture *GetRawTexture();

			uint32_t GetRawTextureFormat();

			int32_t Initialize(SurfacePool *pool, int32_t width, int32_t height, ImageMode format, ImageOrder order, SurfaceType surf_type, int32_t num_page, int32_t num_level);

			int32_t Initialize(int32_t width, int32_t height, ImageMode format, ImageOrder order, SurfaceType surf_type, int32_t num_page, void *bp, int32_t line_bytes, int32_t num_level);

			int32_t Initialize(SurfacePool *pool, int32_t width, int32_t height, ImageMode format, ImageOrder order, SurfaceType surf_type, int32_t num_page, int32_t align_bytes, int32_t size_byte, int32_t line_bytes, int32_t num_level);

			void InitObj(int32_t line_bytes);

			void Reorder();

			int32_t Resize(int32_t width, int32_t height);

			int32_t SetDecodeImageOption(SurfacePool *pool, LoadOption *option, intrusive_ptr<Surface>& surf, common::SharedPtr<image::Image> *image);

			int32_t SetLodBias(uint32_t bias);

			int32_t SetMagFilter(TextureFilter value);

			int32_t SetMinFilter(TextureFilter value);

			void SetMemAttr();

			void SetMemParam(int32_t line_bytes, int16_t adj_width, int16_t adj_height);

			int32_t SetPalette(Texture *tex, const void *palette_addr);

			bool SetSymmetryU(bool is_symmetry);

			bool SetSymmetryV(bool is_symmetry);

			int32_t SetWrapS(TextureWrap value);

			int32_t SetWrapT(TextureWrap value);

			void TexFlush();

			int32_t Texturize(uint32_t map_type, float offset_u, float offset_v, float scale_u, float scale_v);

			int32_t Texturize()
			{
				return Texturize(0, 0.0f, 0.0f, 1.0f, 1.0f);
			}

			int32_t Release();

			int32_t UnsafeRelease()
			{
				sceAtomicDecrement32AcqRel(&m_ref_count);
				return m_ref_count;
			};

			int32_t AddRef();

			int32_t GetScore() const;

			int32_t GetStride(int32_t level) const;

			uint8_t *GetPagePtr(int32_t page) const;

			uint8_t *GetPagePtr(int32_t page, int32_t level) const;

			float GetFactorU() const
			{
				return m_factor_u;
			}

			float GetFactorV() const
			{
				return m_factor_v;
			}

			int32_t GetHeight() const
			{
				return m_height;
			}

			int32_t GetWidth() const
			{
				return m_width;
			}

			int32_t GetMagFilter() const
			{
				return m_texture_param.mag_filter;
			}

			int32_t GetMinFilter() const
			{
				return m_texture_param.min_filter;
			}

			int32_t GetPageSize() const
			{
				return m_page_size;
			}

			int32_t GetRefCount() const
			{
				return m_ref_count;
			}

			int32_t GetStride() const
			{
				return m_stride;
			}

			int32_t GetWrapS() const
			{
				return m_texture_param.wrap_s;
			}

			int32_t GetWrapT() const
			{
				return m_texture_param.wrap_t;
			}

			void *operator new(size_t size);

			void operator delete(void*);

		protected:

			class SysMemory
			{
			public:

				void *bp;
				int16_t align;
				int16_t attr;
			};

			class TexParam
			{
			public:

				uint32_t mag_filter;
				uint32_t min_filter;
				uint32_t mip_filter;
				uint32_t wrap_s;
				uint32_t wrap_t;
				uint32_t lod_bias;
			};

			int32_t m_ref_count;
			int16_t m_width;
			int16_t m_height;
			ImageOrder m_order;
			SurfaceType m_surf_type;
			MemClass m_mem_class;
			int16_t m_tex_width;
			int16_t m_tex_height;
			float m_factor_u;
			float m_factor_v;
			int32_t m_page_size;
			int32_t m_stride;
			bool m_locked : 1;
			bool m_texturized : 1;
			bool m_symmetry_u : 1;
			bool m_symmetry_v : 1;
			Texture *m_tex_pages;
			TexParam m_texture_param;
			bool m_texture_param_chenged;
			int16_t m_num_level;
			int16_t m_num_page;
			int16_t m_page_counter;
			SysMemory m_mem;
			int32_t m_score;
			intrusive_ptr<Surface> m_depth;
			intrusive_ptr<SurfaceCLUT> m_clut;
			SurfacePool *m_pool;
			int32_t m_unk_80;
			int32_t m_unk_84;
			int32_t m_unk_88;
			int32_t m_unk_8C;
			int32_t m_unk_90;

			__declspec (dllimport) static void* m_active_mark[2];
			__declspec (dllimport) static int32_t m_initialized;
			__declspec (dllimport) static thread::RMutex m_list_cs;
			__declspec (dllimport) static thread::Mutex m_lock_mutex;
			__declspec (dllimport) static SurfaceListNode m_surface_list;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_SURFACE_SURFACE_H */
