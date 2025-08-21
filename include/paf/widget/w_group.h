/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_GROUP_H
#define _VDSUITE_USER_PAF_WIDGET_W_GROUP_H

#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryGroup;

namespace paf {

	namespace ui {

		class Group : public Widget
		{
		public:

			static const char *TypeName(void);

			virtual ~Group();

			virtual bool IsInherit(char const *) const;
			virtual char *GetTypeName(void) const;

		protected:
			unsigned char m_unk_0x27C[4];

			__declspec (dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_GROUP_H */