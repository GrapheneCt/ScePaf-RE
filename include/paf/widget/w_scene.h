/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_SCENE_H
#define _VDSUITE_USER_PAF_WIDGET_W_SCENE_H

#include <paf/widget/core/widget.h>

namespace paf {

	namespace graph {

		class RenderStage;
	}

	namespace ui {

		class Environment;
		class EnvironmentParam;
		class Camera;

		class Scene : public Widget
		{
		public:

			enum
			{
				OBJ_LIGHT = 0,
				OBJ_SCENE_END = 1
			};

			enum
			{
				CB_WIDGET = 0x10000000,
				CB_SCENE_ONCANCEL = 0x10000001,
				CB_SCENE_CONTEXTMENU = 0x10000002,
				CB_SCENE_ACTIVATE = 0x10000003,
				CB_SCENE_INACTIVATE = 0x10000004,
				CB_SCENE_SYSTEM = 0x10000005,
				CB_SCENE_END = 0x10000006
			};

			enum
			{
				DEBUG_OFF = 0,
				DEBUG_AUTH_HIDEALL = 1,
				DEBUG_AUTH_LAYOUT = 2,
				DEBUG_AUTH_PARAMVIEW = 3,
				DEBUG_AUTH_PARAMVIEW_INPUT = 4,
				DEBUG_AUTH_5 = 5,
				DEBUG_AUTH_LAYOUT_RULER = 6
			};

			typedef void(*DebugFocusCB)(Widget*, Widget*, void*);

			static const char *TypeName();

			Scene(Environment *env, int32_t entry, CreateParam *_param, EnvironmentParam env_param, uint32_t graphics_flag = 0x80);

			virtual ~Scene();

			void SetDebugFocus(Widget *w);

			void SetDebugMode(uint32_t mode);

			bool IsResolutionActRoll(int32_t id);

			bool IsResolutionActMorph(int32_t id);

			int32_t ResetCameraRoll(float time);

			int32_t DrawScene(bool hide);

			Camera *SetCamera(Camera *cam);

			Camera *GetCamera()
			{
				return m_camera;
			}

			Widget *GetDebugFocus()
			{
				if (m_debug_mode == DEBUG_OFF)
				{
					return NULL;
				}
				return m_debug_focus;
			}

			uint32_t GetDebugMode()
			{
				return m_debug_mode;
			}

			graph::RenderStage *GetRenderStage()
			{
				return m_renderstage;
			}

			void SetDebugFocusCB(DebugFocusCB func)
			{
				m_debug_focus_func = func;
			}

			DebugFocusCB GetDebugFocusCB()
			{
				return m_debug_focus_func;
			}

			ui::Widget *GetDebugCube()
			{
				return m_debug_cube;
			}

			ui::Widget *GetDebugCubeChild()
			{
				return m_debug_cube_child;
			}

		protected: //0x3C0

			int32_t m_unk_27C;
			Camera *m_camera;
			char m_unk_284[0xE4];
			graph::RenderStage *m_renderstage;
			graph::RenderStage *m_renderstage_2;
			char m_unk_370[0x10];
			uint32_t m_debug_mode;
			Widget *m_debug_focus;
			Widget *m_debug_cube;
			Widget *m_debug_cube_child;
			uint32_t m_debug_grab_restore;
			uint32_t m_debug_drag_restore;
			uint32_t m_debug_hitfind_restore;
			uint32_t m_debug_quant_x;
			uint32_t m_debug_quant_y;
			uint32_t m_debug_quant_z;
			uint32_t m_debug_quant_x_restore;
			uint32_t m_debug_quant_y_restore;
			uint32_t m_debug_quant_z_restore;
			float m_debug_showalpha_restore;
			DebugFocusCB m_debug_focus_func;
			int32_t m_unk_3BC;

			__declspec(dllimport) static const char *m_widget_type;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_SCENE_H */