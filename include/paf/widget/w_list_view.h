/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_LIST_VIEW_H
#define _VDSUITE_USER_PAF_WIDGET_W_LIST_VIEW_H

#include <paf/widget/factory.h>
#include <paf/widget/w_scroll_view_base.h>
#include <paf/common/shared_ptr.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factoryListView;

namespace paf {
	
	namespace ui {

		class ListItem;

		namespace common {
			namespace property_list {

				class PropertyList;
			}
		}

		namespace listview {

			class Cell;
			class CellList;
			class Segment;
			class SegmentList;
			class CoordinateEffector;
			class ItemFactory;

			class ListPos
			{
			public:

				int32_t m_segment_index;
				int32_t m_cell_index;
			};
		}

		class ListViewStyleParam : public ScrollViewBaseStyleParam
		{
		public:
			static const char *ParamName();
			ListViewStyleParam();
			virtual const char *GetParamName() const;
			virtual ~ListViewStyleParam();
			virtual int32_t Create(int32_t mode);

			virtual int32_t SetEach(Widget *widget);
			virtual int32_t GetEach(Widget *widget);

		private:
			unsigned char unk_0x0x168[0x18];

			SCE_PAF_IMPORTED_FROM_PRX static const char m_param_name[];
		};

		class ListView : public ScrollViewBase
		{
		public:

			enum
			{
				CB_LIST_VIEW_BEGIN = 0x10000005,
				CB_LIST_VIEW_CELL_MOVED = 0x10000006,
				CB_LIST_VIEW_DRAG_START = 0x10000007,
				CB_LIST_VIEW_DRAG_STOP = 0x10000008,
				CB_LIST_VIEW_END = 0x10000009
			};

			enum LayoutType
			{
				LAYOUT_TYPE_LIST = 0,
				LAYOUT_TYPE_GRID = 1,
				LAYOUT_TYPE_LIST_VARIABLE = 2
			};

			enum ScrollType
			{
				SCROLL_TYPE_VERTICAL = 0,
				SCROLL_TYPE_HORIZONTAL = 1
			};

			enum FocusAlignType
			{
				FOCUS_ALIGN_TYPE_HEAD = 0,
				FOCUS_ALIGN_TYPE_CENTER = 1,
				FOCUS_ALIGN_TYPE_TAIL = 2
			};

			static const char *TypeName();

			ListView(Widget *_parent, CreateParam *_param);

			virtual ~ListView();

			virtual void BeginDrag(int32_t segment_index, int32_t cell_index, int32_t touch_id);
			virtual void EndDrag(int32_t touch_id);
			virtual void SetFocus(int32_t segment_index, int32_t cell_index, FocusAlignType align_type, Timer *timer);
			virtual int32_t unkFun_278();
			virtual void OnCellUnGrab(listview::Cell *cell);
			virtual void OnCellDragMove(listview::Cell *cell);
			virtual void OnCellMoved(int32_t segment_index, int32_t from_index, int32_t to_index);
			virtual void OnCellDragStart(int32_t segment_index, int32_t cell_index);
			virtual void OnCellDragStop(int32_t segment_index, int32_t cell_index);

			math::v2 GetGenerateRange(math::v2 const& visible_range);

			listview::CoordinateEffector *GetCoordinateEffector();

			void BlockSync();
			void UnblockSync();
			void SyncViewSize();
			void Sync();
			void Rebuild();
			void Clear();

			void SetSegmentHeader(int32_t segment_index, Widget *header, bool floating, bool disappearance);
			Widget *GetSegmentHeader(int32_t segment_index);

			void SetItemFactory(listview::ItemFactory *item_factory);

			ListItem* GetListItem(int32_t segment_index, int32_t cell_index);

			int32_t GetGeneratedNum();

			listview::ListPos GetGeneratedPos(int32_t generated_index);

			common::property_list::PropertyList *GetSegmentPropertyList(int32_t segment_index);

			math::v4 GetFocusedViewPos();

			void FocusRect(math::v4 const& rect, Timer *timer);

			void SetScrollType(ScrollType scroll_type);

			void SetGenerateMargin(math::v2 const& margin);

			void InsertCell(int32_t segment_index, int32_t cell_index, size_t num);
			void DeleteCell(int32_t segment_index, int32_t cell_index, size_t num);
			void MoveCell(int32_t segment_index, int32_t from_index, int32_t to_index);
			size_t GetCellNum(int32_t segment_index);

			void InsertSegment(int32_t segment_index, size_t num);
			void DeleteSegment(int32_t segment_index, size_t num);

			size_t GetSegmentNum();

			void SetCellSizeDefault(int32_t segment_index, math::v4 const& size);
			math::v4 GetCellSizeDefault(int32_t segment_index);

			void SetCellSize(int32_t segment_index, int32_t cell_index, math::v4 const& size);
			math::v4 GetCellSize(int32_t segment_index, int32_t cell_index);

