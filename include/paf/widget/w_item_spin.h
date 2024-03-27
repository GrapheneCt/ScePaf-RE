/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_ITEM_SPIN_H
#define _VDSUITE_USER_PAF_WIDGET_W_ITEM_SPIN_H

#include <paf/widget/w_spin_base.h>

namespace paf {

	namespace ui {

		class ItemSpin : public SpinBase
		{
		public:

			ItemSpin(Widget *_parent, CreateParam *_param);

			virtual ~ItemSpin();

		protected:
			unsigned char m_unk_0x2B0[0xC];

			__declspec (dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_ITEM_SPIN_H */