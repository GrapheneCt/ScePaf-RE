/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_APPICON2D_H
#define _VDSUITE_USER_PAF_WIDGET_W_APPICON2D_H

#include <paf/widget/w_appicon_base.h>

namespace paf {

	namespace ui {

		class AppIcon2d : public AppIconBase
		{
		public:

			static const char *TypeName();

			AppIcon2d(Widget *_parent, CreateParam *_param);

			virtual ~AppIcon2d();

		protected: //0x2D0

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_APPICON2D_H */