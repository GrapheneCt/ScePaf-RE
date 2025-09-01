/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_BUTTON_BASE_H
#define _VDSUITE_USER_PAF_WIDGET_W_BUTTON_BASE_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factoryButtonBase;

namespace paf {

	namespace ui {

		class ButtonBase : public Widget
		{
		public:

			enum
			{
				CB_BTN_BEGIN = 0x10000000,
				CB_BTN_NORMAL = 0x10000001,
				CB_BTN_DISABLE = 0x10000002,
				CB_BTN_PRESS = 0x10000003,
				CB_BTN_PRESS_OUT = 0x10000004,
				CB_BTN_PRESS_REPEAT = 0x10000005,
				CB_BTN_PRESS_REPEAT_END = 0x10000006,
				CB_BTN_LONG_PRESS = 0x10000007,
				CB_BTN_DECIDE = 0x10000008,
				CB_BTN_MULTI_TAP = 0x10000009,
				CB_BTN_END = 0x1000000a
			};

			enum
			{
				BTN_MODE_BASIC = 0,
				BTN_MODE_PRESSOVER = 1
			};

			enum ButtonState
			{
				ST_BTN_NORMAL = 0,
				ST_BTN_DISABLE = 1,
				ST_BTN_PRESS = 2,
				ST_BTN_PRESS_OUT = 3,
				ST_BTN_PRESS_REPEAT = 4
			};

			static const char *TypeName();

			ButtonBase(Widget *_parent, CreateParam *_param);

			virtual ~ButtonBase();

			virtual int32_t unkFun_170();
			virtual int32_t unkFun_174();
			virtual int32_t unkFun_178();
			virtual int32_t unkFun_17C();
			virtual int32_t unkFun_180();
			virtual int32_t unkFun_184();
			virtual int32_t unkFun_188();
			virtual int32_t unkFun_18C();
			virtual int32_t unkFun_190();
			virtual int32_t unkFun_194();
			virtual int32_t unkFun_198();
			virtual int32_t unkFun_19C();
			virtual int32_t unkFun_1A0();
			virtual int32_t unkFun_1A4();
			virtual int32_t unkFun_1A8();
			virtual int32_t unkFun_1AC();
			virtual int32_t unkFun_1B0();
			virtual int32_t unkFun_1B4();
			virtual uint32_t ChangeButtonState(ButtonState state);

			void SetButtonMode(uint32_t mode);

			void EnableRepeat(uint32_t begin_msec, uint32_t repeat_msec);

			void Enable(bool unk = true);

			void Disable(bool unk = true);

			void SetDisableColor(math::v4 const& color)
			{
				math::v4 *old_col = m_disable_color;
				m_disable_color = new math::v4(color);
				delete old_col;
			}

			void SetDisableColor(float r, float g, float b, float a)
			{
				math::v4 *old_col = m_disable_color;
				m_disable_color = new math::v4(r, g, b, a);
				delete old_col;
			}

			void SetDisableColor32(uint32_t color)
			{
				uint8_t r = (m_color & 0xFF000000) >> 24;
				uint8_t g = (m_color & 0x00FF0000) >> 16;
				uint8_t b = (m_color & 0x0000FF00) >> 8;
				uint8_t a = (m_color & 0x000000FF);
				math::v4 *old_col = m_disable_color;
				m_disable_color = new math::v4((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, (float)a / 255.0f);
				delete old_col;
			}

			int32_t DoButtonEvent(int32_t type)
			{
				Event ev(EV_COMMAND, Event::MODE_DISPATCH, Event::ROUTE_FORWARD, 0, 0, 0, 0, 0);
				return DoEvent(type, &ev);
			}

			bool IsEnable()
			{
				return m_enable;
			}

			bool IsEnableRepeat()
			{
				return m_enable_repeat;
			}

			math::v4 *GetDisableColor() const
			{
				return m_disable_color;
			}

		protected: //0x2B0

			int32_t m_unk_27C;
			float m_unk_280;
			uint32_t m_btn_mode;
			ButtonState m_btn_state;
			math::v4 *m_disable_color;
			bool m_enable : 1;
			bool m_unk_290_1 : 1;
			bool m_unk_290_2 : 1;
			bool m_enable_repeat : 1;
			bool m_unk_290_4 : 1;
			bool m_unk_290_5 : 1;
			bool m_unk_290_6 : 1;
			bool m_unk_290_7 : 1;
			char m_unk_291;
			char m_unk_292;
			char m_unk_293;
			char m_unk_294;
			char m_unk_295;
			uint32_t m_repeat_begin : 16;
			uint32_t m_repeat_msec : 16;
			uint32_t m_unk_29A : 16;
			char m_unk_29C[0x14];

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_BUTTON_BASE_H */