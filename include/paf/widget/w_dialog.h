/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_DIALOG_H
#define _VDSUITE_USER_PAF_WIDGET_W_DIALOG_H

#include <paf/widget/factory.h>
#include <paf/widget/w_box.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factoryDialog;

namespace paf {

	namespace ui {

		class PartsList
		{
		public:

			int32_t parts_id;
			IDParam id;
		};

		class Dialog : public Box
		{
		public:

			enum
			{
				TERMINATOR = 0,
				PARTS_DIALOG_END = 1
			};

			static const char *TypeName();

			Dialog(Widget *_parent);

			virtual ~Dialog();

			void SetPartsList(const PartsList *parts_list);

			IDParam& GetPartsWidgetId(int32_t parts_id);

			Widget *GetPartsWidget(int32_t parts_id);

			int32_t SetPartsString(int32_t parts_id, wstring const& text);

		protected: //0x330

			map <int32_t, IDParam> m_parts_id_table;
			int32_t padding;

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_DIALOG_H */