/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_CAMERA_H
#define _VDSUITE_USER_PAF_WIDGET_W_CAMERA_H

#include <paf/widget/core/widget.h>

namespace paf {

	namespace graph {

		class DrawInfo;
	}

	namespace ui {

		class Screen;

		class ClipRect
		{
		public:

			int32_t x;
			int32_t y;
			int32_t w;
			int32_t h;
		};

		class Camera : public Widget
		{
		public:

			enum
			{
				DRAW_ORDER_ZSORT = 0,
				DRAW_ORDER_TABLE = 1
			};

			enum
			{
				ANIM_ROLL = 0x1000C
			};

			class DrawScissorArg
			{
			public:

				ClipRect rect;
			};

			static const char *TypeName();

			Camera(Widget *_parent, CreateParam *_param);

			virtual ~Camera();

			void add_obj(Widget *root, graph::DrawInfo& info);

			int32_t Setup(Screen *scr);

			void SetRollScreen(float roll, Timer *t);
			float GetRollScreen(int32_t opt);

			int32_t SyncPosture(Camera *other);

			int32_t SetDrawOrder(int32_t policy)
			{
				m_draw_order = policy;
				return 0;
			}

			void UpdateZList()
			{
				m_update_zlist = true;
			}

			void GetClipRange(float& _near, float& _far) const
			{
				_near = m_near_z;
				_far = m_far_z;
			}

		protected: //0x390

			static void DrawScissor(DrawScissorArg const& arg);

			void SetRollScreen_core(float roll);

			char m_unk_27C[0x2C];
			float m_near_z;
			float m_far_z;
			char m_unk_2B0[0xC8];
			int32_t m_draw_order;
			bool m_update_zlist;
			int32_t m_mipbase;
			int32_t m_mipoffs;
			int32_t m_unk_388;
			int32_t m_unk_38C;

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_CAMERA_H */