/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_CORE_WIDGET_H
#define _VDSUITE_USER_PAF_WIDGET_CORE_WIDGET_H

#include <stdint.h>
#include <paf/std/list>
#include <paf/std/vector>
#include <paf/std/map>
#include <paf/std/memory>
#include <paf/math/math.h>
#include <paf/graphics/surface/surface.h>
#include <paf/versatileparam/idparam.h>
#include <paf/versatileparam/versatileparam.h>
#include <paf/common/transition.h>
#include <paf/timer/timer.h>
#include <paf/widget/types.h>
#include <paf/widget/core/event.h>
#include <paf/widget/core/handler.h>
#include <paf/widget/core/layouter.h>
#include <paf/widget/core/animlistener.h>

namespace paf {

	namespace graph {

		class DrawInfo;
		class DrawObj;
		class PlaneObj;
	}

	namespace ui {

		class HitInfo;
		class TouchInfo;
		class GestureParam;
		class ResolutionData;
		class Camera;
		class Scene;
		class Focuser;
		class Environment;

		class Widget : public Handler
		{
		public:

			enum
			{
				ORIGIN_NONE = 0,
				ORIGIN_CENTER = 0,
				ORIGIN_MINUS = 1,
				ORIGIN_PLUS = 2,
				ORIGIN_LEFT = 1,
				ORIGIN_RIGHT = 2,
				ORIGIN_BOTTOM = 1,
				ORIGIN_TOP = 2,
				ORIGIN_FAR = 1,
				ORIGIN_NEAR = 2,
				ORIGIN_MANUAL = 3,
				ORIGIN_EXT = 4
			};

			enum
			{
				ANCHOR_CENTER = 0,
				ANCHOR_MINUS = 1,
				ANCHOR_PLUS = 2,
				ANCHOR_LEFT = 1,
				ANCHOR_RIGHT = 2,
				ANCHOR_BOTTOM = 1,
				ANCHOR_TOP = 2,
				ANCHOR_FAR = 1,
				ANCHOR_NEAR = 2,
				ANCHOR_MANUAL = 3,
				ANCHOR_PARENT_ORIGIN = 4,
				ANCHOR_NONE = 4,
				ANCHOR_EXT = 5
			};

			enum
			{
				ALIGN_NONE = 0,
				ALIGN_CENTER = 0,
				ALIGN_MINUS = 1,
				ALIGN_PLUS = 2,
				ALIGN_LEFT = 1,
				ALIGN_RIGHT = 2,
				ALIGN_BOTTOM = 1,
				ALIGN_TOP = 2,
				ALIGN_FAR = 1,
				ALIGN_NEAR = 2,
				ALIGN_MANUAL = 3,
				ALIGN_EXT = 4
			};

			enum
			{
				ADJUST_NONE = 0,
				ADJUST_PARENT = 1,
				ADJUST_CONTENT = 2,
				ADJUST_CONTENT_ASPECT = 3,
				ADJUST_SCREEN = 4
			};

			enum
			{
				ROTATE_ORDER_YXZ = 0,
				ROTATE_ORDER_ZYX = 1,
				ROTATE_ORDER_XYZ = 2
			};

			enum
			{
				ANIM_MOVE = 0x10000,
				ANIM_COLOR = 0x10001,
				ANIM_SHOW_ALPHA = 0x10002,
				ANIM_META_ALPHA = 0x10003,
				ANIM_SIZE = 0x10004,
				ANIM_SCALE = 0x10005,
				ANIM_ROT = 0x10006,
				ANIM_QUAT = 0x10007,
				ANIM_ALIGN = 0x10008,
				ANIM_ORIGIN = 0x10009,
				ANIM_ANCHOR = 0x1000A,
				ANIM_CROP = 0x1000B,
				ANIM_WIDGET_EXT = 0x1000C,
				ANIM_WIDGET_EXTMAX = 0x1FFFF,
				ANIM_OBJ = 0x20000,
				ANIM_OBJ_MOVE = 0x20100,
				ANIM_OBJ_SIZE = 0x20200,
				ANIM_OBJ_COLOR = 0x20300,
				ANIM_OBJ_ROT = 0x20400,
				ANIM_OBJ_TEX_ANIM = 0x20500,
				ANIM_OBJ_EXT = 0x30000,
				ANIM_WIDGET_RESERVED = 0xFF0000,
				ANIM_OPTION_LOOP = 0x10000000,
				ANIM_OPTION_RESERVED = 0xFF000000
			};

