/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_WUTIL_H
#define _VDSUITE_USER_PAF_WIDGET_WUTIL_H

#include <stdint.h>
#include <paf/math/math.h>
#include <paf/graphics/graphics.h>
#include <paf/graphics/surface/surface.h>
#include <paf/inputdevice/inputdevice.h>

namespace paf {
	namespace ui {

		class TextBoxEditListener;
		class WebViewEditListener;
		class MessageDialogListener;
		class IWebViewListener;
		class Environment;
		class Handler;

		namespace wutil {

			class InitParam
			{
			public:

				InitParam();

				gutil::WinHandle whandle;
				void *default_shader_addr;
				int32_t default_shader_size;
				void *surf_dev_mem_addr;
				int32_t surf_dev_mem_size;
				void *surf_def_pool_addr;
				int32_t surf_def_pool_size;
				int32_t surf_def_pool_device_type;
				char unk_28[0x18];
				uint32_t input_device_mode;
				inputdevice::pad::DeviceHandler input_handler_pad;
				inputdevice::touchscreen::DeviceHandler input_handler_touch;
				inputdevice::touchscreen::DeviceHandler input_handler_touch_rear;
				inputdevice::motionsensor::DeviceHandler input_handler_motion_sensor;
				TextBoxEditListener *edit_listener;
				WebViewEditListener *web_edit_listener;
				MessageDialogListener *message_dialog_listener;
				int32_t unk_60;
				IWebViewListener *webview_listener;
				int32_t unk_68;

			};

			extern int32_t Init(InitParam const& param);

			extern int32_t Term();

			extern void DevTerm();

			extern void SetEnv(Environment *env);

			extern void PostTouchScreenEvent(Environment *env, int32_t type, int32_t state, int32_t x, int32_t y, int32_t z, int32_t touch_id);

			extern void PostKeycodeEvent(Environment *env, int32_t type, int32_t port, int32_t keydev, int32_t keycode, int32_t modify, int32_t repeat, int32_t mode);

			extern void PostStateEvent(Environment *env, int32_t type, Handler *tgt);

			extern TextBoxEditListener *GetEditListener();

			extern WebViewEditListener *GetWebEditListener();

			extern MessageDialogListener *GetMessageDialogListener();

			extern IWebViewListener *GetWebViewListener();

			namespace debug {

				extern int32_t Term(InitParam& param);

				extern void DevTerm();

				extern void vec4_printf(char *str, math::v4 const& data);

				extern int32_t LoadGimTexture(string const& path, intrusive_ptr<graph::Surface>& surf_ptr);

				extern int32_t LoadPngTexture(string const& path, intrusive_ptr<graph::Surface>& surf_ptr);
			}
		}
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_WUTIL_H */
