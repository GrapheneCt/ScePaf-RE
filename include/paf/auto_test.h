/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_AUTO_TEST_H
#define _VDSUITE_USER_PAF_AUTO_TEST_H

#include <kernel.h>

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

#if defined(SCE_PAF_TOOL_PRX)

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

		extern SceVoid Dump(TestType type, const char *fmt, ...);

		#define SCE_PAF_AUTO_TEST_DUMP(format, ...)			paf::autotest::Dump(paf::autotest::TestType_UserDefined, format, ##__VA_ARGS__)
		#define SCE_PAF_AUTO_TEST_DUMP_CLASS(format, ...)	paf::autotest::Dump(paf::autotest::TestType_Class, format, ##__VA_ARGS__)
		#define SCE_PAF_AUTO_TEST_DUMP_FOCUS(format, ...)	paf::autotest::Dump(paf::autotest::TestType_Focus, format, ##__VA_ARGS__)
		#define SCE_PAF_AUTO_TEST_DUMP_EVENT(format, ...)	paf::autotest::Dump(paf::autotest::TestType_Event, format, ##__VA_ARGS__)

		class EventCallback
		{
		public:

			typedef void(*EventHandler)(SceInt32 eventId, paf::ui::Widget *self, SceInt32, ScePVoid pUserData);

			EventCallback() : state(2), pUserData(SCE_NULL)
			{

			};

			virtual ~EventCallback()
			{

			};

			virtual SceInt32 HandleEvent(SceInt32 eventId, paf::ui::Widget *self, SceInt32 a3)
			{
				SceInt32 ret;

				if ((this->state & 1) == 0) {
					if (this->eventHandler != 0) {
						char *vptr = (char *)self;
						char *name = *(char **)(vptr + 0x140);
						if (sce_paf_strlen(name) > 2)
							SCE_PAF_AUTO_TEST_DUMP_EVENT("event=0x%X widget=%s", eventId, name);
						else
							SCE_PAF_AUTO_TEST_DUMP_EVENT("event=0x%X widget=%s", eventId, "NO_NAME");
						this->eventHandler(eventId, self, a3, this->pUserData);
					}
					ret = SCE_OK;
				}
				else {
					ret = 0x80AF4101;
				}

				return ret;
			};

			virtual EventHandler GetHandler()
			{
				return this->eventHandler;
			};

			SceInt32 state;
			ScePVoid pUserData;
			EventHandler eventHandler;

		};
#else
		static SceVoid Dump(TestType type, const char *fmt, ...)
		{

		}

		class EventCallback
		{
		public:

			typedef void(*EventHandler)(SceInt32 eventId, paf::ui::Widget *self, SceInt32, ScePVoid pUserData);

			EventCallback() : state(2), pUserData(SCE_NULL)
			{

			};

			virtual ~EventCallback()
			{

			};

			virtual SceInt32 HandleEvent(SceInt32 eventId, paf::ui::Widget *self, SceInt32 a3)
			{
				SceInt32 ret;

				if ((this->state & 1) == 0) {
					if (this->eventHandler != 0) {
						this->eventHandler(eventId, self, a3, this->pUserData);
					}
					ret = SCE_OK;
				}
				else {
					ret = 0x80AF4101;
				}

				return ret;
			};

			virtual EventHandler GetHandler()
			{
				return this->eventHandler;
			};

			SceInt32 state;
			ScePVoid pUserData;
			EventHandler eventHandler;

		};

		#define SCE_PAF_AUTO_TEST_SET_DEFAULT_EXTRA_TTY()
		#define SCE_PAF_AUTO_TEST_SET_EXTRA_TTY(x)
		#define SCE_PAF_AUTO_TEST_DUMP(format, ...)
		#define SCE_PAF_AUTO_TEST_DUMP_CLASS(format, ...)
		#define SCE_PAF_AUTO_TEST_DUMP_FOCUS(format, ...)
		#define SCE_PAF_AUTO_TEST_DUMP_EVENT(format, ...)
#endif
	};
}

#endif /* _VDSUITE_USER_PAF_LOWLAYER_H */
