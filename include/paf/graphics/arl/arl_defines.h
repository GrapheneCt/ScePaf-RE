/*
	ScePaf-RE Project
*/

#ifndef _PAF_GRAPHICS_ARL_ARL_DEFINES_H
#define _PAF_GRAPHICS_ARL_ARL_DEFINES_H

namespace paf {
	namespace graph {
		namespace arl {
			
			enum PolygonModeEnum : int32_t
			{
				POLYGON_MODE_FILL = 0,
				POLYGON_MODE_POINT_10UV = 0x10000,
				POLYGON_MODE_POINT = 0x20000,
				POLYGON_MODE_POINT_01UV = 0x20000,
				POLYGON_MODE_LINE = 0x28000,
				POLYGON_MODE_TRIANGLE_LINE = 0x28000,
				POLYGON_MODE_TRIANGLE_POINT = 0x30000
			};
			
			enum DepthFuncEnum : int32_t
			{
				DEPTH_NEVER = 0,
				DEPTH_LESS = 0x400000,
				DEPTH_EQUAL = 0x800000,
				DEPTH_LEQUAL = 0xC00000,
				DEPTH_GREATER = 0x1000000,
				DEPTH_NOTEQUAL = 0x1400000,
				DEPTH_GEQUAL = 0x1800000,
				DEPTH_ALWAYS = 0x1C00000
			};
			
			enum CullModeEnum : int32_t
			{
				CULL_NONE = 0,
				CULL_CW = 1,
				CULL_CCW = 2
			};
			
			enum BlendingFactor : int32_t
			{
				ZERO = 0,
				ONE = 1,
				SRC_COLOR = 2,
				ONE_MINUS_SRC_COLOR = 3,
				SRC_ALPHA = 4,
				ONE_MINUS_SRC_ALPHA = 5,
				DST_COLOR = 6,
				ONE_MINUS_DST_COLOR = 7,
				DST_ALPHA = 8,
				ONE_MINUS_DST_ALPHA = 9,
				SRC_ALPHA_SATURATE = 10,
				DST_ALPHA_SATURATE = 11
			};
			
			enum BlendEquationEnum : int32_t
			{
				FUNC_ADD = 1,
				FUNC_SUBTRACT = 2,
				FUNC_REVERSE_SUBTRACT = 3
			};
			
			enum FaceEnum : int32_t
			{
				FRONT = 1,
				BACK = 2,
				FRONT_AND_BACK = 3
			};
			
			enum EnableCap : int32_t
			{
				BLEND = 0,
				DITHER = 1,
				STENCIL_TEST = 2,
				DEPTH_TEST = 3,
				SCISSOR_TEST = 4,
				POLYGON_OFFSET_FILL = 5,
				SAMPLE_ALPHA_TO_COVERAGE = 6,
				SAMPLE_COVERAGE = 7,
				WCLAMP = 8,
				WBUFFER = 9,
				TWO_SIDED = 10
			};

			enum SurfaceFlagsBits : int32_t
			{
				READ = 0,
				WRITE = 1,
				PALETTE = 2,
				TEXTURE = 3,
				TEXTURE_LINEAR = 4,
				TEXTURE_LINEAR_STRIDED = 5,
				TEXTURE_TILED = 6,
				TEXTURE_SWIZZLED = 7,
				TEXTURE_ALLOC_MIPMAPS = 8,
				COLOR_SURFACE = 9,
				COLOR_SURFACE_LINEAR = 10,
				COLOR_SURFACE_TILED = 11,
				COLOR_SURFACE_SWIZZLED = 12,
				COLOR_SURFACE_SCALE_NONE = 13,
				COLOR_SURFACE_SCALE_MSAA_DOWNSCALE = 14,
				COLOR_SURFACE_OUTPUT_REGISTER_SIZE_32BIT = 15,
				COLOR_SURFACE_OUTPUT_REGISTER_SIZE_64BIT = 16,
				STENCILDEPTH_SURFACE = 17,
				STENCILDEPTH_SURFACE_LINEAR = 18,
				STENCILDEPTH_SURFACE_TILED = 19,
				STENCILDEPTH_SURFACE_FORCE_STORE = 20,
				STENCILDEPTH_SURFACE_FORCE_LOAD = 21
			};

			typedef paf::common::EnumFlag<paf::graph::arl::SurfaceFlagsBits> SurfaceFlags;
		}
	}
}

#endif /* _PAF_GRAPHICS_ARL_ARL_DEFINES_H */
