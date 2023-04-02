/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_ARL_GXM_GXM_ARL_FRONTEND_H
#define _VDSUITE_USER_PAF_GRAPHICS_ARL_GXM_GXM_ARL_FRONTEND_H

#include <stdint.h>
#include <gxm.h>
#include <paf/graphics/arl/arl_defines.h>
#include <paf/common/shared_ptr.h>
#include <paf/math/math.h>

namespace paf {
	namespace graph {
		namespace arl {

			class FrameBufferObject;
			class Texture2D;

			class ShaderPatcher
			{
			public:

				SceGxmShaderPatcher *_raw_patcher;
			};

			class BlendInfo
			{
			public:

				SceGxmBlendInfo m_raw;
			};

			class cached_states
			{
			public:

				PolygonModeEnum m_front_polygon_mode;
				PolygonModeEnum m_back_polygon_mode;
				bool m_wclamp_enabled;
				bool m_wbuffer_enabled;
				bool m_two_sided_enabled;
				DepthFuncEnum m_front_depth_func;
				DepthFuncEnum m_back_depth_func;
				bool m_front_depth_write_enabled;
				bool m_back_depth_write_enabled;
				CullModeEnum m_cull_mode;
				uint32_t m_front_point_line_width;
				uint32_t m_back_point_line_width;
				int32_t unk_24;
				math::v4 m_current_color;
				bool m_blend_enabled;
				BlendInfo m_blend_info;
				bool m_depth_test_enabled;
			};

			class ArlInstance
			{
			public:

				ArlInstance();

				~ArlInstance();

				void CullMode(CullModeEnum mode);

				void BlendFunc(BlendingFactor src_rgb, BlendingFactor dst_rgb, BlendingFactor src_a, BlendingFactor dst_a);

				void BlendEquation(BlendEquationEnum rgb, BlendEquationEnum a);

				void Color(math::v4 color);

				void PointSize(float value, FaceEnum face);

				void LineWidth(float value, FaceEnum face);

				void SetSceneData(intrusive_ptr<Surface> surf);

				void SetSceneData(FrameBufferObject *fbo);

				void Clear(uint32_t clear_mask);

				void ClearColor(math::v4 color);

				void CopyTexImage2D(common::SharedPtr<Texture2D> tex, int32_t level, int32_t x, int32_t y, size_t w, size_t h);

				volatile uint32_t *GetNotificationAddr(size_t sce_paf_index);

				void PolygonMode(PolygonModeEnum mode, FaceEnum face);

				void Enable(EnableCap cap);

				void Disable(EnableCap cap);

				void DepthFunc(DepthFuncEnum func, FaceEnum face);

				void ColorMask(bool r, bool g, bool b, bool a);

				void DepthMask(bool write_enabled, FaceEnum face);

				ImageMode GetFrameBufferFormat()
				{
					return ImageMode_RGBA8888;
				}

				SceGxmContext *GetRawContext()
				{
					return m_raw_context;
				}

				SceGxmShaderPatcher *GetRawShaderPatcher()
				{
					return _patcher->_raw_patcher;
				}

				common::SharedPtr<ShaderPatcher> GetShaderPatcher()
				{
					return _patcher;
				}

			private:

				char unk_000[0x61C];
				common::SharedPtr<ShaderPatcher> _patcher;
				char unk_624[0x68];
				SceGxmContext *m_raw_context;
				char unk_690[0xB4];
				cached_states m_cached;
				char unk_784[0x4C];
			};

			extern ArlInstance *Gl();
		}
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_ARL_GXM_GXM_ARL_FRONTEND_H */
