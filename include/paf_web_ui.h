/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WEB_UI_H
#define _VDSUITE_USER_PAF_WEB_UI_H

#include <kernel.h>
#include <paf.h>

namespace paf {

	class WebUI
	{
	public:

		//PAF plugin loader callbacks

		//SceWebUIPlugin_93C92A4A
		static SceVoid PluginCreateCB(paf::Plugin *plugin);
		//SceWebUIPlugin_07F112B1
		static SceVoid PluginInitCB(paf::Plugin *plugin);
		//SceWebUIPlugin_9CD848A2
		static SceVoid PluginStartCB(paf::Plugin *plugin);
		//SceWebUIPlugin_D480614B
		static SceVoid PluginStopCB(paf::Plugin *plugin);
		//SceWebUIPlugin_12EDFFFD
		static SceVoid PluginExitCB(paf::Plugin *plugin);
	};

}

#endif /* _VDSUITE_USER_PAF_WEB_UI_H */