			enum
			{
				FIND_RECURSIVE = 0,
				FIND_RECURSIVE_DIRECT = 1,
				FIND_DIRECT_ONLY = 2
			};

			enum
			{
				TIMER_QUEUE_PUSH = 0,
				TIMER_QUEUE_CLEAR = 1,
				TIMER_QUEUE_CLEARALL = 2,
				TIMER_QUEUE_FRONT = 3,
				TIMER_QUEUE_MASK = 255
			};

			enum
			{
				GET_CURRENT = 0,
				GET_ANIMTARGET = 1,
				GET_ANIMNEXT = 2
			};

			enum
			{
				UPDATE_MATRIX_LOCAL = 1,
				UPDATE_MATRIX_WORLD = 2,
				UPDATE_DRAW_REGION = 4
			};

			enum
			{
				STATE_READY = 0,
				STATE_INIT = 1,
				STATE_TERM = 2,
				STATE_PREPARE = 3,
				STATE_EXT = 4
			};

			enum
			{
				HIT_FIND_WITH_CHILDREN = 0,
				HIT_FIND_WO_CHILDREN = 1
			};

			enum
			{
				HIT_DETECT_BOX = 0,
				HIT_DETECT_SPHERE = 1,
				HIT_DETECT_PASSTHROUGH = 2,
				HIT_DETECT_ALWAYSFAIL = 3
			};

			enum
			{
				GESTURE_TYPE_TAP = 1,
				GESTURE_TYPE_MULTI_TAP = 2,
				GESTURE_TYPE_LONG_PRESS = 4,
				GESTURE_TYPE_LONG_PRESS_REPEAT = 8,
				GESTURE_TYPE_DRAG = 16,
				GESTURE_TYPE_DRAG_PINCH = 32,
				GESTURE_TYPE_REGION_TRACK = 64,
				GESTURE_TYPE_MOCHI = 128
			};

			enum
			{
				GRAB_MANUAL = 0,
				GRAB_AUTO_WITH_PRESS = 1,
				GRAB_AUTO_WITH_PRESSOVER = 2
			};

			enum
			{
				LAYOUT_NOEFFECT = 0x0,
				LAYOUT_FACTOR_NONE = 0x0,
				LAYOUT_FACTOR_POS = 0x1,
				LAYOUT_FACTOR_SIZE = 0x2,
				LAYOUT_FACTOR_SCALE = 0x4,
				LAYOUT_FACTOR_ROT = 0x8,
				LAYOUT_FACTOR_QUAT = 0x8,
				LAYOUT_FACTOR_ALIGN = 0x10,
				LAYOUT_FACTOR_ORIGIN = 0x20,
				LAYOUT_FACTOR_ANCHOR = 0x40,
				LAYOUT_FACTOR_ALL = 0xff,
				LAYOUT_NOTIFY_NONE = 0x0,
				LAYOUT_NOTIFY_ON_MODIFY = 0x100,
				LAYOUT_NOTIFY_RUN_ANIM = 0x200,
				LAYOUT_NOTIFY_RUN_DRAG = 0x400,
				LAYOUT_NOTIFY_END_DRAG = 0x800,
				LAYOUT_NOTIFY_ALL = 0xff00
			};

			enum
			{
				FOCUS_DIR_UP = 0,
				FOCUS_DIR_DOWN = 1,
				FOCUS_DIR_LEFT = 2,
				FOCUS_DIR_RIGHT = 3
			};

			enum
			{
				OBJ_ROOT = 0
			};

			enum DrawOrder
			{
				DRAW_ORDER_SIBLINGS_FIRST = 0,
				DRAW_ORDER_CHILDREN_FIRST = 1
			};

			enum LoopEffect
			{
				LOOP_EFFECT_NONE = 0,
				LOOP_EFFECT_1,
				LOOP_EFFECT_2,
				LOOP_EFFECT_3,
				LOOP_EFFECT_4,
				LOOP_EFFECT_5,
				LOOP_EFFECT_6,
				LOOP_EFFECT_7
			};

			class UserData
			{
			public:

				UserData()
				{

				}

				virtual ~UserData()
				{

				}
			};

			class CreateParam
			{
			public:

				bool m_create_drawobj : 1;
				bool m_parent_protected : 1;
				bool m_under_template : 1;
				uint32_t reserved : 29;
			};

			static void SetBaseDestroyCount(int32_t count);

			static int32_t GetBaseDestroyCount();

			static int32_t DestroyingCount()
			{
				return s_destroying_count;
			}

			static const char *TypeName();

