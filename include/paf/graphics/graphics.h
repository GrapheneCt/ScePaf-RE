/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_GRAPHICS_H
#define _VDSUITE_USER_PAF_GRAPHICS_GRAPHICS_H

#include <stdint.h>

typedef enum FrameBufferMode {
    FrameBuffer_Normal=0,
    FrameBuffer_Shared_Create=1,
    FrameBuffer_Shared_Share=2,
    FrameBuffer_Shared_OffScreen=3,
    FrameBuffer_Given=4
} FrameBufferMode;

typedef enum ParameterBufferLocation {
    ParameterBuffer_CDRAM=0,
    ParameterBuffer_LPDDR=1
} ParameterBufferLocation;

namespace paf {

	namespace graph {

		class Shader;
		class SurfacePool;
	}

	namespace gutil {

		class WinHandle
		{
		public:

			int32_t width;
			int32_t height;
			void *callback;
		};

		class DevInitParam
		{
		public:

			WinHandle whandle;
			uint32_t frame_buffer_mode;
			uint32_t graph_heap_size_on_main_memory;
			uint32_t graph_heap_size_on_video_memory;
			uint32_t display_list_size;
			uint32_t parameter_buffer_size;
			uint32_t parameter_buffer_location;
		};

		class InitParam
		{
		public:

			void *surf_dev_mem_addr;
			int32_t surf_dev_mem_size;
			void *surf_def_pool_addr;
			int32_t surf_def_pool_size;
			void *text_pool_addr;
			int32_t text_pool_size;
			int32_t text_thread_priority;
			int32_t pvf_heap_size;
			void *pvf_japanese_addr;
			uint32_t pvf_japanese_size;
			void *pvf_latin_addr;
			uint32_t pvf_latin_size;
			void *pvf_hangul_addr;
			uint32_t pvf_hangul_size;
			void *pvf_chinese_addr;
			uint32_t pvf_chinese_size;
			int32_t screen_width;
			int32_t screen_height;
		};

		extern void DevTerm();

		extern common::SharedPtr<graph::Shader> *GetDefaultShader();

		extern graph::SurfacePool *GetDefaultSurfacePool();

		extern int32_t Swap(WinHandle whandle);

		extern void Term();

		namespace debug {

			typedef void(*DebugGuiFunc)(void*);

			extern void DevTerm();

			extern void Term(InitParam& param);

			extern InitParam Init(int32_t w, int32_t h);

			extern void AddDebugGuiFunc(DebugGuiFunc func, void *user_data);

			extern void RemoveDebugGuiFunc(DebugGuiFunc func, void *user_data);

			extern void RemoveDebugGuiFuncs(DebugGuiFunc func);

			extern void CallDebugGuiFuncs();

			extern WinHandle InitWindow(int32_t width, int32_t height, void *callback);

			extern DevInitParam DevInit(int32_t w, int32_t h, void *callback);

			extern void WaitDummyVSync();
		}
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_GRAPHICS_H */