/*
	Vita Development Suite Libraries git-9c2c72f1
*/

#ifndef _VDSUITE_USER_PAF_GRAPHICS_H
#define _VDSUITE_USER_PAF_GRAPHICS_H

#include <kernel.h>
#include <gxm.h>
#include <scetypes.h>
#include <sce_atomic.h>

namespace paf {

	namespace graph {

		class Callback
		{
		public:

			Callback() : unk_00(0) { };

			virtual ~Callback() { };

			virtual SceVoid Run(SceUInt32 drawType) = 0;

		private:

			SceInt32 unk_00;

		};

		class DrawObj
		{
		public:

			DrawObj(SceInt32 *ref);

			virtual bool equal(const char *name);
			virtual const char *name() const;
			virtual ~DrawObj();
			virtual SceInt32 unkFun_10();
			virtual SceInt32 unkFun_14();
			virtual SceInt32 unkFun_18();
			virtual SceInt32 unkFun_1C();
			virtual SceInt32 unkFun_20();
			virtual SceInt32 unkFun_24();
			virtual SceInt32 unkFun_28();
			virtual SceInt32 unkFun_2C();
			virtual SceInt32 unkFun_30();
			virtual SceInt32 unkFun_34();
			virtual SceInt32 unkFun_38();
			virtual SceInt32 unkFun_3C();
			virtual SceInt32 unkFun_40();
			virtual SceInt32 unkFun_44();

			SceVoid SetDrawCallback(SharedPtr<Callback> *drawCb);

		protected:

			__declspec(dllimport) static char *_Myname;

		private:

			SceUChar8 unk_00[0x4C];

		};

		class TextObj : public DrawObj
		{
		public:

			TextObj(SceInt32 *ref);

			virtual bool equal(const char *name);
			virtual const char *name() const;
			virtual ~TextObj();
			virtual SceInt32 unkFun_10();
			virtual SceInt32 unkFun_14();
			virtual SceInt32 unkFun_18();
			virtual SceInt32 unkFun_1C();
			virtual SceInt32 unkFun_20();
			virtual SceInt32 unkFun_24();
			virtual SceInt32 unkFun_28();
			virtual SceInt32 unkFun_2C();
			virtual SceInt32 unkFun_30();
			virtual SceInt32 unkFun_34();
			virtual SceInt32 unkFun_38();
			virtual SceInt32 unkFun_3C();
			virtual SceInt32 unkFun_40();
			virtual SceInt32 unkFun_44();

			SceInt32 GetLabel(wstring *pText);

			SceInt32 SetLabel(wstring *pText);

			SceInt32 SetPlaceholderLabel(wstring *pText);

			SceInt32 GetPlaceholderLabel(wstring *pText);

			SceInt32 GetLength(SceUInt32 *pLength);

			SceInt32 GetDataAndLength(SceWChar16 **ppData, SceUInt32 *pLength);

		private:

			SceUChar8 unk_00[0x54];

		};

		__declspec (dllimport) SceInt32 *s_drawObjRef;

		class SurfacePool
		{
		public:

			enum SurfacePoolType
			{
				SurfacePoolType_Normal,
				SurfacePoolType_SharedHost,
				SurfacePoolType_SharedClient,
			};

			enum MemoryType
			{
				MemoryType_UserNC,
				MemoryType_CDRAM,
				MemoryType_Shared,
			};

			class Option
			{
			public:

				ScePVoid pMemory;
				SceSize size;
				char *pName;
				paf::memory::HeapAllocator::Option *pAllocatorOpt;
				paf::memory::HeapAllocator::Option *pAllocator2Opt;
				SurfacePoolType poolType;
			};

			SurfacePool(const Option *pInitParam);

			SurfacePool(const ScePVoid pMemory, SceSize size, const char *pName, paf::memory::HeapAllocator::Option *pAllocatorOpt = SCE_NULL, SurfacePoolType poolType = SurfacePoolType_Normal);

			virtual ~SurfacePool();

