/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_SCROLLBAR_TOUCH_H
#define _VDSUITE_USER_PAF_WIDGET_W_SCROLLBAR_TOUCH_H

#include <paf/widget/w_scrollbar.h>
#include <paf/widget/factory.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factoryScrollBarTouch;

namespace paf {

	namespace ui {

		class ScrollBarTouch : public ScrollBar
		{
		public:

			enum
			{
				CB_SCROLLBAR_CHANGED = 0x10000000,
				CB_SCROLLBAR_DRAG_BEGIN = 0x10000001,
				CB_SCROLLBAR_DRAG_END = 0x10000002,
				CB_SCROLLBAR_TOUCH_END = 0x10000003
			};

			enum PageScrollMode : int32_t
			{
				PAGE_SCROLL_MODE_OFF = 0,
				PAGE_SCROLL_MODE_AUTO = 1,
				PAGE_SCROLL_MODE_MANUAL = 2
			};

			static const char *TypeName();

			ScrollBarTouch(Widget *_parent, CreateParam *_param);

			virtual ~ScrollBarTouch();

			virtual int32_t SetPageScrollMode(PageScrollMode mode);
			virtual int32_t unkFun_1C8();
			virtual int32_t unkFun_1CC();
			virtual int32_t unkFun_1D0();
			virtual void OnTouch(Event *e);
			virtual void OnDragBeginSlider(Event *e);
			virtual void OnDragMoveSlider(Event *e);
			virtual void OnDragEndSlider(Event *e, bool bAbort);
			virtual void OnDragSlider();

			void PageScroll();

			PageScrollMode GetPageScrollMode()
			{
				return m_pageScrollMode;
			}

		protected: //0x2E8

			PageScrollMode m_pageScrollMode;
			char m_unk_2D4[0x14];

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_SCROLLBAR_TOUCH_H */