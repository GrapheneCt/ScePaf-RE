/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_VIEW_H
#define _VDSUITE_USER_PAF_COMMON_VIEW_H

#include <stdint.h>
#include <paf/std/string>

namespace paf {

	class Plugin;
	class InitEventFunctionEntry;
	class Url;

	namespace ui {
		class Widget;
	}

	namespace common {
		class String;
	}

	class ViewController
	{
	public:

		ViewController()
		{

		}

		virtual ~ViewController()
		{

		}

		virtual void PluginOnInit(Plugin *plugin)
		{

		}

		virtual void PluginOnStart(Plugin *plugin)
		{

		}

		virtual void PluginOnStop(Plugin *plugin)
		{

		}

		virtual void PluginOnExit(Plugin *plugin)
		{

		}
		/*
		virtual void OnStartLoad(ui::Widget *view)
		{
			sceClibPrintf(__func__);
		}

		virtual void OnFinishLoad(ui::Widget *view, int32_t unk)
		{
			sceClibPrintf(__func__);
		}

		virtual void OnReceivedError(ui::Widget *view, common::String *error_msg)
		{
			sceClibPrintf(__func__);
		}

		virtual void OnUrlChanged(ui::Widget *view, Url *url)
		{
			sceClibPrintf(__func__);
		}

		virtual void OnHistoryStackStatusChanged(ui::Widget *view, bool canBack, bool canForward)
		{
			sceClibPrintf(__func__);
		}

		virtual void OnProgressChanged(ui::Widget *view, int32_t progress)
		{
			sceClibPrintf(__func__);
		}
		*/
	};

	class View
	{
	public:

		//ScePafCommon_547491A7 c1
		//ScePafCommon_9109458C c2
		View(string const& pluginName, string const& resourcePath, ViewController *controller);

		//ScePafCommon_17280204 d1
		//ScePafCommon_ED9652F0 d0
		//ScePafCommon_8BC826E1 d2
		virtual ~View();

		//ScePafCommon_E234DA6E
		void BindWidget(Plugin *plugin, ui::Widget *widget);
	};
}

#endif /* _VDSUITE_USER_PAF_COMMON_VIEW_H */
