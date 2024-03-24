/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_PLUGIN_H
#define _VDSUITE_USER_PAF_PLUGIN_H

#include <stdint.h>
#include <stddef.h>
#include <paf/paf_types.h>
#include <paf/std/map>
#include <paf/std/list>
#include <paf/std/vector>
#include <paf/std/string>
#include <paf/common/shared_ptr.h>
#include <paf/cxml/cxml.h>
#include <paf/widget/core/event.h>
#include <paf/widget/core/layouter.h>
#include <paf/widget/factory.h>

namespace paf {

	class Module;
	class VersatileParamManager;
	class Plugin;

	namespace resource {

		class ResourceObj;
	}

	namespace memory {

		class HeapAllocator;
	}

	namespace graph {

		class SurfacePool;
		class DrawObj;
	}

	namespace ui {

		class EnvironmentParam;
		class Scene;
		class WidgetParam;
		class AnimListener;
		class WidgetLayoutParam;
		class WidgetStyleParam;
		class WidgetHandlerParam;
	}

	class DrawOrderElement
	{
	public:

		DrawOrderElement(ui::Scene *_page, int32_t _view_priority, int32_t _page_priority) : page(_page), view_priority(_view_priority), page_priority(_page_priority)
		{

		}

	private:

		ui::Scene *page;
		int32_t view_priority;
		int32_t page_priority;
	};

	class InitEventFunctionEntry2
	{
	public:

		IDParam id;
		ui::HandlerCB func;
		void *userdata;
	};

	class WidgetResourceInfo : public ui::Widget::UserData
	{
	public:

		class LayoutData
		{
		public:

			IDParam m_id;
			cxml::Element m_node;
			ui::WidgetLayoutParam *m_param;
		};

		Plugin *m_plugin;
		ui::WidgetParam *m_wparam;
		cxml::Element m_node;
		vector<LayoutData> m_list_layout;
		IDParam m_style_id;
	};

	class InitEventFunctionEntry
	{
	public:

		IDParam id;
	};

	class LayoutFunctionEntry;
	class EventFunctionEntry;

	class Plugin
	{
	public:

		enum Option //for InitParam::option
		{
			Option_None = 0,
			Option_AutoOpen = 1,
			Option_AutoActivate = 2,
			Option_RememberSurface = 4,
			Option_MakeSurfaceFirst = 8,
			Option_WaitWidgetActuallyDestroyed = 16,
			Option_ResourceLoadWithDebugSymbol = 32,
			Option_Default = 28
		};

		enum LoadUnloadOption
		{
			LoadUnloadOption_None = 0,
			LoadUnloadOption_DontLockInputDevice = 1,
			LoadUnloadOption_Default = 0,
		};

		enum ArgumentType
		{
			ArgumentType_Int = 0,
			ArgumentType_Float = 1,
			ArgumentType_String = 2,
		};

		enum TransitionType
		{
			TransitionType_None,
			TransitionType_SlideFromTop,	// maps to 0xE
			TransitionType_SlideFromBottom,	// maps to 0xF
			TransitionType_SlideFromLeft,	// maps to 0x10
			TransitionType_SlideFromRight,	// maps to 0x11
		};

		enum PageOption //for PageOpenParam::option
		{
			PageOption_None = 0,
			PageOption_Create = 1,
		};

		enum ResolutionDebugMode
		{
			ResolutionDebugMode_Off = 0,
			ResolutionDebugMode_Add2 = 1,
		};

		enum PageDebugMode
		{
			PageDebugMode_PageVisual = 0,
			PageDebugMode_PageVisualEdit = 1,
			PageDebugMode_PageHide = 2,
		};

		class InitParam2;

		typedef void(*SetParamFunction)(InitParam2 *);
		typedef void(*InitFunction)(Plugin *);
		typedef void(*StartFunction)(Plugin *);
		typedef void(*StopFunction)(Plugin *);
		typedef void(*ExitFunction)(Plugin *);

		typedef void(*PageOpenCallback)(Plugin *, cxml::Element *);
		typedef void(*PageActivateCallback)(Plugin *, cxml::Element *);
		typedef void(*PageCloseCallback)(Plugin *, cxml::Element *);

		typedef void(*NotifyCallback)(int32_t, void*);
		typedef void(*UnloadCallback)(void*);

		typedef void(*LoadFinishCallback)(Plugin *);
		typedef void(*UnloadFinishCallback)(const char *);

		class Argument
		{
		public:

			Argument(int32_t _i) : type(ArgumentType_Int), i(_i)
			{

			}

			Argument(float _f) : type(ArgumentType_Float), f(_f)
			{

			}

			Argument(string const& _str) : type(ArgumentType_String), str(_str)
			{

			}

			~Argument()
			{

			}

