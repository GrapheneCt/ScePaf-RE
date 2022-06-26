/*
	Vita Development Suite Libraries git-1ed1a4e7
*/

#ifndef _VDSUITE_USER_PAF_TOPLEVEL_H
#define _VDSUITE_USER_PAF_TOPLEVEL_H

#include <kernel.h>

namespace paf {

	class Plugin
	{
	public:

		typedef void(*PluginCB)(Plugin *plugin);

		class InitParam //0x94
		{
		public:

			InitParam();

			~InitParam() { };

			paf::string pluginName;
			paf::string scopeName;
			paf::Plugin::PluginCB pluginCreateCB;	//Called after plugin module is loaded and started
			paf::Plugin::PluginCB pluginInitCB;		//Called after plugin is fully initialized
			paf::Plugin::PluginCB pluginStartCB;
			paf::Plugin::PluginCB pluginStopCB;
			paf::Plugin::PluginCB pluginExitCB;
			paf::string resourcePath;
			ScePVoid resourceMemory;
			SceSize resourceSize;
			SceInt32 unk_40;
			SceUInt32 privateHeapSize;
			paf::memory::HeapAllocator *privateHeapAllocator;
			SceUInt32 decodeHeapSize;
			paf::memory::HeapAllocator *decodeHeapAllocator;
			paf::graph::SurfacePool *surfaceMemPool;
			SceInt32 unk_58;
			SceUChar8 unk_5C[0xC];
			paf::string pluginPath;
			SceInt32 unk_74;
			paf::Module::Flag pluginModuleFlags;
			SceUChar8 unk_7C[0x18];
		};

		~Plugin();

		class PageInitParam
		{
		public:

			PageInitParam();

			~PageInitParam() { };

			SceInt32 unk_00;
			SceInt32 unk_04;
			SceInt32 priority;
			SceUChar8 unk_0C[0x20];
		};

		class TemplateInitParam
		{
		public:

			TemplateInitParam();

			~TemplateInitParam() { };

			SceInt32 unk_00;
			SceInt32 unk_04;
		};

		static Plugin *Find(const char *pluginName);

		static SceVoid GetTexture(paf::graph::Surface **res, Plugin *plugin, paf::rco::Element *textureSearchParam);

		//6F7E804D
		//SceInt32 AddTextureFromFile(paf::string *unk, const char *filePath, const char *a3);

		paf::ui::Widget *PageOpen(paf::rco::Element *widgetInfo, PageInitParam *initParam);

		paf::ui::Widget *CreateWidgetWithStyle(paf::ui::Widget *parent, const char *widgetType, paf::rco::Element *widgetInfo, paf::rco::Element *styleInfo);

		//ScePafToplevel_923F763A
		paf::ui::Widget *CreateWidgetWithProperty(paf::ui::Widget *parent, const char *widgetType, paf::rco::Element *widgetInfo, const char *propertyType, paf::rco::Element *propertyInfo);

		paf::ui::Widget *GetPageByHash(paf::rco::Element *widgetInfo);

		ScePVoid GetInterface(SceUInt32 slot);

		//F5354FEF
		SceInt32 SetInterface(SceUInt32 slot, ScePVoid interfaceTable);

		paf::ui::Widget *GetChildByHash(paf::rco::Element *widgetInfo);

		SceInt32 TemplateOpen(paf::ui::Widget *targetRoot, paf::rco::Element *templateSearchParam, paf::Plugin::TemplateInitParam *param);

		wchar_t *GetWString(paf::rco::Element *stringInfo);

	public:
		
		bool isLoaded;
		paf::string pluginName;
		paf::string scopeName;
		PluginCB pluginCreateCB;
		PluginCB pluginInitCB;
		PluginCB pluginStartCB;
		PluginCB pluginStopCB;
		PluginCB pluginExitCB;
		paf::Module *module;
		SceUChar8 unk_34[0x7C];
		paf::rco::Resource *resource;
		SceUChar8 unk_B4[0x20];
		graph::SurfacePool *memoryPool;

	private:

		Plugin();

		SceUChar8 m_unk_D8[0x64];

	};

	class Framework
	{
	public:

		enum ApplicationMode
		{
			Mode_Game,
			Mode_Shell, // Do not use shared memory even when possible. Force CDRAM usage for some heaps. GXM flags set to 0x6 (create shared param buffer)
			Mode_Application,
			Mode_ApplicationB,
			Mode_ApplicationC,
			Mode_CDLG
		};

		class InitParam
		{
		public:

			enum FeatureFlags
			{
				FeatureFlag_UseFwUpdateSync = 1,
				FeatureFlag_DisableInternalCallbackChecks = 2,
				FeatureFlag_4 = 4,
				FeatureFlag_8 = 8
			};

			enum FontRasterizerFlags
			{
				FontRasterizerFlag_ExtraFontMusicArib = 1,
				FontRasterizerFlag_ExtraFontKr0 = 8,
				FontRasterizerFlag_ExtraFontCn0 = 16
			};

			enum AudioMode
			{
				AudioMode_Normal = 0,
				AudioMode_ForceCDLG = 1,
				AudioMode_None = 2
			};

			InitParam();

			~InitParam() { };

			InitParam *LoadDefaultParams();

			SceUInt32 gxmRingBufferSize;
			SceUInt32 gxmParameterBufferSize;

			SceUInt32 unk_08;
			SceUInt32 defaultSurfacePoolSize;
			SceUInt32 graphMemSystemHeapSize;

			SceUInt32 graphMemVideoHeapSize;

			SceUInt32 textSurfaceCacheSize;

