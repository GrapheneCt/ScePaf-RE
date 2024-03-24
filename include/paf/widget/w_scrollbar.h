/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_SCROLLBAR_H
#define _VDSUITE_USER_PAF_WIDGET_W_SCROLLBAR_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryScrollBar;

namespace paf {

	namespace ui {

		class ScrollBar : public Widget
		{
		public:

			enum
			{
				OBJ_BASE = 0,
				OBJ_SLIDER = 1,
				OBJ_SCROLLBAR_END = 2
			};

			enum ScrollType
			{
				SCROLL_TYPE_VERTICAL = 0,
				SCROLL_TYPE_HORIZONTAL = 1
			};

			static const char *TypeName();

			ScrollBar(Widget *_parent, CreateParam *_param);

			virtual ~ScrollBar();

			virtual int32_t SetObjColor(math::v4 const& color, int32_t obj);
			virtual int32_t GetObjColor(math::v4& color, int32_t obj);
			virtual int32_t unkFun_178();
			virtual int32_t unkFun_17C();
			virtual int32_t unkFun_180();
			virtual int32_t unkFun_184();
			virtual int32_t unkFun_188();
			virtual int32_t SetScrollType(ScrollType type);
			virtual int32_t SetSliderSize(math::v4 const& size);
			virtual int32_t SetSliderMinSize(float min);
			virtual int32_t SetMaxValue(float val);
			virtual int32_t SetMaxValue(int32_t val);
			virtual int32_t SetVisibleAmount(float val);
			virtual int32_t SetVisibleAmount(int32_t val);
			virtual int32_t SetValue(float val, bool bWithAnim);
			virtual int32_t SetValue(int32_t val, bool bWithAnim);
			virtual float GetValue();
			virtual int32_t SetSliderAnim(float animTime, int32_t animFunc);
			virtual Widget *GetPartsWidget(int32_t obj, int32_t *pChildObj);
			virtual void UpdateSlider(bool bWithAnim);
			virtual int32_t unkFun_1C0();

			void AdjustParameter(bool bWithAnim);

			void AdjustSliderSize();

			float GetMaxValue()
			{
				return m_max;
			}

			ScrollType GetScrollType()
			{
				return m_type;
			}

			void GetSliderAnim(float *pAnimTime, int32_t *pAnimFunc)
			{
				if (pAnimTime != NULL)
				{
					*pAnimTime = m_animTime;
				}
				if (pAnimFunc != NULL)
				{
					*pAnimFunc = m_animFunc;
				}
			}

			float GetSliderMinSize()
			{
				return m_fMinSize;
			}

			math::v4& GetSliderSize()
			{
				return m_sliderSize;
			}

			float GetVisibleAmount()
			{
				return m_visible;
			}



		protected: //0x2D0

			vector<Widget*> m_partsList;
			ScrollType m_type;
			math::v4 m_sliderSize;
			float m_fMinSize;
			float m_max;
			float m_visible;
			float m_value;
			float m_animTime;
			int32_t m_animFunc;
			int32_t m_unk_2B8;
			int32_t m_unk_2BC;
			float m_normVisible;
			float m_normValue;
			float m_normBase;
			int32_t m_unk_2CC;

			__declspec(dllimport) static const char *m_widget_type;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_SCROLLBAR_H */