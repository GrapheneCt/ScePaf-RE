/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_CHECK_BOX_H
#define _VDSUITE_USER_PAF_WIDGET_W_CHECK_BOX_H

#include <paf/widget/w_state_button_base.h>

namespace paf {

	namespace ui {

		class CheckBox : public StateButtonBase
		{
		public:

			static const char *TypeName();

			CheckBox(Widget *_parent, CreateParam *_param);

			virtual ~CheckBox();

		protected: //0x2C8

			__declspec(dllimport) static const char *m_widget_type;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_CHECK_BOX_H */