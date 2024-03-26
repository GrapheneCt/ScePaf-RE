/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_LIST_ITEM_H
#define _VDSUITE_USER_PAF_WIDGET_W_LIST_ITEM_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryListItem;

namespace paf {

	namespace ui {

		namespace listview {

			class Cell;
		}

		class ListItem : public Widget
		{
		public:

			enum
			{
				OBJ_BG = 0,
				OBJ_LIST_ITEM_END = 1
			};

			static const char *TypeName();

			ListItem(Widget *_parent, CreateParam *_param);

			virtual ~ListItem();

			int32_t GetSegmentIndex();

			int32_t GetCellIndex();

			ListView *GetListView();

			ListItem *GetListItem();

			bool BeginDrag(int32_t touch_id);

			void EndDrag(int32_t touch_id);

		protected: //0x2D0

			listview::Cell *m_cell;
			char m_unk_280[0x50];

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_LIST_ITEM_H */