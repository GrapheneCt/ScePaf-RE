/*
	ScePaf-RE Project
*/

#ifndef _PAF_PAF_TYPES_H
#define _PAF_PAF_TYPES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ScePafInit {
	uint32_t global_heap_size;
	int32_t reserved[2];
	int32_t cdlg_mode;
	int32_t global_heap_alignment;
	int32_t global_heap_disable_assert_on_alloc_failure;
} ScePafInit;

#if defined(SCE_PAF_FULL_BUILD)
#if defined(_WIN32)
#define SCE_PAF_IMPORTED_FROM_PRX __declspec(dllexport)
#else
#error Current target platform is not supported or no target platform defined
#endif
#else
#if defined(__SNC__) || defined(_WIN32)
#define SCE_PAF_IMPORTED_FROM_PRX __declspec(dllimport)
#elif defined(__vita__)
#define SCE_PAF_IMPORTED_FROM_PRX
#else
#error Current target platform is not supported or no target platform defined
#endif
#endif

typedef enum ImageMode : int32_t
{
	ImageMode_NONE = -1,
	ImageMode_XBGR0565 = 0,
	ImageMode_ABGR1555 = 1,
	ImageMode_ABGR4444 = 2,
	ImageMode_ABGR8888 = 3,		//unsupported
	ImageMode_RGBA8888 = 4,
	ImageMode_ARGB8888 = 5,
	ImageMode_BGRA8888 = 6,
	ImageMode_WZYX16FP = 7,		//unsupported
	ImageMode_WZYX32FP = 8,		//unsupported
	ImageMode_XCRYCB8888 = 9,	//unsupported
	ImageMode_CRYCBX8888 = 10,	//unsupported
	ImageMode_XCRYCB16FP = 11,	//unsupported
	ImageMode_RGBX16INT = 12,	//unsupported
	ImageMode_CRYCBX16INT = 13,	//unsupported
	ImageMode_A8 = 14,
	ImageMode_L8 = 15,
	ImageMode_DXT1 = 16,
	ImageMode_DXT2 = 17,		//unsupported
	ImageMode_DXT3 = 18,
	ImageMode_DXT4 = 19,		//unsupported
	ImageMode_DXT5 = 20,
	ImageMode_index4 = 21,
	ImageMode_index8 = 22,
	ImageMode_index16 = 23,		//unsupported
	ImageMode_index32 = 24,		//unsupported
	ImageMode_BGR888 = 25,		//unsupported
	ImageMode_RGB888 = 26,		//unsupported
	ImageMode_YUV420P2 = 27,
	ImageMode_YUV420P3 = 28,
	ImageMode_PVRT2BPP = 29,
	ImageMode_PVRT4BPP = 30,
	ImageMode_PVRTII2BPP = 31,
	ImageMode_PVRTII4BPP = 32,
	ImageMode_depth16 = 100,
	ImageMode_depth32 = 101,
	ImageMode_A16FP = 102,
	ImageMode_A32FP = 103
} ImageMode;

typedef enum Locale : int32_t
{
	Locale_Default = -1,
	Locale_JP = 0,
	Locale_MIN = 0,
	Locale_EN = 1,
	Locale_FR = 2,
	Locale_ES = 3,
	Locale_DE = 4,
	Locale_IT = 5,
	Locale_NL = 6,
	Locale_PT = 7,
	Locale_RU = 8,
	Locale_KO = 9,
	Locale_ZH_T = 10,
	Locale_ZH_S = 11,
	Locale_FI = 12,
	Locale_SV = 13,
	Locale_DA = 14,
	Locale_NO = 15,
	Locale_PL = 16,
	Locale_TR = 17,
	Locale_MAX = 17,
} Locale;

typedef enum ResolutionId : int32_t
{
	ResolutionId_Landscape_Padkey_Headside = 0,
	ResolutionId_Landscape_Padkey_Footside = 1,
	ResolutionId_Portrait_Padkey_Leftside = 2,
	ResolutionId_Portrait_Padkey_Rightside = 3,
	ResolutionId_HD_Full = 4,
	ResolutionId_HD_Half = 5,
	ResolutionId_SD_NTSC = 6,
	ResolutionId_SD_PAL = 7,
	ResolutionId_PSP = 8,
	ResolutionId_END = 9
} ResolutionId;

