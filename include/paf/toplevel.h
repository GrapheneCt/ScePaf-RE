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
		typedef void(*PluginGraphicsFreeCb)();

		class InitParam //0x94
		{
		public:

			enum PluginFlags
			{
				PluginFlag_UseRcdDebug = 0x20,
			};

			InitParam();

			~InitParam() { };

			paf::string pluginName;
			paf::string scopeName;
			paf::Plugin::PluginCB pluginSetParamCB;	//Called after plugin module is loaded and started
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
			SceUInt32 pluginFlags;
			SceInt32 unk_80;
			PluginGraphicsFreeCb graphicsFreeCb;
			SceUChar8 unk_88[0x0C];
		};

		~Plugin();

		enum PageEffectType
		{
			PageEffectType_None,
			PageEffectType_SlideFromTop, // effect 0xE
			PageEffectType_SlideFromBottom, // effect 0xF
			PageEffectType_SlideFromLeft, // effect 0x10
			PageEffectType_SlideFromRight, // effect 0x11
		};

		class PageOpenParam
		{
		public:

			PageOpenParam();

			~PageOpenParam() { };

			SceInt32 unk_00;
			SceInt32 unk_04;
			SceInt32 priority;
			SceInt32 unk_0C;
			SceInt32 unk_10;
			bool useFadein;
			SceFloat32 fadeinTimeMs;
			PageEffectType effectType;
			SceInt32 unk_20;
			ui::Context::Option *uiOpt;
			SceInt32 unk_28_pageArg_a5;
		};

		class PageCloseParam
		{
		public:

			PageCloseParam();

			~PageCloseParam() { };

			bool useFadeout;
			SceFloat32 fadeoutTimeMs;
			PageEffectType effectType;
			SceInt32 reserved;
		};

		class TemplateOpenParam
		{
		public:

			TemplateOpenParam();

			~TemplateOpenParam() { };

			SceInt32 unk_00;
			SceInt32 unk_04;
		};

		static Plugin *Find(const char *pluginName);

		static SceVoid GetTexture(paf::graph::Surface **res, Plugin *plugin, paf::rco::Element *textureSearchParam);

		//6F7E804D
		//SceInt32 AddTextureFromFile(paf::string *unk, const char *filePath, const char *a3);

		paf::ui::Scene *PageOpen(paf::rco::Element *widgetInfo, PageOpenParam *openParam);

		SceVoid PageClose(paf::rco::Element *widgetInfo, PageCloseParam *closeParam);

		paf::ui::Widget *CreateWidgetWithStyle(paf::ui::Widget *parent, const char *widgetType, paf::rco::Element *widgetInfo, paf::rco::Element *styleInfo);

		//ScePafToplevel_923F763A
		paf::ui::Widget *CreateWidgetWithProperty(paf::ui::Widget *parent, const char *widgetType, paf::rco::Element *widgetInfo, const char *propertyType, paf::rco::Element *propertyInfo);

		paf::ui::Widget *GetPageByHash(paf::rco::Element *widgetInfo);

		ScePVoid GetInterface(SceUInt32 slot);

		//F5354FEF
		SceInt32 SetInterface(SceUInt32 slot, ScePVoid interfaceTable);

		paf::ui::Widget *GetChildByHash(paf::rco::Element *widgetInfo);

		SceInt32 TemplateOpen(paf::ui::Widget *targetRoot, paf::rco::Element *templateSearchParam, paf::Plugin::TemplateOpenParam *param);

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
				FeatureFlag_UseDisplayAreaSettings = 8
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
			ScePVoid extFont1Buf;
			SceUInt32 extFont1Size;
			ScePVoid extFont2Buf;
			SceUInt32 extFont2Size;
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
			ui::Context::Option *uiCtxOpt;
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

		static SceVoid LoadPluginCRFinishCallback(Plugin *crPlugin);

		static SceVoid PluginCRGraphicsFreeCallback();

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

		paf::ui::Context *GetUiContext();

		wchar_t *GetCRWString(paf::rco::Element *stringInfo);

	public:

		SceUChar8 unk_00[0x18];

		SceUInt32 loadedPluginNum;
		Plugin *crPlugin;

		SceUChar8 unk_20[0x14];

		memory::HeapAllocator *fwDecodeHeapAlloc;
		bool hasFwDecodeHeapAlloc;
		memory::HeapAllocator *fwDefaultPluginHeap;
		bool hasFwDefaultPluginHeap;
		ScePVoid crSurfacePoolMem;
		graph::SurfacePool *crSurfacePool;
		ScePVoid *uiCtx;

		SceUChar8 unk_50[0x4];

		ApplicationMode applicationMode;
		SceUInt32 optionalFeatureFlags;
		SceUInt32 language;

		thread::Mutex *fwUpdateMutex;
		thread::Mutex *fwUpdateCond;
		thread::RWLock *fwListLock;

		SceUChar8 unk_6C[0x8];

		SceUID powerCallbackId;
		ui::Context::Option *uiCtxOpt;
	};

	__declspec (dllimport) Framework *s_frameworkInstance;
}

#endif /* _VDSUITE_USER_PAF_TOPLEVEL_H */
