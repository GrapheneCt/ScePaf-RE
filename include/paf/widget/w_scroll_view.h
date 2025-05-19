/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_SCROLL_VIEW_H
#define _VDSUITE_USER_PAF_WIDGET_W_SCROLL_VIEW_H

#include <paf/widget/factory.h>
#include <paf/widget/w_scroll_view_base.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryScrollView;

namespace paf {
	
	namespace ui {

		class ScrollViewStyleParam : public ScrollViewBaseStyleParam
		{
		public:
			static const char *ParamName();
			virtual const char *GetParamName() const;
			virtual ~ScrollViewStyleParam();

		private:
			unsigned char m_unk_0x168[0x28];

			__declspec (dllimport) static const char m_param_name[];
		};

		class ScrollView : public ScrollViewBase
		{
		public:

			static const char *TypeName();

			ScrollView(Widget *_parent, CreateParam *_param);

			virtual ~ScrollView();

			virtual void UpdateViewBox();
			virtual void UpdateAutoSnapPoint();
			virtual bool IsIgnored(Widget *w);

			Widget *GetViewParent();

			void Clear();

			void DelSnapChild(Widget *child);
			void AddSnapChild(Widget *child);

			void DelIgnoredChild(Widget *child);
			void AddIgnoredChild(Widget *child);

			void SetAutoSnap(bool onoff);

			int32_t GetSnapID(Widget *child);

			bool IsAutoSnap()
			{
				return m_is_auto_snap;
			}

		protected: //0x440

			map<Widget*, int32_t> m_snap_map;
			vector<Widget*> m_ignore_list;
			bool m_is_auto_snap;
			bool m_unk_41D;
			int m_unk_420[8];

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_SCROLL_VIEW_H */