/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_AVOUT_SOUND_H
#define _VDSUITE_USER_PAF_AVOUT_SOUND_H

#include <stdint.h>

namespace paf {
	namespace sound {

		class Output
		{
		public:

			enum Mode
			{
				Mode_Normal = 0,
				Mode_CommonDialog = 1,
				Mode_None = 2,
			};

			Output(int32_t mode);

			~Output();

			void Update();

			bool EnableSound(bool enable);

			void StopSound(const char *buffer);

			void StopSoundAll();

			void WaitSoundStopped();

			void PlayADPCM1ch(const char *buffer, uint32_t size, int32_t samplerate, float vol, bool ignore_init);

			void PlayADPCM2ch(const char *buffer1, uint32_t size1, const char *buffer2, uint32_t size2, int32_t samplerate, float vol, bool ignore_init);

			void PlaySound(const char *buffer, uint32_t size, int32_t samplerate, float vol, bool ignore_init);

			void PlaySound(const char *buffer1, uint32_t size1, const char *buffer2, uint32_t size2, int32_t samplerate, float vol, bool ignore_init);

		private:

			class Sound
			{
			public:

				enum State
				{
					State_Default = 0,
					State_Playing = 1,
					State_Stopped = 2,
				};

				int32_t state;
				char *buffer;
				int32_t no;
			};

			void Init(int32_t mode);

			char m_common_se[0x528];
			int32_t m_is_init;
			int32_t m_unk_52C;
			bool m_enabled;
			Sound m_sounds[8];
			int32_t m_se_num;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_AVOUT_SOUND_H */
