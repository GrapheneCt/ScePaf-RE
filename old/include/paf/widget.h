/*
	Vita Development Suite Libraries git-9c2c72f1
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_H
#define _VDSUITE_USER_PAF_WIDGET_H

#include <ctrl.h>
#include <scetypes.h>

namespace paf {

	namespace ui {

		typedef void(*OnAnimationEvent)(Timer *timer, ScePVoid anim, Widget *widget, ScePVoid userArg);

		enum LoopEffect
		{
			LoopEffect_None = 0,
			LoopEffect_1,
			LoopEffect_2,
			LoopEffect_3,
			LoopEffect_4,
			LoopEffect_5,
			LoopEffect_6,
			LoopEffect_7,
			LoopEffect_Paceholder = 0xff,
		};

		enum EventCtrl
		{
			EventCtrl_ButtonPress = 0x10001,
			EventCtrl_ButtonRelease = 0x10002,
			EventCtrl_ButtonHold = 0x10003
		};

		enum EventFocus
		{
			EventFocus_On = 0x40001,
			EventFocus_Off = 0x40002
		};

		enum EventRender
		{
			EventRender_RenderStateReady = 0x100004
		};

		enum EventMain
		{
			EventMain_Tapped = 0x10000003,
			EventMain_EditBegin = 0x10000005,
			EventMain_EditEnd = 0x10000006,
			EventMain_LongDecide = 0x10000007,
			EventMain_Decide = 0x10000008,
			EventMain_UpdateParam = 0x10000009
		};

		enum EventSystem
		{
			EventSystem_UpdateSize = 0x80004,
			EventSystem_Destroy = 0x20080000,
		};

		enum FocusDirection
		{
			FocusDirection_Up,
			FocusDirection_Down,
			FocusDirection_Left,
			FocusDirection_Right,
		};

		enum Anchor
		{
			Anchor_None = 0,
			Anchor_Left = 1,
			Anchor_Right = 2,
			Anchor_Bottom = 1,
			Anchor_Top = 2,
		};

		enum Align
		{
			Align_None = 0,
			Align_Left = 1,
			Align_Right = 2,
			Align_Bottom = 1,
			Align_Top = 2,
		};

		enum Adjust
		{
			Adjust_None = 0,
			Adjust_ByParent = 1,
			Adjust_ByChild = 2,
		};

		enum Origin
		{
			Origin_None = 0,
			Origin_Left = 1,
			Origin_Right = 2,
			Origin_Bottom = 1,
			Origin_Top = 2,
		};

		enum GraphicsState
		{
			GraphicsState_Normal,
			GraphicsState_Disabled,
			GraphicsState_DebugHighlightAndMove,
			GraphicsState_DebugHighlight,
			GraphicsState_DebugHighlightWithInput,
			GraphicsState_Unk5,
			GraphicsState_DebugHighlightRuler
		};

		class EventCallback : public paf::autotest::EventCallback
		{

		};

		class Context
		{
		public:

			class Option
			{
			public:

				enum Flag
				{
					Flag_None,
					Flag_ResolutionDefault = 1,
					Flag_ResolutionHalfHd = 2,
					Flag_ResolutionFullHd = 4,

					Flag_OrientationLandscapeDown = 0x1000000,
					Flag_OrientationPortraitRight = 0x2000000,
					Flag_OrientationLandscapeUp = 0x4000000,
					Flag_OrientationPortraitLeft = 0x8000000,
				};

				Option(SceUInt32 flags);

				virtual ~Option();

				virtual int unkFun_08(SceInt32 width, SceInt32 height, SceInt32 mode);
				virtual int unkFun_0C(SceInt32 mode1, SceInt32 mode2);

			private:

				SceUChar8 m_work[0x10];
			};

			//393F0EF0 c1
			//038B47A4 c2
			Context(Option *opt);

			//B01FAD50 d1
			//C79BAF2C d0
			virtual ~Context();

			SceInt32 SetResolution(SceUInt16 width, SceUInt16 height);

		private:

			SceUChar8 m_work[0x2D9C];
		};

		class CopyPaste
		{
		public:

			virtual ~CopyPaste();

			virtual int Open(Widget *targetWidget);
			virtual int Close(Widget *targetWidget);
			virtual int unkFun_10(Widget *targetWidget, paf::Vector4 *arg);
			virtual int unkFun_14(Widget *targetWidget);
			virtual int unkFun_1C(Widget *targetWidget);

		private:

			SceUChar8 work[0x34];
		};

		class Event
		{
		public:

			Event(SceInt32 a1, SceInt32 a2, SceInt32 a3, SceInt32 a4, SceInt32 a5, SceInt32 a6, SceInt32 a7, SceInt32 a8);

			virtual ~Event();

		private:

			SceChar8 m_work[0x20];
		};

		class Widget
		{
		public:

			Widget(Widget *parent, SceInt32 a2);

			virtual ~Widget();

			//109 virtual functions
			virtual int unkFun_008(SceInt32);
			virtual int unkFun_00C(SceInt32);
			virtual int unkFun_010(SceInt32);
			virtual int unkFun_014(SceInt32);
			virtual int unkFun_018(SceInt32);
			virtual int unkFun_01C(SceInt32);
			virtual int unkFun_020(SceInt32);
			virtual int unkFun_024(SceInt32);
			virtual int unkFun_028(SceInt32);
			virtual int unkFun_02C(SceInt32);
			virtual int unkFun_030();
			virtual int unkFun_034();
			virtual int unkFun_038();
			virtual int unkFun_03C();
			virtual int unkFun_040(SceInt32);
			virtual int unkFun_044(SceInt32);
			virtual int unkFun_048(SceInt32, SceInt32);
			virtual SceVoid SetFocusEnable(bool enable);
			virtual int unkFun_050(SceInt32);
			virtual int unkFun_054();
			virtual SceVoid SetTouchEnable(bool enable);
			virtual bool GetTouchEnable();
			virtual SceInt32 SendEvent(SceUInt32 eventId, Event *event);
			virtual bool equal(const char *pTypeName);
			virtual const char *name();
			virtual int unkFun_06C();
			virtual int unkFun_070();
			virtual int unkFun_074(SceInt32, SceInt32);
			virtual int unkFun_078();
			virtual int unkFun_07C();
			virtual int unkFun_080();
			virtual int unkFun_084();
			virtual int unkFun_088();
			virtual int unkFun_08C();
			virtual int unkFun_090_effect(SceFloat32 a1, SceInt32 animationCode, bool setSomeFloat);
			virtual int unkFun_094_effectRev(SceFloat32 a1, SceInt32 animationCode, bool setSomeFloat);
			virtual SceInt32 SetColor(const Rgba *pColor);
			virtual int unkFun_09C();
			virtual int unkFun_0A0();
			virtual int unkFun_0A4();
			virtual int unkFun_0A8();
			virtual int unkFun_0AC();
			virtual int unkFun_0B0();
			virtual int unkFun_0B4();
			virtual int unkFun_0B8();
			virtual int unkFun_0BC();
			virtual int unkFun_0C0();
			virtual int unkFun_0C4();
			virtual SceInt32 SetOrigin(Origin x, Origin y, Origin z, SceInt32 a4 = 0);
			virtual int unkFun_0CC();
			virtual int unkFun_0D0();
			virtual SceInt32 SetAnchor(Anchor x, Anchor y, Anchor z, SceInt32 a4 = 0);
			virtual int unkFun_0D8();
			virtual int unkFun_0DC();
			virtual int unkFun_0E0();
			virtual int unkFun_0E4();
			virtual int unkFun_0E8();
			virtual int unkFun_0EC();
			virtual int unkFun_0F0();
			virtual int unkFun_0F4();
			virtual graph::DrawObj *GetDrawObj(SceInt32 objNum = 0);
			virtual int SetSurface(paf::graph::Surface **surf, SceInt32 objNum, SceInt32 texNum = 0);
			virtual int SetSurfaceBase(paf::graph::Surface **surf);
			virtual int GetSurface(paf::graph::Surface **surf, SceInt32 objNum, SceInt32 texNum = 0);
			virtual int GetSurfaceBase(paf::graph::Surface **surf);
			virtual int unkFun_10C();
			virtual int unkFun_110();
			virtual int unkFun_114();
			virtual SceInt32 SetLabelWithFlag(paf::wstring *text, SceInt32 flag);
			virtual SceInt32 SetLabel(paf::wstring *text);
			virtual SceInt32 GetLabelWithFlag(paf::wstring *text, SceInt32 flag);
			virtual SceInt32 GetLabel(paf::wstring *text);
			virtual int unkFun_128();
			virtual int unkFun_12C();
			virtual int unkFun_130(SceInt32);
			virtual int unkFun_134(SceInt32);
			virtual SceInt32 SetFocusDirectionId(FocusDirection directionType, paf::string *id);
			virtual int unkFun_13C();
			virtual SceInt32 SetFocusSearchRectangle(paf::Vector4 *rect);
			virtual int unkFun_144();
			virtual int unkFun_148();
			virtual int unkFun_14C();
			virtual int unkFun_150();
			virtual int unkFun_154();
			virtual int unkFun_158();
			virtual int unkFun_15C();
			virtual int unkFun_160();
			virtual int unkFun_164();
			virtual int unkFun_168();
			virtual int unkFun_16C();
			virtual int unkFun_170(SceUInt32 eventId, bool a2);
			virtual int unkFun_174(SceInt32 a1);
			virtual int unkFun_178(SceInt32 a1);
			virtual int unkFun_17C();
			virtual int unkFun_180();
			virtual int unkFun_184();
			virtual int unkFun_188();
			virtual int unkFun_18C();
			virtual int unkFun_190();
			virtual int unkFun_194(SceFloat32 a1, SceFVector4 *a2, SceInt32 a3, SceInt32 a4, SceInt32 a5);
			virtual int unkFun_198();
			virtual int unkFun_19C();
			virtual int unkFun_1A0();
			virtual int unkFun_1A4();
			virtual int unkFun_1A8();

			//ScePafWidget_1EE9D37E
			//static CopyPaste *GetCopyPasteObj();

			//ScePafWidget_BFF4C5A2
			//static ScePVoid GetCopyPasteTextBoxObj();

			Widget *GetChild(paf::rco::Element *widgetInfo, SceUInt32 param); //param can be 0,1,2

			Widget *GetChild(SceUInt32 childNum);

			Widget *GetParent();

			static SceVoid GetPosition(paf::Vector4 *pos, Widget *w, SceInt32 a1, Widget *a2);

			paf::Vector4 GetPosition(SceInt32 a1 = 0, Widget *a2 = SCE_NULL)
			{
				paf::Vector4 ret;
				GetPosition(&ret, this, a1, a2);
				return ret;
			}

			paf::Vector4 *GetSize(SceInt32 a1 = 0);

			SceInt32 SetPosition(
				const paf::Vector4& position,
				Timer *timer = SCE_NULL,
				SceUInt32 type = 0x10000,
				SceFloat32 inOutTime = 0.0f,
				SceInt32 inOutType = 0,
				OnAnimationEvent onComplete = SCE_NULL,
				ScePVoid userArg = SCE_NULL);

			SceInt32 SetColor(
				const paf::Rgba& color,
				Timer *timer = SCE_NULL,
				SceUInt32 type = 0x10001,
				SceFloat32 inOutTime = 0.0f,
				SceInt32 inOutType = 0,
				OnAnimationEvent onComplete = SCE_NULL,
				ScePVoid userArg = SCE_NULL);
			
			//TODO: 0x10002

			SceInt32 SetFadeout(
				SceFloat32 value,
				Timer *timer = SCE_NULL,
				SceUInt32 type = 0x10003,
				SceFloat32 inOutTime = 0.0f,
				SceInt32 inOutType = 0,
				OnAnimationEvent onComplete = SCE_NULL,
				ScePVoid userArg = SCE_NULL);

			SceInt32 SetSize(
				const paf::Vector4& size,
				Timer *timer = SCE_NULL,
				SceUInt32 type = 0x10004,
				SceFloat32 inOutTime = 0.0f,
				SceInt32 inOutType = 0,
				OnAnimationEvent onComplete = SCE_NULL,
				ScePVoid userArg = SCE_NULL);

			SceInt32 SetZoom(
				const paf::Vector4& zoom,
				Timer *timer = SCE_NULL,
				SceUInt32 type = 0x10005,
				SceFloat32 inOutTime = 0.0f,
				SceInt32 inOutType = 0,
				OnAnimationEvent onComplete = SCE_NULL,
				ScePVoid userArg = SCE_NULL);

			SceInt32 SetRotation(
				const paf::Vector4& rot,
				SceInt32 unused = 0,
				Timer *timer = SCE_NULL,
				SceUInt32 type = 0x10006,
				SceFloat32 inOutTime = 0.0f,
				SceInt32 inOutType = 0,
				OnAnimationEvent onComplete = SCE_NULL,
				ScePVoid userArg = SCE_NULL);

			SceInt32 SetAdjust(SceUInt32 x, SceUInt32 y, SceUInt32 z);

			SceInt32 SetAlign(Align x, Align y, Align z, SceInt32 a4 = 0);

			SceVoid SetGraphicsState(SceInt32 state);

			SceVoid SetOrientation();

			SceInt32 RegisterEventCallback(SceInt32 eventId, EventCallback *cb, bool a3 = false);

			SceInt32 UnregisterEventCallback(SceInt32 eventId, SceInt32 a2, SceInt32 a3);

			SceInt32 RegisterFwEventCallback(SceInt32 eventId, EventCallback *cb);

			SceInt32 UnregisterFwEventCallback(SceInt32 eventId);

			SceInt32 SetDirectKey(SceUInt32 buttons);

			SceVoid Disable(bool a1);

			SceVoid Enable(bool a1);

			SceVoid SetLimitedFpsMode(bool enable);

			SceInt32 SetLoopEffect(LoopEffect effId, SceInt32 a2);

			SceInt32 PlayEffect(SceFloat32 parameter, paf::effect::EffectType animId, EventCallback::EventHandler animCB = 0, ScePVoid pUserData = SCE_NULL);

			SceInt32 PlayEffectReverse(SceFloat32 parameter, paf::effect::EffectType animId, EventCallback::EventHandler animCB = 0, ScePVoid pUserData = SCE_NULL);

			SceVoid SendEvent(SceUInt32 eventId, SceInt32 a2 = 0, SceInt32 a3 = 0, SceInt32 a4 = 0, SceInt32 a5 = 0);

			SceInt32 SetCtrlInternal(SceInt32 a1);

			static SceVoid SetControlFlags(paf::ui::Widget *widget, SceUInt32 flags)
			{
				unsigned char bVar1;
				int iVar2;
				int iVar3;
				int param_1 = (int)widget;

				bVar1 = *(unsigned char *)(param_1 + 0x194);
				if (((flags & 0xff) == 0) && ((int)(char)bVar1 << 0x1b < 0)) {
					ui::Widget *widg = (ui::Widget *)param_1;
					widg->SetCtrlInternal(1);
					bVar1 = *(unsigned char *)(param_1 + 0x194);
				}
				iVar2 = *(int *)(param_1 + 0x170);
				*(unsigned char *)(param_1 + 0x194) = bVar1 & 0xef | (unsigned char)(flags << 4) & 0x10;
				iVar3 = 0;
				if (iVar2 != 0) {
					iVar3 = *(int *)(iVar2 + 4);
				}
				if (iVar3 != iVar2) {
					do {
						SetControlFlags(*(paf::ui::Widget **)(iVar3 + 8), flags & 0xff);
						if (iVar3 != 0) {
							iVar3 = *(int *)(iVar3 + 4);
						}
					} while (iVar3 != *(int *)(param_1 + 0x170));
				}
			}

			//84BE12BE
			static SceInt32 CreateSurface(paf::string *file, paf::graph::Surface **res);

		public:

			SceUChar8 unk_004[0x13C];
			rco::Element elem;
			SceInt32 unk_150;
			SceInt32 unk_154;
			SceInt32 unk_158;
			SceInt32 unk_15C;
			SceInt32 unk_160;
			SceInt32 unk_164;
			ui::Widget *parent;
			SceInt32 unk_16C;
			SceInt32 unk_170;
			SceUInt32 childNum;
			SceUChar8 unk_178[0x1E];
			SceUInt8 animationStatus;
			SceUChar8 unk_197[0x15];
			SceFloat32 alpha;
			SceUInt32 color;
			SceUChar8 unk_1B4[0xAC];
			SceUInt32 adjust;
			SceUChar8 unk_264[0x1C];
		};

		class BusyIndicator : public Widget
		{
		public:

			BusyIndicator(Widget *parent, SceInt32 a2);

			virtual ~BusyIndicator();

			SceVoid Start();

			SceVoid Stop();

			SceVoid SetBallSize(SceFloat32 size);

		private:

			SceUChar8 unk_280[0x28];
		};

		class Text : public Widget //0x2d4
		{
		public:

			enum FontType
			{
				FontType_Text = 0
			};

			enum CharacterType
			{
				CharacterType_Text = 1
			};

			enum ColorType
			{
				ColorType_Text = 2,
				ColorType_TextShadow,
				ColorType_Background,
				ColorType_Unk5,
				ColorType_Unk6
			};

			enum CapFlag
			{
				CapFlag_CopyMode = 1,
				CapFlag_TextScroll = 2,
				CapFlag_PasteMode = 4,
				CapFlag_EditMode = 8
			};

			enum Option
			{
				Option_Bold = 0x7,
				Option_Shadow = 0xC,
				Option_ExternalLine = 0xD
			};

			enum FontId
			{
				FontId_0,
				FontId_1,
				FontId_2,
				FontId_3,
				FontId_4,
				FontId_5,
				FontId_6,
				FontId_7,
				FontId_8,
				FontId_9
			};

			class CharacterSize
			{
			public:

				CharacterSize() : width(0.0), height(0.0)
				{

				};

				CharacterSize(SceFloat32 width, SceFloat32 height) : width(width), height(height)
				{

				};

				~CharacterSize() { };

				SceFloat32 width;
				SceFloat32 height;
			};


			Text(Widget *parent, SceInt32 a2);

			virtual ~Text();

			SceInt32 SetColor(ColorType type, SceInt32 pos, SceInt32 len, const paf::Rgba *pColor);

			SceInt32 SetCharacterSize(CharacterType type, SceInt32 pos, SceInt32 len, const CharacterSize *pSize);

			SceInt32 SetFont(FontType type, SceInt32 pos, SceInt32 len, FontId fontId);

			SceInt32 SetOption(Option option, SceInt32 pos, SceInt32 len, bool enable);

			SceInt32 SetFontSize(SceFloat32 size, SceInt32 a2, SceSize pos, SceSize len);

			paf::Rgba GetColor(ColorType type, SceInt32 pos);

		public:

			graph::TextObj *textObj;

			SceUChar8 unk_284[0x4];

			SceByte capFlags;

			SceUChar8 unk_289[0x3];

			paf::Rgba *pDisabledColor;

			SceUInt32 unk_290;

			SceUChar8 unk_294[0x1];

			SceUInt32 unk_298;

		private:

			SceUChar8 unk_29C[0x3C];
		};

		class TextBox : public Text
		{
		public:

			TextBox(Widget *parent, SceInt32 a2);

			virtual ~TextBox();

			SceInt32 Hide();

		private:

			SceChar8 unk_2D8[0x50];
		};

		class Camera : public Widget
		{
		public:

			Camera(Widget *parent, SceInt32 a2);

			virtual ~Camera();

		private:

			SceChar8 unk_280[0x110];
		};

		class Scene : public Widget
		{
		public:

			Scene(Widget *parent, SceInt32 priority, SceInt32 a3, SceInt32 a4, SceInt32 a5);

			virtual ~Scene();

		private:

			SceChar8 unk_280[0x140];
		};

		class Plane : public Widget
		{
		public:

			Plane(Widget *parent, SceInt32 a2);

			virtual ~Plane();
		};

		class SpeechBalloon : public Plane
		{
		public:

			SpeechBalloon(Widget *parent, SceInt32 a2);

			virtual ~SpeechBalloon();

		private:

			SceChar8 unk_280[0x8];
		};

		class Box : public Plane
		{
		public:

			Box(Widget *parent, SceInt32 a2);

			virtual ~Box();

		private:

			SceUChar8 unk_280[0xA0];
		};

		class AppIconBase : public Widget
		{
		public:

			AppIconBase(Widget *parent, SceInt32 a2);

			virtual ~AppIconBase();
		};

		class AppIcon2d : public AppIconBase
		{
		public:

			AppIcon2d(Widget *parent, SceInt32 a2);

			virtual ~AppIcon2d();
		};

		class ButtonBase : public Widget
		{
		public:

			ButtonBase(Widget *parent, SceInt32 a2);

			virtual ~ButtonBase();

			SceVoid SetThreshold(SceInt32 threshold, SceInt32 repeatThreshold);

			SceChar8 unk_280[0xC];

			Rgba *pDisabledColor;

			SceUChar8 unk_290[0x1D];

			SceUInt8 state;

			//SceUChar8 unk_2AE[0x3];
		};

		class Button : public ButtonBase
		{
		public:

			Button(Widget *parent, SceInt32 a2);

			virtual ~Button();

		private:

			SceUChar8 unk_2AE[0x10];
		};

		class CornerButton : public Button
		{
		public:

			CornerButton(Widget *parent, SceInt32 a2);

			virtual ~CornerButton();

		private:

			SceUChar8 unk_2BE[0x10];
		};

		class Dialog : public Box
		{
		public:

			Dialog(Widget *parent, SceInt32 a2);

			virtual ~Dialog();

		private:

			SceUChar8 unk_320[0x10];
		};

		class ImageButton : public Button
		{
		public:

			ImageButton(Widget *parent, SceInt32 a2);

			virtual ~ImageButton();

		private:

			SceChar8 unk_2BE[0xA];

			graph::Surface *imageSurf;

			graph::Surface *baseSurf;

			SceChar8 unk_2D0[0x90];
		};

		//TODO
		class PlaneButton : public Widget
		{
		public:

			PlaneButton(Widget *parent, SceInt32 a2);

			virtual ~PlaneButton();
		};

		//TODO
		class CompositeButton : public Widget
		{
		public:

			CompositeButton(Widget *parent, SceInt32 a2);

			virtual ~CompositeButton();
		};

		class ImageSlidebar : public Widget
		{
		public:

			ImageSlidebar(Widget *parent, SceInt32 a2);

			virtual ~ImageSlidebar();

		private:

			SceChar8 unk_280[0x28];
		};

		class CompositeDrawer : public Widget
		{
		public:

			CompositeDrawer(Widget *parent, SceInt32 a2);

			virtual ~CompositeDrawer();
		};

		class ScrollViewBase : public Widget
		{
		public:

			ScrollViewBase(Widget *parent, SceInt32 a2);

			virtual ~ScrollViewBase();

		private:

			SceChar8 unk_280[0x180];
		};

		class SlidingDrawer : public ScrollViewBase
		{
		public:

			SlidingDrawer(Widget *parent, SceInt32 a2);

			virtual ~SlidingDrawer();
		};

		class ScrollViewParent : public Widget
		{
		public:

			ScrollViewParent(Widget *parent, SceInt32 a2);

			virtual ~ScrollViewParent();

		private:

			SceChar8 unk_280[0x28];
		};

		class ScrollView : public ScrollViewBase
		{
		public:

			ScrollView(Widget *parent, SceInt32 a2);

			virtual ~ScrollView();

			virtual int unkFun_1AC();
			virtual int unkFun_1B0();
			virtual int unkFun_1B4();
			virtual int unkFun_1B8();
			virtual int unkFun_1BC();
			virtual int unkFun_1C0();
			virtual int unkFun_1C4();
			virtual int unkFun_1C8();
			virtual int unkFun_1CC();
			virtual int unkFun_1D0();
			virtual int unkFun_1D4();
			virtual int unkFun_1D8();
			virtual int unkFun_1DC();
			virtual int unkFun_1E0();
			virtual int unkFun_1E4();
			virtual int unkFun_1E8();
			virtual int unkFun_1EC();
			virtual int unkFun_1F0();
			virtual int unkFun_1F4();
			virtual int unkFun_1F8();
			virtual int unkFun_1FC();
			virtual int unkFun_200();
			virtual int unkFun_204();
			virtual int unkFun_208();
			virtual int unkFun_20C();
			virtual int unkFun_210();
			virtual int unkFun_214();
			virtual int unkFun_218();
			virtual int unkFun_21C();
			virtual int unkFun_220();
			virtual int unkFun_224();
			virtual int unkFun_228();
			virtual int unkFun_22C(SceInt32 a2);
			virtual int unkFun_230();
			virtual int unkFun_234();
			virtual int unkFun_238();
			virtual int unkFun_23C();
			virtual int unkFun_240(SceFVector4 *a1, SceInt32 a2);
			virtual int unkFun_244();
			virtual int unkFun_248(SceInt32 a1);
			virtual int unkFun_24C(SceInt32 a1);
			virtual int unkFun_250();
			virtual int unkFun_254(SceUInt64 *a1, SceInt32 a2, SceInt32 a3, SceInt32 a4);
			virtual int unkFun_258(SceInt32 a1);
			virtual int unkFun_25C();
			virtual int unkFun_260(SceFVector4 *a1, SceInt32 a2);
			virtual int unkFun_264();
			virtual int unkFun_268();
			virtual int unkFun_26C();
			virtual int unkFun_270();
			virtual int unkFun_274(SceInt32 a1);

		private:

			SceChar8 unk_400[0x40];
		};

		class ScrollBar2D : public Widget
		{
		public:

			ScrollBar2D(Widget *parent, SceInt32 a2);

			virtual ~ScrollBar2D();

		private:

			SceChar8 unk_280[0x50];
		};

		class ScrollBar : public Widget
		{
		public:

			ScrollBar(Widget *parent, SceInt32 a2);

			virtual ~ScrollBar();

		private:

			SceChar8 unk_280[0x50];
		};

		class SlideBar : public Widget
		{
		public:

			SlideBar(Widget *parent, SceInt32 a2);

			virtual ~SlideBar();

		private:

			SceChar8 unk_280[0x70];
		};

		class RichText : public ScrollViewBase
		{
		public:

			RichText(Widget *parent, SceInt32 a2);

			virtual ~RichText();

			SceInt32 SetRichText(char *text, SceUInt32 len);
		};

		class PageTurnBase : public Widget
		{
		public:

			PageTurnBase(Widget *parent, SceInt32 a2);

			virtual ~PageTurnBase();

		private:

			SceChar8 unk_280[0x30];
		};

		class PageTurn : public Widget
		{
		public:

			PageTurn(Widget *parent, SceInt32 a2);

			virtual ~PageTurn();
		};

		class ProgressBar : public Widget
		{
		public:

			ProgressBar(Widget *parent, SceInt32 a2);

			virtual ~ProgressBar();

			virtual int unkFun_1AC();
			virtual int unkFun_1B0();
			virtual int unkFun_1B4();
			virtual int unkFun_1B8();
			virtual int unkFun_1BC();
			virtual int unkFun_1C0();
			virtual int unkFun_1C4();
			virtual int unkFun_1C8();
			virtual int unkFun_1CC();
			virtual int unkFun_1D0();
			virtual int unkFun_1D4();
			virtual int unkFun_1D8();
			virtual int unkFun_1DC();
			virtual int unkFun_1E0();
			virtual int unkFun_1E4();
			virtual int SetProgress(SceFloat32 value, SceUInt32 a2, SceUInt32 a3);
			virtual int unkFun_1EC();
			virtual int unkFun_1F0();
			virtual int unkFun_1F4();
			virtual int unkFun_1F8();
			virtual int unkFun_1FC();
			virtual int unkFun_200();

			SceUChar8 unk_280[0x1C];

			SceFloat32 maxValue;
			SceFloat32 minValue;
			SceFloat32 currentValue;

		private:

			SceChar8 unk_2A8[0x48];

		};

		class ProgressBarTouch : public ProgressBar
		{
		public:

			ProgressBarTouch(Widget *parent, SceInt32 a2);

			virtual ~ProgressBarTouch();

		private:

			SceChar8 unk_2F0[0x28];
		};

		class ListItem : public Widget
		{
		public:

			ListItem(Widget *parent, SceInt32 a2);

			virtual ~ListItem();

		private:

			SceUChar8 unk_280[0x50];
		};

		class ListView : public ScrollViewBase
		{
		public:

			enum ConfigurationType
			{
				ConfigurationType_None,
				ConfigurationType_Advanced,
				ConfigurationType_Simple
			};

			class ItemCallback
			{
			public:

				class Param
				{
				public:

					ui::ListView *list;
					SceInt32 segment;
					SceInt32 cellIndex;
					ui::Widget *parent;
				};

				ItemCallback();

				virtual ~ItemCallback();

				virtual paf::ui::ListItem *Create(Param *info);
				virtual SceVoid Start(Param *info);
				virtual SceVoid Stop(Param *info);
				virtual SceVoid Dispose(Param *info);
			};

			ListView(Widget *parent, SceInt32 a2);

			virtual ~ListView();

			SceVoid Lock();

			SceVoid Unlock();

			SceVoid RegisterItemCallback(ItemCallback *callback);

			SceVoid SetSegmentSize(Vector4 *arg);

			SceVoid SetSegmentEnable(SceInt32 segment, SceInt32 val);

			SceVoid SetCellSize(SceInt32 a1, Vector4 *arg);

			SceInt32 AddItem(SceInt32 segment, SceInt32 startingCellIndex, SceInt32 itemCount);

			SceVoid SetConfigurationType(SceInt32 segment, ConfigurationType val);

			SceVoid RemoveItem(SceInt32 segment, SceInt32 startingCellIndex, SceInt32 itemCount);

			SceInt32 GetCellNum(SceInt32 segment);

			SceInt32 SetSegmentCapacity(SceInt32 segment, SceInt32 capacity);

			SceUChar8 unk_400[0x30];

			ItemCallback *itemCb;

		private:

			SceUChar8 unk_434[0xB4];
		};

		class FileList : public ListView
		{
		public:

			FileList(Widget *parent, SceInt32 a2);

			virtual ~FileList();
		};

		class RadioBox : public Widget
		{
		public:

			RadioBox(Widget *parent, SceInt32 a2);

			virtual ~RadioBox();
		};

		class StateButtonBase : public ButtonBase
		{
		public:

			StateButtonBase(Widget *parent, SceInt32 a2);

			virtual ~StateButtonBase();
		};

		class RadioButton : public StateButtonBase
		{
		public:

			RadioButton(Widget *parent, SceInt32 a2);

			virtual ~RadioButton();
		};

		class CheckBox : public StateButtonBase
		{
		public:

			virtual int unkFun_1AC();
			virtual int unkFun_1B0();
			virtual int unkFun_1B4();
			virtual int unkFun_1B8(SceInt32);
			virtual SceVoid SetChecked(SceFloat32 delay, bool checked, SceInt32 a3);
			virtual SceVoid SwitchChecked();
			virtual int unkFun_1C4();
			virtual int unkFun_1C8();

			CheckBox(Widget *parent, SceInt32 a2);

			virtual ~CheckBox();
		};

		//TODO
		class SpinBase : public Widget
		{
		public:

			SpinBase(Widget *parent, SceInt32 a2);

			virtual ~SpinBase();
		};

		//TODO
		class ItemSpin : public SpinBase
		{
		public:

			ItemSpin(Widget *parent, SceInt32 a2);

			virtual ~ItemSpin();
		};

		//TODO
		class NumSpin : public SpinBase
		{
		public:

			NumSpin(Widget *parent, SceInt32 a2);

			virtual ~NumSpin();
		};

		__declspec (dllimport) SceInt32 s_widget19999DA5;

		__declspec (dllimport) SceInt32 s_widget91871D2D;
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_H */
