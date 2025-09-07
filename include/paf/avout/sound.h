/*
	ScePaf-RE Project
*/

#ifndef _PAF_AVOUT_SOUND_H
#define _PAF_AVOUT_SOUND_H

#ifndef SCE_PAF_NO_SOUND

#include <stdint.h>

#if defined(__SNC__) || defined(__vita__) || defined(_WIN32)

#else
#error Current target platform is not supported or no target platform defined
#endif

#if defined(_WIN32)
#undef PlaySound
#endif

namespace paf {
	namespace sound {

		class Output
		{
		public:

			enum Mode : int32_t
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

				enum State : int32_t
				{
					State_Default = 0,
					State_Playing = 1,
					State_Stopped = 2,
				};

				State state;
				const char *buffer;
#if defined(__SNC__) || defined(__vita__)
				int32_t no;
				char unk_0C[0xC];
#elif defined(_WIN32)
				bool is_2ch;
				uint64_t sound_left_mono;
				uint64_t sound_right;
				uint64_t source_left_mono;
				uint64_t source_right;
				uint64_t sfx_left_mono;
				uint64_t sfx_right;
#endif
			};

			void Init(int32_t mode);

			char m_common_se[0x528];
			int32_t m_is_init;
			int32_t m_disable_count;
			bool m_enabled;
			Sound m_sounds[8];
			int32_t m_se_num;
		};
	}
}

#endif /* SCE_PAF_NO_SOUND */

#endif /* _PAF_AVOUT_SOUND_H */
