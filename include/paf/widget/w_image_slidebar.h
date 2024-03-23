/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_IMAGE_SLIDEBAR_H
#define _VDSUITE_USER_PAF_WIDGET_W_IMAGE_SLIDEBAR_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryImageSlideBar;

namespace paf {

	namespace ui {

		class ImageSlideBar : public Widget
		{
		public:

			enum
			{
				OBJ_BASE = 0,
				OBJ_BAR = 1,
				OBJ_IMAGE_SLIDEBAR_END = 2
			};

			enum
			{
				CB_IMAGE_SLIDEBAR_CHANGED = 0x10000000,
				CB_IMAGE_SLIDEBAR_DRAG_BEGIN = 0x10000001,
				CB_IMAGE_SLIDEBAR_DRAG_END = 0x10000002,
				CB_IMAGE_SLIDEBAR_END = 0x10000003
			};

			enum
			{
				PARTS_BASE = 0,
				PARTS_BAR = 1,
				PARTS_IMAGE_SLIDEBAR_END = 2
			};

			enum BaseMode
			{
				BASE_MODE_ZERO_BASED = 0,
				BASE_MODE_ONE_BASED = 1
			};

			enum TextureMode
			{
				TEXTURE_MODE_WHOLE = 0,
				TEXTURE_MODE_STEP = 1
			};

			static const char *TypeName();

			ImageSlideBar(Widget *_parent, CreateParam *_param);

			virtual ~ImageSlideBar();

			virtual int32_t SetObjColor(math::v4 const& color, int32_t obj);
			virtual int32_t GetObjColor(math::v4& color, int32_t obj);
			virtual int32_t SetBaseMode(BaseMode mode);
			virtual int32_t SetTextureMode(TextureMode mode);
			virtual int32_t SetMaxValue(int32_t max);
			virtual int32_t SetValue(int32_t val, bool bWithAnim);
			virtual int32_t SetBarAnim(float animTime, int32_t animFunc);
			virtual void AdjustParameter();
			virtual void UpdateBase();
			virtual void UpdateBar(bool bWithAnim);
			virtual void OnTouch(Event *e);
			virtual void OnTouchUpdateValue();
			virtual void OnDragEnd(bool bAbort);

			void SetTexRegion(int32_t obj, math::v4 const& texRegion, Timer *pTimer, int32_t option);

			void GetBarAnim(float *pAnimTime, int32_t *pAnimFunc)
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

			BaseMode GetBaseMode()
			{
				return m_baseMode;
			}

			TextureMode GetTextureMode()
			{
				return m_textureMode;
			}

			int32_t GetValue()
			{
				return m_value;
			}

		protected: //0x2A8

			BaseMode m_baseMode;
			TextureMode m_textureMode;
			int32_t m_max;
			int32_t m_value;
			float m_animTime;
			int32_t m_animFunc;
			float m_normValue;
			int m_unk_0x298;
			int m_unk_0x29C;
			int m_unk_0x2A0;
			int m_unk_0x2A4;

			__declspec(dllimport) static const char *m_widget_type;
		};


	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_IMAGE_SLIDEBAR_H */