			virtual ScePVoid Allocate(SceInt32 alignment, SceInt32 size);
			virtual SceVoid Free(ScePVoid ptr);
			virtual SceSize GetFreeSize();

			enum MemoryTypeSpecial
			{
				MemoryTypeSpecial_Unused,
				MemoryTypeSpecial_Tool,
				MemoryTypeSpecial_Phycont
			};

			enum GpuMapType
			{
				GpuMapType_Normal,
				GpuMapType_VertexUsse,
				GpuMapType_FragmentUsse,
				GpuMapType_NoMap
			};

			class SurfaceMemoryOption
			{
			public:

				MemoryTypeSpecial memoryTypeSpecial;
				SceKernelAllocMemBlockOpt *memBlockOpt;
				GpuMapType gpuMapType;
				SceUInt32 mapAttribs;
				SceUInt32 usseOffset;
				SceUInt32 unused;
			};

			static ScePVoid AllocSurfaceMemory(MemoryType memoryType, SceSize size, const char *pName, SurfaceMemoryOption *pOptParam = SCE_NULL);

			static SceVoid FreeSurfaceMemory(MemoryType memoryType, ScePVoid pMemory);

			static SurfacePool *GetDefaultSurfacePool();

		public:

			ScePVoid allocator;
			ScePVoid membase;
			SceSize memsize;
			char *name;
			SurfacePoolType type;
			SceUID sharedMemUID;
			ScePVoid sharedMemBase;
			SceInt32 allocCount;
			SceSize reservedSize;
			thread::Mutex mtx;
		};

		class Surface
		{
		public:

			class GxmTexture
			{
			public:

				SceGxmTexture *texture;
				SceInt32 unk_04;
			};

			class Base
			{
			public:

				Base *prev;
				Base *next;
				SceInt32 refCount;
				SceUInt16 width;
				SceUInt16 height;
				SceInt32 texType; // linear/swizzled/tiled
				SceInt32 unk_14;
				SceInt32 unk_18;
				SceUInt16 widthAligned;
				SceUInt16 heightAligned;
				SceFloat32 xScale;
				SceFloat32 yScale;
				SceInt32 byteSize;
				SceUInt16 width3;
				SceUInt16 unk_3e;
				SceInt32 unk_30;
				GxmTexture *texture;
				SceGxmTextureFilter magFilter;
				SceGxmTextureFilter minFilter;
				SceGxmTextureFilter mipFilter;
				SceGxmTextureAddrMode uaddrMode;
				SceGxmTextureAddrMode vaddrMode;
				SceUInt32 lodBias;
				SceInt32 unk_50;
				SceInt32 unk_54;
				SceInt32 unk_58;
				ScePVoid gxmData;
			};

			Surface(SurfacePool *memPool, SceInt32 width, SceInt32 height, paf::image::ImageMode mode, paf::image::ImageOrder order, SceInt32 a6, SceUInt32 numLevel, SceInt32 a8); //0x7C8B2A63

			virtual ~Surface();

			virtual SceInt32 unkFun_0C();
			virtual SceInt32 unkFun_10();
			virtual SceInt32 unkFun_14();
			virtual SceInt32 unkFun_18();
			virtual SceInt32 unkFun_1C();
			virtual SceInt32 unkFun_20();
			virtual ScePVoid Lock(SceInt32 lockArea = 0); // Returns pointer to surface memory
			virtual SceVoid  Unlock();
			virtual SceInt32 unkFun_2C();
			virtual SceInt32 unkFun_30();

			void* operator new(size_t size);

			void operator delete(void*);

			static SceVoid Create(Surface **res, SurfacePool *memPool, SharedPtr<File> *file, ScePVoid fwOpt = SCE_NULL);

			static SceVoid Create(Surface **res, SurfacePool *memPool, const ScePVoid ptr, SceInt32 unused_1, SceSize size, SceInt32 unused_2 = 0, ScePVoid fwOpt = SCE_NULL);