			void FreeCellPosition(int32_t segment_index, int32_t cell_index, bool onoff);

			void SetSegmentLayoutType(int32_t segment_index, LayoutType layout_type);
			LayoutType GetSegmentLayoutType(int32_t segment_index);

		protected: //0x4E8

			ScrollType m_scroll_type;
			math::v2 m_generate_margin;
			char m_unk_40C[0x14];
			int32_t m_block_count;
			char m_unk_424[0xC4];

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};

		namespace listview {

			class SyncParam
			{
			public:

				math::v2 generate_range;
				math::v2 visible_range;
				CoordinateEffector *effector;
			};

			class CellList
			{
			public:

				CellList(Segment *segment);

				~CellList()
				{

				}

				void LowerBound(int32_t sce_paf_index);

				Cell *CreateCell(int32_t sce_paf_index);

				Cell *GetLast();

				void Sort();

				void Find(int32_t sce_paf_index);

				Cell *GetCell(int32_t sce_paf_index);

			private:

				vector<paf::common::SharedPtr<Cell>> m_list;
				Segment *m_segment;
			};

			class CellMap : public vector<Cell*>
			{
			public:

				CellMap(ListView *list_view);

				~CellMap()
				{

				}

				void Erase(Cell *cell);

				void Find(Cell *cell);

				Cell *Find(int32_t segment_index, int32_t cell_index);

				Cell *Find(ListItem *list_item);

				void Insert(Cell *cell);

				void LowerBound(Cell *cell);

				void Sort();

			private:

				ListView *m_list_view;
			};

			class SegmentList : public vector<paf::common::SharedPtr<Segment>>
			{
			public:

				SegmentList(ListView *list_view);

				~SegmentList()
				{

				}

				Segment *GetSegment(int32_t sce_paf_index);

				void InsertSegment(int32_t sce_paf_index, size_t num);
				void DeleteSegment(int32_t sce_paf_index, size_t num);

			private:

				ListView *m_list_view;
			};

			class Segment
			{
			public:

				Segment(SegmentList *segment_list, int32_t sce_paf_index);

				~Segment();

				void SetHeaderPos(float head_pos, CoordinateEffector const& effector);

				math::v4 GetHeaderSize();

				void SetHeaderVisible(bool visible);

				void ResetHeaderPosition(math::v2 const& range, CoordinateEffector const& effector);

				void ResetCellPosition(CoordinateEffector const& effector);

				void GenerateCell(int32_t first, int32_t last);

				void GetGenerationIndex(int32_t& first, int32_t& last, math::v2 const& range);

				void Sync(SyncParam const& param);

				math::v4 GetCellSize(int32_t sce_paf_index);

				void UpdateViewSize();

				void DestroyCell(int32_t sce_paf_index, size_t num);

				int32_t GetCellIndex(math::v2 const& pos);

				int32_t GetDropIndex(math::v2 const& pos);

				void InsertCell(int32_t sce_paf_index, size_t num);

				void DeleteCell(int32_t sce_paf_index, size_t num);

				bool MoveCell(int32_t from, int32_t& to);

				bool SetCellSize(int32_t sce_paf_index, math::v4 const& size);

				bool SetLayoutType(ListView::LayoutType layout_type);

			private:

				char m_unk_00[0xB8];
			};

			class Cell
			{
			public:

				Cell(CellList *cell_list, int32_t sce_paf_index);

				void EndDrag(int32_t touch_id);

				Segment *GetSegment();

				void UpdateDragRange();

				int32_t GetSegmentIndex();

				void ResetPos(bool with_anim);

				ListView *GetListView();

				void SetPos(math::v2 const& pos, bool with_anim);

				math::v2 GetPos(bool current);

				bool BeginDrag(int32_t touch_id);

				math::v4 GetRect(bool current);

				void FreeCellPosition(bool onoff);

			private:

				char m_unk_00[0x30];
			};

			class ItemFactory
			{
			public:

				class CreateParam
				{
				public:

					ListView *list_view;
					int32_t segment_index;
					int32_t cell_index;
					Widget *parent;
				};

				class StartParam
				{
				public:

					ListView *list_view;
					int32_t segment_index;
					int32_t cell_index;
					ListItem *list_item;
				};

				class StopParam
				{
				public:

					ListView *list_view;
					int32_t segment_index;
					int32_t cell_index;
					ListItem *list_item;
				};

				class DisposeParam
				{
				public:

					ListView *list_view;
					int32_t segment_index;
					int32_t cell_index;
					ListItem *list_item;
				};

				ItemFactory()
				{

				}

				virtual ~ItemFactory();

				virtual ListItem* Create(CreateParam& param);
				virtual void Start(StartParam& param);
				virtual void Stop(StopParam& param);
				virtual void Dispose(DisposeParam& param);
			};
		}
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_LIST_VIEW_H */