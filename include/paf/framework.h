/*
	ScePaf-RE Project
*/

#ifndef _PAF_FRAMEWORK_H
#define _PAF_FRAMEWORK_H

#include <stdint.h>
#include <stddef.h>
#if defined(__SNC__)
#include <scetypes.h>
#elif defined(__vita__)
#include <psp2/types.h>
#endif
#include <paf/paf_types.h>
#include <paf/std/stdcxx.h>
#include <paf/plugin.h>

namespace paf {

	namespace thread {

		class Mutex;
		class Cond;
		class RWLock;
	}

	namespace memory {

		class HeapAllocator;
	}

	namespace graph {

		class SurfacePool;
		class Surface;
	}

	namespace sound {

		class Output;
	}

	namespace ui {

		class EnvironmentParam;
		class Environment;
		class Screen;
	}

	class Framework
	{
	public:

		typedef void(*LoadCRFinishCallback)();
		typedef void(*UnloadCRFinishCallback)();
		typedef void(*ShutdownCallback)(void*);

		typedef void(*LoadFinishCallback)(Plugin *);
		typedef void(*UnloadFinishCallback)(const char *);

#if defined(__SNC__) || defined(__vita__)

		enum Mode : int32_t //for InitParam::mode
		{
			Mode_Normal = 0,		// FrameBuffer_Normal
			Mode_Shell = 1,			// FrameBuffer_Shared_Create. Do not use shared memory even when possible. Force CDRAM usage for some heaps. GXM flags set to 0x6 (create shared param buffer)
			Mode_Application = 2,	// FrameBuffer_Shared_Share
			Mode_ApplicationB = 3,	// FrameBuffer_Shared_OffScreen
			Mode_ApplicationC = 4,	// Can switch between 2 and 3 at runtime
			Mode_CommonDialog = 5,	// FrameBuffer_Given
		};

		enum FrameworkOption : int32_t //for InitParam::option?
		{
			FrameworkOption_None = 0,
			FrameworkOption_OneFrameMode = 1,
			FrameworkOption_DisableInternalCallbackChecks = 2,
			FrameworkOption_4 = 4,
			FrameworkOption_UseDisplayAreaSettings = 8

		};

		enum PvfOption : int32_t // for InitParam::pvf_option
		{
			PvfOption_ExtraFontMusicArib = 1,
			PvfOption_ExtraFontKr0 = 8,
			PvfOption_ExtraFontCn0 = 16
		};

		class InitParam
		{
		public:

			InitParam();

			~InitParam()
			{

			};

			uint32_t display_list_size; //gxm ring buffer size
			uint32_t parameter_buffer_size;
			uint32_t parameter_buffer_location;
			uint32_t surface_pool_size;
			uint32_t graph_heap_size_on_main_memory;
			uint32_t graph_heap_size_on_video_memory;
			uint32_t text_surface_pool_size;
			uint32_t unk_1C;
			uint32_t unk_20;
			void *mem_pvf_japanese_addr;
			uint32_t mem_pvf_japanese_size;
			void *mem_pvf_latin_addr;
			uint32_t mem_pvf_latin_size;
			void *mem_pvf_hangul_addr;
			uint32_t mem_pvf_hangul_size;
			void *mem_pvf_chinese_addr;
			uint32_t mem_pvf_chinese_size;
			char *path_pvf_japanese;
			char *path_pvf_latin;
			char *path_pvf_hangul;
			char *path_pvf_chinese;
			uint32_t pvf_option;
			uint32_t pvf_heap_size;
			uint32_t decode_heap_size;
			uint32_t plugin_heap_size;
			ImageMode image_mode;
			uint32_t screen_width;
			uint32_t screen_height;
			uint32_t mode;
			uint32_t option;
			Locale locale;
			uint32_t enter_button_assign;
			bool allow_button_control;
			bool show_focus;
			bool ext_control;
			bool unk_opt_2;
			ui::EnvironmentParam *env_param;
			uint32_t screen_orientation_mode;
			uint32_t graphics_option;
			uint32_t edit_listener;
			uint32_t unk_94;
			uint32_t message_dialog_listener;
			uint32_t unk_9C;
			void *webview_listener;
			void *web_edit_listener;
			uint32_t sound_mode;
			uint32_t unk_AC;
			uint32_t unk_B0;
		};

		class CommonResourceInitParam
		{
		public:

			CommonResourceInitParam();

			~CommonResourceInitParam()
			{

			};

			string resource_file;
			uint8_t *resource_data;
			uint32_t resource_data_size;
			uint32_t private_heap_size;
			memory::HeapAllocator *private_heap;
			graph::SurfacePool *surface_pool;
			int32_t draw_priority;
		};

#elif defined(_WIN32)

		enum Mode : int32_t //for InitParam::mode
		{
			Mode_Normal = 0,
		};

		enum FrameworkOption : int32_t //for InitParam::option?
		{
			FrameworkOption_None = 0,
			FrameworkOption_OneFrameMode = 1,

		};

		class InitParam
		{
		public:

			InitParam();

			~InitParam()
			{

			};

			uint32_t zoom_level;
			bool allow_dpi_override;
			bool simulator_mode;
			uint32_t screen_width;
			uint32_t screen_height;
			wstring app_name;
			ui::EnvironmentParam *env_param;
			uint32_t mode;
			uint32_t option;
			uint32_t sound_mode;
		};

