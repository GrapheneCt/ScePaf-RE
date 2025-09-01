/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_IMAGE_BUTTON_H
#define _VDSUITE_USER_PAF_WIDGET_W_IMAGE_BUTTON_H

#include <paf/widget/w_button.h>
#include <paf/widget/factory.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factoryImageButton;

namespace paf {

	namespace ui {

		class ImageButton : public Button
		{
		public:

			enum
			{
				OBJ_IMAGE_BACK = 2,
				OBJ_IMAGE = 3,
				OBJ_IMAGE_BTN_END = 4
			};

			static const char *TypeName();

			ImageButton(Widget *_parent, CreateParam *_param);

			virtual ~ImageButton();

			virtual int32_t unkFun_1C4();

			void OverlayVertical();
			void BackVertical();
			void FrontVertical();

			void OverlayHorizontal();
			void BackHorizontal();
			void FrontHorizontal();

			void SetTextureSize(math::v3 const& size);

			void SetTextureCrossFadeAnim(float time, int32_t func);

		protected: //0x360

			char m_unk_2C0[0xA0];

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_IMAGE_BUTTON_H */