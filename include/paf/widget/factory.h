/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_FACTORY_H
#define _VDSUITE_USER_PAF_WIDGET_FACTORY_H

#include <stdint.h>
#include <stddef.h>

namespace paf {

	namespace graph {

		class DrawObj;
		class DrawObjParam;
	}

	namespace ui {

		class Widget;
		class WidgetParam;
		class WidgetLayoutParam;
		class WidgetStyleParam;
		class WidgetHandlerParam;

		class FactoryFuncTable
		{
		public:

			char *m_name;
			Widget*(*m_factory_widget)(Widget *);
			WidgetParam*(*m_factory_param)();
			WidgetLayoutParam*(*m_factory_layout)();
			WidgetStyleParam*(*m_factory_style)();
			WidgetHandlerParam*(*m_factory_handler)();
		};

		class FactoryFuncDrawObj
		{
		public:

			char * m_name;
			graph::DrawObj*(*m_factory_drawobj)(void);
			graph::DrawObjParam*(*m_factory_objparam)(void);
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_FACTORY_H */