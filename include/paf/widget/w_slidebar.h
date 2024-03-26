﻿/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_SLIDEBAR_H
#define _VDSUITE_USER_PAF_WIDGET_W_SLIDEBAR_H

#include <paf/widget/factory.h>
#include <paf/widget/core/widget.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factorySlideBar;

namespace paf {
	namespace ui {

		class SlideBarParam : public WidgetParam
		{
		public:
			static const char *ParamName(void);

			virtual const char *GetParamName(void) const;
			SlideBarParam();
			virtual ~SlideBarParam();
			virtual int Set(void);
			virtual int Get(void);
			virtual int Create(int mode);

		private:
			unsigned char m_unk_0x78[0x70];

			__declspec (dllimport) static const char m_param_name[];
			__declspec (dllimport) static const WidgetParam::TextureList c_textureList[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_SLIDEBAR_H */