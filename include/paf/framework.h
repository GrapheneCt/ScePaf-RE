/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_FRAMEWORK_H
#define _VDSUITE_USER_PAF_FRAMEWORK_H

#include <stdint.h>
#include <stddef.h>
#include <scetypes.h>
#include <paf/paf_types.h>
#include <paf/std/vector>
#include <paf/std/string>
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

		enum Mode //for InitParam::mode
		{
			Mode_Normal = 0,
			Mode_Shell = 1,			// Do not use shared memory even when possible. Force CDRAM usage for some heaps. GXM flags set to 0x6 (create shared param buffer)
			Mode_Application = 2,
			Mode_ApplicationB = 3,	//FrameBuffer_Shared_OffScreen
			Mode_ApplicationC = 4,
			Mode_CommonDialog = 5,
		};

		enum FrameworkOption //for InitParam::option?
		{
			FrameworkOption_None = 0,
			FrameworkOption_OneFrameMode = 1,
			FrameworkOption_DisableInternalCallbackChecks = 2,
			FrameworkOption_4 = 4,
			FrameworkOption_UseDisplayAreaSettings = 8

		};

		enum PvfOption // for InitParam::pvf_option
		{
			PvfOption_ExtraFontMusicArib = 1,
			PvfOption_ExtraFontKr0 = 8,
			PvfOption_ExtraFontCn0 = 16
		};

		typedef void(*LoadCRFinishCallback)();
		typedef void(*UnloadCRFinishCallback)();
		typedef void(*ShutdownCallback)(void*);

		typedef void(*LoadFinishCallback)(Plugin *);
		typedef void(*UnloadFinishCallback)(const char *);

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
			bool unk_opt_1;
			bool ext_control;
			bool unk_opt_2;
			ui::EnvironmentParam *env_param;
			uint32_t screen_orientation_mode;
			uint32_t graphics_option;
			uint32_t unk_90;
			uint32_t unk_94;
			uint32_t unk_98;
			uint32_t unk_9C;
			uint32_t unk_A0;
			uint32_t unk_A4;
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

		static void SampleInit(InitParam *init_param);

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

		Framework *Instance();

		ui::Environment *GetEnvironmentInstance();

		sound::Output *GetSoundInstance();

		Plugin *FindPlugin(const char *name, bool unk = false);

		int32_t GetCommonResourceStyles(const char *widget_type, vector<string> *styleIds);

		int32_t GetCommonResourceTextures(vector<string> *textureIds);

		intrusive_ptr<graph::Surface> GetCommonTexture(IDParam const& id);

		int32_t GetCommonSound(IDParam const& id, void **addr1, uint32_t *size1, void **addr2, uint32_t *size2, int32_t *samplerate, uint32_t *type);

		wchar_t *GetCommonString(IDParam const& id) const;

		Locale GetCommonResourceLocale() const;

		Locale paf::Framework::GetLocale() const
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

		uint32_t run_loop_count;
		vector<Plugin*> plugin_list;
		Plugin *active_plugin;
		int32_t loading_plugin_count;
		Plugin *common_resource_plugin;
		LoadCRFinishCallback *load_finish_callback;
		UnloadCRFinishCallback *unload_finish_callback;
		ShutdownCallback *shutdown_callback;
		void *shutdown_callback_userdata;
		char unk_30[0x04];
		memory::HeapAllocator *decode_heap;
		bool decode_heap_created;
		memory::HeapAllocator *plugin_heap;
		bool plugin_heap_created;
		void *surface_pool_addr;
		graph::SurfacePool *surface_pool;
		ui::Environment *m_env;
		ui::Screen *m_scr;
		uint32_t m_mode;
		uint32_t m_option;
		Locale m_locale;
		thread::Mutex *update_mutex;
		thread::Cond *update_cond;
		thread::RWLock *list_lock;
		sound::Output *sound_output;
		bool shutdown_requested;
		SceUID power_cb_id;
		ui::EnvironmentParam *env_param;

		__declspec (dllimport) static Framework *framework;
	};
}

#endif /* _VDSUITE_USER_PAF_FRAMEWORK_H */