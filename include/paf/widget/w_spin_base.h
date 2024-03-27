/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_SPIN_BASE_H
#define _VDSUITE_USER_PAF_WIDGET_W_SPIN_BASE_H

#include <paf/widget/core/widget.h>

namespace paf {

	namespace ui {

		class SpinBase : public Widget
		{
		public:

			SpinBase(Widget *_parent, CreateParam *_param);

			virtual ~SpinBase();

		protected:
			unsigned char m_unk_0x27C[0x34];

			__declspec (dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_SPIN_BASE_H */