#ifndef _VDSUITE_USER_COMMON_GUI_DIALOG_H
#define _VDSUITE_USER_COMMON_GUI_DIALOG_H

#include <paf.h>
#include <kernel.h>
#include <appmgr.h>

namespace sce {
	namespace CommonGuiDialog {

		class BaseHashTable;
		class ContentsHashTable;

		enum DIALOG_CB
		{
			DIALOG_CB_X = 1,
			DIALOG_CB_OK,
			DIALOG_CB_CANCEL,
			DIALOG_CB_YES,
			DIALOG_CB_NO,
			DIALOG_CB_UNK6,
			DIALOG_CB_JOINPSPLUS,
			DIALOG_CB_ABOUTPSPLUS
		};

		enum REGISTER_ID
		{
			REGISTER_ID_TEXT_MESSAGE_1 = 1,
			REGISTER_ID_TEXT_MESSAGE_2,
			REGISTER_ID_PLANE_BODY,
			REGISTER_ID_DIALOG,
			REGISTER_ID_PLANE_ICON,
			REGISTER_ID_TEXT_TITLE,
			REGISTER_ID_PLANE_TITLE,
			REGISTER_ID_PLANE_BUTTON_X,
			REGISTER_ID_SCROLL_VIEW,
			REGISTER_ID_BOX,
			REGISTER_ID_LIST_VIEW,
			REGISTER_ID_BUTTON_1,
			REGISTER_ID_BUTTON_2,
			REGISTER_ID_BUTTON_3,
			REGISTER_ID_UNK15,
			REGISTER_ID_UNK16,
			REGISTER_ID_UNK17,
			REGISTER_ID_PROGRESSBAR,
			REGISTER_ID_TEXT_PROGRESSBAR,

			REGISTER_ID_TEXT_ABOUTPSPLUS = 23
		};

		class EventCBListener
		{
		public:

			typedef void(*HandlerCB)(int32_t instance_slot, DIALOG_CB type, void *userdata);

			EventCBListener(HandlerCB func, void *data) : m_func(func), m_data(data)
			{

			}

			virtual ~EventCBListener()
			{

			}

			virtual int32_t Do(int32_t instance_slot, DIALOG_CB type)
			{
				if (m_func) {
					m_func(instance_slot, type, m_data);
				}
			}

		protected:

			HandlerCB m_func;
			void *m_data;
		};


		class Param
		{
		public:

			BaseHashTable *base_list;
			int32_t unk_04;
			ContentsHashTable *contents_list;

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

			static paf::ui::Widget *GetWidget(int32_t instanceSlot, REGISTER_ID id);

			static int32_t SetDimmerColor(int32_t instanceSlot, paf::math::v4 const& color);

			static int32_t SetTitleTextColor(int32_t instanceSlot, paf::math::v4 const& color);

			static int32_t SetDialogColor(int32_t instanceSlot, paf::math::v4 const& color);

			static int32_t SetTexture(int32_t instanceSlot, REGISTER_ID id, paf::intrusive_ptr<paf::graph::Surface> const& tex);

			static int32_t Show(paf::Plugin *workPlugin, paf::wstring *title, paf::wstring *message, Param *param, EventCBListener::HandlerCB buttonCB, ScePVoid pUserArg);

			static int32_t Show(paf::Plugin *workPlugin, paf::wstring *title, paf::wstring *message, Param *param, EventCBListener *cb);

			static int32_t Close(int32_t instanceSlot);
		};

		class CommonDialog : public Dialog
		{
		public:

			// SceCommonGuiDialog_CCFCD9A6
			int32_t Show();

			paf::Plugin *workPlugin;
			int32_t unk_04; // unused?
			paf::math::v4 color1;
			paf::math::v4 color2;
			int32_t unk_28; // default 0
			int32_t unk_2C; // default 0
			int32_t unk_30; // default -1
			int32_t unk_34; // default 0
			int32_t unk_38; // default -1
			void *unk_3C; // default SCE_NULL
			void *unk_40; // default 0x80
			bool  unk_44;
			Param param;
			paf::wstring title;
			paf::wstring message;
			int32_t unk_6C;
			paf::math::v4 color3;
			paf::ui::Widget *unk_80_widget;
			paf::graph::Surface *unk_84_surface;
			void *unk_88;
			paf::graph::Surface *unk_8C_surface;
			EventCBListener *eventHandler;
			void *unk_94_cb;
			void *unk_98_cb;
		};

		class ErrorDialog : public Dialog
		{
		public:

			ErrorDialog()
			{
				unk_48 = 0;
				faulty_app_id = SCE_APPMGR_APP_ID_THIS;
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
				has_ok_button = true;
				unk_AA = 0;

				error = 0;
				listener = NULL;
				unk_BC_cb = NULL;
			}

			~ErrorDialog() {};

			int32_t Show();

			paf::Plugin *work_plugin;
			char unk_04[0x2C];
			int32_t unk_30;
			int32_t unk_34;
			int32_t unk_38;
			int32_t unk_3C;
			int32_t unk_40;
			int32_t error;
			int32_t unk_48;
			int32_t faulty_app_id;
			int32_t unk_50;
			int32_t unk_54;
			int32_t unk_58;
			int32_t unk_5C;
			paf::wstring title;
			int32_t unk_6C;
			int32_t unk_70;
			int32_t unk_74;
			int32_t unk_78;
			paf::wstring message;
			int32_t unk_88;
			int32_t unk_8C;
			int32_t unk_90;
			int32_t unk_94;
			int32_t unk_98;
			int32_t unk_9C;
			int32_t unk_A0;
			int32_t unk_A4;
			bool unk_A8;
			bool has_ok_button;
			bool unk_AA;
			bool unk_AB;
			char unk_AC[0xC];
			EventCBListener *listener;
			EventCBListener *unk_BC_cb;
		};
	}
}

#endif /* _VDSUITE_USER_COMMON_GUI_DIALOG_H */
