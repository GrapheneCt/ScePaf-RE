/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_AUTOTEST_TTY_H
#define _VDSUITE_USER_PAF_AUTOTEST_TTY_H

#include <stdint.h>
#include <stddef.h>
#ifdef __SNC__
#include <kernel.h>
#else
#include <psp2/kernel/processmgr.h>
#endif

namespace paf {
	namespace autotest
	{

		enum TestType
		{
			TestType_UserDefined,
			TestType_Class,
			TestType_Focus,
			TestType_Event
		};

#if defined(SCE_PAF_TOOL_PRX) && defined(__SNC__)

#pragma comment(lib, "libScePafAutoTestTty_stub_weak.a")

#define SCE_PAF_AUTO_TEST_SET_DEFAULT_EXTRA_TTY() \
		{ \
			extern SceUID sceKernelGetStdout(); \
			void *ptr = &paf::basic_string<char>::empty_string; \
			*(SceUID *)(ptr - 0xC8) = sceKernelGetStdout(); \
		}

#define SCE_PAF_AUTO_TEST_SET_EXTRA_TTY(x) \
		{ \
			void *ptr = &paf::basic_string<char>::empty_string; \
			*(SceUID *)(ptr - 0xC8) = x; \
		}

		extern void Dump(TestType type, const char *fmt, ...);

		#define SCE_PAF_AUTO_TEST_DUMP(format, ...)			paf::autotest::Dump(paf::autotest::TestType_UserDefined, format, ##__VA_ARGS__)
		#define SCE_PAF_AUTO_TEST_DUMP_CLASS(format, ...)	paf::autotest::Dump(paf::autotest::TestType_Class, format, ##__VA_ARGS__)
		#define SCE_PAF_AUTO_TEST_DUMP_FOCUS(format, ...)	paf::autotest::Dump(paf::autotest::TestType_Focus, format, ##__VA_ARGS__)
		#define SCE_PAF_AUTO_TEST_DUMP_EVENT(format, ...)	paf::autotest::Dump(paf::autotest::TestType_Event, format, ##__VA_ARGS__)
#else
		static void Dump(TestType type, const char *fmt, ...)
		{

		}

		#define SCE_PAF_AUTO_TEST_SET_DEFAULT_EXTRA_TTY()
		#define SCE_PAF_AUTO_TEST_SET_EXTRA_TTY(x)
		#define SCE_PAF_AUTO_TEST_DUMP(format, ...)
		#define SCE_PAF_AUTO_TEST_DUMP_CLASS(format, ...)
		#define SCE_PAF_AUTO_TEST_DUMP_FOCUS(format, ...)
		#define SCE_PAF_AUTO_TEST_DUMP_EVENT(format, ...)
#endif
	};
}

#endif /* _VDSUITE_USER_PAF_AUTOTEST_TTY_H */
