/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WEB_MAP_VIEW_H
#define _VDSUITE_USER_PAF_WEB_MAP_VIEW_H

#include <kernel.h>
#include <gxm.h>

namespace paf {

	namespace ui {

		class WebView : public ScrollView //0x830
		{
			//ScePafWebMapView_28D5A209 c1
			//ScePafWebMapView_37E2F9BD c2
			WebView();

			//DD15B10B d1
			//8A929D79 d0
			//316A5F32 d2
			~WebView();
		};
	}

	namespace webview {

		extern int32_t ScePafWebMapView_B8CFECAE(void *a1, paf::common::String& s1, paf::common::String& s2);

		class Context
		{
		public:

			class GraphicsParam
			{
			public:

				SceGxmContext *gxm_ctx;
				uint32_t width;
				uint32_t height;
			};

			//ScePafWebMapView_5E7D0BE7
			static void Initialize();

			//ScePafWebMapView_DE7C5CBE
			static int32_t Create(const char *name, uint32_t graphicsHeapSize, SceKernelMemBlockType graphicsHeapMemblockType, uint32_t a4, uint32_t a5);

			//ScePafWebMapView_C2581D7F
			static Context *Get();

			//ScePafWebMapView_EE99BD02
			static void SetGraphicsParam(GraphicsParam *param);

			//ScePafWebMapView_6E0719FB
			void InitGraphics();

			//ScePafWebMapView_273F200C
			void InitIPC();

		private:

			Context();

			~Context();
		};


		class ViewListener //size is 0x1C
		{
		public:

			enum
			{
				WEBCORE_FULL = 0,
				WEBCORE_MINI = 1,
			};

			// ScePafWebMapView_794A8DD2 c1
			// ScePafWebMapView_6CA6CFC0 c2
			ViewListener();

			// ScePafWebMapView_6CA6CFC0 d1
			// ScePafWebMapView_74B967D9 d0
			// ScePafWebMapView_36FCBE5F d2
			virtual ~ViewListener();

			virtual int32_t Initialize(int32_t *webview) = 0;
			virtual int32_t Term(int32_t *webview) = 0;
			virtual bool Get_0D() = 0;
			virtual bool IsGameAppAndMiniWebCore() = 0;
			virtual int32_t UnloadWebCore(int32_t type) = 0;
			virtual int32_t UnloadWebCore() = 0;

			void SetWebCorePID(SceUID pid)
			{
				m_webcorePID = pid;
			}

		protected:

			int32_t m_reserved;
			int32_t m_unk_08;
			bool m_isInitialized;
			bool m_unk_0D;
			bool m_unk_0E;
			bool m_isMiniCore;
			bool m_unk_10;
			SceUID m_webcorePID;
			int32_t *m_webview;
		};

		class EditListener //size is 0x8
		{
		public:

			// ScePafWebMapView_CA377603 c1
			// ScePafWebMapView_7B01B9F2 c2
			EditListener();

			// ScePafWebMapView_6AB2C061 d1
			// ScePafWebMapView_B3EDD645 d0
			// ScePafWebMapView_3BCB03B2 d2
			virtual ~EditListener();

			virtual int32_t f1(void *unk_1, void *unk_2) = 0;
			virtual int32_t f2(void *unk_1) = 0;
			virtual int32_t f3() = 0;
			virtual int32_t f4(char *unk_1, void *unk_2) = 0;

		protected:

			void *m_unk_04;
		};
	}

}

#endif /* _VDSUITE_USER_PAF_WEB_MAP_VIEW_H */

