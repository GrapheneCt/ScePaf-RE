/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_APP_SETTINGS_H
#define _VDSUITE_USER_APP_SETTINGS_H

#include <stdint.h>
#include <stddef.h>
#include <scetypes.h>
#include <paf.h>

namespace sce {

	class AppSettings
	{
	public:

		class Element;

		//PAF plugin loader callbacks

		static void PluginSetParamCB(paf::Plugin::InitParam2 *param);
		static void PluginInitCB(paf::Plugin *plugin);
		static void PluginStartCB(paf::Plugin *plugin);
		static void PluginStopCB(paf::Plugin *plugin);
		static void PluginExitCB(paf::Plugin *plugin);

		//PAF plugin interface (see paf::Plugin::GetInterface())

		class InterfaceCallbacks
		{
		public:

			typedef void(*TermCallback)(int32_t result);
			typedef void(*PageCallback)(const char *elementId, int32_t type);
			typedef wchar_t*(*GetStringCallback)(const char *elementId);
			typedef int32_t(*CheckVisibleCallback)(const char *elementId, bool *pIsVisible);
			typedef int32_t(*PressCallback)(const char *elementId, const char *newValue);
			typedef int32_t(*PreCreateCallback)(const char *elementId, Element *element);
			typedef int32_t(*PostCreateCallback)(const char *elementId, paf::ui::Widget *widget);
			typedef int32_t(*GetSurfaceCallback)(paf::graph::Surface **surf, const char *key);

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

			int32_t(*Show)(InterfaceCallbacks *callbacks);
			int32_t(*unkFun_04)(int32_t a1, int32_t a2);
			int32_t(*unkFun_08)(const char *a1);
			int32_t(*AddElement)(const char *a1, int32_t a2);
			int32_t(*RemoveElement)(const char *a1);
			int32_t(*ReloadElement)(const char *a1);
			int32_t(*EnableElement)(const char *a1);
			int32_t(*DisableElement)(const char *a1);
			int32_t(*ReloadPage)();
			int32_t(*ReloadPage2)();
			int32_t(*SetFooterButtonStatus)(int32_t status, const char *a2); // 1 - enable, 2 - disable
			int32_t(*AddFooterButton)(const char *a1, paf::wstring *label, int32_t pos); // 1 - left, 2 - right
			int32_t(*ShowFooter)();
			int32_t(*HideFooter)();
			int32_t(*ShowBackButton)();
			int32_t(*HideBackButton)();
			int32_t(*unkFun_40)(const char *a1);
			int32_t(*unkFun_44)(int32_t a1);
		};

		class InitParam
		{
		public:

			typedef void* (*Allocate)(size_t size);
			typedef void* (*Reallocate)(void* ptr, size_t newSize);
			typedef void(*Deallocate)(void* ptr);

			paf::common::SharedPtr<paf::MemFile> xml_file;
			Allocate alloc_cb;
			Reallocate realloc_cb;
			Deallocate free_cb;
			int32_t safemem_offset;
			size_t safemem_size;
		};

		class Element
		{
		public:

			virtual ~Element();

			paf::string *GetProperty(const char *property);

			void SetProperty(const char *property, const char *value);

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

		static int32_t GetInstance(InitParam& pInitParam, AppSettings **ppAppSettingsInstance);

		int32_t Terminate();

		int32_t Initialize();

		int32_t GetInt(const char *key, int32_t *pValue, int32_t defaultValue);

		int32_t SetInt(const char *key, int32_t value);

		int32_t GetString(const char *key, const char* value, uint32_t size, const char* defaultValue);

		int32_t SetString(const char *key, const char* value);

		int32_t GetBool(const char *key, bool *pValue, bool defaultValue);

		int32_t SetBool(const char *key, bool value);

		/*int Test1();

		int Test2(const char *pKey, SceInt32 *value, SceInt32 a3);

		int Test3(const char *pKey, SceInt32 value);

		int Test4();*/

	};
}

#endif /* _VDSUITE_USER_APP_SETTINGS_H */
