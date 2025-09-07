/*
	ScePaf-RE Project
*/

#ifndef _PAF_WIDGET_W_ITEM_SPIN_H
#define _PAF_WIDGET_W_ITEM_SPIN_H

#include <paf/widget/w_spin_base.h>

namespace paf {

	namespace ui {

		class ItemSpin : public SpinBase
		{
		public:

			static const char *TypeName(void);

			ItemSpin(Widget *_parent, CreateParam *_param);

			virtual ~ItemSpin();

			virtual bool IsInherit(char const *) const;
			virtual char *GetTypeName(void) const;

		protected:
			unsigned char m_unk_0x2B0[0xC];

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _PAF_WIDGET_W_ITEM_SPIN_H */
