/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_CACHE_CACHE_BASE_H
#define _VDSUITE_USER_PAF_CACHE_CACHE_BASE_H

#include <stdint.h>
#include <stddef.h>
#include <paf/paf_types.h>
#include <paf/std/stdcxx.h>
#include <paf/common/shared_ptr.h>

namespace paf {

	class File;

	namespace job {

		class JobQueue;
	}

	namespace cache {

		class CacheJobRunner;
		class CacheManagerImpl;

		class CacheBase
		{
		public:

			class Option
			{
			public:

				/*
				bool auto_delete;
				uint8_t load_type;
				size_t read_size;
				size_t read_offset
				*/
				char unk_00[0x20];
			};

			static CacheBase *CreateCacheInstance(CacheManagerImpl *manager, const Option *option);

			static void DestroyCacheInstance(CacheBase *cache);

			static bool CheckLongLifeHeap(CacheBase *base);

			CacheBase(CacheManagerImpl *manager, const Option *option, uint8_t cache_type);

			virtual ~CacheBase();

			virtual void DestroyInstance();

			virtual bool DiffOption(const Option *option);

			virtual int32_t RestartJob();

			virtual int32_t JobRun();

			virtual int32_t JobFinish(int32_t result, bool& is_finished);

			virtual bool IsEnableReleaseInstance();

			void Clear();

			int32_t AddRef();

			int32_t Release();

			void *GetData();

			void *GetDataPtr()
			{
				return m_data;
			}

			void Init();

			void Term();

			int32_t LoadFile();

			void GetExtension(string const& path);

			bool IsCancel(void *userdata);

			void Touch();

			int32_t GetTicks();

			void SetTicks(int32_t ticks);

			CacheJobRunner *GetJobItem()
			{
				return m_job;
			}

			uint32_t GetJobStatus()
			{
				return m_job_state;
			}

			string& GetPath()
			{
				return m_path;
			}

			int32_t GetRefCount()
			{
				return m_ref_count;
			}

			bool GetRegistManagerFlag()
			{
				return m_regist_manager;
			}

			off_t GetSize()
			{
				return m_size;
			}

			uint32_t GetType()
			{
				return m_cache_type;
			}

			bool IsAutoDelete()
			{
				return m_auto_delete;
			}

			void RegistManagerFlag(bool flag)
			{
				m_regist_manager = flag;
			}

			void SetCacheManager(CacheManagerImpl *man)
			{
				m_manager = man;
			}

			void SetJobQueue(job::JobQueue *q, uint32_t sce_paf_index)
			{
				m_jobq[sce_paf_index] = q;
			}

			void SetJobStatus(uint32_t s, CacheJobRunner *job)
			{
				m_job_state = s;
				m_job = job;
			}

			void SetPath(string const& path)
			{
				m_path = path;
			}

		private:

			CacheManagerImpl *m_manager;
			uint8_t m_cache_type;
			uint8_t m_load_type;
			uint8_t m_job_state;
			int32_t m_error;
			int32_t m_ref_count;
			job::JobQueue *m_jobq[2];
			CacheJobRunner *m_job;
			string m_path;
			void *m_data;
			off_t m_size;
			size_t m_read_size;
			size_t m_read_offset;

			int32_t m_unk_40;

			bool m_auto_delete : 1;
			bool m_regist_manager : 1;
			bool m_instance_heap : 1;

			int32_t m_unk_48;

			int32_t m_ticks;

			int32_t m_unk_50;
			int32_t m_unk_54;
			int32_t m_unk_58;

			common::SharedPtr<File> m_file;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_CACHE_CACHE_BASE_H */
