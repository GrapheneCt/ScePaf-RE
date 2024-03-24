/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WEB_MAP_VIEW_H
#define _VDSUITE_USER_PAF_WEB_MAP_VIEW_H

#include <kernel.h>
#include <gxm.h>
#include <paf/common/view.h>

namespace paf {

	namespace ui {
		class WebView;
	}

	class WebViewController
	{
	public:

		//ScePafWebMapView_D2EDAB2E c2
		//ScePafWebMapView_46DA0ABA c1
		WebViewController();

		//ScePafWebMapView_A7382CB8 d1
		//ScePafWebMapView_6F5AF8DC d0
		//ScePafWebMapView_A0CFE141 d2
		~WebViewController();

		virtual void OnStartLoad(ui::WebView *view);
		virtual void OnFinishLoad(ui::WebView *view, int32_t unk);
		virtual void unk_fun_04();
		virtual void unk_fun_05();
		virtual void unk_fun_06();
		virtual void OnProgressChanged(ui::WebView *view, int32_t progress);
		virtual void OnReceivedError(ui::WebView *view, common::String *error_msg);
		virtual void OnUrlChanged(ui::WebView *view, Url *url);
		virtual void unk_fun_10();
		virtual void unk_fun_11();
		virtual void unk_fun_12();
		virtual void unk_fun_13();
		virtual void unk_fun_14();
		virtual void unk_fun_15();
		virtual void unk_fun_16();
		virtual void unk_fun_17();
		virtual void unk_fun_18();
		virtual void unk_fun_19();
		virtual void unk_fun_20();
		virtual void unk_fun_21();
		virtual void unk_fun_22();
		virtual void unk_fun_23();
		virtual void OnHistoryStackStatusChanged(ui::WebView *view, bool canBack, bool canForward);
		virtual void unk_fun_25();
		virtual void unk_fun_26();
		virtual void unk_fun_27();
	};

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

			//ScePafWebMapView_4F3F5380
			int32_t LoadUrl(Url url);

			//ScePafWebMapView_0A8125D7
			int32_t EnableJavaScript(bool enable);

			//ScePafWebMapView_AA0A053C
			int32_t EnableCookie(bool enable);

			//ScePafWebMapView_23039C08
			int32_t SetCursorParam(intrusive_ptr<graph::Surface> *base, intrusive_ptr<graph::Surface> *base_highlight, intrusive_ptr<graph::Surface> *interact, intrusive_ptr<graph::Surface> *interact_highlight);

			//ScePafWebMapView_48BF783B
			int32_t ScePafWebMapView_48BF783B(int32_t a1);

			void SetController(WebViewController *controller)
			{
				m_controller = controller;
			}

			WebViewController *GetController() const
			{
				return m_controller;
			}

		private:

			char m_unk_440[0x18];
			WebViewController *m_controller;
			char m_unk_45C[0x3D4];
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
				uint32_t viewport_width;
				uint32_t viewport_height;
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

			virtual int32_t Initialize(ui::Widget *webview) = 0;
			virtual int32_t Term(ui::Widget *webview) = 0;
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
			ui::Widget *m_webview;
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

