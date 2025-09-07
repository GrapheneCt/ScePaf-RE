/*
	ScePaf-RE Project
*/

#ifndef _PAF_GRAPHICS_ARL_GXM_TEXTURE_H
#define _PAF_GRAPHICS_ARL_GXM_TEXTURE_H

#include <stdint.h>
#if defined(__SNC__)
#include <gxm.h>
#elif defined(__vita__)
#include <psp2/gxm.h>
#endif
#include <paf/graphics/arl/arl_defines.h>
#include <paf/common/shared_ptr.h>
#include <paf/std/stdcxx.h>

namespace paf {
	namespace graph {
		namespace arl {

			class TextureObject
			{
			public:

				uint8_t m_reserved[0x98];
			};

			class Texture2D : public TextureObject
			{
			public:

				static common::SharedPtr<Texture2D> load(string const& filename, SurfaceFlags alloc_flags);

			};
		}
	}
}

#endif /* _PAF_GRAPHICS_ARL_GXM_TEXTURE_H */