			Widget(Widget *_parent, CreateParam *_param);

			virtual ~Widget();

			virtual bool IsInherit(char const *type) const;
			virtual char *GetTypeName() const;
			virtual void DestroyWidget();
			virtual uint32_t CheckState();
			virtual uint32_t ChangeState(uint32_t state, int32_t ev_type);
			virtual int32_t SetEnvironment(Environment *env);
			virtual int32_t SetScene_core(Scene *scene);
			virtual bool RemoveChild(Widget *obj);
			virtual void RegisterChild(Widget *obj, Widget *sibling);
			virtual bool ReorderChild(Widget *obj, Widget *sibling);
			virtual Widget *GetInternalWidget();
			virtual int32_t DoTransition_core(float parameter, uint32_t type, bool set);
			virtual int32_t DoTransitionReverse_core(float parameter, uint32_t type, bool set);
			virtual int32_t SetColor_core(math::v4 const& v);
			virtual int32_t SetSize_core_force(math::v4 const& v, uint32_t notify_layout, bool force);
			virtual void UpdateSize();
			virtual int32_t unkFun_0A4();
			virtual void Update();
			virtual void UpdateAfterChildren();
			virtual void UpdatePost();
			virtual int32_t OnDraw(graph::DrawInfo& info);
			virtual int32_t unkFun_0B8();
			virtual int32_t unkFun_0BC();
			virtual int32_t unkFun_0C0();
			virtual math::v4 calc_align_offset(math::v4 const& size, math::v4 const& aoffs, uint32_t ax, uint32_t ay, uint32_t az);
			virtual int32_t SetOrigin(uint32_t ax, uint32_t ay, uint32_t az, Timer *t);
			virtual void GetOrigin(uint32_t& ax, uint32_t& ay, uint32_t& az);
			virtual math::v4 calc_origin_offset(math::v4 const& size, math::v4 const& offs, uint32_t ax, uint32_t ay, uint32_t az);
			virtual int32_t SetAnchor(uint32_t ax, uint32_t ay, uint32_t az, Timer *t);
			virtual void GetAnchor(uint32_t& ax, uint32_t& ay, uint32_t& az);
			virtual math::v4 calc_anchor_offset(math::v4 const& size, math::v4 const& offs, uint32_t ax, uint32_t ay, uint32_t az);
			virtual int32_t unkFun_0E0();
			virtual int32_t unkFun_0E4();
			virtual int32_t unkFun_0E8();
			virtual void UpdateAdjustSize();
			virtual void UpdateAdjustChildSize(Widget *child);
			virtual int32_t unkFun_0F4();
			virtual graph::DrawObj *GetDrawObj(int32_t obj);
			virtual int32_t SetTexture(intrusive_ptr<graph::Surface> const& surf, int32_t obj, uint32_t sce_paf_index);
			virtual int32_t SetTexture(intrusive_ptr<graph::Surface> const& surf);
			virtual int32_t GetTexture(intrusive_ptr<graph::Surface>& surf, int32_t obj, uint32_t sce_paf_index);
			virtual int32_t GetTexture(intrusive_ptr<graph::Surface>& surf);
			virtual int32_t unkFun_10C();
			virtual int32_t unkFun_110();
			virtual int32_t unkFun_114();
			virtual int32_t SetString(wstring const& str, int32_t obj);
			virtual int32_t SetString(wstring const& str);
			virtual int32_t GetString(wstring& strOut, int32_t obj);
			virtual int32_t GetString(wstring& strOut);
			virtual int32_t unkFun_128();
			virtual int32_t unkFun_12C();
			virtual int32_t unkFun_130();
			virtual int32_t unkFun_134();
			virtual int32_t SetFocusDirectionId(uint32_t directionType, string const& id);
			virtual int32_t unkFun_13C();
			virtual int32_t SetFocusSearchRectangle(math::v4 const& rect);
			virtual int32_t unkFun_144();
			virtual int32_t unkFun_148();
			virtual int32_t unkFun_14C();
			virtual int32_t unkFun_150();
			virtual int32_t unkFun_154();
			virtual int32_t unkFun_158();
			virtual int32_t unkFun_15C();
			virtual int32_t EventExecDispatch(Event *e);
			virtual int32_t EventExecBroadcast(Event *e);
			virtual int32_t EventExecDirect(Event *e);
			virtual int32_t unkFun_16C();

			math::v4 CalcBound(math::v4 const& _size, math::quaternion const& _quat);
			math::v4 GetSizeBound(int32_t opt, Widget *ref);

