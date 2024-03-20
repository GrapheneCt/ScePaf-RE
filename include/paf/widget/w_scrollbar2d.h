/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_SCROLLBAR2D_H
#define _VDSUITE_USER_PAF_WIDGET_W_SCROLLBAR2D_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryScrollBar2d;

namespace paf {

	namespace ui {

		class ScrollBar2d : public Widget
		{
		public:

			enum
			{
				OBJ_BASE = 0,
				OBJ_SLIDER = 1,
				OBJ_SCROLLBAR2D_END = 2
			};

			enum
			{
				PARTS_BASE = 0,
				PARTS_SLIDER = 1,
				PARTS_SCROLLBAR2D_END = 2
			};

			enum
			{
				CB_SCROLLBAR2D_CHANGED = 0x10000000,
				CB_SCROLLBAR2D_DRAG_BEGIN = 0x10000001,
				CB_SCROLLBAR2D_DRAG_END = 0x10000002,
				CB_SCROLLBAR2D_END = 0x10000003
			};

			static const char *TypeName();

			ScrollBar2d(Widget *_parent, CreateParam *_param);

			virtual ~ScrollBar2d();

			virtual int32_t SetObjColor(math::v4 const& color, int32_t obj);
			virtual int32_t GetObjColor(math::v4& color, int32_t obj);
			virtual int32_t SetMaxValue(math::v2 const& val);
			virtual int32_t SetVisibleAmount(math::v2 const& val);
			virtual int32_t SetValue(math::v2 const& val, bool bWithAnim);
			virtual int32_t SetSliderAnim(float animTime, int32_t animFunc);
			virtual Widget *GetPartsWidget(int32_t obj, int32_t *pChildObj);
			virtual void UpdateSlider(bool bWithAnim);
			virtual void OnTouch(Event *e);
			virtual void OnDragBeginSlider(Event *e);
			virtual void OnDragMoveSlider(Event *e);
			virtual void OnDragEndSlider(Event *e, bool bAbort);
			virtual void OnDragSlider();

			void AdjustParameter(bool bWithAnim);


		protected: //0x2D0

			static void OnDragSliderEvent(int32_t type, Handler *h, Event *e, void *data);

			vector<Widget*> m_partsList;
			int32_t m_unk_28C;
			math::v2 m_max;
			math::v2 m_visible;
			math::v2 m_value;
			float m_animTime;
			int32_t m_animFunc;
			char m_unk_2B0[0x20];
			
			__declspec(dllimport) static const char *m_widget_type;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_SCROLLBAR2D_H */