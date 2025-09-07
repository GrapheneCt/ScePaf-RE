/*
	ScePaf-RE Project
*/

#ifndef _PAF_WIDGET_W_SLIDEBAR_H
#define _PAF_WIDGET_W_SLIDEBAR_H

#include <paf/widget/factory.h>
#include <paf/widget/core/widget.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factorySlideBar;

namespace paf {
	namespace ui {

		class SlideBarParam : public WidgetParam
		{
		public:
			static const char *ParamName(void);

			virtual const char *GetParamName(void) const;
			SlideBarParam();
			virtual ~SlideBarParam();
			virtual int Set(void);
			virtual int Get(void);
			virtual int Create(int mode);

		private:
			unsigned char m_unk_0x78[0x70];

			SCE_PAF_IMPORTED_FROM_PRX static const char m_param_name[];
			SCE_PAF_IMPORTED_FROM_PRX static const WidgetParam::TextureList c_textureList[];
		};

		class SlideBarStyleParam : public WidgetStyleParam
		{
		public:
			static const char *ParamName();
			SlideBarStyleParam();
			virtual const char *GetParamName() const;
			virtual ~SlideBarStyleParam();
			virtual int32_t Create(int32_t mode);
			virtual int32_t SetEach(Widget *widget);
			virtual int32_t GetEach(Widget *widget);

		private:
			unsigned char unk_0x60[0x3A8];

			SCE_PAF_IMPORTED_FROM_PRX static const char m_param_name[];
		};

		class SlideBarSoundParam : public WidgetSoundParam
		{
		public:
			static const char *ParamName();
			SlideBarSoundParam();
			virtual const char *GetParamName() const;
			virtual ~SlideBarSoundParam();

		private:

			SCE_PAF_IMPORTED_FROM_PRX static const char m_param_name[];
		};

		class SlideBar : public Widget
		{
		public:

			static const char *TypeName(void);

			SlideBar(Widget *_parent, CreateParam *_param);

			virtual ~SlideBar();

			virtual bool IsInherit(char const *) const;
			virtual char *GetTypeName(void) const;

			void UpdateSlider(bool bWithAnim = true); // TODO: this is in virtual really.

			void SetFraction(SceUInt32 fraction)
			{
				m_fraction = fraction;
			}

			void SetValue(float value)
			{
				m_value = value;
				m_unk_0x294 = (int32_t)(((float)m_fraction) * value);
				UpdateSlider(false);
			}

			float GetValue()
			{
				return m_value;
			}

		protected:

			void *m_unk_0x27C;
			uint32_t m_unk_0x280;
			uint32_t m_unk_0x284;
			uint32_t m_unk_0x288;
			uint32_t m_unk_0x28C;
			uint32_t m_fraction;
			uint32_t m_unk_0x294;
			float m_unk_0x298;
			uint32_t m_unk_0x29C;
			uint32_t m_unk_0x2A0;
			uint32_t m_unk_0x2A4;
			uint32_t m_unk_0x2A8;
			uint32_t m_unk_0x2AC;
			uint32_t m_unk_0x2B0;
			uint32_t m_unk_0x2B4;
			float m_unk_0x2B8;
			float m_unk_0x2BC;
			float m_unk_0x2C0;
			float m_value;
			int32_t m_unk_0x2C8;
			int32_t m_unk_0x2CC;
			uint32_t m_unk_0x2D0;
			uint32_t m_unk_0x2D4;
			uint32_t m_unk_0x2D8;
			uint32_t m_unk_0x2DC;
			void *m_unk_0x2E0;
			uint32_t m_unk_0x2E4;
			uint32_t m_unk_0x2E8;
			uint32_t m_unk_0x2EC;

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _PAF_WIDGET_W_SLIDEBAR_H */
