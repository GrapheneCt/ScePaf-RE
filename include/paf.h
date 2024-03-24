/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_H
#define _VDSUITE_USER_PAF_H

#include <paf/paf_types.h>

/* STDC */

#include <paf/std/stdlib.h>
#include <paf/std/stdio.h>
#include <paf/std/string.h>
#include <paf/std/wchar.h>
#include <paf/std/wctype.h>
#include <paf/std/math.h>
#include <paf/std/setjmp.h>
#include <paf/std/globalheapsize.h>
#include <paf/std/__stdc__.h>

/* STDCXX */

#include <paf/std/std_bridge>
#include <paf/std/algorithm>
#include <paf/std/functional>
#include <paf/std/iosfwd>
#include <paf/std/memory>
#include <paf/std/list>
#include <paf/std/utility>
#include <paf/std/xtree>
#include <paf/std/map>
#include <paf/std/vector>
#include <paf/std/string>
#include <paf/std/stdc>

/* THREAD */

#include <paf/thread/atomic.h>
#include <paf/thread/mutex.h>
#include <paf/thread/rmutex.h>
#include <paf/thread/cond.h>
#include <paf/thread/semaphore.h>
#include <paf/thread/rwlock.h>
#include <paf/thread/callqueue.h>
#include <paf/thread/synccall.h>
#include <paf/thread/threadid.h>
#include <paf/thread/thread.h>
#include <paf/job/job.h>

/* COMMON */

#include <paf/common/halt_assert.h>
#include <paf/common/static_log.h>
#include <paf/common/static_stack.h>
#include <paf/common/enum_flag.h>
#include <paf/common/averaged_value.h>
#include <paf/common/frame_count.h>
#include <paf/common/array_func.h>
#include <paf/common/small_string.h>
#include <paf/common/shared_ptr.h>
#include <paf/common/char_encoding.h>
#include <paf/common/string_misc.h>
#include <paf/common/string_util.h>
#include <paf/common/tokenizer.h>
#include <paf/common/ref_obj.h>
#include <paf/common/call_list.h>
#include <paf/common/main_thread_call.h>
#include <paf/common/job_call_queue.h>
#include <paf/common/property_list.h>
#include <paf/common/intrusive_list.h>
#include <paf/common/transition.h>
#include <paf/common/path.h>
#include <paf/common/view.h>

/* MISC */

#include <paf/memory/allocator.h>
#include <paf/memory/heap_allocator.h>
#include <paf/buffer/buffer.h>
#include <paf/math/math.h>
#include <paf/timer/raw_timer.h>
#include <paf/timer/timer.h>
#include <paf/timer/timerlistener.h>
#include <paf/timer/timerlistenerlist.h>
#include <paf/timer/timerqueue.h>
#include <paf/rtc/rtc.h>
#include <paf/datetime/datetime.h>
#include <paf/url/url.h>
#include <paf/file/file.h>
#include <paf/file/localfile_types.h>
#include <paf/file/httpfile_types.h>
#include <paf/file/localfile_impl.h>
#include <paf/file/localfile_psp2.h>
#include <paf/file/localfile.h>
#include <paf/file/memfile.h>
#include <paf/file/httpfile.h>
#include <paf/file/bufferedfile.h>
#include <paf/dir/dir.h>
#include <paf/cache/cache_base.h>
#include <paf/cache/cache_image.h>
#include <paf/cache/cache_manager_impl.h>
#include <paf/cache/cache_manager.h>
#include <paf/module/module.h>
#include <paf/hash/sha1.h>
#include <paf/image/image_types.h>
#include <paf/image/image_region.h>
#include <paf/image/image_attribute.h>
#include <paf/image/image_array.h>
#include <paf/image/image.h>
#include <paf/inputdevice/inputdevice.h>
#include <paf/inputdevice/inputlistener.h>
#include <paf/avout/sound.h>
#include <paf/compress/compress.h>
#include <paf/compress/decompress.h>
#include <paf/system/system.h>

/* RESOURCE */

