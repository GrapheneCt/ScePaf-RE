/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_TEXT_TEXT_STYLE_H
#define _VDSUITE_USER_PAF_GRAPHICS_TEXT_TEXT_STYLE_H

#include <stdint.h>
#include <paf/math/math.h>

namespace paf {
	namespace graph {
		
		enum FontFamily
		{
			FontFamily_0,
			FontFamily_1,
			FontFamily_2,
			FontFamily_3,
			FontFamily_4,
			FontFamily_5,
			FontFamily_6,
			FontFamily_7,
			FontFamily_8,
			FontFamily_9
		};

		enum TextStyleAttribute
		{
			TextStyleAttribute_Family = 0,
			TextStyleAttribute_Point = 1,
			TextStyleAttribute_Color = 2,
			TextStyleAttribute_BackColor = 3,
			TextStyleAttribute_UnkColor0 = 4,
			TextStyleAttribute_UnkColor1 = 5,
			TextStyleAttribute_UnkColor2 = 6,
			TextStyleAttribute_Bold = 7,
			TextStyleAttribute_Oblique = 8,
			TextStyleAttribute_Underline = 9,
			TextStyleAttribute_Strike = 10,
			TextStyleAttribute_Mask = 11
		};

		class TextStyle
		{
		public:

			TextStyle();

			TextStyle(TextStyle const& style);

			virtual ~TextStyle();

			TextStyle& operator=(TextStyle const& style);

			bool operator==(TextStyle const& style);

			bool operator!=(TextStyle const& style);

			bool EqualFontStyle(TextStyle const& style);

			bool EqualFontType(TextStyle const& style);

			int32_t SetStyleAttribute(TextStyleAttribute attr, int32_t val);

			int32_t SetStyleAttribute(TextStyleAttribute attr, float val);

			int32_t SetStyleAttribute(TextStyleAttribute attr, math::v4 const& val);

			int32_t SetStyleAttribute(TextStyleAttribute attr, bool val);

			int32_t GetStyleAttribute(TextStyleAttribute attr, int32_t& valOut) const;

			int32_t GetStyleAttribute(TextStyleAttribute attr, float& valOut) const;

			int32_t GetStyleAttribute(TextStyleAttribute attr, math::v4& valOut) const;

			int32_t GetStyleAttribute(TextStyleAttribute attr, bool& valOut) const;

		protected:

			int8_t m_family;
			int16_t m_flag;
			math::v2 m_point;
			uint32_t m_color;
			uint32_t m_backColor;
			uint32_t m_unkColor0;
			uint32_t m_unkColor1;
			uint32_t m_unkColor2;
			int32_t reserved;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_TEXT_TEXT_STYLE_H */
