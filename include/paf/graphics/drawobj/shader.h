/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_SHADER_H
#define _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_SHADER_H

#include <paf/std/stdcxx.h>
#include <paf/math/math.h>

namespace paf {
	namespace graph {
		
		class Surface;

		class ShaderDrawArg
		{
		public:

			char unk_00[0x18];
			intrusive_ptr<Surface> *pTextures;
			int32_t unk_1C;
			int32_t unk_20;
			math::v4 *pTextureRegion;
		};

		class Shader
		{
		public:

			Shader()
			{

			}

			virtual ~Shader()
			{

			}
		};
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_SHADER_H */
