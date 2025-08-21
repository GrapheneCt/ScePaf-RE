/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_CANVAS_H
#define _VDSUITE_USER_PAF_WIDGET_W_CANVAS_H

#include <paf/widget/w_plane.h>

namespace paf {

	namespace ui {

		class Canvas : public Plane
		{
		public:

			Canvas(Widget *_parent, CreateParam *_param);

			virtual ~Canvas();

		protected:
			int m_unk_0x280;
			int m_unk_0x284;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_CANVAS_H */