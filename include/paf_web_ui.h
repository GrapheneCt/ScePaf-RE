/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WEB_UI_H
#define _VDSUITE_USER_PAF_WEB_UI_H

#include <paf.h>

namespace paf {

	class WebUI
	{
	public:

		//PAF plugin loader callbacks

		//SceWebUIPlugin_93C92A4A
		static SceVoid PluginSetParamCB(paf::Plugin::InitParam2 *param);
		//SceWebUIPlugin_07F112B1
		static SceVoid PluginInitCB(paf::Plugin *plugin);
		//SceWebUIPlugin_9CD848A2
		static SceVoid PluginStartCB(paf::Plugin *plugin);
		//SceWebUIPlugin_D480614B
		static SceVoid PluginStopCB(paf::Plugin *plugin);
		//SceWebUIPlugin_12EDFFFD
		static SceVoid PluginExitCB(paf::Plugin *plugin);

		static int32_t SceWebUIPlugin_732FD74D(void *a1, void *a2);

		static int32_t SceWebUIPlugin_C59CB476(int32_t a1, void *a2, string& a3);

		static int32_t SceWebUIPlugin_E6A8A5BC(int32_t a1, int32_t a2);

		static int32_t SceWebUIPlugin_B888A5A6(int32_t a1);
	};

}

#endif /* _VDSUITE_USER_PAF_WEB_UI_H */

