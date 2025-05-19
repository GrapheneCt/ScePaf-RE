/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_TEXT_H
#define _VDSUITE_USER_PAF_WIDGET_W_TEXT_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>
#include <paf/graphics/text/text_layout.h>
#include <paf/graphics/text/text_style.h>
#include <paf/graphics/text/attributed_string.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryText;

namespace paf {

	namespace graph {

		class TextObj;
		class PlaneObj;
	}

	namespace ui {

		class TextStyleParam : public WidgetStyleParam
		{
		public:
			static const char *ParamName();
			TextStyleParam();
			virtual const char *GetParamName() const;
			virtual ~TextStyleParam();
			virtual int32_t Create(int32_t mode);

			virtual int32_t SetEach(Widget *widget);
			virtual int32_t GetEach(Widget *widget);

		private:
			unsigned char m_unk_0x60[0x1F8];

			__declspec (dllimport) static const char m_param_name[];
		};

		class Text : public Widget
		{
		public:

			enum
			{
				OBJ_TEXT = 0,
				OBJ_PLANE = 1,
				OBJ_TEXT_END = 2
			};

			enum
			{
				CB_TEXT_SELECTION_BEGIN = 0x10000000,
				CB_TEXT_SELECTION_END = 0x10000001,
				CB_TEXT_SELECTION_POS_CHANGED = 0x10000002,
				CB_TEXT_END = 0x10000003
			};

			enum
			{
				ALIGN_TEXT_CENTER = 4,
				ALIGN_BOTTOM_BASELINE = 5,
				ALIGN_TOP_BASELINE = 6,
				ALIGN_TEXT_END = 7
			};

			enum
			{
				ORIGIN_TEXT_CENTER = 4,
				ORIGIN_BOTTOM_BASELINE = 5,
				ORIGIN_TOP_BASELINE = 6,
				ORIGIN_TEXT_END = 7
			};

			enum
			{
				ANCHOR_TEXT_CENTER = 5,
				ANCHOR_BOTTOM_BASELINE = 6,
				ANCHOR_TOP_BASELINE = 7,
				ANCHOR_TEXT_END = 8
			};

			enum
			{
				ANIM_AUTO_SCROLL = 0x1000C,
				ANIM_CHAR_ANIM = 0x1000D,
				ANIM_CARET_SCROLL = 0x1000E,
				ANIM_CARET_BLINK = 0x1000F,
				ANIM_TEXT_END = 0x10010
			};

			enum ScrollType
			{
				SCROLL_TYPE_HORIZONTAL = 1,
				SCROLL_TYPE_VERTICAL = 2
			};

			enum CharAnimType
			{
				CHAR_ANIM_TYPE_WAVE = 1,
				CHAR_ANIM_TYPE_CUSTOM = 2
			};

			enum StyleType
			{
				MIN_STYLE_TYPE = 0,
				STYLE_MANUAL = 0,
				STYLE_AUTO = 1,
				NUM_STYLE_TYPES = 2,
				MAX_STYLE_TYPE = 1
			};

			static const char *TypeName();

			Text(Widget *_parent, CreateParam *_param);

			virtual ~Text();

			virtual int32_t unkFun_170();
			virtual int32_t ReplaceString(uint32_t sce_paf_index, uint32_t len, wstring const& str);
			virtual int32_t MoveCaretUp();
			virtual int32_t MoveCaretDown();
			virtual int32_t MoveCaretLeft();
			virtual int32_t MoveCaretRight();
			virtual int32_t SetCaretPos(math::v2 const& pos);
			virtual int32_t SetSelectionPos(math::v2 const& startPos, math::v2 const& endPos);
			virtual int32_t SetCaretIndex(uint32_t sce_paf_index);
			virtual int32_t SetSelectionRange(uint32_t sce_paf_index, uint32_t len);
			virtual int32_t SetCaretVisible(bool visible);
			virtual int32_t HandleTouchPress(Event *e);
			virtual int32_t HandleTouchRelease();
			virtual int32_t unkFun_1A4();
			virtual int32_t UpdateTouch(math::v2 const& pos);
			virtual int32_t SetVisiblePos(math::v2 const& pos);
			virtual int32_t AdjustSize();

