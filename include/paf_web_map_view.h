/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WEB_MAP_VIEW_H
#define _VDSUITE_USER_PAF_WEB_MAP_VIEW_H

#include <kernel.h>
#include <gxm.h>
#include <paf/widget/factory.h>
#include <paf/widget/w_scroll_view.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryWebView;

namespace paf {

	namespace ui {

		class WebView;

		class IWebViewListener
		{
		public:

			IWebViewListener();

			virtual ~IWebViewListener();

			virtual int32_t Initialize(WebView *webview) = 0;
			virtual int32_t Term(WebView *webview) = 0;
		};

		class WebViewDelegate
		{
		public:

			WebViewDelegate();

			virtual ~WebViewDelegate();

			virtual void OnStartLoad(WebView *webview);
			virtual void OnFinishLoad(WebView *webview, int32_t unk);
			virtual void OnReceivedError(WebView *webview, int32_t error_code, paf::common::String const& error_msg);
			virtual void OnStartLoadWithRequest(WebView *webview);
			virtual void OnInitializedBrowser(WebView *webview);
			virtual void OnProgressChanged(WebView *webview, int32_t progress);
			virtual void OnTitleChanged(WebView *webview, paf::common::String const& title);
			virtual void OnUrlChanged(WebView *webview, Url const& url);
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
			virtual void OnDownloadStart(int32_t unk, paf::Url const& url, paf::common::String const& content_type);
			virtual void unk_fun_21();
			virtual void unk_fun_22();
			virtual void unk_fun_23();
			virtual void historyStackStatusChanged(WebView *webview, bool canBack, bool canForward);
			virtual void unk_fun_25();
			virtual void unk_fun_26();
			virtual void unk_fun_27();
		};

		class WebViewEditListener //size is 0x8
		{
		public:

			WebViewEditListener();

			virtual ~WebViewEditListener();

			virtual int32_t f1(void *unk_1, void *unk_2) = 0;
			virtual int32_t f2(void *unk_1) = 0;
			virtual int32_t f3() = 0;
			virtual int32_t f4(char *unk_1, void *unk_2) = 0;

		protected:

			void *m_unk_04;
		};

		class WebViewParam : public WidgetParam
		{
		public:

			static const char *ParamName(void);

			WebViewParam();
			virtual const char *GetParamName(void) const;
			virtual ~WebViewParam();
			virtual int Create(int mode);
			virtual int Set(void);

		private:
			unsigned char m_unk_0x78[0x68];

			__declspec(dllimport) static const char m_param_name[];
		};

		class WebViewStyleParam : public WidgetStyleParam
		{
		public:

			static const char *ParamName(void);

			virtual const char *GetParamName(void) const;
			virtual ~WebViewStyleParam();

		private:

			__declspec(dllimport) static const char m_param_name[];
		};

		class WebView : public ScrollView //0x830
		{
		public:

			WebView(Widget *_parent, CreateParam *_param);

			~WebView();

			virtual int32_t OnStartLoad();
			virtual int32_t OnFinishLoad();
			virtual int32_t OnReceivedError(int32_t error_code, paf::common::String const& error_msg);
			virtual int32_t OnStartLoadWithRequest();
			virtual int32_t OnInitializedBrowser();
			virtual int32_t OnProgressChanged(int32_t progress);
			virtual int32_t OnTitleChanged(paf::common::String const& title);
			virtual int32_t OnUrlChanged(Url const& url);
			virtual int32_t unkFun_298();
			virtual int32_t unkFun_29C();
			virtual int32_t unkFun_300();
			virtual int32_t unkFun_304();
			virtual int32_t unkFun_308();
			virtual int32_t OnDownloadStart(int32_t unk, paf::Url const& url, paf::common::String const& content_type);
			virtual int32_t unkFun_310();
			virtual int32_t unkFun_314();
			virtual int32_t unkFun_318();
			virtual int32_t OnHistoryStackStatusChanged(bool canBack, bool canForward);
			virtual int32_t unkFun_320();
			virtual int32_t unkFun_324();
			virtual int32_t unkFun_328();
			virtual int32_t unkFun_32C();
			virtual int32_t unkFun_330();
			virtual int32_t unkFun_334();
			virtual int32_t unkFun_338();
			virtual int32_t unkFun_33C();
			virtual int32_t unkFun_340();
			virtual int32_t unkFun_344();
			virtual int32_t unkFun_348();
			virtual int32_t unkFun_34C();
			virtual int32_t unkFun_350();
			virtual int32_t unkFun_354();
			virtual int32_t unkFun_358();
			virtual int32_t unkFun_35C();
			virtual int32_t unkFun_360();
			virtual int32_t unkFun_364();
			virtual int32_t unkFun_368();
			virtual int32_t unkFun_36C();
			virtual int32_t unkFun_370();

			int32_t LoadUrl(Url const& url);

			int32_t EnableJavaScript(bool enable);

			int32_t EnableCookie(bool enable);

			int32_t GoForward();

			int32_t GoBack();

			int32_t Wakeup();

			int32_t StopLoading();

			int32_t Reload();

			int32_t SetCursorParam(intrusive_ptr<graph::Surface> *base, intrusive_ptr<graph::Surface> *base_highlight, intrusive_ptr<graph::Surface> *interact, intrusive_ptr<graph::Surface> *interact_highlight);

			int32_t ScePafWebMapView_48BF783B(int32_t a1);

			void SetDelegate(WebViewDelegate *controller)
			{
				m_delegate = controller;
			}

			WebViewDelegate *GetDelegate() const
			{
				return m_delegate;
			}

		private:

			char m_unk_440[0x18];
			WebViewDelegate *m_delegate;
			char m_unk_45C[0x3D4];

			__declspec(dllimport) static const char *m_widget_type;
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
	}

}

#endif /* _VDSUITE_USER_PAF_WEB_MAP_VIEW_H */

