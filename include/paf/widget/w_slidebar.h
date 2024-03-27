/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_SLIDEBAR_H
#define _VDSUITE_USER_PAF_WIDGET_W_SLIDEBAR_H

#include <paf/widget/factory.h>
#include <paf/widget/core/widget.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factorySlideBar;

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

			__declspec (dllimport) static const char m_param_name[];
			__declspec (dllimport) static const WidgetParam::TextureList c_textureList[];
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

			__declspec (dllimport) static const char m_param_name[];
		};

		class SlideBarSoundParam : public WidgetSoundParam
		{
		public:
			static const char *ParamName();
			SlideBarSoundParam();
			virtual const char *GetParamName() const;
			virtual ~SlideBarSoundParam();

		private:

			__declspec (dllimport) static const char m_param_name[];
		};

		class SlideBar : public Widget
		{
		public:

			static const char *TypeName(void);

			SlideBar(Widget *_parent, CreateParam *_param);

			virtual ~SlideBar();

			virtual bool IsInherit(char const *) const;
			virtual char *GetTypeName(void) const;

		protected:
			unsigned char m_unk_0x27C[0x74];

			__declspec (dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_SLIDEBAR_H */