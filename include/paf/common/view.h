/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_VIEW_H
#define _PAF_COMMON_VIEW_H

#include <stdint.h>
#include <paf/std/stdcxx.h>

namespace paf {

	class Plugin;

	namespace ui {
		class Widget;
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
	};

	class View
	{
	public:

		View(paf::string const& pluginName, paf::string const& resourcePath, ViewController *controller);

		virtual ~View();

		void BindWidget(Plugin *plugin, ui::Widget *widget);
	};
}

#endif /* _PAF_COMMON_VIEW_H */
