/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_COMPOSITE_DRAWER_H
#define _VDSUITE_USER_PAF_WIDGET_W_COMPOSITE_DRAWER_H

#include <paf/widget/core/widget.h>

namespace paf {

	namespace ui {

		class CompositeDrawer : public Widget
		{
		public:

			static const char *TypeName();

			CompositeDrawer(Widget *_parent, CreateParam *_param);

			virtual ~CompositeDrawer();

			virtual int32_t unkFun_170();
			virtual int32_t unkFun_174();
			virtual int32_t unkFun_178();

		protected: //0x27C

			__declspec(dllimport) static const char *m_widget_type;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_COMPOSITE_DRAWER_H */