			int32_t SetLayoutAttribute(graph::TextLayoutAttribute attr, bool val);
			int32_t SetLayoutAttribute(graph::TextLayoutAttribute attr, math::v2 const& val);
			int32_t SetLayoutAttribute(graph::TextLayoutAttribute attr, int32_t val);
			int32_t SetLayoutAttribute(graph::TextLayoutAttribute attr, float val);

			int32_t GetLayoutAttribute(graph::TextLayoutAttribute attr, int32_t& valOut);
			int32_t GetLayoutAttribute(graph::TextLayoutAttribute attr, float& valOut);
			int32_t GetLayoutAttribute(graph::TextLayoutAttribute attr, math::v2& valOut);
			int32_t GetLayoutAttribute(graph::TextLayoutAttribute attr, bool& valOut);

			int32_t SetStyleAttribute(graph::TextStyleAttribute attr, uint32_t sce_paf_index, uint32_t len, int32_t val);
			int32_t SetStyleAttribute(graph::TextStyleAttribute attr, uint32_t sce_paf_index, uint32_t len, float val);
			int32_t SetStyleAttribute(graph::TextStyleAttribute attr, uint32_t sce_paf_index, uint32_t len, math::v4 const& val);
			int32_t SetStyleAttribute(graph::TextStyleAttribute attr, uint32_t sce_paf_index, uint32_t len, math::v2 const& val);
			int32_t SetStyleAttribute(graph::TextStyleAttribute attr, uint32_t sce_paf_index, uint32_t len, bool val);

			int32_t GetStyleAttribute(graph::TextStyleAttribute attr, uint32_t sce_paf_index, int32_t& valOut);
			int32_t GetStyleAttribute(graph::TextStyleAttribute attr, uint32_t sce_paf_index, float& valOut);
			int32_t GetStyleAttribute(graph::TextStyleAttribute attr, uint32_t sce_paf_index, math::v4& valOut);
			int32_t GetStyleAttribute(graph::TextStyleAttribute attr, uint32_t sce_paf_index, math::v2& valOut);
			int32_t GetStyleAttribute(graph::TextStyleAttribute attr, uint32_t sce_paf_index, bool& valOut);

			int32_t SetCharPos(uint32_t sce_paf_index, math::v2 const& pos);

			int32_t GetLength(uint32_t& lenOut);

			int32_t GetCaretVisible(bool& visibleOut);

			int32_t SetCaretColor(math::v4 const& color);
			int32_t GetCaretColor(math::v4& colorOut);

			int32_t SetSelectionColor(math::v4 const& color);
			int32_t GetSelectionColor(math::v4& colorOut);

			int32_t Invalidate();

			int32_t SetSelectionMode(bool mode);
			int32_t GetSelectionMode(bool& modeOut);

			int32_t StartAutoScroll(ScrollType type);
			int32_t StopAutoScroll();

			int32_t SetStyle(uint32_t sce_paf_index, uint32_t len, graph::TextStyle const& style);
			int32_t GetStyle(uint32_t sce_paf_index, graph::TextStyle& styleOut);

			int32_t SetAttributedString(graph::AttributedString const& attrStr);
			int32_t GetAttributedString(graph::AttributedString& attrStrOut);

			int32_t GetBounds(math::v2& boundsOut);

			int32_t GetLineCount(uint32_t& countOut);

			int32_t GetCharInfo(uint32_t sce_paf_index, graph::TextLayoutCharInfo& charInfoOut);
			int32_t GetLineInfo(uint32_t line, graph::TextLayoutLineInfo& lineInfoOut);

			int32_t GetNextUpHit(uint32_t sce_paf_index, uint32_t& nextIndexOut);
			int32_t GetNextDownHit(uint32_t sce_paf_index, uint32_t& nextIndexOut);
			int32_t GetNextLeftHit(uint32_t sce_paf_index, uint32_t& nextIndexOut);
			int32_t GetNextRightHit(uint32_t sce_paf_index, uint32_t& nextIndexOut);

			int32_t GetCaretIndex(uint32_t& indexOut);

			int32_t GetSelectionRange(uint32_t& indexOut, uint32_t& lenOut);

			int32_t CreatePlaneObj();

		protected: //0x2D8

			int32_t BeginTouch(math::v2& pos);

			int32_t EndTouch();

			graph::PlaneObj *m_pPlaneObj;
			graph::TextObj *m_pTextObj;
			char m_unk_284[0x54];

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_TEXT_H */