/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_RADIO_BOX_H
#define _VDSUITE_USER_PAF_WIDGET_W_RADIO_BOX_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factoryRadioBox;

namespace paf {

	namespace ui {

		class RadioButton;

		class RadioBox : public Widget
		{
		public:

			static const char *TypeName();

			RadioBox(Widget *_parent, CreateParam *_param);

			virtual ~RadioBox();

			virtual void SetSlider(Widget *widget);
			virtual int32_t unkFun_174();
			virtual void OnValueChanged(RadioButton *radio_button);
			virtual void OnDestroyChecked(Widget *widget);
			virtual int32_t unkFun_180();
			virtual int32_t unkFun_184();
			virtual int32_t unkFun_188();
			virtual int32_t unkFun_18C();
			virtual int32_t unkFun_190();

			void SendEvent(int32_t type, int32_t v0, int32_t v1, int32_t v2, int32_t v3);

			void CBDestroyChecked(void *data);

		protected: // 0x290

			Widget *m_slider;
			RadioButton *m_checked;
			unsigned int m_unk_284;
			unsigned int m_unk_288;
			unsigned int m_unk_28C;

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_RADIO_BOX_H */