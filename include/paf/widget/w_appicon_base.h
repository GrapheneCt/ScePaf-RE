/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_APPICON_BASE_H
#define _VDSUITE_USER_PAF_WIDGET_W_APPICON_BASE_H

#include <paf/widget/core/widget.h>

namespace paf {

	namespace ui {

		class AppIconBaseParam : public WidgetParam
		{
		public:
			static const char *ParamName();
			AppIconBaseParam();
			virtual const char *GetParamName() const;
			virtual ~AppIconBaseParam();
			virtual int32_t Set();
			virtual int32_t Get();
			virtual int32_t Create(int32_t mode);

		private:

			__declspec (dllimport) static const char m_param_name[];
		};

		class AppIconBaseStyleParam : public WidgetStyleParam
		{
		public:
			static const char *ParamName();
			AppIconBaseStyleParam();
			virtual const char *GetParamName() const;
			virtual ~AppIconBaseStyleParam();

		private:

			__declspec (dllimport) static const char m_param_name[];
		};

		class AppIconBase : public Widget
		{
		public:

			static const char *TypeName();

			AppIconBase(Widget *_parent, CreateParam *_param);

			virtual ~AppIconBase();

			virtual int32_t unkFun_170();
			virtual int32_t unkFun_174();
			virtual int32_t unkFun_178();
			virtual int32_t unkFun_17C();
			virtual int32_t unkFun_180();
			virtual int32_t unkFun_184();

		protected: //0x2D0

			char m_unk_27C[0x54];

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_APPICON_BASE_H */