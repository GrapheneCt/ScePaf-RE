/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_TEXT_ATTRIBUTED_STRING_H
#define _VDSUITE_USER_PAF_GRAPHICS_TEXT_ATTRIBUTED_STRING_H

#include <paf/std/stdcxx.h>
#include <paf/math/math.h>
#include <paf/graphics/text/text_style.h>

namespace paf {
	namespace graph {
		
		class TextStyleRun
		{
		public:

			TextStyleRun() : len(0)
			{

			}

			virtual ~TextStyleRun()
			{

			}

		private:

			int32_t unk_04;
			TextStyle style;
			uint32_t len;
			int32_t reserved;
		};

		class AttributedString
		{
		public:

			AttributedString();

			AttributedString(TextStyle const& style);

			AttributedString(AttributedString const& attrStr);

			virtual ~AttributedString();

			int32_t GetLength(uint32_t& lenOut);

			int32_t GetStringBuffer(wchar_t const*& pBufOut, uint32_t& lenOut);

			//void ClearStyleRuns();

			AttributedString& operator=(AttributedString const& attrStr);

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

		private:

			wstring m_str;
			list<TextStyleRun*> m_styleRuns;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_TEXT_ATTRIBUTED_STRING_H */