			SceUInt32 unk_1C;
			SceUInt32 unk_20;
			SceUInt32 unk_24;
			SceUInt32 unk_28;
			SceUInt32 unk_2C;
			SceUInt32 unk_30;
			SceUInt32 unk_34;
			SceUInt32 unk_38;
			SceUInt32 unk_3C;
			SceUInt32 unk_40;
			SceUInt32 unk_44;
			SceUInt32 unk_48;
			SceUInt32 unk_4C;
			SceUInt32 unk_50;

			SceUInt32 fontRasterizerFlags;
			SceUInt32 fontRasterizerHeapSize;
			SceUInt32 decodeHeapSize;
			SceUInt32 defaultPluginHeapSize;
			SceUInt32 unkSize_64;
			SceInt32 screenWidth;
			SceInt32 sceenHeight;
			ApplicationMode applicationMode;
			SceUInt32 optionalFeatureFlags;
			SceInt32 language;
			SceInt32 enterButtonAssign;
			SceUInt8 allowControlWithButtons;
			SceUInt8 unkOptFlag1;
			SceUInt8 extCtrlMode;
			SceUInt8 unkOptFlag3;
			ui::Context *extUiContext;
			SceInt32 screenOrientationMode;
			SceInt32 graphicsFlags;

			SceUInt32 unk_90;
			SceUInt32 unk_94;
			SceUInt32 unk_98;
			SceUInt32 unk_9C;
			SceUInt32 unk_A0;
			SceUInt32 unk_A4;

			SceUInt32 audioMode;

			SceUChar8 unk2[0x8];
		};

		class CommonResourceInitParam
		{
		public:

			CommonResourceInitParam();

			~CommonResourceInitParam() { };

			paf::string resourcePath;
			SceUChar8 unk_08[0x1C];
		};

		class RenderSurfaceParam
		{
		public:

			SceUInt32 strideInPixels;
			SceUInt32 width;
			SceUInt32 height;
			SceGxmColorFormat colorFormat;
			SceGxmColorSurfaceType surfaceType;
			ScePVoid colorSurfaceData;
			SceInt32 unk_18; // 0
			SceGxmSyncObject *displaySyncObject;
		};

		typedef void(*LoadCRFinishCallback)();
		typedef void(*LoadPluginFinishCallback)(Plugin *plugin);
		typedef void(*UnloadPluginFinishCallback)(Plugin *plugin);

		Framework(const InitParam& fwInitParam);

		~Framework();

		static SceVoid InitializeDefaultJobQueue();

		static SceUInt32 GetFwLangBySystemLang(SceUInt32 systemLanguage);

		static SceVoid LoadPluginAsync(Plugin::InitParam *initParam, LoadPluginFinishCallback finishCallback = SCE_NULL, UnloadPluginFinishCallback unloadFinishCallback = SCE_NULL);

		static SceVoid UnloadPluginAsync(const char *pluginName, LoadPluginFinishCallback finishCallback = SCE_NULL, UnloadPluginFinishCallback unloadFinishCallback = SCE_NULL);

		static SceVoid LoadPlugin(Plugin::InitParam *initParam, LoadPluginFinishCallback finishCallback = SCE_NULL, UnloadPluginFinishCallback unloadFinishCallback = SCE_NULL);

		static Framework *GetInstance();

		static paf::graph::SurfacePool *GetDefaultSurfaceMemoryPool();

		static SceVoid GetTexture(paf::graph::Surface **res, Framework *fw, paf::rco::Element *searchParam);

		//static SceVoid CreateSurfaceFromMemory(paf::graphics::Surface **surf, Plugin *plugin, ScePVoid ptr, SceSize size, paf::image::Image::Type type, bool isCompressed, SceSize origsize);

		//ScePafToplevel_E37EC9D8
		static paf::ui::Widget *CreateWidgetWithStyle(paf::ui::Widget *parent, const char *widgetType, paf::rco::Element *widgetInfo, paf::rco::Element *styleInfo, Framework *fw);

		SceVoid _LoadPluginAsync(Plugin::InitParam *initParam, LoadPluginFinishCallback finishCallback = SCE_NULL, UnloadPluginFinishCallback unloadFinishCallback = SCE_NULL);

		SceInt32 EnterRenderingLoop();

		SceVoid ExitRenderingLoop();

		SceVoid SetRenderTarget(RenderSurfaceParam *param);

		SceVoid LoadCommonResourceAsync(LoadCRFinishCallback finishCallback = SCE_NULL);

		SceVoid LoadCommonResourceAsync(CommonResourceInitParam *initParam, LoadCRFinishCallback finishCallback = SCE_NULL);

		SceVoid LoadCommonResource(LoadCRFinishCallback finishCallback = SCE_NULL);

		SceVoid LoadCommonResource(CommonResourceInitParam *initParam, LoadCRFinishCallback finishCallback = SCE_NULL);

		Plugin *FindPluginByName(const char *pluginName, bool enableSomeCheck = SCE_FALSE);

		ApplicationMode GetApplicationMode();

		paf::ui::Widget *GetCurrentPage();

		wchar_t *GetCRWString(paf::rco::Element *stringInfo);

	public:

		SceUChar8 unk_00[0x18];

		SceUInt32 loadedPluginNum;

		Plugin *crPlugin;

		SceUChar8 unk_20[0x2C];

		ScePVoid widgetFwHandle;

		SceUChar8 unk_50[0x4];

		ApplicationMode applicationMode;

		SceUInt32 optionalFeatureFlags;

		SceUInt32 language;

		thread::Mutex *fwUpdateMutex;

		thread::Mutex *fwUpdateCond;

		thread::RWLock *fwListLock;

		SceUChar8 unk_6C[0x8];

		SceUID powerCallbackId;

		paf::memory::HeapAllocator *defaultAllocator;
	};

	__declspec (dllimport) Framework *s_frameworkInstance;
}

#endif /* _VDSUITE_USER_PAF_TOPLEVEL_H */
