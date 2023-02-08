/*
	Vita Development Suite Libraries git-1ed1a4e7
*/

#ifndef _VDSUITE_USER_APP_SETTINGS_H
#define _VDSUITE_USER_APP_SETTINGS_H

#include <scetypes.h>
#include <paf.h>

namespace sce {

	class AppSettings
	{
	public:

		class Element;

		//PAF plugin loader callbacks

		static SceVoid PluginCreateCB(paf::Plugin *plugin);
		static SceVoid PluginInitCB(paf::Plugin *plugin);
		static SceVoid PluginStartCB(paf::Plugin *plugin);
		static SceVoid PluginStopCB(paf::Plugin *plugin);
		static SceVoid PluginExitCB(paf::Plugin *plugin);

		//PAF plugin interface (see paf::Plugin::GetInterface())

		class InterfaceCallbacks
		{
		public:

			typedef SceVoid(*TermCallback)(SceInt32 result);
			typedef SceVoid(*PageCallback)(const char *elementId, SceInt32 type);
			typedef wchar_t*(*GetStringCallback)(const char *elementId);
			typedef SceInt32(*CheckVisibleCallback)(const char *elementId, SceInt32 *pIsVisible);
			typedef SceInt32(*PressCallback)(const char *elementId, const char *newValue);
			typedef SceInt32(*PreCreateCallback)(const char *elementId, Element *element);
			typedef SceInt32(*PostCreateCallback)(const char *elementId, paf::ui::Widget *widget);
			typedef SceInt32(*GetSurfaceCallback)(paf::graph::Surface **surf, const char *key);

			PageCallback onStartPageTransitionCb;
			PageCallback onPageActivateCb;
			PageCallback onPageDeactivateCb;
			CheckVisibleCallback onCheckVisible;
			PreCreateCallback onPreCreateCb;
			PostCreateCallback onPostCreateCb;
			PressCallback onPressCb;
			PressCallback onPressCb2;
			TermCallback onTermCb;
			GetStringCallback onGetStringCb;
			GetSurfaceCallback onGetSurfaceCb;
		};

		class Interface
		{
		public:

			SceInt32(*Show)(InterfaceCallbacks *callbacks);
			SceInt32(*unkFun_04)(SceInt32 a1, SceInt32 a2);
			SceInt32(*unkFun_08)(const char *a1);
			SceInt32(*AddElement)(const char *a1, SceInt32 a2);
			SceInt32(*RemoveElement)(const char *a1);
			SceInt32(*ReloadElement)(const char *a1);
			SceInt32(*EnableElement)(const char *a1);
			SceInt32(*DisableElement)(const char *a1);
			SceInt32(*ReloadPage)();
			SceInt32(*ReloadPage2)();
			SceInt32(*SetFooterButtonStatus)(SceInt32 status, const char *a2); // 1 - enable, 2 - disable
			SceInt32(*AddFooterButton)(const char *a1, paf::wstring *label, SceInt32 pos); // 1 - left, 2 - right
			SceInt32(*ShowFooter)();
			SceInt32(*HideFooter)();
			SceInt32(*ShowBackButton)();
			SceInt32(*HideBackButton)();
			SceInt32(*unkFun_40)(const char *a1);
			SceInt32(*unkFun_44)(SceInt32 a1);
		};

		class InitParam
		{
		public:

			typedef void* (*Allocate)(size_t size);
			typedef void* (*Reallocate)(void* ptr, size_t newSize);
			typedef void(*Deallocate)(void* ptr);

			paf::common::SharedPtr<paf::MemFile> xmlFile;
			Allocate allocCB;
			Reallocate reallocCB;
			Deallocate freeCB;
			SceInt32 safeMemoryOffset;
			SceUInt32 safeMemorySize;
		};

		class Element
		{
		public:

			virtual ~Element();

			paf::string *GetProperty(const char *property);

			SceVoid SetProperty(const char *property, const char *value);

		private:

			Element()
			{

			}
		};

		class ListItem : public Element
		{
		public:

			ListItem();

			virtual ~ListItem();
		};

		static SceInt32 GetInstance(InitParam *pInitParam, AppSettings **ppAppSettingsInstance);

		SceInt32 Terminate();

		SceInt32 Initialize();

		SceInt32 GetInt(const char *key, SceInt32 *pValue, SceInt32 defaultValue);

		SceInt32 SetInt(const char *key, SceInt32 value);

		SceInt32 GetString(const char *key, const char* value, SceUInt32 size, const char* defaultValue);

		SceInt32 SetString(const char *key, const char* value);

		SceInt32 GetBool(const char *key, bool *pValue, bool defaultValue);

		SceInt32 SetBool(const char *key, bool value);

		/*int Test1();

		int Test2(const char *pKey, SceInt32 *value, SceInt32 a3);

		int Test3(const char *pKey, SceInt32 value);

		int Test4();*/

	};
}

#endif /* _VDSUITE_USER_APP_SETTINGS_H */
