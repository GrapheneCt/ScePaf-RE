/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_APPICON_SAMPLE_H
#define _VDSUITE_USER_PAF_WIDGET_W_APPICON_SAMPLE_H

#include <paf/widget/core/widget.h>

namespace paf {

	namespace ui {

		class AppIconSimple : public Widget
		{
		public:

			static const char *TypeName(void);

			AppIconSimple(Widget *_parent, CreateParam *_param);
			virtual ~AppIconSimple();

			virtual bool IsInherit(char const *) const;
			virtual char *GetTypeName(void) const;

		protected:
			unsigned char m_unk_0x27C[0x14];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_APPICON_SAMPLE_H */