		class CommonResourceInitParam
		{
		public:

			CommonResourceInitParam();

			~CommonResourceInitParam()
			{

			};

			string resource_file;
			uint8_t *resource_data;
			uint32_t resource_data_size;
			uint32_t private_heap_size;
			memory::HeapAllocator *private_heap;
		};

#endif

		static void SampleInit(InitParam *init_param);

		static Framework *Instance();

		Framework(InitParam const& init_param);

		~Framework();

		bool IsShutdownDone();

		void RequestShutdown();

		int32_t Run();

		void Update(void *param);

		void SetLocale(Locale _locale);

		void LoadCommonResourceAsync(LoadCRFinishCallback finishCallback = NULL);

		void LoadCommonResourceAsync(CommonResourceInitParam& initParam, LoadCRFinishCallback finishCallback = NULL);

		void LoadCommonResourceSync(LoadCRFinishCallback finishCallback = NULL);

		void LoadCommonResourceSync(CommonResourceInitParam& initParam, LoadCRFinishCallback finishCallback = NULL);

		void UnLoadCommonResourceAsync(UnloadCRFinishCallback finish_callback = NULL);

		int32_t SetCommonResourceLocale(Locale _locale);

		int32_t InitCommonSE();

		int32_t PlayCommonSE(int32_t iSeNo, float volume, bool force);

		int32_t SetMode(uint32_t mode);

		int32_t GetMode();

		int32_t GetMode_ApplicationC();

		ui::Environment *GetEnvironmentInstance();

		sound::Output *GetSoundInstance();

		Plugin *FindPlugin(const char *name, bool unk = false);

		int32_t GetCommonResourceStyles(const char *widget_type, vector<string> *styleIds);

		int32_t GetCommonResourceTextures(vector<string> *textureIds);

		intrusive_ptr<graph::Surface> GetCommonTexture(IDParam const& id);

		int32_t GetCommonSound(IDParam const& id, void **addr1, uint32_t *size1, void **addr2, uint32_t *size2, int32_t *samplerate, uint32_t *type);

		wchar_t *GetCommonString(IDParam const& id) const;

		Locale GetCommonResourceLocale() const;

		Locale GetLocale() const
		{
			return m_locale;
		}

	private:

		class ConstructPluginData;
		class DestructPluginData;

		static void JobInit();

		static void CRLoadFinishCallback(Plugin *plugin);

		void LoadInitAction(int32_t option);

		void RequestLoadPlugin(Plugin::InitParam const& plugin_init_param, LoadFinishCallback *finish_callback, int32_t option);

		void UnloadPreaction(Plugin *plugin);

		void UnloadInitAction(Plugin *plugin, const char *name, int32_t option);

		void RequestUnloadPlugin(Plugin *plugin, const char *name, UnloadFinishCallback *finish_callback, int32_t option);

		void SetLocaleAllPlugin(Locale _locale);

		void LoadRunAction(ConstructPluginData *data);

		void LoadFinishedAction(ConstructPluginData *data);

		void UnloadRunAction(DestructPluginData *data);

		void UnloadFinishedAction(DestructPluginData *data);

		void Main(int32_t **inout);

#if defined(__SNC__) || defined(__vita__)

		uint32_t m_run_loop_count;
		vector<Plugin*> m_plugin_list;
		Plugin *m_active_plugin;
		int32_t m_loading_plugin_count;
		Plugin *m_common_resource_plugin;
		LoadCRFinishCallback m_load_finish_callback;
		UnloadCRFinishCallback m_unload_finish_callback;
		ShutdownCallback m_shutdown_callback;
		void *m_shutdown_callback_userdata;
		char m_unk_30[0x04];
		memory::HeapAllocator *m_decode_heap;
		bool m_decode_heap_created;
		memory::HeapAllocator *m_plugin_heap;
		bool m_plugin_heap_created;
		void *m_surface_pool_addr;
		graph::SurfacePool *m_surface_pool;
		ui::Environment *m_env;
		ui::Screen *m_scr;
		uint32_t m_mode;
		uint32_t m_option;
		Locale m_locale;
		thread::Mutex *m_update_mutex;
		thread::Cond *m_update_cond;
		thread::RWLock *m_list_lock;
		sound::Output *m_sound_output;
		bool m_shutdown_requested;
		SceUID m_power_cb_id;
		ui::EnvironmentParam *m_env_param;

#elif defined(_WIN32)

		uint32_t m_run_loop_count;
		vector<Plugin*> m_plugin_list;
		int32_t m_loading_plugin_count;
		ShutdownCallback m_shutdown_callback;
		void *m_shutdown_callback_userdata;
		ui::Environment *m_env;
		ui::Screen *m_scr;
		uint32_t m_mode;
		uint32_t m_option;
		Locale m_locale;
		thread::Mutex *m_update_mutex;
		thread::Cond *m_update_cond;
		thread::RWLock *m_list_lock;
		sound::Output *m_sound_output;
		bool m_shutdown_requested;
		ui::EnvironmentParam *m_env_param;

#endif

		SCE_PAF_IMPORTED_FROM_PRX static Framework *framework;
	};
}

#endif /* _PAF_FRAMEWORK_H */