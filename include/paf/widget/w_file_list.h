/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_FILE_LIST_H
#define _VDSUITE_USER_PAF_WIDGET_W_FILE_LIST_H

#include <paf/widget/factory.h>
#include <paf/widget/w_list_view.h>
#include <paf/common/ref_obj.h>

SCE_PAF_IMPORTED_FROM_PRX extern paf::ui::FactoryFuncTable g_factoryFileList;

namespace paf {

	namespace job {

		class JobQueue;
	}
	
	namespace ui {

		namespace filelist {

			class CellFocusParam;
			class CellListAccessor;
			class SegmentListAccessor;
			class CellSource;
			class SegmentSource;
			class Visualizer;
		}

		class FileList : public ListView
		{
		public:

			static const char *TypeName();

			FileList(Widget *_parent, CreateParam *_param);

			virtual ~FileList();

			virtual int32_t unkFun_290();

			ListItem *CreateItem(listview::ItemFactory::CreateParam& param);
			void StartItem(listview::ItemFactory::StartParam& param);
			void StopItem(listview::ItemFactory::StopParam& param);
			void DisposeItem(listview::ItemFactory::DisposeParam& param);

			void SetSegmentSource(intrusive_ptr<filelist::SegmentSource> segment_source);

			int64_t GetSegmentID(int32_t segment_index);

			intrusive_ptr<filelist::CellSource> GetCellSource(int32_t segment_index);

		protected: //0x4E8

			SCE_PAF_IMPORTED_FROM_PRX static const char m_widget_type[];
		};

		namespace filelist {

			class VisualizerBindParam
			{
			public:

				int32_t m_index;
				int64_t m_id;
				Widget *m_parent;
			};

			class IDPair
			{
			public:

				IDPair(int64_t id, int32_t sce_paf_index) : m_id(id), m_index(sce_paf_index)
				{

				}

				int64_t m_id;
				int32_t m_index;
			};

			class CellFocusParam
			{
			public:

				void Apply(FileList *file_list);

				void Set(int32_t segment_index, int32_t cell_index, ListView::FocusAlignType align_type, Timer *timer);

			private:

				int32_t m_segment_index;
				int32_t m_cell_index;
				ListView::FocusAlignType m_align_type;
				Timer *m_timer;
			};

			namespace Manager {

				class InitParam
				{
				public:

					string m_storage_path;
				};

				enum QueueType
				{
					Queue_Fast = 0,
					Queue_Normal = 1,
					Queue_Slow = 2,
					Queue_Long = 3,
					Queue_MAX = 4
				};

				typedef void(*TaskFunction)(void *userdata);

				extern ListItem *PopCacheItem(uint32_t type, Widget *parent);

				extern void PushCacheItem(uint32_t type, ListItem *list_item);

				extern void Initialize(InitParam const& param);

				extern void Finalize();

				extern job::JobQueue *GetJobQueue(QueueType type);

				extern string *GetStoragePath();

				extern void PostTask(QueueType type, const char *name, TaskFunction func, void *userdata);
			}

			class CellSource : public paf::common::RefObj
			{
			public:

				static const char *TypeName();

				virtual ~CellSource()
				{

				}

				virtual bool IsInherit(char const *type) const;
				virtual char *GetTypeName() const;
				virtual bool IsDirty();
				virtual void Update(CellListAccessor& accessor);
				virtual int64_t GetID(int32_t sce_paf_index);
				virtual void GetVisualizer(VisualizerBindParam& param);
				virtual math::v4 GetVisualSize();
				virtual bool IsDraggable();
				virtual void OnMoved(int32_t from_index, int32_t to_index);
				virtual void OnDragStart(int32_t sce_paf_index);
				virtual void OnDragStop(int32_t sce_paf_index);
				virtual void OnUpdated();

			protected:

				SCE_PAF_IMPORTED_FROM_PRX static const char m_type_name[];
			};

			class SegmentSource : public paf::common::RefObj
			{
			public:

				static const char *TypeName();

				virtual ~SegmentSource()
				{

				}

				virtual bool IsInherit(char const *type) const;
				virtual char *GetTypeName() const;
				virtual bool IsDirty();
				virtual void Update(SegmentListAccessor& accessor);
				virtual int64_t GetID(int32_t sce_paf_index);
				virtual intrusive_ptr<CellSource> GetCellSource(int32_t sce_paf_index, int64_t id);
				virtual void OnUpdated();

			protected:

				SCE_PAF_IMPORTED_FROM_PRX static const char m_type_name[];
			};

			class CellListAccessor
			{
			public:

				CellListAccessor(FileList *file_list, int32_t segment_index, CellFocusParam *focus_param);

				virtual ~CellListAccessor()
				{

				}

				virtual void Insert(int32_t sce_paf_index, size_t num);
				virtual void Delete(int32_t sce_paf_index, size_t num);
				virtual size_t GetNum();
				virtual void GetExists(vector<IDPair>& list);
				virtual int32_t unkFun_18();
				virtual void SetFocus(int32_t sce_paf_index, ListView::FocusAlignType align_type, Timer *timer);

			protected:

				FileList *m_file_list;
				int32_t m_segment_index;
				CellFocusParam *m_focus_param;
			};

			class SegmentListAccessor
			{
			public:

				class OptionParam
				{
				public:

					ListView::LayoutType m_layout_type;
					Widget *m_header;
					bool m_header_floating;
					bool m_header_disappearance;
				};

				SegmentListAccessor(FileList *file_list);

				virtual ~SegmentListAccessor()
				{

				}

				virtual void Insert(int32_t sce_paf_index, size_t num);
				virtual void Delete(int32_t sce_paf_index, size_t num);
				virtual size_t GetNum();
				virtual void GetExists(vector<IDPair>& list);
				virtual void SetOption(int32_t sce_paf_index, OptionParam& param);

			protected:

				FileList *m_file_list;
			};

			class Visualizer : public paf::common::RefObj
			{
			public:

				static const char *TypeName();

				virtual ~Visualizer()
				{

				}

				virtual bool IsInherit(char const *type) const;
				virtual char *GetTypeName() const;
				virtual void Start();
				virtual void Stop();
				virtual ListItem *GetListItem();

			protected:

				SCE_PAF_IMPORTED_FROM_PRX static const char m_type_name[];
			};

			extern int64_t GetCellID(ListItem *list_item);

			extern intrusive_ptr<Visualizer> GetVisualizer(ListItem *list_item);
		}
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_FILE_LIST_H */