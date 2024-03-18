/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_CORNER_BUTTON_H
#define _VDSUITE_USER_PAF_WIDGET_W_CORNER_BUTTON_H

#include <paf/widget/factory.h>
#include <paf/widget/w_button.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryCornerButton;

namespace paf {

	namespace ui {

		class CornerButton : public Button
		{
		public:

			static const char *TypeName();

			CornerButton(Widget *_parent, CreateParam *_param);

			virtual ~CornerButton();

		protected: //0x2D0

			char m_unk_2C0[0x10];

			__declspec(dllimport) static const char *m_widget_type;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_CORNER_BUTTON_H */