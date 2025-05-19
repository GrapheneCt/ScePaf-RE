/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_PAGETURN_H
#define _VDSUITE_USER_PAF_WIDGET_W_PAGETURN_H

#include <paf/widget/factory.h>
#include <paf/widget/w_pageturn_base.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryPageTurn;

namespace paf {

	namespace ui {

		class PageTurn : public PageTurnBase
		{
		public:

			static const char *TypeName(void);

			PageTurn(Widget *_parent, CreateParam *_param);

			virtual ~PageTurn();

			virtual bool IsInherit(char const *) const;
			virtual char *GetTypeName(void) const;

		protected:
			unsigned char m_unk_0x2B0[0x48];

			__declspec (dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_PAGETURN_H */