typedef enum ResolutionType : int32_t
{
	ResolutionType_Landscape = 9,
	ResolutionType_Portrait = 10,
	ResolutionType_HD = 11,
	ResolutionType_SD = 12,
	ResolutionType_PSP = 13
} ResolutionType;

typedef enum OrientationType : int32_t
{
	OrientationType_Standard = 0,
	OrientationType_Upsidedown = 1,
	OrientationType_Rightsidedown = 2,
	OrientationType_Leftsidedown = 3,
	OrientationType_Auto = 4
} OrientationType;

typedef enum ImageOrder : int32_t
{
	ImageOrder_NONE = -1,
	ImageOrder_Linear = 1,
	ImageOrder_Normal = 1,
	ImageOrder_Swizzle = 2,
	ImageOrder_Tiled = 3
} ImageOrder;

typedef enum CharEncoding : int32_t
{
	CharEncoding_AllowIllegalCode = 0x2,
	CharEncoding_AllowOutOfCodeRange = 0x4,
	CharEncoding_AllowInvalidEncode = 0x8,
	CharEncoding_AllowSrcBufferEnd = 0x10
} CharEncoding;

#define SCE_PAF_OK	(0)

#define SCE_PAF_ERROR_THREAD_ALREADY_STARTED	(0x80AF0702)

#define SCE_PAF_ERROR_JOB_ALREADY_IN_QUEUE		(0x80AF0901)
#define SCE_PAF_ERROR_JOB_NO_THREADS			(0x80AF0902)

#define SCE_PAF_ERROR_FILE_INVALID_OFFSET		(0x80AF5001)
#define SCE_PAF_ERROR_FILE_INVALID_ARGUMENT		(0x80AF5002)
#define SCE_PAF_ERROR_FILE_NO_MEMORY			(0x80AF5003)
#define SCE_PAF_ERROR_FILE_READ_ONLY			(0x80AF5004)
#define SCE_PAF_ERROR_FILE_NOT_SUPPORTED		(0x80AF5005)
#define SCE_PAF_ERROR_FILE_PROTECTED			(0x80AF5006)
#define SCE_PAF_ERROR_FILE_BAD_FILE				(0x80AF5021)
#define SCE_PAF_ERROR_FILE_NO_ENTRY				(0x80AF5022)
#define SCE_PAF_ERROR_FILE_TOO_MANY				(0x80AF5023)
#define SCE_PAF_ERROR_FILE_NO_DEVICE			(0x80AF5024)
#define SCE_PAF_ERROR_FILE_NO_ACCESS			(0x80AF5025)
#define SCE_PAF_ERROR_FILE_EXIST				(0x80AF5026)
#define SCE_PAF_ERROR_FILE_NO_SPACE				(0x80AF5027)
#define SCE_PAF_ERROR_FILE_ALREADY_OPENED		(0x80AF5028)
#define SCE_PAF_ERROR_FILE_NOT_OPENED			(0x80AF5029)
#define SCE_PAF_ERROR_FILE_BUSY					(0x80AF5041)
#define SCE_PAF_ERROR_FILE_NOT_BUSY				(0x80AF5042)

#define SCE_PAF_ERROR_CXML_CANT_READ			(0x80AF0501)
#define SCE_PAF_ERROR_CXML_CANT_SEEK			(0x80AF0503)
#define SCE_PAF_ERROR_CXML_CANT_ALLOC			(0x80AF0504)
#define SCE_PAF_ERROR_CXML_FORMAT				(0x80AF0505)
#define SCE_PAF_ERROR_CXML_VERSION				(0x80AF0506)
#define SCE_PAF_ERROR_CXML_INVALID_NODE			(0x80AF0507)
#define SCE_PAF_ERROR_CXML_NOT_ENOUGH_BUF		(0x80AF0508)
#define SCE_PAF_ERROR_CXML_ACCESS_MODE			(0x80AF0509)
#define SCE_PAF_ERROR_CXML_NOT_EXIST			(0x80AF050A)
#define SCE_PAF_ERROR_CXML_TYPE					(0x80AF050B)
#define SCE_PAF_ERROR_CXML_NO_ALLOCATOR			(0x80AF050D)

#ifdef __cplusplus
}
#endif

#endif /* _PAF_PAF_TYPES_H */