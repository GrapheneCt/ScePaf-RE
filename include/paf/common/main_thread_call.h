/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_MAIN_THREAD_CALL_H
#define _PAF_COMMON_MAIN_THREAD_CALL_H

namespace paf {
	namespace common {

		class MainThreadCall
		{
		public:

			class StateCheck
			{
			public:

				StateCheck()
				{

				}

				virtual ~StateCheck()
				{

				}

				virtual bool IsReady()
				{
					return true;
				}

				virtual void Sleep();
			};

			typedef void(*Function)(void *userdata);

			MainThreadCall(StateCheck *check, Function func, void *userdata);

			~MainThreadCall();

			StateCheck *GetStateCheck()
			{
				return m_check;
			}

		private:

			static void Run(void *userdata);

			void Execute()
			{
				m_func(m_userdata);
			}

			StateCheck *m_check;
			Function m_func;
			void *m_userdata;
		};
	}
}

#endif /* _PAF_COMMON_MAIN_THREAD_CALL_H */
