/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_TEXT_BOX_H
#define _VDSUITE_USER_PAF_WIDGET_W_TEXT_BOX_H

#include <paf/widget/factory.h>
#include <paf/widget/w_text.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryTextBox;

extern "C"
{
	struct SceImeVshEvent;
}

namespace paf {

	namespace ui {

		class ScrollBar;
		class TextBoxEditListener;
		
		class ImeParam
		{
		public:

			uint64_t supportedLanguages;
			int32_t languagesForced;
			int32_t type;
			int32_t option;
			int32_t(*filter)(wchar_t);
		};

		class TextBox : public Text
		{
		public:

			//TODO: bad values, recheck
			/*
			enum
			{
				CB_TEXT_BOX_EDIT_BEGIN = 0x10000003,
				CB_TEXT_BOX_EDIT_END = 0x10000004,
				CB_TEXT_BOX_IME_OPENED = 0x10000005,
				CB_TEXT_BOX_ENTER_PRESSED = 0x10000006,
				CB_TEXT_BOX_STRING_CHANGED = 0x10000007,
				CB_TEXT_BOX_CARET_UP = 0x10000008,
				CB_TEXT_BOX_CARET_DOWN = 0x10000009,
				CB_TEXT_BOX_CARET_LEFT = 0x1000000A,
				CB_TEXT_BOX_CARET_RIGHT = 0x1000000B,
				CB_TEXT_BOX_CARET_POS_CHANGED = 0x1000000C,
				CB_TEXT_BOX_END = 0x1000000D
			};
			*/

			enum
			{
				CB_TEXT_BOX_ENTER_PRESSED = 0x1000000B,
			};

			static const char *TypeName();

			TextBox(Widget *_parent, CreateParam *_param);

			virtual ~TextBox();

			int32_t SetCaretAlpha(float alpha);

			int32_t SetCaretBlink();
			int32_t SetCaretScroll();

			int32_t KillCaretScroll();
			int32_t KillCaretBlink();

			int32_t DetachHScrollBar();
			int32_t DetachVScrollBar();

			int32_t AttachHScrollBar(ScrollBar *pScrollBar);
			int32_t AttachVScrollBar(ScrollBar *pScrollBar);

			int32_t SetMaxLength(uint32_t len);
			int32_t GetMaxLength(uint32_t& lenOut);

			int32_t SetPasswordMode(bool mode);
			int32_t GetPasswordMode(bool& modeOut);

			int32_t SetEditMode(bool mode);
			int32_t GetEditMode(bool& modeOut);

			int32_t SetEditAutoTransitionMode(bool mode);
			int32_t GetEditAutoTransitionMode(bool& modeOut);

			int32_t SetEditListener(TextBoxEditListener *pListener);
			int32_t GetEditListener(TextBoxEditListener*& pListenerOut);

			int32_t SetImeParam(ImeParam const& param);
			int32_t GetImeParam(ImeParam& paramOut);

			int32_t BeginEdit();
			int32_t EndEdit();
			bool IsEditing();

		protected: //0x328

			ScrollBar *m_pHScrollBar;
			ScrollBar *m_pVScrollBar;
			uint32_t m_maxLen;
			char m_unk_2E3[0x44];

			static void OnVScrollBarChanged(int32_t type, Handler *self, Event *e, void *usrdata);
			static void OnHScrollBarChanged(int32_t type, Handler *self, Event *e, void *usrdata);
			static void OnCaretScrollPos(Timer *timer, AnimListener *anim, void *data1, void *data2, void *data3);
			static void OnCaretBlinkFadeIn(Timer *timer, AnimListener *anim, void *data1, void *data2, void *data3);
			static void OnCaretBlinkFadeOut(Timer *timer, AnimListener *anim, void *data1, void *data2, void *data3);

			__declspec(dllimport) static const char *m_widget_type;
			__declspec(dllimport) static const float c_caretWidth;
		};

		class TextBoxEditListener
		{
		public:

			TextBoxEditListener();

			virtual ~TextBoxEditListener();

			virtual int32_t BeginEdit(TextBox *pTextBox) = 0;
			virtual int32_t EndEdit(TextBox *pTextBox) = 0;
			virtual int32_t Update(TextBox *pTextBox) = 0;
			virtual int32_t NotifyCaretMove(TextBox *pTextBox) = 0;
			virtual int32_t HandleImeEvent(SceImeVshEvent *e) = 0;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_TEXT_BOX_H */