			float CalcDistPointToPlane(math::v4 const& point, math::v4 const& plane_p, math::v4 const& plane_n, int32_t normalized);
			float CalcDistPointToLine(math::v4 const& point, math::v4 const& cam_p, math::v4 const& touch_p, HitInfo *h_info);
			float CalcDistLineToLine(math::v4 const& p1, math::v4 const& v1, math::v4 const& p2, math::v4 const& v2, math::v4 *pa1, math::v4 *pa2);

			int32_t CalcHitLineToPlane(math::v4 const& cam_p, math::v4 const& line_p, math::v4 const& plane_p, math::v4 const& plane_n, HitInfo *h_info);
			int32_t CalcHitBoxToLine(math::v4 const& box, math::v4 const& cam_p, math::v4 const& touch_p, HitInfo *h_info);
			int32_t CalcHitBoxToPlane(math::v4 const& box, math::v4 const& plane_p, math::v4 const& plane_n, float *dist, HitInfo *h_info);

			math::v4 GetHitBoxSize(int32_t opt);
			math::v4 GetHitBoxCenter();

			math::v4 CalcClipRect();
			math::v4 CalcHitRect();

			int32_t HitDetectRouting(Event *e, math::v4 const& touch_p, math::v4 const& cam_p, TouchInfo *t_info, HitInfo *h_info);
			
			void ApplyPadGesture(uint32_t port_id, uint32_t type, const GestureParam *param);
			void ApplyTouchGesture(uint32_t port_id, uint32_t touch_id, uint32_t type, const GestureParam *param);

