/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_BOX_H
#define _VDSUITE_USER_PAF_WIDGET_W_BOX_H

#include <paf/widget/factory.h>
#include <paf/widget/w_plane.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factoryBox;

namespace paf {

	namespace ui {

		class Box : public Plane
		{
		public:

			enum LayoutType
			{
				MIN_LAYOUT_TYPE = 0,
				LAYOUT_MANUAL = 0,
				LAYOUT_VERTICAL = 1,
				LAYOUT_HORIZONTAL = 2,
				NUM_LAYOUT_TYPES = 3,
				MAX_LAYOUT_TYPE = 2
			};

			enum ChildrenAdjust
			{
				CHILDREN_ADJUST_NONE = 0,
				MIN_CHILDREN_ADJUST = 0,
				CHILDREN_ADJUST_CONTENT_MAX = 1,
				CHILDREN_ADJUST_FIXED = 2,
				CHILDREN_ADJUST_FIT = 3,
				CHILDREN_ADJUST_MAX = 4,
				MAX_CHILDREN_ADJUST = 4,
				NUM_CHILDREN_ADJUST = 5
			};

			enum SpaceAdjust
			{
				MIN_SPACE_ADJUST = 0,
				SPACE_ADJUST_NONE = 0,
				MAX_SPACE_ADJUST = 1,
				SPACE_ADJUST_FIT = 1,
				NUM_SPACE_ADJUST = 2
			};

			enum ChildrenAdjustState
			{
				CHILDREN_ADJUST_INIT = 0,
				CHILDREN_ADJUST_WAIT = 1,
				CHILDREN_ADJUST_SET = 2,
				CHILDREN_ADJUST_DONE = 3
			};

			class LayoutVars
			{
			public:

				math::v4 min_size;
				math::v4 max_size;
				SpaceAdjust space_adjust;
				float space;
				float top_margin;
				float bottom_margin;
				float left_margin;
				float right_margin;
				uint32_t children_align_x;
				uint32_t children_align_y;
				bool boundary_mode_x;
				bool boundary_mode_y;
				int32_t padding;
			};

			static const char *TypeName();

			Box(Widget *_parent, CreateParam *_param);

			virtual ~Box();

			void SetLayoutType(LayoutType layout_type);

			float GetFitSize(uint32_t align, float pos, float box_size, float box_origin_offset, float margin1_size, float margin2_size);

			void AdjustChildSize(Widget *w, math::v4 const& max_child_size, math::v4 const& total_child_size, uint32_t num_children, uint32_t num_fit_children_x, uint32_t num_fit_children_y, ChildrenAdjust children_adjust_x, ChildrenAdjust children_adjust_y);

			ChildrenAdjustState GetNextAdjustChildrenState(bool after_children_onupdate, ChildrenAdjustState state, ChildrenAdjust mode);

			void AdjustChildrenSize(bool after_children_onupdate);

			void UpdateLayoutSizePre(bool only_for_adjust_none);
			void UpdateLayoutSizePost(math::v4 const& boundary_size);

			math::v4 GetChildrenInfo();

			void UpdateBoxSize();

			void SetChildrenAdjustX(ChildrenAdjust mode, float width);
			void SetChildrenAdjustY(ChildrenAdjust mode, float height);

			void SetLayoutVars(LayoutVars const& layout_vars);

			void SetChildPos(Widget *w, math::v4 pos);

			void AddToExclusiveList(Widget *w);
			void DeleteFromExclusiveList(Widget *w);

			void GetChildrenAdjustX(ChildrenAdjust *mode, float *width) const
			{
				if (mode != NULL)
				{
					*mode = m_children_adjust_x;
				}
				if (width != NULL)
				{
					*width = m_children_width;
				}
			}

			void GetChildrenAdjustY(ChildrenAdjust *mode, float *height) const
			{
				if (mode != NULL)
				{
					*mode = m_children_adjust_y;
				}
				if (height != NULL)
				{
					*height = m_children_height;
				}
			}

			LayoutType GetLayoutType() const
			{
				return m_layout_type;
			}

			const LayoutVars& GetLayoutVars() const
			{
				return m_layout_vars;
			}

			void GetBoundary(math::v4 *size, math::v4 *offs) const;

		protected: //0x320

			char m_unk_280[0x44];
			ChildrenAdjust m_children_adjust_x;
			ChildrenAdjust m_children_adjust_y;
			float m_children_width;
			float m_children_height;
			LayoutType m_layout_type;
			LayoutVars m_layout_vars;
			int m_unk_31C;

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];

		private:

			float calc_offset(uint32_t orign, float layout_size, float boundary_size);

			uint32_t anchor_to_orign(uint32_t anchor);
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_BOX_H */