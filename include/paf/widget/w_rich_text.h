/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_RICH_TEXT_H
#define _VDSUITE_USER_PAF_WIDGET_W_RICH_TEXT_H

#include <paf/widget/factory.h>
#include <paf/widget/w_scroll_view_base.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryRichText;

namespace paf {
	
	namespace ui {

		class RichText : public ScrollViewBase
		{
		public:

			enum
			{
				CB_RICH_TEXT_BEGIN = 0x10000005,
				CB_RICH_TEXT_REQ_IMG_SIZE = 0x10000006,
				CB_RICH_TEXT_FINISH_LAYOUT = 0x10000007,
				CB_RICH_TEXT_SCROLL_IN = 0x10000008,
				CB_RICH_TEXT_SCROLL_OUT = 0x10000009,
				CB_RICH_TEXT_END = 0x1000000A
			};

			enum
			{
				ITEM_NONE = 0,
				ITEM_TEXT = 1,
				ITEM_IMAGE = 2
			};

			enum
			{
				NUM_FONT_SIZE = 8
			};

			class Layouter;

			static const char *TypeName();

			RichText(Widget *_parent, CreateParam *_param);

			virtual ~RichText();

			void Clear();

			void scroll_up(float y);

			void scroll_down(float y);

			void SetVisibleTop(float y);

			int32_t SetCText(const char *str, size_t length);

			Widget *GetItemWidget(int32_t sce_paf_index);

			int32_t GetItemType(int32_t sce_paf_index);

			int32_t GetItemUrl(int32_t sce_paf_index, string& url);

			int32_t GetImageUrl(int32_t image_index, string& url);

			int32_t GetHtmlImageSize(int32_t image_index, math::v4& size);

			int32_t SetImageSize(int32_t image_index, math::v4 const& size);

		protected: //0x550

			class MemoryAllocator
			{
			public:

				void *alloc;
				void *free;
			};

			MemoryAllocator m_text_allocator;
			char *m_str;
			char *m_str_end;
			char m_unk_410[0x9C];
			float m_content_height;
			float m_visible_top;
			bool m_layout_done;
			Layouter *m_layouter;
			char m_unk_4BC[0x94];

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_RICH_TEXT_H */