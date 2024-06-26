/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_STATE_BUTTON_BASE_H
#define _VDSUITE_USER_PAF_WIDGET_W_STATE_BUTTON_BASE_H

#include <paf/widget/factory.h>
#include <paf/widget/w_button_base.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryStateButtonBase;

namespace paf {

	namespace ui {

		class StateButtonBaseStyleParam : public WidgetStyleParam
		{
		public:
			static const char *ParamName();
			StateButtonBaseStyleParam();
			virtual const char *GetParamName() const;
			virtual ~StateButtonBaseStyleParam();
			virtual int32_t Create(int32_t mode);
			virtual int32_t SetEach(Widget *widget);
			virtual int32_t GetEach(Widget *widget);

		private:
			unsigned char unk_0x60[0x3E0];

			__declspec (dllimport) static const char m_param_name[];
		};

		class StateButtonBase : public ButtonBase
		{
		public:

			enum
			{
				OBJ_IMAGE = 0,
				OBJ_STBTN_END = 1
			};

			enum
			{
				CB_STBTN_BEGIN = 0x1000000A,
				CB_STBTN_VALUE_CHANGED = 0x1000000B,
				CB_STBTN_END = 0x1000000C
			};

			static const char *TypeName();

			StateButtonBase(Widget *_parent, CreateParam *_param);

			virtual ~StateButtonBase();

			virtual void SetCheck(bool onoff, float time = 0.0f, bool ch_anim = false);
			virtual void OnButtonDecide();
			virtual int32_t unkFun_1C4();
			virtual int32_t unkFun_1C8();

			void DoTexAnim(bool onoff, float time);

			int32_t SendEvent(int32_t type, int32_t v0, int32_t v1, int32_t v2, int32_t v3);

			int32_t GetFrameNum()
			{
				return m_frame_num;
			}

			float GetFrameTime()
			{
				return m_frame_time;
			}

		protected: //0x2C8

			int32_t m_frame_num;
			float m_frame_time;
			int32_t m_unk_2B8;
			int32_t m_unk_2BC;
			int32_t m_unk_2C0;
			int32_t m_unk_2C4;

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_STATE_BUTTON_BASE_H */