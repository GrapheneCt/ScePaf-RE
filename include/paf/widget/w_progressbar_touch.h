/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_PROGRESSBAR_TOUCH_H
#define _VDSUITE_USER_PAF_WIDGET_W_PROGRESSBAR_TOUCH_H

#include <paf/widget/w_progressbar.h>
#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryProgressBarTouch;

namespace paf {

	namespace ui {

		class ProgressBarTouch : public ProgressBar
		{
		public:

			enum
			{
				OBJ_SLIDER = 7,
				OBJ_PROGRESSBAR_TOUCH_END = 8
			};

			enum
			{
				CB_PROGRESSBAR_CHANGED = 0x10000000,
				CB_PROGRESSBAR_DRAG_BEGIN = 0x10000001,
				CB_PROGRESSBAR_DRAG_MOVE = 0x10000002,
				CB_PROGRESSBAR_DRAG_END = 0x10000003,
				CB_PROGRESSBAR_TOUCH_END = 0x10000004
			};

			enum SliderMode
			{
				SLIDER_MODE_NORMAL = 0,
				SLIDER_MODE_LIMITED_BY_BACK = 1
			};

			enum
			{
				PARTS_SLIDER = 8,
				PARTS_LABEL_SLIDER = 9,
				PARTS_PROGRESSBAR_TOUCH_END = 10
			};

			enum
			{
				DIRTY_FLAG_LABEL_SLIDER_POS = 4,
				DIRTY_FLAG_PROGRESSBAR_TOUCH_END = 5
			};

			static const char *TypeName();

			ProgressBarTouch(Widget *_parent, CreateParam *_param);

			virtual ~ProgressBarTouch();

			virtual int32_t SetObjSize(math::v4 const& size, int32_t obj);
			virtual int32_t GetObjSize(math::v4& size, int32_t obj);
			virtual int32_t SetSliderMode(SliderMode mode);
			virtual SliderMode GetSliderMode();
			virtual int32_t AttachLabelSliderWidget(Widget *pWidget);
			virtual int32_t DetachLabelSliderWidget();
			virtual Widget *GetLabelSliderWidget();
			virtual int32_t SetLabelSliderMode(LabelMode mode);
			virtual LabelMode GetLabelSliderMode();
			virtual int32_t SetLabelSliderPosMode(LabelPosMode mode);
			virtual LabelPosMode GetLabelSliderPosMode();
			virtual int32_t SetLabelSliderMargin(float margin);
			virtual float GetLabelSliderMargin();
			virtual int32_t unkFun_238();
			virtual int32_t unkFun_23C();
			virtual void UpdateSliderPos(bool bWithAnim);
			virtual void UpdateSliderDragRange();
			virtual void UpdateLabelSlider(float val);
			virtual void UpdateLabelSliderPos();
			virtual void OnTouch(Event *e);
			virtual void OnDragBeginSlider(Event *e);
			virtual void OnDragMoveSlider(Event *e);
			virtual void OnDragEndSlider(Event *e, bool bAbort);
			virtual void OnDragSlider(int32_t type, bool bAbort);

		protected: //0x318

			SliderMode m_sliderMode;
			LabelMode m_labelSliderMode;
			LabelPosMode m_labelSliderPosMode;
			float m_labelSliderMargin;
			char m_unk_300[0x18];

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_PROGRESSBAR_TOUCH_H */