			SceInt32 Copy(SceUInt32 level, ScePVoid srcAddr, paf::image::ImageOrder srcOrder, SceInt32 srcMemPitch, SceInt32 a6 = -1);

			SceInt32 Release();

			SceInt32 UnsafeRelease()
			{
				sceAtomicDecrement32AcqRel(&this->base.refCount);
				return this->base.refCount; 
			};

			SceInt32 AddRef();

			//ScePafGraphics_879B135D
			ScePVoid GetGxmData();

			//ScePafGraphics_D075A824
			SceInt32 ReplaceData(SceGxmTexture **tex, const ScePVoid data);

			//ScePafGraphics_3B5327DF
			SceUInt32 GetPixelCount();

			//ScePafGraphics_804E92B1
			SceInt32 ApplyFilters();

			SceInt32 texFormat;
			SceInt32 unk_08;
			SceInt32 unk_0C;
			Base base;

		private:

			SceUChar8 m_work[0x24];

		};

		class GraphicsContext
		{
		public:

			class ShaderPatcher {
			public:

				SceGxmShaderPatcher *shaderPatcher;

				//more?
			};

			enum Target
			{
				Target_None,
				Target_Front,
				Target_Back
			};

			static GraphicsContext *GetGraphicsContext();

			static SharedPtr<Callback> *GetDefaultDrawCallback();

			static SceGxmContext *GetGxmContext();

			//ScePafGraphics_E4B3B1D2
			SceVoid Finish();

			//ScePafGraphics_751FC8E6
			SceInt32 BeginScene(const SceGxmRenderTarget *renderTarget, SceGxmSyncObject *fragmentSyncObject, const SceGxmColorSurface *colorSurface, const SceGxmDepthStencilSurface *depthStencilSurface, SceUInt32 flags);

			//ScePafGraphics_D5E30C64
			SceInt32 EndScene(const SceGxmNotification *vertexNotification, const SceGxmNotification *fragmentNotification);

			//ScePafGraphics_6E7B77AC
			SceVoid SetWClampValue(float clampValue);

			//ScePafGraphics_84619C66
			SceVoid SetPolygonMode(SceGxmPolygonMode mode, SceUInt32 target);

			//ScePafGraphics_D9EA2729
			SceVoid SetPointLineWidth(SceFloat32 width, SceUInt32 target);

			//ScePafGraphics_9EAD43B5
			SceVoid SetPointLineWidth2(SceFloat32 width, SceUInt32 target);

			//ScePafGraphics_DAC195AC
			SceVoid SetStencilFunc(SceGxmStencilFunc func, SceGxmStencilOp stencilFail, SceGxmStencilOp depthFail, SceGxmStencilOp depthPass, uint8_t compareMask, uint8_t writeMask, SceUInt32 target);

			//ScePafGraphics_722A4987
			SceVoid SetCullMode(SceGxmCullMode mode);

			//ScePafGraphics_7EC1D482
			SceVoid SetDepthFunc(SceGxmDepthFunc depthFunc, SceUInt32 target);

			//ScePafGraphics_2AE23377
			SceVoid SetDepthWriteEnable(SceGxmDepthWriteMode enable, SceUInt32 target);

			//ScePafGraphics_5F8FDEC7
			SceVoid ResetParam(SceUInt32 targetParam);

			SceUChar8 unk_000[0x61C];

			ShaderPatcher *shaderPatcher;

			SceUChar8 unk_620[0x6C];

			SceGxmContext *gxmContext;

			SceUChar8 unk_690[0xD4];

			SceUInt8 frontDepthWriteEnabled;
			SceUInt8 backDepthWriteEnabled;

			SceUInt16 unk_766;

			SceGxmCullMode cullMode;
		};

		//VARIABLES

		__declspec (dllimport) paf::thread::Mutex s_surfaceMutex;
		__declspec (dllimport) paf::thread::Mutex s_surfaceCLUTMutex;
	}
}

#endif /* _VDSUITE_USER_PAF_GRAPHICS_H */
