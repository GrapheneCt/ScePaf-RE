/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_CACHE_CACHE_IMAGE_H
#define _VDSUITE_USER_PAF_CACHE_CACHE_IMAGE_H

#include <stdint.h>
#include <stddef.h>
#include <paf/std/memory>
#include <paf/image/image_types.h>
#include <paf/image/image_region.h>
#include <paf/graphics/surface/surface.h>
#include <paf/common/shared_ptr.h>
#include <paf/cache/cache_base.h>

namespace paf {

	namespace image {

		class Image;
	}

	namespace graph {

		class SurfacePool;
	}

	namespace cache {

		class CacheImage : public CacheBase
		{
		public:

			class Option
			{
			public:


			};

			static CacheImage *CreateCacheInstance(CacheManagerImpl *manager, const Option *option);

			static void DestroyCacheInstance(CacheImage *cache);

			CacheImage(CacheManagerImpl *manager, const Option *option);

			virtual ~CacheImage();

			virtual void DestroyInstance();

			virtual bool DiffOption(const Option *option);

			virtual int32_t RestartJob();

			virtual int32_t JobRun();

			virtual int32_t JobFinish(int32_t result, bool& is_finished);

			virtual bool IsEnableReleaseInstance();

			intrusive_ptr<graph::Surface> GetImage();

			void *AllocHeap(size_t size, bool *load, void *userdata);

			void FreeHeap(void *buf, void *userdata);

			void AllocSurface(graph::SurfacePool *pool, common::SharedPtr<image::Image> const& image, int32_t num_page, int32_t mipmap_level, void *userdata);

			bool CheckSurfacePool();

		private:

			image::ImageRect m_sub_rect;
			image::ImageExtent m_scale;
			ImageResizeType m_resize_type;
			bool m_direct_load;
			bool m_surface_retry;
			intrusive_ptr<graph::Surface> m_surface;
			int32_t m_job_status;

			char unk_90[0x18];

		};
	}
}

#endif /* _VDSUITE_USER_PAF_CACHE_CACHE_IMAGE_H */