			operator float() const;

			operator int32_t() const;

			operator string() const;

		private:

			ArgumentType type;
			union
			{
				int32_t i;
				float f;
			};
			string str;
		};

		class AddTextureInfo
		{
		public:

			AddTextureInfo()
			{

			}

			~AddTextureInfo()
			{

			}

			char unk_00[32];
		};

		class InitParam2
		{
			int32_t draw_priority;
			uint32_t surface_pool_size;
			int32_t texture_load_filter;
			int32_t unk_0C;
		};

		class InitParam
		{
		public:

			InitParam();

			~InitParam()
			{

			};

			string name;
			string caller_name;
			SetParamFunction set_param_func;	//Called after plugin module is loaded and started
			InitFunction init_func;				//Called after plugin constructor has finished
			StartFunction start_func;			//Called after Plugin::Start() has finished
			StopFunction stop_func;				//Called after Plugin::Stop() has finished
			ExitFunction exit_func;				//Called after Plugin::Exit() has finished
			string resource_file;
			uint8_t *resource_data;
			uint32_t resource_data_size;
			Locale locale;
			uint32_t private_heap_size;
			memory::HeapAllocator *private_heap;
			uint32_t decode_heap_size;
			memory::HeapAllocator *decode_heap;
			graph::SurfacePool *surface_pool;
			int32_t draw_priority;
			map<string, Argument> arguments;
			paf::string module_file;
			int32_t module_interface_version;
			int32_t module_option;
			int32_t option;
			NotifyCallback *notify_callback;
			UnloadCallback *unload_callback;
			void *param;
			char unk_8C[0x08];
		};

		class PageOpenParam
		{
		public:

			PageOpenParam();

			~PageOpenParam()
			{

			};

			int32_t draw_layer;
			int32_t draw_mask;
			int32_t overwrite_draw_priority;
			int32_t option;
			InitEventFunctionEntry2 *event_handler_table;
			bool fade;
			float fade_time_ms;
			TransitionType transition_type;
			Timer *timer;
			ui::EnvironmentParam *env_param;
			int32_t graphics_flag;
		};

		class PageCloseParam
		{
		public:

			PageCloseParam();

			~PageCloseParam()
			{

			};

			bool fade;
			float fade_time_ms;
			TransitionType transition_type;
			Timer *timer;
		};

		class TemplateOpenParam
		{
		public:

			TemplateOpenParam();

			~TemplateOpenParam()
			{

			};

			InitEventFunctionEntry2 *event_handler_table;
			ui::Widget *sibling;
		};

		static void LoadAsync(InitParam const& init_param, LoadFinishCallback finish_callback = NULL, int32_t option = LoadUnloadOption_None);

		static void LoadSync(InitParam const& init_param, LoadFinishCallback finish_callback = NULL, int32_t option = LoadUnloadOption_None);

		static void UnloadAsync(Plugin *plugin, UnloadFinishCallback finish_callback = NULL, int32_t option = LoadUnloadOption_None);

		static void UnloadAsync(const char *name, UnloadFinishCallback finish_callback = NULL, int32_t option = LoadUnloadOption_None);

		static Plugin *Find(const char *name);

		static void SetLocaleAll(Locale _locale);

		void RegistFactoryTable(const char *name, ui::FactoryFuncTable handler);

		void RemoveFactoryTable(const char *name);

		void RegistFactoryDrawObj(const char *name, ui::FactoryFuncDrawObj handler);

		void RemoveFactoryDrawObj(const char *name);

		map<string, ui::FactoryFuncTable> *GetWFactoryTable();

		ui::Scene *PageOpen(cxml::Element const& node, PageOpenParam const& page_open_param);

		ui::Scene *PageOpen(IDParam const& id, PageOpenParam const& page_open_param);

		void PageClose(cxml::Element const& node, PageCloseParam const& page_close_param);

		void PageClose(IDParam const& id, PageCloseParam const& page_close_param);

		void PageCloseAll();

		void PageActivate(cxml::Element const& node);

		void PageActivate(IDParam const& id);

		void PageInactivate(cxml::Element const& node);

		void PageInactivate(IDParam const& id);

		void SetLocale(Locale _locale);

		ui::Widget *CallFactoryWidget(const char *name, ui::Widget *parent);

		ui::WidgetParam *CallFactoryWidgetParam(const char *name);

		ui::WidgetLayoutParam *CallFactoryLayout(const char *name);

		ui::WidgetStyleParam *CallFactoryStyle(const char *name);

		ui::WidgetHandlerParam *CallFactoryHandler(const char *name);

		graph::DrawObj *CallFactoryDrawObj(const char *name);

		graph::DrawObjParam *CallFactoryDrawObjParam(const char *name);

