/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_PLANE_BUTTON_H
#define _VDSUITE_USER_PAF_WIDGET_W_PLANE_BUTTON_H

#include <paf/widget/factory.h>
#include <paf/widget/w_button_base.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryPlaneButton;

namespace paf {

	namespace ui {

		class PlaneButton : public ButtonBase
		{
		public:

			enum
			{
				OBJ_IMAGE = 0,
				OBJ_BTN_END = 1
			};

			enum StyleType
			{
				MIN_STYLE_TYPE = 0,
				STYLE_MANUAL = 0,
				MAX_STYLE_TYPE = 1,
				STYLE_AUTO = 1,
				NUM_STYLE_TYPES = 2
			};

			static const char *TypeName();

			PlaneButton(Widget *_parent, CreateParam *_param);

			virtual ~PlaneButton();

			virtual bool UpdateObjsSize();
			virtual void UpdateButtonSize();
			virtual void SetStyleAnimator(StyleType style_type);

			math::v4 GetLayoutSize(math::v4 const& fit_size, math::v4 const& offs);

			void GetFitGeometry(math::v4 const& size, math::v4 const& offs);

		protected: //0x2C0

			char m_unk_2B0[0x10];

			__declspec(dllimport) static const char *m_widget_type;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_PLANE_BUTTON_H */