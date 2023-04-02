/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_BUTTON_H
#define _VDSUITE_USER_PAF_WIDGET_W_BUTTON_H

#include <paf/widget/w_button_base.h>

namespace paf {

	namespace ui {

		class Button : public ButtonBase
		{
		public:

			enum
			{
				OBJ_BG = 0,
				OBJ_LABEL = 1,
				OBJ_BTN_END = 2
			};

			enum StyleType
			{
				MIN_STYLE_TYPE = 0,
				STYLE_MANUAL = 0,
				STYLE_AUTO = 1,
				NUM_STYLE_TYPES = 2,
				MAX_STYLE_TYPE = 1
			};

			static const char *TypeName();

			Button(Widget *_parent, CreateParam *_param);

			virtual ~Button();

			virtual bool UpdateObjsSize();
			virtual void UpdateButtonSize();

			void GetChildrenFitGeometry(math::v4 *size, math::v4 *offs);

			void SetStyleAnimator(StyleType style_type);

			void GetFitGeometry(math::v4 *size, math::v4 *offs) const;

			math::v4 GetLayoutSize(math::v4 const& fit_size, math::v4 const& offs);

			StyleType paf::ui::Button::GetStyleType() const
			{
				return m_style_type;
			}

		protected: //0x2C0

			StyleType m_style_type;
			int32_t m_unk_2B4;
			int32_t m_unk_2B8;
			int32_t m_unk_2BC;

			__declspec(dllimport) static const char *m_widget_type;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_BUTTON_BASE_H */