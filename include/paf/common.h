/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_H
#define _VDSUITE_USER_PAF_COMMON_H

#include <scetypes.h>
#include <sce_atomic.h>
#include <wchar.h>
#include <paf/stdc.h>
#include <paf/stdcxx/typeinfo.hpp>
#include <paf/stdcxx/memory.hpp>
#include <paf/stdcxx/iosfwd.hpp>
#include <paf/stdcxx/string.hpp>
#include <paf/stdcxx/shared_ptr.hpp>

namespace paf {

	namespace frame {

		extern SceUInt32 Get();

		extern SceVoid Reset();

		extern SceVoid Increment();
	};

	namespace effect
	{
		enum EffectType
		{
			EffectType_Reset = 0xFF,
			EffectType_Fadein1 = 0,
			EffectType_Popup1 = 1,
			EffectType_Popup2 = 2,
			EffectType_SlideFromBottom1 = 3,
			EffectType_SlideFromRight1 = 4,
			EffectType_Fadein2 = 5,
			EffectType_SlideFromTop1 = 6,
			EffectType_SlideFromTop2 = 7,
			EffectType_SlideFromBottom2 = 8,
			EffectType_SlideFromBottom3 = 9,
			EffectType_Popup3 = 0xA,
			EffectType_Popup4 = 0xB,
			EffectType_Popup5 = 0xD,
			EffectType_SlideFromTop3 = 0xE,
			EffectType_SlideFromBottom4 = 0xF,
			EffectType_SlideFromLeft1 = 0x10,
			EffectType_SlideFromRight2 = 0x11,
			EffectType_SlideFromTop4 = 0x12,
			EffectType_SlideFromBottom5 = 0x13,
			EffectType_SlideFromLeft2 = 0x14,
			EffectType_SlideFromRight3 = 0x15,
			EffectType_3D_SlideFromFront = 0x16,
			EffectType_3D_SlideToBack1 = 0x17,
			EffectType_18 = 0x18,
			EffectType_3D_SlideToBack2 = 0x19
		};

		extern SceFloat32 GetDefaultParameterValue(EffectType type);

		extern SceFloat32 GetDefaultParameterValueReverse(EffectType type, paf::ui::Widget *widget = SCE_NULL);

		extern SceFloat32 Play(SceFloat32 parameter, paf::ui::Widget *widget, EffectType effect, bool disableOnEnd, bool ignoreDefaultParameter);

		extern SceFloat32 PlayReverse(SceFloat32 parameter, paf::ui::Widget *widget, EffectType effect, bool disableOnEnd, bool ignoreDefaultParameter);
	}

	namespace task {

		typedef void(*TaskEntryFunction)(void *pArgBlock);

		extern SceVoid Register(TaskEntryFunction entry, ScePVoid pArgBlock);

		extern SceVoid Unregister(TaskEntryFunction entry, ScePVoid pArgBlock);
	}

	/*
	class MainPlugin
	{
	public:

		class Callbacks;

		class LoadArg
		{
		public:

			Callbacks *cb;
		};

		typedef void(*PluginCBWithArg)(LoadArg *arg, Plugin *plugin);
		typedef void(*PluginCB)();

		class Callbacks
		{
		public:

			SceInt32 unk_00;
			PluginCB pluginCreateCB;	//Called after plugin module is loaded and started
			PluginCB pluginInitCB;		//Called after plugin is fully initialized
			PluginCBWithArg pluginStartCB;
			PluginCB pluginStopCB;
			PluginCB pluginExitCB;
		};

		MainPlugin(paf::string *pluginName, paf::string *resourcePath, LoadArg *callbacks);

		//ScePafCommon_17280204 d1
		//ScePafCommon_ED9652F0 d0
		//ScePafCommon_8BC826E1 d2
		virtual ~MainPlugin();

		LoadArg *loadArg;

		SceInt32 unk[9];
	};
	*/

	/*
	namespace job {

		class JobCallQueue
		{
		public:

			typedef void(*JobCallQueueEntryFunction)(void *pArgBlock);

			//ScePafCommon_91CD88B3 c1
			//ScePafCommon_543B37D2 c2
			JobCallQueue(paf::string *name, paf::thread::JobQueue *queue);

			//ScePafCommon_BCD1863A d1
			//ScePafCommon_03E15726 d2
			~JobCallQueue();

			//ScePafCommon_354C389A
			SceVoid WaitEmpty();

			//ScePafCommon_B01BE5EF
			SceUInt32 GetSize();

			//ScePafCommon_FDD1CBBD
			SceVoid Enqueue(JobCallQueueEntryFunction entry, ScePVoid pArgBlock);

			//ScePafCommon_C16C2378
			SceVoid Check();

			paf::string name;
			paf::thread::JobQueue *queue;

		private:

			SceChar8 m_work[0x28];
		};
	}
	*/
}

#endif /* _VDSUITE_USER_PAF_COMMON_H */
