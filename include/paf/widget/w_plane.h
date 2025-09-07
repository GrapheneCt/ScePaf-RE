/*
	ScePaf-RE Project
*/

#ifndef _PAF_WIDGET_W_PLANE_H
#define _PAF_WIDGET_W_PLANE_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factoryPlane;

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

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _PAF_WIDGET_W_PLANE_H */
