/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_MAIN_THREAD_CALL_H
#define _VDSUITE_USER_PAF_COMMON_MAIN_THREAD_CALL_H

namespace paf {
	namespace common {

		class MainThreadCall
		{
		public:

			typedef void(*Function)(void *userdata);

			MainThreadCall(Function func, void *userdata);

			~MainThreadCall();

			void Run();
		};
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_MAIN_THREAD_CALL_H */