		void InstantiateWidget_EventHandler(cxml::Element const& node, ui::Widget *widget, const char *event_name, int32_t event_type);

		void InstantiateWidget_LayoutHandler(cxml::Element const& node, ui::Widget *widget, const char *layout_name);

		void InstantiateWidget_Texture(cxml::Element const& node, ui::Widget *widget, int32_t texno, const char *name, intrusive_ptr<graph::Surface> const& default_texture);

		void InstantiateWidget_Layout(cxml::Element const& node, ui::Widget *widget, WidgetResourceInfo *wri);

		void InstantiateWidget_HandlerAll(cxml::Element const& node, ui::Widget *widget);

		void InstantiateWidget_String(cxml::Element const& node, const char *str_name, ui::Widget *widget);

		void InstantiateWidget_InitEventHandler(IDParam const& id, ui::Widget *widget, InitEventFunctionEntry2 *event_handler_table);

		void SetInitEventHandler(const InitEventFunctionEntry *_event_handler_table);

		void SetEventHandler(const EventFunctionEntry *_event_handler_table);

		void SetLayoutHandler(const LayoutFunctionEntry *_layout_handler_table);

		void SetInterface(int32_t version, void *_interface);

		void AppendNotifyCallback(NotifyCallback notify_callback);

		void RemoveNotifyCallback(NotifyCallback notify_callback);

		void AppendUnloadCallback(UnloadCallback unload_callback);

		void RemoveUnloadCallback(UnloadCallback unload_callback);

		ui::Widget *CreateWidget(ui::Widget *parent, const char *widget_type, IDParam const& widget_name, IDParam const& style_id);

		ui::Widget *CreateWidgetWithStyleType(ui::Widget *parent, const char *widget_type, IDParam const& widget_name, const char *style_type, IDParam const& style_id);

		int32_t CreateStyle(const char *widget_type, IDParam const& id);

		int32_t TemplateOpen(ui::Widget *parent, IDParam const& template_id, TemplateOpenParam const& template_open_param);

		int32_t MorphWidgetLayout(ui::Widget *widget, uint32_t sce_paf_index, Timer *timer);

		int32_t MorphWidgetLayout(ui::Widget *widget, IDParam const& id, Timer *timer);

		int32_t MorphWidgetLayout(ui::Widget *widget, cxml::Element const& node, Timer *timer);

		int32_t SetPageDebugMode(IDParam const& id, PageDebugMode mode, bool on);

		int32_t WriteResourceAll(common::SharedPtr<File> xmlfp);

		int32_t WriteResourcePageTable(common::SharedPtr<File> xmlfp, bool write_table);

		int32_t WriteResourceStyleTable(common::SharedPtr<File> xmlfp, bool write_table);

		int32_t WriteResourceTextureTable(common::SharedPtr<File> xmlfp, bool write_table);

		int32_t GetResourcePages(vector<string> *pageIds);

		int32_t GetOpenedPages(vector<string> *pageIds);

		int32_t GetResourceStyles(const char *widget_type, vector<string> *styleIds);

		int32_t GetResourceTextures(vector<string> *textureIds);

		bool IsRegisteredID(IDParam const& id);

		int32_t AddResourceTexture(IDParam const& id, const char *path, const char *src);

		intrusive_ptr<graph::Surface> GetTexture(IDParam const& id);

		intrusive_ptr<graph::Surface> GetTexture(cxml::Element const& node);

		int32_t GetSound(IDParam const& id, void **addr1, uint32_t *size1, void **addr2, uint32_t *size2, int32_t *samplerate, uint32_t *type);

		wchar_t *GetString(IDParam const& id) const;

		ui::Scene *PageRoot(IDParam const& id) const;

		ui::Scene *PageRoot(cxml::Element const& node) const;

		Argument GetArg(const char *key, bool *exist) const;

		ui::HandlerCB GetEventHandler(const char *name) const;

		ui::LayoutCB GetLayoutHandler(const char *name) const;

		ui::HandlerCB GetInitEventHandler(IDParam const& id) const;

		void *GetInterface(int32_t version) const;

		void Notify(int32_t status) const;

		Locale GetLocale() const
		{
			return locale;
		}

		char *GetName() const
		{
			return name.c_str();
		}

		resource::ResourceObj *GetResource() const
		{
			return rscobj;
		}

		bool IsResourceFromMemory() const
		{
			return (resource_data != NULL);
		}

		ui::Widget *GetNodeEntity_Widget(cxml::Element const& node) const;

		ui::Widget *GetNodeEntity_Widget(IDParam const& id) const;

	private:

		static void WidgetDebugDeleteCb(ui::Widget *obj, void *data);

		static int32_t PageDebugFocusCB(ui::Widget *curr, ui::Widget *pre, void *data);

