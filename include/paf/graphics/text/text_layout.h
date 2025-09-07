/*
	ScePaf-RE Project
*/

#ifndef _PAF_GRAPHICS_TEXT_TEXT_LAYOUT_H
#define _PAF_GRAPHICS_TEXT_TEXT_LAYOUT_H

#include <paf/math/math.h>

namespace paf {
	namespace graph {
		
		enum TextLayoutAttribute : int32_t
		{
			TextLayoutAttribute_AlignX = 0,
			TextLayoutAttribute_AlignY = 1,
			TextLayoutAttribute_TextAlign = 2,
			TextLayoutAttribute_LineSpace = 3,
			TextLayoutAttribute_LinePitch = 4,
			TextLayoutAttribute_Size = 5,
			TextLayoutAttribute_VisiblePos = 6,
			TextLayoutAttribute_VisibleSize = 7,
			TextLayoutAttribute_AdjustX = 8,
			TextLayoutAttribute_AdjustY = 9,
			TextLayoutAttribute_CondenseX = 10,
			TextLayoutAttribute_CondenseY = 11,
			TextLayoutAttribute_WordWrap = 12,
			TextLayoutAttribute_Kinsoku = 13,
			TextLayoutAttribute_Ellipsis = 14,
			TextLayoutAttribute_CharPrimitive = 15,
			TextLayoutAttribute_LayoutOnly = 16
		};

		enum TextLayoutAlignX : int32_t
		{
			TextLayoutAlignX_Left = 0,
			TextLayoutAlignX_Center = 1,
			TextLayoutAlignX_Right = 2
		};

		enum TextLayoutAlignY : int32_t
		{
			TextLayoutAlignY_Top = 0,
			TextLayoutAlignY_Center = 1,
			TextLayoutAlignY_Bottom = 2
		};

		enum TextLayoutState : int32_t
		{
			TextLayoutState_None = 0,
			TextLayoutState_InvalidLayout = 1,
			TextLayoutState_InvalidGeometry = 2,
			TextLayoutState_InvalidGraphics = 4,
			TextLayoutState_Invalid = 7,
			TextLayoutState_UpdatingLayout = 16,
			TextLayoutState_UpdatingGeometry = 32,
			TextLayoutState_UpdatingGraphics = 64,
			TextLayoutState_Updating = 112,
			TextLayoutState_Queuing = 256,
			TextLayoutState_Waiting = 512,
			TextLayoutState_Abort = 1024
		};

		typedef enum TextLayoutTextAlign : int32_t
		{
			TextLayoutTextAlign_Left = 0,
			TextLayoutTextAlign_Center = 1,
			TextLayoutTextAlign_Right = 2
		} TextLayoutTextAlign;

		class TextLayoutCharInfo
		{
		public:

			TextLayoutCharInfo()
			{

			}

			virtual ~TextLayoutCharInfo()
			{

			}

			float x;
			uint32_t line;
		};

		class TextLayoutLineInfo
		{
		public:

			TextLayoutLineInfo()
			{

			}

			virtual ~TextLayoutLineInfo()
			{

			}

			math::v4 frame;
			float ascender;
			uint32_t sce_paf_index;
			uint32_t len;
		};
	}
}

#endif /* _PAF_GRAPHICS_TEXT_TEXT_LAYOUT_H */
