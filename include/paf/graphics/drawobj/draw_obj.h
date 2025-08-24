/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_DRAW_OBJ_H
#define _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_DRAW_OBJ_H

#include <stdint.h>
#include <stddef.h>
#include <paf/math/math.h>
#include <paf/graphics/surface/surface.h>
#include <paf/versatileparam/versatileparam.h>
#include <paf/paf_types.h>

namespace paf {
	namespace graph {
		
		class Shader;
		class DrawEnv;
		class DrawObj;

		enum BlendType
		{
			BLEND_DISABLE = 0,
			BLEND_INTERPOLATION = 1,
			BLEND_ADDITION = 2
		};

		enum CompareType
		{
			COMP_ALWAYS = 1,
			COMP_NEVER = 2,
			COMP_LESS = 3,
			COMP_LEQUAL = 4,
			COMP_EQUAL = 5,
			COMP_NOTEQUAL = 6,
			COMP_GEQUAL = 7,
			COMP_GREATER = 8
		};

		enum LightType
		{
			LIGHT_DISABLE = 0,
			LIGHT_STANDARD = 1
		};

		enum CullFaceType
		{
			CULL_FACE_DISABLE = 0,
			CULL_FACE_CW = 1,
			CULL_FACE_CCW = 2
		};

		enum BoolType
		{
			BOOL_FALSE = 0,
			BOOL_TRUE = 1
		};

		class DrawCallbackArg
		{
		public:

			DrawObj *self;
			math::matrix *world_mat;
			math::v4 *color;
			//Light *light;
			int32_t unk_0C;
		};

		class DeleteCBInfo
		{
		public:

			int32_t unk_00;
			int32_t unk_04;
		};

		class DrawStyle
		{
		public:

			uint32_t blend : 4;
			uint32_t depth : 4;
			uint32_t lighting : 4;
			uint32_t face_cull : 2;
			uint32_t scissor : 1;
			uint32_t reserved1 : 17;
		};

		//TODO
		class DrawObjParam : public VersatileParam
		{
		public:

			static const char *ParamName(void);

			DrawObjParam()
			{
				Init();
			}

			virtual const char *GetParamName(void) const;

			virtual ~DrawObjParam();

			virtual int Set(void);
			virtual int Get(void);
			virtual int Create(int mode);

			virtual int AttachPlugin(paf::Plugin *plugin){
				m_plugin = plugin;
				return 0;
			}

			virtual int SetEach(DrawObj *);
			virtual int GetEach(DrawObj *);

			int Init(void);
			int AddDrawObj(DrawObj *);
			int DelDrawObj(DrawObj *);
			int delete_cb(DrawObj *, void *);

		private:

			int m_unk_0x20;
			int m_unk_0x24;
			paf::list<int> m_list; // TODO: fix list type
			unsigned char m_unk_0x34[0x1C];

			SCE_PAF_IMPORTED_FROM_PRX static const char m_param_name[];
			SCE_PAF_IMPORTED_FROM_PRX static const char * const s_names[];
		};

		class DrawObj
		{
		public:

			static const char *DrawObjType();

			static bool IsSafety()
			{
				return s_safety;
			}

			DrawObj(DrawStyle const& _style);

			virtual bool IsInherit(char const *type) const;
			virtual char *GetDrawObjType() const;
			virtual ~DrawObj();
			virtual int32_t unkFun_10();
			virtual int32_t unkFun_14();
			virtual int32_t ReleaseAll();
			virtual int32_t unkFun_1C();
			virtual void SetTexture(intrusive_ptr<Surface> const& texture, uint32_t sce_paf_index = 0);
			virtual void GetTexture(intrusive_ptr<Surface>& texture, uint32_t sce_paf_index = 0);
			virtual void SetPos(paf::math::v3 pos);
			virtual void SetSize(paf::math::v3 size);
			virtual void SetColor(paf::math::v4 color);
			virtual void SetRot(paf::math::v3 rot);
			virtual void Update();
			virtual void UpdatePost(math::matrix const& world_mat);
			virtual int32_t unkFun_40();
			virtual int32_t unkFun_44();

			void EnterSafety();

			void FinishSafety();

			void SetDirtyCount(uint32_t count);

			void BindDrawStyle();

			void SetShader(common::SharedPtr<Shader> const& shader);

			void SetTextureRegion(math::v4 region);

			bool IsDirty()
			{
				return (m_dirty != 0);
			}

			DrawStyle GetDrawStyle()
			{
				return m_draw_style;
			}

			math::v3 GetPos() const
			{
				return m_pos;
			}

			math::v3 GetSize() const
			{
				return m_size;
			}

			math::v4 GetColor() const
			{
				uint8_t r = (m_color & 0xFF000000) >> 24;
				uint8_t g = (m_color & 0x00FF0000) >> 16;
				uint8_t b = (m_color & 0x0000FF00) >> 8;
				uint8_t a = (m_color & 0x000000FF);
				return math::v4((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, (float)a / 255.0f);
			}

			math::v3 GetRot() const
			{
				return *m_rot;
			}

			SCE_PAF_IMPORTED_FROM_PRX static uint32_t s_dirty_count;

			SCE_PAF_IMPORTED_FROM_PRX static bool s_safety;

		protected:

			int32_t unk_04;
			math::v3 m_pos;
			math::v3 m_size;
			math::v3 *m_rot;
			uint32_t m_color;
			DrawStyle m_draw_style;
			uint32_t m_dirty : 2;
			uint32_t m_prepare : 1;
			uint32_t m_visible : 1;
			common::SharedPtr<Shader> m_shader;
			//common::SharedPtr<Material> m_material;
			vector<DeleteCBInfo> m_list_delete_cb;

			SCE_PAF_IMPORTED_FROM_PRX static const char m_drawobj_type[];

		};

		extern DrawEnv *DrawCalls();
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_DRAW_OBJ_H */