			int32_t SetScale(math::v4 const& scale, Timer *t = NULL, int32_t id = ANIM_SCALE, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL);
			int32_t SetRot(math::v4 const& rot, int32_t option = 0, Timer *t = NULL, int32_t id = ANIM_ROT, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL);
			int32_t SetQuat(math::quaternion const& quat, Timer *t = NULL, int32_t id = ANIM_QUAT, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL);
			int32_t SetColor(math::v4 const& col, Timer *t = NULL, int32_t id = ANIM_COLOR, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL);
			int32_t SetSize(math::v4 const& size, Timer *t = NULL, int32_t id = ANIM_SIZE, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL);
			int32_t SetPos(math::v4 const& pos, Timer *t = NULL, int32_t id = ANIM_MOVE, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL);
			int32_t SetMetaAlpha(float _alpha, Timer *t = NULL, int32_t id = ANIM_META_ALPHA, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL);
			int32_t SetShowAlpha(float _alpha, Timer *t = NULL, int32_t id = ANIM_SHOW_ALPHA, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL);
			int32_t SetScale(float x, float y, float z, Timer *t = NULL, int32_t id = ANIM_SCALE, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL)
			{
				math::v4 val(x, y, z, 0.0f);
				return SetScale(val, t, id, opt, delay, cb_fin, usrdata);
			}
			int32_t SetRot(float x, float y, float z, int32_t option = 0, Timer *t = NULL, int32_t id = ANIM_ROT, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL)
			{
				math::v4 val(x, y, z, 0.0f);
				return SetRot(val, option, t, id, opt, delay, cb_fin, usrdata);
			}
			int32_t SetColor32(uint32_t color, Timer *t = NULL, int32_t id = ANIM_COLOR, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL)
			{
				uint8_t r = (m_color & 0xFF000000) >> 24;
				uint8_t g = (m_color & 0x00FF0000) >> 16;
				uint8_t b = (m_color & 0x0000FF00) >> 8;
				uint8_t a = (m_color & 0x000000FF);
				math::v4 val((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, (float)a / 255.0f);
				return SetColor(val, t, id, opt, delay, cb_fin, usrdata);
			}
			int32_t SetColor(float r, float g, float b, float a, Timer *t = NULL, int32_t id = ANIM_COLOR, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL)
			{
				math::v4 val(r, g, b, a);
				return SetColor(val, t, id, opt, delay, cb_fin, usrdata);
			}
			int32_t SetSize(float w, float h, float d, Timer *t = NULL, int32_t id = ANIM_SIZE, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL)
			{
				math::v4 val(w, h, d, 0.0f);
				return SetSize(val, t, id, opt, delay, cb_fin, usrdata);
			}
			int32_t SetPos(float x, float y, float z, Timer *t = NULL, int32_t id = ANIM_MOVE, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL, void *usrdata = NULL)
			{
				math::v4 val(x, y, z, 0.0f);
				return SetPos(val, t, id, opt, delay, cb_fin, usrdata);
			}



			int32_t SetPos(const ResolutionData *array, uint32_t num, Timer *t, int32_t id, int32_t opt, float delay, AnimCB cb_fin, void *usrdata);
			int32_t SetSize(const ResolutionData *array, uint32_t num, Timer *t, int32_t id, int32_t opt, float delay, AnimCB cb_fin, void *usrdata);
			int32_t SetRot(const ResolutionData *array, uint32_t num, int option, Timer *t, int32_t id, int32_t opt, float delay, AnimCB cb_fin, void *usrdata);


			int32_t SetAlignOffset(math::v4 const& offs, Timer *t, int32_t id, int32_t opt, float delay, AnimCB cb_fin, void *usrdata);
			int32_t SetOriginOffset(math::v4 const& offs, Timer *t, int32_t id, int32_t opt, float delay, AnimCB cb_fin, void *usrdata);
			int32_t SetAnchorOffset(math::v4 const& offs, Timer *t, int32_t id, int32_t opt, float delay, AnimCB cb_fin, void *usrdata);

			int32_t SetAlign(uint32_t ax, uint32_t ay, uint32_t az, Timer *t);
			int32_t SetPosture(math::v4 const& eye2, math::v4 const& up2, Widget *ref);
			int32_t SetAdjust(uint32_t ax, uint32_t ay, uint32_t az);

			int32_t LookAt(math::v4 const& ref_pos, math::v4 const& up_pos);
			int32_t LookAt(Widget *ref, math::v4 const& off, Widget *ref_up, math::v4 const& off2);

			int32_t SetScale_core(math::v4 const& v, uint32_t notify_layout);
			int32_t SetRot_core(math::v4 const& v, int32_t _option, uint32_t notify_layout);
			int32_t SetQuat_core(math::quaternion const& q, uint32_t notify_layout);
			int32_t SetMetaAlpha_core(float _alpha);

			void SetResolutionSize_core(const ResolutionData *data, int32_t num);
			void SetResolutionRot_core(const ResolutionData *data, int32_t num);
			void SetResolutionPos_core(const ResolutionData *data, int32_t num);

			int32_t SetAlignOffset_core(math::v4 const& offs, uint32_t notify_layout);
			int32_t SetOriginOffset_core(math::v4 const& offs, uint32_t notify_layout);
			int32_t SetAnchorOffset_core(math::v4 const& offs, uint32_t notify_layout);

			math::v4 GetAlignOffsetToCenter(int32_t opt);
			math::v4 GetAlignOffsetToRotatedCenter(int32_t opt);
			math::v4 GetOriginOffset(int32_t opt);
			math::v4 GetAnchorOffset(int32_t opt);

			int32_t Show(Timer *t = NULL, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL);
			int32_t Hide(Timer *t = NULL, int32_t opt = 0, float delay = 0.0f, AnimCB cb_fin = NULL);

			int32_t Show(common::transition::Type type, float parameter = 0.0f, HandlerCB cb = NULL, void *userdata = NULL);
			int32_t Hide(common::transition::Type type, float parameter = 0.0f, HandlerCB cb = NULL, void *userdata = NULL);

			int32_t ReleaseFocus();

			int32_t GrabEventRouting(Event *e, math::v4 const& touch_p, math::v4 const& cam_p, TouchInfo *t_info, HitInfo *h_info);

			int32_t SetPosCenter(math::v4 const& v);

			math::v4 *GetScale(int32_t opt);
			math::v4 GetRot(int32_t opt, Widget *ref, math::v4 const& off_rot, int32_t _option);
			math::v4 *GetSize(int32_t opt);
			math::v4 GetPos(int32_t opt, Widget *ref, math::v4 const& off_pos);
			math::v4 GetPosCenter(int32_t opt, Widget *ref, math::v4 const& off_pos);

			void OnUpdate();
			void OnUpdatePost();

			bool UpdateDestroy();
			void UpdateRestruct();

			int32_t SetParent(Widget *parent, Widget *sibling, int32_t flag);

			Widget *FindChild(IDParam const& id_name, int32_t option = 0);
			Widget *FindChild(Widget *obj, int32_t option = 0);

			void CountFocusEnableChildren(int32_t diff);

			int32_t SetBehind(Widget *target);
			int32_t SetForward(Widget *target);

			AnimQueue *FindAnim(int32_t id);

			int32_t KillAnim(int32_t id);
			int32_t KillObjAnim(int32_t obj_id, int32_t type);
			int32_t KillAnimType(int32_t type);

			int32_t SetAnimListener(int32_t id, AnimListener *listener, int32_t option);
			int32_t SetAnimListener_withDelay(int32_t id, AnimListener *listener, float delay, int32_t opt);

			int32_t SetObjAnim(int32_t obj_id, int32_t type, math::v4 const& val, Timer *t, int32_t option);
			int32_t SetTexAnim(int32_t obj_id, int32_t column_num, int32_t row_num, int32_t start_frame, int32_t end_frame, Timer *t, int32_t option, float delay, AnimCB cb_fin, void *userdata);

			void SetUpdateParam(uint32_t flag);

			void SetPinchMode(uint32_t mode);
			void SetDragMode(uint32_t mode);

			bool IsPrepareObjs();
			bool IsMorphResolution(uint32_t& next, uint32_t& pre, float& time, float& value);

			math::matrix *UpdateMatrix();

			void CountPrepareChildren(int32_t diff);

			void NotifyAnimatorDirty(uint32_t notify);
			void NotifyLayoutDirty(uint32_t notify);

			int32_t SetKeycode(uint32_t keycode);
			int32_t ClearKeycode(uint32_t keycode);

			void SetLoopEffect(LoopEffect effect, bool overwrite);

			void SetActivate(bool on_off)
			{
				set_activate(on_off);
			}

			void EnableDebugFocus(bool on_off)
			{
				m_enable_debugfocus = on_off;
			}

			void GetAdjust(uint32_t& ax, uint32_t& ay, uint32_t& az)
			{
				ax = m_adjust_x;
				ay = m_adjust_y;
				az = m_adjust_z;
			}

			void GetAlign(uint32_t& ax, uint32_t& ay, uint32_t& az)
			{
				ax = m_align_x;
				ay = m_align_y;
				az = m_align_z;
			}

			list<Widget*>::iterator GetChildrenEnd()
			{
				return m_children.end();
			}

			list<Widget*>::iterator GetChildrenBegin()
			{
				return m_children.begin();
			}

			int32_t GetChildrenNum()
			{
				return m_children.size();
			}

			math::v4 GetColor()
			{
				uint8_t r = (m_color & 0xFF000000) >> 24;
				uint8_t g = (m_color & 0x00FF0000) >> 16;
				uint8_t b = (m_color & 0x0000FF00) >> 8;
				uint8_t a = (m_color & 0x000000FF);
				return math::v4((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, (float)a / 255.0f);
			}

			Layouter *GetLayouter()
			{
				return m_layouter;
			}

			Timer *GetMorphTimer()
			{
				return m_resolution_timer;
			}

			IDParam& GetName()
			{
				return m_name;
			}

			int32_t GetResolutionId()
			{
				return m_resolution_id;
			}

			int32_t GetResolutionIdPre()
			{
				return m_resolution_id_pre;
			}

			float GetMetaAlpha() const
			{
				return m_meta_alpha;
			}

			float GetShowAlpha() const
			{
				return m_show_alpha;
			}

			float GetTotalAlpha()
			{
				return (m_color & 0x000000FF) * m_meta_a_sum * m_show_a_sum;
			}

			UserData *GetUserData2(int32_t n)
			{
				if ((n < 0) || (1 < n))
				{
					return NULL;
				}
				return m_user_data2[n];
			}

			bool IsActivated()
			{
				if (m_activated && (0.95f <= m_show_a_sum))
				{
					return true;
				}
				return false;
			}

			bool IsAdjusted()
			{
				return ((m_adjust_x | m_adjust_y | m_adjust_z) != 0);
			}

			bool IsAligned()
			{
				return ((m_align_x | m_align_y | m_align_z) != 0);
			}

			bool IsEnableDebugFocus()
			{
				return m_enable_debugfocus;
			}

			bool IsFocused()
			{
				return m_focused;
			}

			bool IsFocusEnable()
			{
				return IsEnableEvent(EV_FOCUS);
			}

			bool IsOrigin()
			{
				return ((m_origin_x | m_origin_y | m_origin_z) != 0);
			}

			bool IsParentProtected()
			{
				return m_parent_protected;
			}

			bool IsUnderTemplate()
			{
				return m_under_template;
			}

			bool IsVisible()
			{
				return (0.02f <= m_show_a_sum);
			}

			bool IsXAdjusted()
			{
				return (m_adjust_x != 0);
			}

			bool IsYAdjusted()
			{
				return (m_adjust_y != 0);
			}

			bool IsZAdjusted()
			{
				return (m_adjust_z != 0);
			}

			bool IsXAligned()
			{
				return (m_align_x != 0);
			}

			bool IsYAligned()
			{
				return (m_align_y != 0);
			}

			bool IsZAligned()
			{
				return (m_align_z != 0);
			}

			int32_t SetAnimator(Animator *animator)
			{
				delete m_animator;
				m_animator = animator;
				if (m_animator)
				{
					m_animator->BindWidget(this);
				}
				return 0;
			}

			/*
			int32_t SetFocuser(Focuser *focuser)
			{

			}
			*/

			int32_t SetLayouter(Layouter *layouter)
			{
				delete m_layouter;
				m_layouter = layouter;
				if (m_layouter)
				{
					m_layouter->BindWidget(this);
				}
				return 0;
			}

			int32_t SetAnimCallback(int32_t id, Timer *t, AnimCB func, AnimCB fin, void *data, int32_t option)
			{
				AnimListener *listener = new AnimListener(t, this, func, fin, data);
				return SetAnimListener(id, listener, option);
			}

			int32_t SetAnimDelay(int32_t id, float time, int32_t option)
			{
				Timer *timer = new Timer(time, Timer::FUNC_LINEAR, 0, -1, NULL, NULL);
				AnimListener *listener = new AnimListener(timer, this, NULL, NULL, NULL);
				return  SetAnimListener(id, listener, option);
			}

			void SetFocusedState(bool on_off)
			{
				m_focused = on_off;
			}

			void SetUnderTemplate(bool on_off)
			{
				m_under_template = on_off;
			}

			void SetName(const char *name)
			{
				m_name = name;
			}

			void SetName(IDParam const& name)
			{
				m_name = name;
			}

			void SetName(uint32_t name_idhash)
			{
				m_name.SetIDHash(name_idhash);
			}

			void SetUserData2(UserData *data, int32_t n)
			{
				if ((-1 < n) && (n < 2))
				{
					if (m_user_data2[n])
					{
						delete m_user_data2[n];
					}
					m_user_data2[n] = data;
				}
			}

			Widget *GetParent() const
			{
				return m_parent;
			}

			Environment *GetEnvironment() const
			{
				return m_env;
			}

			uint32_t GetColor32() const
			{
				return m_color;
			}

			bool GetClip() const
			{
				return m_clip;
			}

			Camera *GetCamera() const;

			Widget *GetChild(int32_t num) const;

		protected: //0x27C

			int32_t HitDetect_core(uint32_t mode, Event *e, uint32_t e_mask, math::v4 const& touch_p, math::v4 const& cam_p, HitInfo *h_info);

			void apply_pad_gesture_longpress(uint32_t port_id, uint32_t type);
			void apply_pad_gesture_tap(uint32_t port_id, uint32_t type);
			void apply_pad_gesture_mask(uint32_t port_id, uint32_t type);
			void apply_touch_gesture_mask(uint32_t port_id, uint32_t touch_id, uint32_t type);

			void remove_pad_gesture_mask(uint32_t port_id, uint32_t type);
			void remove_touch_gesture_mask(uint32_t port_id, uint32_t touch_id, uint32_t type);

			int32_t EventExecDo(Event *e);

			void UpdateResolutionTimer();

			int32_t SetBehind_core(Widget *target);
			int32_t SetForward_core(Widget *target);
			int32_t SetBehindOneStep_core();
			int32_t SetForwardOneStep_core();
			int32_t SetBehindMost_core();
			int32_t SetForwardMost_core();

			void detach_environment();

			int32_t SetParent_core(Widget *parent, Widget *sibling);

			void InitCreateParam(const CreateParam *param);

			int32_t set_activate_core(bool on_off);

			void set_activate(bool on_off)
			{
				if (on_off == false && ((int)(char)on_off << 0x1B < 0))
				{
					set_activate_core(true);
				}
				m_activated = on_off;
				for (list<Widget*>::iterator it = m_children.begin(); it != m_children.end(); ++it)
				{
					(*it)->set_activate(on_off);
				}
			}

			ResolutionData *get_resolution_data(ResolutionData *array, uint32_t size, uint32_t id) const;

			math::v4 m_pos;
			math::v4 m_scale;
			math::v4 m_size;
			math::v4 m_rot;
			char m_unk_068[0x90];
			math::v4 m_align_offs;
			math::v4 m_anchor_offs;
			math::v4 m_origin_offs;
			char m_unk_128[0x18];
			IDParam m_name;
			uint32_t m_state;
			void *m_user_data[2];
			UserData *m_user_data2[2];
			Environment *m_env;
			Widget *m_parent;
			Scene *m_scene;
			list<Widget*> m_children;
			int32_t m_unk_17C;
			uint32_t m_unk_180 : 8;
			uint32_t m_unk_181 : 8;
			uint32_t m_unk_182 : 8;
			uint32_t m_update_flag : 8;
			int32_t m_transition;
			uint32_t m_keycode;

			char m_unk_18C;
			char m_unk_18D;
			char m_unk_18E;
			char m_unk_18F;
			char m_unk_190;
			char m_unk_191;

			bool m_unk_192_0 : 1;
			bool m_unk_192_1 : 1;
			bool m_unk_192_2 : 1;
			bool m_focused : 1;
			bool m_unk_192_4 : 1;
			bool m_unk_192_5 : 1;
			bool m_unk_192_6 : 1;
			bool m_unk_192_7 : 1;

			bool m_unk_193_0 : 1;
			bool m_unk_193_1 : 1;
			bool m_unk_193_2 : 1;
			bool m_unk_193_3 : 1;
			bool m_unk_193_4 : 1;
			bool m_unk_193_5 : 1;
			bool m_unk_193_6 : 1;
			bool m_unk_193_7 : 1;

			bool m_parent_protected : 1;
			bool m_under_template : 1;
			bool m_enable_debugfocus : 1;
			bool m_clip : 1;
			bool m_activated : 1;
			bool m_unk_194_5 : 1;
			bool m_touch_device_region : 1;
			bool m_unk_194_7 : 1;

			bool m_unk_195_0 : 1;
			bool m_unk_195_1 : 1;
			bool m_unk_195_2 : 1;
			bool m_unk_195_3 : 1;
			bool m_unk_195_4 : 1;
			bool m_unk_195_5 : 1;
			bool m_unk_195_6 : 1;
			bool m_unk_195_7 : 1;

			bool m_unk_196_0 : 1;
			bool m_unk_196_1 : 1;
			bool m_unk_196_2 : 1;
			bool m_unk_196_3 : 1;
			bool m_bound_keycode : 1;
			bool m_unk_196_5 : 1;
			bool m_unk_196_6 : 1;
			bool m_transition_complete : 1;

			char m_unk_197;
			char m_unk_198;
			char m_unk_199;
			char m_unk_19A;
			char m_unk_19B;

			float m_show_alpha;
			float m_show_a_sum;
			float m_meta_alpha;
			float m_meta_a_sum;
			int32_t m_unk_1AC;
			uint32_t m_color;
			int32_t m_unk_1B4;
			Timer *m_resolution_timer;
			Timer *m_resolution_timer_next;
			ResolutionData *m_pos_array;
			ResolutionData *m_size_array;
			ResolutionData *m_rot_array;
			int32_t m_resolution_id : 8;
			int32_t  m_resolution_id_pre : 8;
			int32_t  m_unk_1CE : 8;
			int32_t  m_unk_1CF : 8;
			char m_unk_1D0[0x20];
			uint32_t m_unk_1F0 : 8;
			uint32_t m_hit_find_mode : 8;
			uint32_t m_hit_detect_mode : 8;
			uint32_t m_hit_detect_b_mode : 8;
			char m_unk_1F4[0x8];
			uint32_t m_align_x : 4;
			uint32_t m_align_y : 4;
			uint32_t m_align_z : 4;
			uint32_t m_origin_x : 4;
			uint32_t m_origin_y : 4;
			uint32_t m_origin_z : 4;
			uint32_t m_anchor_x : 8;
			uint32_t m_anchor_y : 8;
			uint32_t m_anchor_z : 8;
			uint32_t m_adjust_x : 4;
			uint32_t m_adjust_y : 4;
			uint32_t m_adjust_z : 4;
			uint32_t m_unk_203_1 : 4;
			int32_t m_unk_204;
			float *m_drag_minmax;
			float *m_pinch_minmax;
			int32_t m_unk_210;
			Layouter *m_layouter;
			Animator *m_animator;
			Focuser *m_focuser;
			char m_unk_220[0x5C];

			__declspec(dllimport) static const char *m_widget_type;

			__declspec (dllimport) static int32_t s_base_destroy_count;

			__declspec (dllimport) static int32_t s_destroying_count;

			__declspec (dllimport) static int32_t s_instance_count;

			__declspec (dllimport) static int32_t s_upmat_count_L;

			__declspec (dllimport) static int32_t s_upmat_count_W;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_CORE_WIDGET_H */