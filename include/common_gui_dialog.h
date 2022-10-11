#ifndef _VDSUITE_USER_COMMON_GUI_DIALOG_H
#define _VDSUITE_USER_COMMON_GUI_DIALOG_H

#include <paf.h>
#include <kernel.h>
#include <appmgr.h>

namespace sce {
	namespace CommonGuiDialog {

		class BaseHashTable;
		class ContentsHashTable;

		enum ButtonCode
		{
			ButtonCode_X = 1,
			ButtonCode_Ok,
			ButtonCode_Cancel,
			ButtonCode_Yes,
			ButtonCode_No,
			ButtonCode_Unk6,
			ButtonCode_JoinPSPlus,
			ButtonCode_AboutPSPlus
		};

		enum WidgetType
		{
			WidgetType_TextMessage1 = 1,
			WidgetType_TextMessage2,
			WidgetType_PlaneBody,
			WidgetType_Dialog,
			WidgetType_PlaneIcon,
			WidgetType_TextTitle,
			WidgetType_PlaneTitle,
			WidgetType_PlaneButtonX,
			WidgetType_Unk9,
			WidgetType_Box,
			WidgetType_ListView,
			WidgetType_Button1,
			WidgetType_Button2,
			WidgetType_Button3,
			WidgetType_Unk15,
			WidgetType_Unk16,
			WidgetType_Unk17,
			WidgetType_Progressbar,
			WidgetType_TextProgressbar,

			WidgetType_TextAboutPSPlus = 23
		};

		class EventCallback
		{
		public:

			typedef void(*EventHandler)(SceInt32 instanceSlot, ButtonCode buttonCode, ScePVoid pUserArg);

			EventCallback() : eventHandler(SCE_NULL), pUserData(SCE_NULL)
			{

			};

			virtual ~EventCallback()
			{

			};

			virtual SceInt32 HandleEvent(SceInt32 instanceSlot, ButtonCode buttonCode)
			{
				if (eventHandler) {
					eventHandler(instanceSlot, buttonCode, pUserData);
				}
			};

			EventHandler eventHandler;
			ScePVoid pUserData;

		};

		class Param
		{
		public:

			BaseHashTable *baseList;
			SceInt32 unk_04;
			ContentsHashTable *contentsList;

			static Param s_dialogOk;
			static Param s_dialogCancel;
			static Param s_dialogYesNo;
			static Param s_dialogYesNoVertical;
			static Param s_dialogYesNoCancel;
			static Param s_dialogOkCancel;
			static Param s_dialogCancelProgress;
			static Param s_dialogCancelLProgress;
			static Param s_dialogCancelText2LProgress;
			static Param s_dialogCancelUnk1;
			static Param s_dialogProgress;
			static Param s_dialogText;
			static Param s_dialogTextSmall;
			static Param s_dialogXView;
			static Param s_dialogOkView;
			static Param s_dialogYesNoView;
			static Param s_dialogXLView;
			static Param s_dialogOkLView;
			static Param s_dialogTextSmallBusy;
			static Param s_dialogCancelBusy;
			static Param s_dialogOkIcon;
			static Param s_dialogOkCancelIcon;
			static Param s_dialogFullscreen;
			static Param s_dialogOkFullscreen;
			static Param s_dialogOkTextbox;
			static Param s_dialogPlusInvitation;
		};

		class Dialog
		{
		public:

			Dialog();

			~Dialog() {};

			static paf::ui::Widget *GetWidget(SceInt32 instanceSlot, WidgetType type);

			static SceInt32 SetDimmerColor(SceInt32 instanceSlot, paf::Rgba *color);

			static SceInt32 SetTitleTextColor(SceInt32 instanceSlot, paf::Rgba *color);

			static SceInt32 SetDialogColor(SceInt32 instanceSlot, paf::Rgba *color);

			static SceInt32 SetTexture(SceInt32 instanceSlot, WidgetType type, paf::graph::Surface **tex);

			static SceInt32 Show(paf::Plugin *workPlugin, paf::wstring *title, paf::wstring *message, Param *param, EventCallback::EventHandler buttonCB, ScePVoid pUserArg);

			static SceInt32 Show(paf::Plugin *workPlugin, paf::wstring *title, paf::wstring *message, Param *param, EventCallback *cb);

			static SceInt32 Close(SceInt32 instanceSlot);
		};

		class CommonDialog : public Dialog
		{
		public:

			// SceCommonGuiDialog_CCFCD9A6
			SceInt32 Show();

			paf::Plugin *workPlugin;
			SceInt32 unk_04; // unused?
			paf::Rgba color1;
			paf::Rgba color2;
			SceInt32 unk_28; // default 0
			SceInt32 unk_2C; // default 0
			SceInt32 unk_30; // default -1
			SceInt32 unk_34; // default 0
			SceInt32 unk_38; // default -1
			ScePVoid unk_3C; // default SCE_NULL
			ScePVoid unk_40; // default 0x80
			SceBool  unk_44;
			Param    param;
			paf::wstring title;
			paf::wstring message;
			SceInt32 unk_6C;
			paf::Rgba color3;
			paf::ui::Widget *unk_80_widget;
			paf::graph::Surface *unk_84_surface;
			ScePVoid unk_88;
			paf::graph::Surface *unk_8C_surface;
			EventCallback *eventHandler;
			ScePVoid unk_94_cb;
			ScePVoid unk_98_cb;
		};

		class ErrorDialog : public Dialog
		{
		public:

			ErrorDialog()
			{
				unk_48 = 0;
				faultyAppId = SCE_APPMGR_APP_ID_THIS;
				unk_50 = 2;
				unk_54 = 2;
				unk_58 = 2;
				unk_5C = 0;
				unk_6C = 0;
				unk_70 = 0;
				unk_74 = 0;
				unk_88 = 0;
				unk_8C = 0;
				unk_90 = 0;
				unk_98 = 0;
				unk_9C = 0;
				unk_A0 = 0;
				unk_A8 = 0;
				hasOkButton = 1;
				unk_AA = 0;

				errorCode = 0;
				eventHandler = SCE_NULL;
				unk_BC_cb = SCE_NULL;
			}

			~ErrorDialog() {};

			SceInt32 Show();

			paf::Plugin *workPlugin;
			SceUChar8 unk_04[0x2C];
			SceInt32 unk_30;
			SceInt32 unk_34;
			SceInt32 unk_38;
			SceInt32 unk_3C;
			SceInt32 unk_40;
			SceInt32 errorCode;
			SceInt32 unk_48;
			SceInt32 faultyAppId;
			SceInt32 unk_50;
			SceInt32 unk_54;
			SceInt32 unk_58;
			SceInt32 unk_5C;
			paf::wstring title;
			SceInt32 unk_6C;
			SceInt32 unk_70;
			SceInt32 unk_74;
			SceInt32 unk_78;
			paf::wstring message;
			SceInt32 unk_88;
			SceInt32 unk_8C;
			SceInt32 unk_90;
			SceInt32 unk_94;
			SceInt32 unk_98;
			SceInt32 unk_9C;
			SceInt32 unk_A0;
			SceInt32 unk_A4;
			SceByte unk_A8;
			SceByte hasOkButton;
			SceByte unk_AA;
			SceByte unk_AB;
			SceUChar8 unk_AC[0xC];
			EventCallback *eventHandler;
			EventCallback *unk_BC_cb;
		};
	}
}

#endif /* _VDSUITE_USER_COMMON_GUI_DIALOG_H */