#include <paf/cxml/cxml.h>
#include <paf/versatileparam/idparam.h>
#include <paf/resource/resource_types.h>
#include <paf/resource/resource_obj.h>
#include <paf/versatileparam/resourceparam.h>
#include <paf/versatileparam/versatileparam.h>
#include <paf/versatileparam/versatileparammanager.h>

/* GRAPHICS */

#include <paf/graphics/graphics.h>
#include <paf/graphics/graphmem/graphmem.h>
#include <paf/graphics/surface/surface_pool.h>
#include <paf/graphics/surface/surface_base.h>
#include <paf/graphics/surface/surface.h>
#include <paf/graphics/surface/surface_screen.h>
#include <paf/graphics/surface/surface_display.h>
#include <paf/graphics/arl/arl_defines.h>
#include <paf/graphics/drawobj/shader.h>
#include <paf/graphics/drawobj/basic_shader.h>
#include <paf/graphics/drawobj/drawsys_predeclare.h>
#include <paf/graphics/arl/gxm/gxm_arl_frontend.h>
#include <paf/graphics/drawobj/draw_obj.h>
#include <paf/graphics/drawobj/plane_obj.h>
#include <paf/graphics/text/text_layout.h>
#include <paf/graphics/text/text_style.h>
#include <paf/graphics/text/attributed_string.h>
#include <paf/graphics/drawobj/text_obj.h>

/* WIDGET */

#include <paf/widget/types.h>
#include <paf/widget/wutil.h>
#include <paf/widget/core/environment.h>
#include <paf/widget/core/event.h>
#include <paf/widget/core/handler.h>
#include <paf/widget/core/layouter.h>
#include <paf/widget/core/uiinputlistener.h>
#include <paf/widget/core/animlistener.h>
#include <paf/widget/core/widget.h>
#include <paf/widget/w_scroll_view_base.h>
#include <paf/widget/w_button_base.h>
#include <paf/widget/w_state_button_base.h>
#include <paf/widget/w_button.h>
#include <paf/widget/w_scene.h>
#include <paf/widget/w_text.h>
#include <paf/widget/w_rich_text.h>
#include <paf/widget/w_radio_box.h>
#include <paf/widget/w_scroll_view.h>
#include <paf/widget/w_text_box.h>
#include <paf/widget/w_list_view.h>
#include <paf/widget/w_scrollbar2d.h>
#include <paf/widget/w_scrollbar.h>
#include <paf/widget/w_scrollbar_touch.h>
#include <paf/widget/w_sliding_drawer.h>
#include <paf/widget/w_image_slidebar.h>
#include <paf/widget/w_list_item.h>
#include <paf/widget/w_plane.h>
#include <paf/widget/w_box.h>
#include <paf/widget/w_radio_button.h>
#include <paf/widget/w_image_button.h>
#include <paf/widget/w_file_list.h>
#include <paf/widget/w_directbar.h>
#include <paf/widget/w_progressbar.h>
#include <paf/widget/w_progressbar_touch.h>
#include <paf/widget/w_camera.h>
#include <paf/widget/w_check_box.h>
#include <paf/widget/w_dialog.h>
#include <paf/widget/w_plane_button.h>
#include <paf/widget/w_busyindicator.h>
#include <paf/widget/w_appicon_base.h>
#include <paf/widget/w_appicon2d.h>
#include <paf/widget/w_corner_button.h>
#include <paf/widget/w_composite_button.h>
#include <paf/widget/w_composite_drawer.h>
#include <paf/widget/w_group.h>
#include <paf/widget/w_pageturn_base.h>
#include <paf/widget/w_pageturn.h>
#include <paf/widget/w_slidebar.h>
#include <paf/widget/w_supplier.h>
#include <paf/widget/factory.h>

/* AUTOTEST */

#include <paf/autotest/tty.h>

/* TOPLEVEL */

#include <paf/paf_cdlg.h>
#include <paf/plugin.h>
#include <paf/framework.h>

#endif /* _VDSUITE_USER_PAF_H */

