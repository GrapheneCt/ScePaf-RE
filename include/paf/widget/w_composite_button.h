/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_COMPOSITE_BUTTON_H
#define _VDSUITE_USER_PAF_WIDGET_W_COMPOSITE_BUTTON_H

#include <paf/widget/w_button_base.h>

namespace paf {

	namespace ui {

		class CompositeButton : public ButtonBase
		{
		public:

			static const char *TypeName();

			CompositeButton(Widget *_parent, CreateParam *_param);

			virtual ~CompositeButton();

			virtual int32_t unkFun_1BC();
			virtual int32_t unkFun_1C0();
			virtual int32_t unkFun_1C4();

		protected: //0x2B0

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_COMPOSITE_BUTTON_H */