/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_RADIO_BUTTON_H
#define _VDSUITE_USER_PAF_WIDGET_W_RADIO_BUTTON_H

#include <paf/widget/factory.h>
#include <paf/widget/w_state_button_base.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factoryRadioButton;

namespace paf {

	namespace ui {

		class RadioButton : public StateButtonBase
		{
		public:

			static const char *TypeName();

			RadioButton(Widget *_parent, CreateParam *_param);

			virtual ~RadioButton();

		protected: //0x2C8

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_RADIO_BUTTON_H */