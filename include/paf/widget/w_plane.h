/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_PLANE_H
#define _VDSUITE_USER_PAF_WIDGET_W_PLANE_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryPlane;

namespace paf {

	namespace graph {

		class PlaneObj;
	}

	namespace ui {

		class Plane : public Widget
		{
		public:

			enum
			{
				OBJ_PLANE = 0
			};

			static const char *TypeName();

			Plane(Widget *_parent, CreateParam *_param);

			virtual ~Plane();

		protected: //0x280

			graph::PlaneObj *m_planeobj;

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_PLANE_H */