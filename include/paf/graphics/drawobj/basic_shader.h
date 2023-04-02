/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_BASIC_SHADER_H
#define _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_BASIC_SHADER_H

#include <paf/std/string.h>
#include <paf/graphics/drawobj/shader.h>

namespace paf {
	namespace graph {
		
		//TODO: fix implementation
		class BasicShader : public Shader
		{
		public:

			BasicShader()
			{
				sce_paf_memset(m_unk_04, 0, sizeof(m_unk_04));
			}

			virtual ~BasicShader()
			{

			}

			virtual void Draw(ShaderDrawArg const& arg) = 0;

		private:

			char m_unk_04[0x24];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_BASIC_SHADER_H */
