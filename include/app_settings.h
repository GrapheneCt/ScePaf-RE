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

			typedef SceInt32(*Ret0)();
			typedef SceVoid(*Ret)();
			typedef SceVoid(*OnListChange)(const char *elementId);
			typedef SceVoid(*OnListForwardChange)(const char *elementId);
			typedef SceVoid(*OnListBackChange)(const char *elementId);
			typedef wchar_t*(*GetStringElement)(const char *elementId);
			typedef SceInt32(*IsElementVisible)(const char *elementId, SceInt32 *pIsVisible);
			typedef SceInt32(*OnValueChange)(const char *elementId, const char *newValue);
			typedef SceInt32(*OnElementInit)(const char *elementId);
			typedef SceInt32(*OnElementAdd)(const char *elementId, paf::ui::Widget *widget);
			typedef SceInt32(*GetTexture)(paf::graph::Surface **surf, const char *key);

			OnListChange listChangeCb;
			OnListForwardChange listForwardChangeCb;
			OnListBackChange listBackChangeCb;
			IsElementVisible isVisibleCb;
			OnElementInit elemInitCb;
			OnElementAdd elemAddCb;
			OnValueChange valueChangeCb;
			OnValueChange valueChangeCb2;
			Ret termCb;
			GetStringElement getStringCb;
			GetTexture getTexCb;
		};

		class Interface
		{
		public:

			SceInt32(*Show)(InterfaceCallbacks *callbacks);
			SceInt32(*unkFun_04)(SceInt32 a1, SceInt32 a2);
			SceInt32(*unkFun_08)(const char *a1);
			SceInt32(*unkFun_0C)(SceInt32 a1, SceInt32 a2);
			SceInt32(*unkFun_10)(const char *a1);
			SceInt32(*unkFun_14)(const char *a1);
			SceInt32(*unkFun_18)(const char *a1);
			SceInt32(*unkFun_1C)(const char *a1);
			SceInt32(*unkFun_20)();
			SceInt32(*unkFun_24)();
			SceInt32(*unkFun_28)(SceInt32 a1, const char *a2);
			SceInt32(*unkFun_2C)(SceInt32 a1, SceInt32 a2, SceInt32 a3);
			SceInt32(*unkFun_30)();
			SceInt32(*unkFun_34)();
			SceInt32(*unkFun_38)();
			SceInt32(*unkFun_3C)();
			SceInt32(*unkFun_40)(const char *a1);
			SceInt32(*unkFun_44)(SceInt32 a1);
		};

		class InitParam
		{
		public:

			typedef void* (*Allocate)(size_t size);
			typedef void* (*Reallocate)(void* ptr, size_t newSize);
			typedef void(*Deallocate)(void* ptr);

			paf::SharedPtr<paf::MemFile> xmlFile;
			Allocate allocCB;
			Reallocate reallocCB;
			Deallocate freeCB;
			SceInt32 safeMemoryOffset;
			SceUInt32 safeMemorySize;
		};

		static SceInt32 GetInstance(InitParam *pInitParam, AppSettings **ppAppSettingsInstance);
		//1C135375
		SceInt32 Terminate();

		SceInt32 Initialize();

		SceInt32 GetInt(const char *key, SceInt32 *pValue, SceInt32 defaultValue);

		SceInt32 SetInt(const char *key, SceInt32 value);

		SceInt32 GetString(const char *key, const char* value, SceUInt32 size, const char* defaultValue);

		SceInt32 SetString(const char *key, const char* value);

		/*int Test1();

		int Test2(const char *pKey, SceInt32 *value, SceInt32 a3);

		int Test3(const char *pKey, SceInt32 value);

		int Test4();*/

	};
}

#endif /* _VDSUITE_USER_APP_SETTINGS_H */
