/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_PLANE_OBJ_H
#define _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_PLANE_OBJ_H

#include <stdint.h>
#include <stddef.h>
#include <paf/graphics/drawobj/draw_obj.h>
#include <paf/math/math.h>
#include <paf/graphics/surface/surface.h>

namespace paf {
	namespace graph {

		class PlaneObj : public DrawObj
		{
		public:

			enum AlignMode
			{
				ALIGN_CENTER = 0,
				ALIGN_NONE = 0,
				ALIGN_BOTTOM = 1,
				ALIGN_LEFT = 1,
				ALIGN_MINUS = 1,
				ALIGN_PLUS = 2,
				ALIGN_RIGHT = 2,
				ALIGN_TOP = 2
			};

			enum ScaleMode
			{
				SCALE_SIZE = 0,
				SCALE_SURFACE = 1,
				SCALE_VALUE = 2,
				SCALE_ASPECT_SIZE = 3,
				SCALE_ASPECT_VALUE = 4,
				SCALE_REGION = 5,
				SCALE_REGION_ASPECT_SIZE = 6,
				SCALE_REGION_ASPECT_VALUE = 7,
				SCALE_MODE_MAX = 8
			};

			static void DrawCallback(DrawCallbackArg const& arg);

			static const char *DrawObjType();

			PlaneObj(DrawStyle const& _style);

			virtual bool IsInherit(char const *type) const;
			virtual char *GetDrawObjType() const;
			virtual ~PlaneObj();
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
			virtual void UpdateLayout();
			virtual void UpdateDivVerticesPosition();
			virtual void UpdateDivVerticesTexcoord();

			int32_t SetTexRegion(math::v4 const& region);

			int32_t SetMinFilter(Surface::TextureFilter value, uint32_t sce_paf_index = 0);

			int32_t SetMagFilter(Surface::TextureFilter value, uint32_t sce_paf_index = 0);

			int32_t SetWrapS(Surface::TextureWrap value, uint32_t sce_paf_index = 0);

			int32_t SetWrapT(Surface::TextureWrap value, uint32_t sce_paf_index = 0);

			int32_t GetMinFilter(uint32_t sce_paf_index = 0);

			int32_t GetMagFilter(uint32_t sce_paf_index = 0);

			int32_t GetWrapS(uint32_t sce_paf_index = 0);

			int32_t GetWrapT(uint32_t sce_paf_index = 0);

			void SetAlign(AlignMode ax, AlignMode ay);

			void SetScaleMode(ScaleMode sx, ScaleMode sy);

			void SetScaleValue(math::v3 const& scale);

			void SetDivBorderScale(float scale);

		protected:

			int32_t unk_50;
			AlignMode m_align_x;
			AlignMode m_align_y;
			ScaleMode m_scale_mode_x;
			ScaleMode m_scale_mode_y;
			math::v4 *m_tex_region;
			char m_unk_68[0x20];
			math::v3 m_scale_value;
			char m_unk_98[0x24];
			float m_div_border_scale;
			int32_t m_unk_C0;
			intrusive_ptr<Surface> m_tex_surface[4];
			int32_t m_unk_D4;

			__declspec(dllimport) static const char *m_drawobj_type;
		};

		class PlaneObjParam : public DrawObjParam
		{
		public:

			virtual const char *GetParamName(void) const;

			PlaneObjParam();
			virtual ~PlaneObjParam();

			virtual int Create(int mode);
			virtual int SetEach(DrawObj *);
			virtual int GetEach(DrawObj *);

			const char *ParamName(void);

		private:

			unsigned char m_unk_0x50[0x98];

			__declspec(dllimport) static const char m_param_name[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_DRAWOBJ_PLANE_OBJ_H */
