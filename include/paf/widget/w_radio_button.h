/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_RADIO_BUTTON_H
#define _VDSUITE_USER_PAF_WIDGET_W_RADIO_BUTTON_H

#include <paf/widget/w_state_button_base.h>

namespace paf {

	namespace ui {

		class RadioButton : public StateButtonBase
		{
		public:

			static const char *TypeName();

			RadioButton(Widget *_parent, CreateParam *_param);

			virtual ~RadioButton();

		protected: //0x2C8

			__declspec(dllimport) static const char *m_widget_type;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_RADIO_BUTTON_H */