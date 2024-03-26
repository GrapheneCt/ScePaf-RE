/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_TEXT_OBJ_H
#define _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_TEXT_OBJ_H

#include <stdint.h>
#include <stddef.h>
#include <paf/std/string>
#include <paf/graphics/drawobj/draw_obj.h>
#include <paf/math/math.h>
#include <paf/graphics/surface/surface.h>
#include <paf/graphics/text/text_layout.h>
#include <paf/graphics/text/text_style.h>
#include <paf/graphics/text/attributed_string.h>

namespace paf {
	namespace graph {

		class TextObj : public DrawObj
		{
		public:

			static void DrawCallback(DrawCallbackArg const& arg);

			static const char *DrawObjType();

			TextObj(DrawStyle const& _style);

			virtual bool IsInherit(char const *type) const;
			virtual char *GetDrawObjType() const;
			virtual ~TextObj();
			virtual int32_t unkFun_10();
			virtual int32_t unkFun_14();
			virtual int32_t ReleaseAll();
			virtual int32_t unkFun_1C();
			virtual void SetTexture(intrusive_ptr<Surface> const& texture, uint32_t sce_paf_index = 0);
			virtual void GetTexture(intrusive_ptr<Surface>& texture, uint32_t sce_paf_index = 0);
			virtual void SetPos(paf::math::v3 pos);
			virtual void SetSize(paf::math::v3 size);
			virtual void SetColor(paf::math::v4 color);
			virtual void SetRot(paf::math::v3 rot);
			virtual void Update();
			virtual void UpdatePost(math::matrix const& world_mat);
			virtual int32_t unkFun_40();
			virtual int32_t unkFun_44();

			int32_t SetLayoutAttribute(TextLayoutAttribute attr, int32_t val);

			int32_t SetLayoutAttribute(TextLayoutAttribute attr, float val);

			int32_t SetLayoutAttribute(TextLayoutAttribute attr, math::v2 const& val);

			int32_t SetLayoutAttribute(TextLayoutAttribute attr, bool val);

			int32_t GetLayoutAttribute(TextLayoutAttribute attr, int32_t& valOut);

			int32_t GetLayoutAttribute(TextLayoutAttribute attr, float& valOut);

			int32_t GetLayoutAttribute(TextLayoutAttribute attr, math::v2& valOut);

			int32_t GetLayoutAttribute(TextLayoutAttribute attr, bool& valOut);

			int32_t SetSelectionPos(math::v2 const& startPos, math::v2 const& endPos);

			int32_t SetCaretIndex(uint32_t sce_paf_index);

			int32_t GetCaretIndex(uint32_t& indexOut);

			int32_t SetSelectionRange(uint32_t sce_paf_index, uint32_t len);

			int32_t GetSelectionRange(uint32_t& indexOut, uint32_t& lenOut);

			int32_t SetCaretVisible(bool visible);

			int32_t GetCaretVisible(bool& visibleOut);

			int32_t SetCaretColor(math::v4 const& color);

			int32_t GetCaretColor(math::v4& colorOut);

			int32_t SetSelectionColor(math::v4 const& color);

			int32_t GetSelectionColor(math::v4& v4colorOut);

			int32_t Invalidate();

			int32_t SetStyleAttribute(TextStyleAttribute attr, uint32_t sce_paf_index, uint32_t len, int32_t val);

			int32_t SetStyleAttribute(TextStyleAttribute attr, uint32_t sce_paf_index, uint32_t len, float val);

			int32_t SetStyleAttribute(TextStyleAttribute attr, uint32_t sce_paf_index, uint32_t len, math::v4 const& val);

			int32_t SetStyleAttribute(TextStyleAttribute attr, uint32_t sce_paf_index, uint32_t len, bool val);

			int32_t GetStyleAttribute(TextStyleAttribute attr, uint32_t sce_paf_index, int32_t& valOut);

			int32_t GetStyleAttribute(TextStyleAttribute attr, uint32_t sce_paf_index, float& valOut);

			int32_t GetStyleAttribute(TextStyleAttribute attr, uint32_t sce_paf_index, math::v4& valOut);

			int32_t GetStyleAttribute(TextStyleAttribute attr, uint32_t sce_paf_index, bool& valOut);

			int32_t SetStyle(uint32_t sce_paf_index, uint32_t len, TextStyle const& style);

			int32_t GetStyle(uint32_t sce_paf_index, TextStyle& styleOut);

			int32_t SetString(wstring const& str);

			int32_t GetString(wstring& strOut);

			int32_t GetStringBuffer(wchar_t const*& pBufOut, uint32_t& lenOut);

			int32_t SetPlaceholderString(wstring const& str);

			int32_t GetPlaceholderString(wstring& strOut);

			int32_t GetLength(uint32_t& lenOut);

			int32_t SetAttributedString(AttributedString const& attrStr);

			int32_t GetAttributedString(AttributedString& attrStrOut);

			int32_t GetBounds(math::v2& boundsOut);

			int32_t GetLineCount(uint32_t& countOut);

			int32_t SetCharPos(uint32_t sce_paf_index, math::v2 const& pos);

			int32_t GetCharInfo(uint32_t sce_paf_index, TextLayoutCharInfo& charInfoOut);

			int32_t GetLineInfo(uint32_t line, TextLayoutLineInfo& lineInfoOut);

			int32_t GetNextUpHit(uint32_t sce_paf_index, uint32_t& nextIndexOut);

			int32_t GetNextDownHit(uint32_t sce_paf_index, uint32_t& nextIndexOut);

			int32_t GetNextLeftHit(uint32_t sce_paf_index, uint32_t& nextIndexOut);

			int32_t GetNextRightHit(uint32_t sce_paf_index, uint32_t& nextIndexOut);

			int32_t MoveCaretUp();

			int32_t MoveCaretDown();

			int32_t MoveCaretLeft();

			int32_t MoveCaretRight();

			int32_t SetCaretPos(math::v2 const& pos);

		protected:

			int32_t unk_50;
			int32_t unk_54;

			__declspec(dllimport) static const char m_drawobj_type[];
		};

		class TextObjParam : public DrawObjParam
		{
		public:

			virtual const char *GetParamName(void) const;

			TextObjParam();
			virtual ~TextObjParam();

			virtual int Create(int mode);
			virtual int SetEach(DrawObj *);
			virtual int GetEach(DrawObj *);

			const char *ParamName(void);

		private:

			unsigned char m_unk_0x50[0xB8];

			__declspec(dllimport) static const char m_param_name[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_TEXT_OBJ_H */
