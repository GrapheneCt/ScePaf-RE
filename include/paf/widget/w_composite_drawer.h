/*
	ScePaf-RE Project
*/

#ifndef _PAF_WIDGET_W_COMPOSITE_DRAWER_H
#define _PAF_WIDGET_W_COMPOSITE_DRAWER_H

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

		protected: //0x280

			int m_unk_0x27C;

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _PAF_WIDGET_W_COMPOSITE_DRAWER_H */
