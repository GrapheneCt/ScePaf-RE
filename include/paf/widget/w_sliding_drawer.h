/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_SLIDING_DRAWER_H
#define _VDSUITE_USER_PAF_WIDGET_W_SLIDING_DRAWER_H

#include <paf/widget/w_scroll_view_base.h>
#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factorySlidingDrawer;

namespace paf {
	
	namespace ui {

		class SlidingDrawer : public ScrollViewBase
		{
		public:

			enum SNAP_ALIGN_TYPE
			{
				SNAP_ALIGN_CENTER = 0,
				SNAP_ALIGN_TOP = 1,
				SNAP_ALIGN_BOTTOM = 2,
				SNAP_ALIGN_LEFT = 3,
				SNAP_ALIGN_RIGHT = 4
			};

			enum MOVABLE_DIRECTION_TYPE
			{
				MOVABLE_DIRECTION_NONE = 0,
				MOVABLE_DIRECTION_HORIZONTAL = 1,
				MOVABLE_DIRECTION_VERTICAL = 2
			};

			static const char *TypeName();

			SlidingDrawer(Widget *_parent, CreateParam *_param);

			virtual ~SlidingDrawer();

			virtual void UpdateViewBox();

			int32_t AddSnapPoint(Widget *w_snap, SNAP_ALIGN_TYPE align, math::v2 const& offset);
			int32_t AddSnapPoint(IDParam const& id, SNAP_ALIGN_TYPE align, math::v2 const& offset);
			void DelAllSnapPoint();

			void SetViewFocus(Widget *w, SNAP_ALIGN_TYPE align, math::v2 const& offset, Timer *timer);
			void SetViewFocus(IDParam const& id, SNAP_ALIGN_TYPE align, math::v2 const& offset, Timer *timer);
			math::v2 GetViewFocus(int32_t opt);

			void SetMovableDirection(uint32_t direction);
			uint32_t GetMovableDirection();

			void CheckMovableRange();

		protected: //0x430

			math::v4 m_last_view_pos;
			math::v4 m_view_velocity;
			math::v4 m_movable_range;

			__declspec(dllimport) static const char *m_widget_type;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_SLIDING_DRAWER_H */