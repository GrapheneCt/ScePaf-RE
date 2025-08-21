/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_PAGETURN_BASE_H
#define _VDSUITE_USER_PAF_WIDGET_W_PAGETURN_BASE_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryPageTurnBase;

namespace paf {

	namespace ui {

		class PageTurnBase : public Widget
		{
		public:

			static const char *TypeName(void);

			PageTurnBase(Widget *_parent, CreateParam *_param);

			virtual ~PageTurnBase();

			virtual bool IsInherit(char const *) const;
			virtual char *GetTypeName(void) const;

		protected:
			unsigned char m_unk_0x27C[0x34];

			__declspec (dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_PAGETURN_BASE_H */