		static void DrawVisualParams(void *user_data);

		static void DebugAddResolution(ui::Widget *curr, ResolutionDebugMode mode);

		static void OnAnimPageHideFin(Timer *t, ui::AnimListener *anim, void *data1, void *data2, void *data);

		Plugin(const InitParam *init_param);

		~Plugin();

		void Start();

		void Stop();

		void Exit();

		void Init();

		void End();

		void PageActivateActually();

		void PageInactivateActually();

		void SetNodeEntity_Widget(cxml::Element const& node, ui::Widget *widget);

		void SetNodeEntity_Widget(IDParam const& id, ui::Widget *widget);

		void ClearNodeEntity_ForEachWidget(cxml::Element const& node);

		void SetNodeEntity_Surface(cxml::Element const& node, graph::Surface *surface);

		void SetNodeEntity_Surface(IDParam const& id, graph::Surface *surface);

		void SetNodeEntity_CreatePage(IDParam const& id, ui::Widget *widget);

		void SetNodeEntity_AddTexture(IDParam const& id, AddTextureInfo& addTexture);

		void AdjustPageDrawOrder(ui::Scene *page, IDParam const& id, int overwrite_draw_priority);

		int32_t WriteTextureTable(common::SharedPtr<File> xmlfp, bool write_table);

		int32_t WriteStyleTable(common::SharedPtr<File> xmlfp, bool write_table);

		int32_t WritePageTable(common::SharedPtr<File> xmlfp, bool write_table, bool write_template);

		int32_t WriteWidget(ui::Widget *widget, common::SharedPtr<File> xmlfp, uint32_t indent_level, bool write_template);

		int32_t WritePage(common::SharedPtr<File> xmlfp, IDParam const& id);

		void InstantiateWidget(cxml::Element const& node, ui::Widget *parent_widget, bool is_template, InitEventFunctionEntry2 *event_handler_table, ui::Widget *sibling);

		void SetDrawOrder_Insert(ui::Scene *page, int view_priority, int page_priority);

		void SetDrawOrder_Remove(ui::Scene *page);

		void LoadResourceTable_Texture();

		void UnloadResourceTable_Texture();

		void SetResourceTable_Texture();

		void LoadResourceTable_Style();

		graph::Surface *GetNodeEntity_Surface(cxml::Element const& node) const;

		graph::Surface *GetNodeEntity_Surface(IDParam const& id) const;

		ui::Widget *GetNodeEntity_CreatePage(IDParam const& id) const;

		AddTextureInfo *GetNodeEntity_AddTexture(IDParam const& id) const;

		bool initialized;
		string name;
		string caller_name;
		SetParamFunction set_param_func;
		InitFunction init_func;
		StartFunction start_func;
		StopFunction stop_func;
		ExitFunction exit_func;
		Module *module;
		InitEventFunctionEntry *init_event_handler_table;
		EventFunctionEntry *event_handler_table;
		map<uint32_t, int32_t> event_handler_name_table;
		LayoutFunctionEntry *layout_handler_table;
		map<string, int32_t> layout_handler_name_table; //0x4c
		map<int32_t, void*> interface_table; //0x58
		map<uint32_t, ui::Widget*> widget_table; //0x64
		map<string, ui::Widget*> create_page_table; //0x70
		map<uint32_t, graph::Surface*> surface_table; //0x7c
		map<uint32_t, AddTextureInfo> add_texture_table; //0x88
		char unk_94[0xC]; //0x94, unknown map
		vector<DrawOrderElement> draw_order;
		resource::ResourceObj *rscobj; //0xb0
		VersatileParamManager *style_param_manager;
		VersatileParamManager *obj_param_manager;
		VersatileParamManager *unk_param_manager;
		memory::HeapAllocator *private_heap;
		bool private_heap_created;
		memory::HeapAllocator *decode_heap;
		bool decode_heap_created;
		void *surface_pool_addr; //0xd0
		graph::SurfacePool *surface_pool; //0xd4
		map<string, Argument> arguments;
		int32_t option; //0xe4
		list<void(*)(int32_t, void*)> notify_callback_list;
		list<void(*)(void*)> unload_callback_list;
		void *param;
		cxml::Element *last_active_page_node;
		int32_t draw_priority;
		Locale locale;
		bool texture_table_loaded;
		int32_t tex_load_filter; //0x114
		PageOpenCallback monitoring_callback_pageopen;
		PageActivateCallback monitoring_callback_pageactivate;
		PageCloseCallback monitoring_callback_pageclose;
		uint8_t *resource_data;
		uint32_t resource_data_size;
		char unk_12C[0x10];
	};
}

#endif /* _VDSUITE_USER_PAF_PLUGIN_H */