/*
	Vita Development Suite Libraries git-9c2c72f1
*/

#ifndef _VDSUITE_USER_PAF_MISC_H
#define _VDSUITE_USER_PAF_MISC_H

#include <libsha1.h>
#include <kernel.h>
#include <rtc.h>
#include <touch.h>
#include <ctrl.h>
#include <motion.h>

namespace paf {

	class Rgba
	{
	public:

		Rgba() : r(0.0), g(0.0), b(0.0), a(0.0)
		{

		};

		Rgba(SceFloat32 r, SceFloat32 g, SceFloat32 b, SceFloat32 a) : r(r), g(g), b(b), a(a)
		{

		};

		~Rgba() { };

		SceFloat32 r;
		SceFloat32 g;
		SceFloat32 b;
		SceFloat32 a;
	};

	namespace memory {

		class HeapAllocator
		{
		public:

			class Option
			{
			public:

				Option() { };

				~Option() { };

				int a1;
				int a2;
				SceUInt8 skipDbgMsg;
				SceUInt8 a3_1;
				SceUInt8 a3_2;
				SceUInt8 a3_3;
				bool useCdlgMemory;
				SceSize alignment;
			};

			class HeapInfo
			{
			public:

				SceInt32 numOfFreeSpaces;
				SceInt32 freeSize;
			};

			HeapAllocator(ScePVoid membase, SceSize size, const char *name, const Option *pOpt = SCE_NULL);

			virtual SceInt32 GetType() const;
			virtual bool IsCdlgMemory() const;
			virtual char* GetName() const;
			virtual SceVoid GetRange(ScePVoid *membase, SceSize *size) const;
			virtual SceSize GetFreeSize();

			virtual ~HeapAllocator();

			static HeapAllocator *GetGlobalHeapAllocator();

			SceVoid sce_paf_free(ScePVoid ptr);

			SceVoid sce_paf_free_d(ScePVoid ptr, const char *msg = SCE_NULL, SceUInt32 p1 = 0, SceUInt32 p2 = 0);

			SceVoid sce_paf_mtrim();

			ScePVoid sce_paf_calloc(SceSize nitems, SceSize size);

			ScePVoid sce_paf_malloc(SceSize size);

			ScePVoid sce_paf_malloc_d(SceSize size, const char *msg = SCE_NULL, SceUInt32 p1 = 0, SceUInt32 p2 = 0);

			ScePVoid sce_paf_realloc(ScePVoid ptr, SceSize size);

			ScePVoid sce_paf_realloc_d(ScePVoid ptr, SceSize size, const char *msg = SCE_NULL, SceUInt32 p1 = 0, SceUInt32 p2 = 0);

			ScePVoid sce_paf_memalign(SceSize alignment, SceSize size);

			ScePVoid sce_paf_memalign_d(SceSize alignment, SceSize size, const char *msg = SCE_NULL, SceUInt32 p1 = 0, SceUInt32 p2 = 0);

			SceVoid sce_paf_musable_size(ScePVoid ptr);

			SceVoid sce_paf_dump_heap_status();

			bool CheckMemoryBounds(ScePVoid ptr);

			SceVoid QueryInfo(HeapInfo *info);

		private:

			SceUChar8 m_work[0x5C];

		};

		/*
		class HeapAllocator2
		{
		public:

			class Option
			{
			public:

				Option() { };

				~Option() { };

				int a1;
				int a2;
				SceUInt8 skipDbgMsg;
				SceUInt8 a3_1;
				SceUInt8 a3_2;
				SceUInt8 a3_3;
				bool useCdlgMemory;
				SceSize alignment;
			};

			class HeapInfo
			{
			public:

				SceInt32 numOfFreeSpaces;
				SceInt32 freeSize;
			};

			//ScePafMisc_0E353BB3
			HeapAllocator2(ScePVoid membase, SceSize size, const char *name, const Option *pOpt = SCE_NULL);

			virtual SceInt32 GetType() const;
			virtual bool IsCdlgMemory() const;
			virtual char* GetName() const;
			virtual SceVoid GetRange(ScePVoid *membase, SceSize *size) const;
			virtual SceSize GetFreeSize();

			//ScePafMisc_71E4B8B3 d1
			//ScePafMisc_E8F1AAF8 d2
			//ScePafMisc_1FD33B17 d0
			virtual ~HeapAllocator2();

			//ScePafMisc_D1A490F2
			SceVoid sce_paf_free(ScePVoid ptr);

			SceVoid sce_paf_free_d(ScePVoid ptr, const char *msg = SCE_NULL, SceUInt32 p1 = 0, SceUInt32 p2 = 0);

			SceVoid sce_paf_mtrim();

			ScePVoid sce_paf_calloc(SceSize nitems, SceSize size);

			ScePVoid sce_paf_malloc(SceSize size);

			ScePVoid sce_paf_malloc_d(SceSize size, const char *msg = SCE_NULL, SceUInt32 p1 = 0, SceUInt32 p2 = 0);

			ScePVoid sce_paf_realloc(ScePVoid ptr, SceSize size);

			ScePVoid sce_paf_realloc_d(ScePVoid ptr, SceSize size, const char *msg = SCE_NULL, SceUInt32 p1 = 0, SceUInt32 p2 = 0);

			//ScePafMisc_AA0732F6
			ScePVoid sce_paf_memalign(SceSize alignment, SceSize size);

			ScePVoid sce_paf_memalign_d(SceSize alignment, SceSize size, const char *msg = SCE_NULL, SceUInt32 p1 = 0, SceUInt32 p2 = 0);

			SceVoid sce_paf_musable_size(ScePVoid ptr);

			SceVoid sce_paf_dump_heap_status();

			//ScePafMisc_8AB8866F
			bool CheckMemoryBounds(ScePVoid ptr);

			SceVoid QueryInfo(HeapInfo *info);

		private:

			SceUChar8 m_work[0x5C];

		};
		*/
	}

	class Buffer
	{
		
	};

	class UnmanagedBuffer : public Buffer
	{
	public:

		virtual ScePVoid GetAddr();
		virtual ScePVoid GetAddr() const;
		virtual SceSize GetSize();

		virtual ~UnmanagedBuffer();

		static common::SharedPtr<UnmanagedBuffer> Create(ScePVoid addr, SceSize size);

	private:

		ScePVoid addr;
		SceSize size;
	};

	class UnmanagedConstBuffer : public Buffer
	{
	public:

		virtual ScePVoid GetAddr();
		virtual ScePVoid GetAddr() const;
		virtual SceSize GetSize();

		virtual ~UnmanagedConstBuffer();

		static common::SharedPtr<UnmanagedConstBuffer> Create(ScePVoid addr, SceSize size);

	private:

		ScePVoid addr;
		SceSize size;
		ScePVoid constAddr;
	};

	class MallocBuffer : public Buffer
	{
	public:

		virtual ScePVoid GetAddr();
		virtual ScePVoid GetAddr() const;
		virtual SceSize GetSize();

		virtual ~MallocBuffer();

		static common::SharedPtr<MallocBuffer> Create(ScePVoid addr, SceSize size);

		static common::SharedPtr<MallocBuffer> Allocate(SceSize size);

	private:

		ScePVoid addr;
		SceSize size;
	};

	class HeapAllocBuffer : public Buffer
	{
	public:

		virtual ScePVoid GetAddr();
		virtual ScePVoid GetAddr() const;
		virtual SceSize GetSize();

		virtual ~HeapAllocBuffer();

		static common::SharedPtr<HeapAllocBuffer> Create(ScePVoid addr, SceSize size, paf::memory::HeapAllocator *allocator);

		static common::SharedPtr<HeapAllocBuffer> Allocate(SceSize size, paf::memory::HeapAllocator *allocator);

	private:

		ScePVoid addr;
		SceSize size;
		paf::memory::HeapAllocator *allocator;
	};

	class Url
	{
	public:

		Url();

		//67BA6456 c1
		//987D8B51 c2
		Url(paf::string *url);

		virtual ~Url();

	private:

		SceUChar8 m_work[0x38];
		paf::common::String url;
	};

	namespace http {

		class Template
		{
		public:

			class Option
			{
			public:

				Option()
				{
					debugFlags = 1;
					resolveTimeout = 0;
					resolveRetry = 0;
					connectTimeout = 0;
					sendTimeout = 0;
					recvTimeout = 0;
					unk_48 = 1;
				}

				~Option() { }

				string userAgent;
				SceInt32 debugFlags; // can be 2, 4 or 8
				string username;
				string password;
				string referer;
				SceInt32 resolveTimeout;
				SceInt32 resolveRetry;
				SceInt32 connectTimeout;
				SceInt32 sendTimeout;
				SceInt32 recvTimeout;
				SceInt32 unk_48;
			};

			Template(Option *pOpt);

			~Template();

			SceInt32 SetResponseHeaderMaxSize(SceSize size);

		protected:

			string userAgent;
			SceInt32 debugFlags;
			string username;
			string password;
			string referer;
			SceInt32 resolveTimeout;
			SceInt32 resolveRetry;
			SceInt32 connectTimeout;
			SceInt32 sendTimeout;
			SceInt32 recvTimeout;
			SceInt32 unk_48;
			SceInt32 templateId;
		};

		class Request
		{
		public:

			Request(Template *pTmp);

			~Request();

			SceInt32 Connect(const char *url, const char *method, ScePVoid unkCb = SCE_NULL);

			//2D83836A
			//SceInt32 Connect(const char *url, const char *method, ScePVoid unkCb, SceInt32 unkHttpFlag, SceULong64 postContentLength);

			SceInt32 AddRequestHeader(const char *name, const char *value);

			SceInt32 Send(const ScePVoid postData = SCE_NULL, SceSize size = 0);

			SceInt32 GetStatusCode(SceInt32 *statusCode);

			SceInt32 GetFilename(string *filename);

			SceInt32 GetMimeType(string *mimeType);

			SceInt32 GetResponseHeaderField(const char *fieldName, string *fieldValue);

			SceInt32 GetContentLength(SceULong64 *contentLength);

			SceInt32 Read(common::SharedPtr<MallocBuffer> *pBuf, SceSize *pReadSize);

			SceInt32 GetAutoRedirect(bool *pEnabled);

			SceInt32 SetAutoRedirect(bool *enabled);

			SceInt32 Abort();

			SceInt32 GetUrl(string *pUrl);

		protected:

			Template *tmp;
			ScePVoid cbTask;
			SceInt32 connectionId;
			SceInt32 requestId;
			SceInt32 unk_10;
			string url;
		};
	}

	namespace rtc {

		typedef SceUInt64 Tick;

		class SQLiteDateTimeFormatType
		{

		};

		class DateTime
		{

		};

		class DateTimeEx
		{

		};

		extern SceInt32 IsLeapYear(SceUInt16 year);

		extern SceInt32 IsLeapYear(const Tick *pTick);

		extern SceInt32 GetDaysInMonth(const Tick *pTick);

		extern SceInt32 GetDaysInMonth(const SceUInt16 *pA1, SceUInt16 a2);

		extern SceInt32 ParseSQLiteDateTime(Tick *pTick, const char *dt);

		extern SceInt32 ParseSQLiteDateTime(Tick *pTick, SQLiteDateTimeFormatType *ftype, const char *dt);

		extern SceInt32 ConvertDateTimeToTick(DateTime const* src, Tick *pTick);

		extern SceInt32 ConvertTickToDateTime(Tick *pTick, DateTime *dst);

		extern SceInt32 GetCurrentLocalTick(Tick *pTick);

		extern SceInt32 GetCurrentTick(Tick *pTick);

		extern SceInt32 GetCurrentNetworkTick(Tick *pTick);

		extern SceInt32 TickAddMicroseconds(Tick *pTick0, const Tick *pTick1, SceLong64 lAdd);

		extern SceInt32 TickAddSeconds(Tick *pTick0, const Tick *pTick1, SceLong64 lAdd);

		extern SceInt32 TickAddMinutes(Tick *pTick0, const Tick *pTick1, SceLong64 lAdd);

		extern SceInt32 TickAddHours(Tick *pTick0, const Tick *pTick1, SceInt32 iAdd);

		extern SceInt32 TickAddDays(Tick *pTick0, const Tick *pTick1, SceInt32 iAdd);

		extern SceInt32 TickAddWeeks(Tick *pTick0, const Tick *pTick1, SceInt32 iAdd);

		extern SceInt32 TickAddMonths(Tick *pTick0, const Tick *pTick1, SceInt32 iAdd);

		extern SceInt32 TickAddYears(Tick *pTick0, const Tick *pTick1, SceInt32 iAdd);

		extern SceInt32 ConvertUtcToLocalTime(const Tick *pUtc, Tick *pLocalTime);

		extern SceInt32 ConvertLocalTimeToUtc(const Tick *pLocalTime, Tick *pUtc);

		extern SceInt32 ParseRFC3339(Tick *pUtc, const char *pszDateTime);

		extern SceInt32 ParseRFC3339LocalTime(Tick *pUtc, const char *pszDateTime);

		extern SceInt32 FormatRFC3339(char *pszDateTime, const Tick *pUtc, SceInt32 iTimeZoneMinutes);

		extern SceInt32 FormatRFC3339LocalTime(char *pszDateTime, const Tick *pUtc);
	}

	namespace datetime {

		class DateTime
		{
		public:

			DateTime
			(
				SceUInt16 year,
				SceUInt16 month,
				SceUInt16 day,
				SceUInt16 hour,
				SceUInt16 minute,
				SceUInt16 second,
				SceUInt32 microsecond
			);

			DateTime() { };

			~DateTime();

			static SceVoid SetTimeFormat(const wchar_t *format);
			static wchar_t *GetTimeFormat();

			static SceVoid SetDateFormat(const wchar_t *format);
			static wchar_t *GetDateFormat();

			static SceVoid SetDateTimeFormat(const wchar_t *format);

			static rtc::Tick ConvertDateTimeToRtcTick(DateTime& dt);

			SceVoid ConvertRtcTickToDateTime(paf::rtc::Tick *tick);

			SceVoid ParseRFC3339(const char *pszDateTime);

			SceVoid ParseSQLiteDateTime(const char *pszDateTime);

			SceVoid UTC();

			SceVoid Now();

			SceVoid NetworkUTC();

			SceVoid DayOfWeek(SceUInt16 a1, SceUInt16 a2, SceUInt16 a3);

			SceUInt32 Wcsftime(wchar_t *buf, SceInt32 maxLen, wchar_t *format, SceInt32 flags = 0);

			DateTime operator+(const DateTime& s) const;

			bool operator<(const DateTime& pDt) const;

			SceUInt16 year;
			SceUInt16 month;
			SceUInt16 day;
			SceUInt16 hour;
			SceUInt16 minute;
			SceUInt16 second;
			SceUInt32 microsecond;
			SceUInt32 unk_10;
			SceUInt8 unk_14;

		};

	}

	class DirEnt
	{
	public:

		enum Type
		{
			Type_Dir,
			Type_File,
			Type_Reg,
			Type_Lnk
		};

		Type type;
		paf::string name;
		SceInt32 size;
		SceUInt32 creationYear;
	};

	class Dir
	{
	public:

		Dir();

		~Dir() { Close(); };

		SceInt32 Open(const char *dirname);

		SceInt32 Close();

		SceInt32 Read(DirEnt *entry);

		static SceInt32 Create(const char *dirname, SceUInt32 mode);

		//dot-separated path list
		static SceInt32 CreateRecursive(const char *dirnameList, SceUInt32 mode);

		//default mode RWSYS
		static SceInt32 Create(const char *dirname);

		//default mode RWSYS, dot-separated path list
		static SceInt32 CreateRecursive(const char *dirnameList);

		static bool IsDirectory(const char *path);

		static bool IsExist(const char *path);

		static SceInt32 RemoveRecursive(const char *path);

		static SceInt32 Remove(const char *path);

	private:

		SceUID uid;
	};

	class Module
	{
	public:

		enum Flag
		{
			Flag_None = 0,
			Flag_UseSelfAsArg = 1,
			Flag_CDLGMode = 2
		};

		Module(const char *pPath, SceInt32 unused_a2 = 0, SceUInt32 flags = 0, SceInt32 unused_a4 = 0);

		~Module();

		SceInt32 GetStartResult();

		SceUID GetModuleId()
		{
			return *(SceUID *)((char *)impl + 0xC);
		}

		ScePVoid GetInterface(SceInt32 slot);

		SceVoid SetInterface(SceInt32 slot, ScePVoid interface);

	private:

		ScePVoid impl;

	};

	class File
	{
	public:

		class OpenArg
		{
		public:

			OpenArg() {};

			~OpenArg() {};
		};
	};

	class FileStat : public SceIoStat
	{
	};

	class LocalFileStat
	{
	public:

		SceIoMode			st_mode;
		SceUInt32			st_attr;
		SceOff				st_size;
		datetime::DateTime	ctime;
		SceUChar8			pad1[3];
		datetime::DateTime	atime;
		SceUChar8			pad2[3];
		datetime::DateTime	mtime;
	};

	class HttpFileStat : public LocalFileStat
	{
	};

	class LocalFilePsp2Impl : public File
	{
	public:

		LocalFilePsp2Impl();

		virtual ~LocalFilePsp2Impl();

		virtual SceInt32 Open(const char *filename, SceUInt32 flag, SceUInt32 mode);
		virtual SceInt32 Close();
		virtual SceInt32 Read(ScePVoid buf, SceSize nbyte);
		virtual SceInt32 Write(const ScePVoid buf, SceSize nbyte);
		virtual SceOff   Seek(SceOff offset, SceInt32 whence);
		virtual SceInt32 Flush();
		virtual SceInt32 OpenAsync(const char *filename, SceUInt32 flag, SceUInt32 mode);
		virtual SceInt32 CloseAsync();
		virtual SceInt32 ReadAsync(ScePVoid buf, SceSize nbyte);
		virtual SceInt32 WriteAsync(const ScePVoid buf, SceSize nbyte);
		virtual SceInt32 SeekAsync(SceOff offset, SceInt32 whence);
		virtual SceInt32 FlushAsync();
		virtual SceInt32 WaitAsync(SceInt64 *pResult);
		virtual SceInt32 PollAsync(SceInt64 *pResult);
		virtual bool     IsOpened();
		virtual bool     IsEof();
		virtual SceInt32 Abort();
		virtual SceOff   GetFileSize();
		virtual SceInt32 Getstat(FileStat *stat);
		virtual SceInt32 SetPriority(SceInt32 ioPriority);

		static SceInt32 RenameFile(const char *oldname, const char *newname);

		static SceInt32 RemoveFile(const char *path);

		static SceOff GetFileSize(const char *path);

		static SceInt32 Getstat(const char *path, LocalFileStat *buf);

		static SceInt32 SetDefaultPriority(SceInt32 ioPriority);

	private:

		SceUChar8 m_work[0x2C];

	};

	class LocalFile : public File
	{
	public:

		class OpenArg : public File::OpenArg
		{
		public:

			OpenArg() : fileType(1), filename(SCE_NULL), flag(SCE_O_RDONLY), mode(0) {};

			SceUInt32 fileType;
			const char *filename;
			SceUInt32 flag;
			SceUInt32 mode;
		};

		LocalFile();

		LocalFile(memory::HeapAllocator *allocator);

		virtual SceInt32 GetFileType() const;
		virtual SceInt32 GetCapability() const;
		virtual SceOff   GetFileSize() const;
		virtual SceInt32 Open(const File::OpenArg *param);
		virtual SceInt32 OpenAsync(const File::OpenArg *param);
		virtual SceInt32 Close();
		virtual SceInt32 CloseAsync();
		virtual bool     IsOpened() const;
		virtual bool     IsEof();
		virtual SceInt32 Abort();
		virtual SceInt32 Read(void *buf, SceSize nbyte);
		virtual SceInt32 ReadAsync(void *buf, SceSize nbyte);
		virtual SceInt32 Write(const void *buf, SceSize nbyte);
		virtual SceInt32 WriteAsync(const void *buf, SceSize nbyte);
		virtual SceOff   Seek(SceOff offset, SceInt32 whence);
		virtual SceInt32 SeekAsync(SceOff offset, SceInt32 whence);
		virtual SceInt32 Flush();
		virtual SceInt32 FlushAsync();
		virtual SceInt32 WaitAsync(SceInt64 *pResult);
		virtual SceInt32 PollAsync(SceInt64 *pResult);
		virtual SceInt32 Getstat(FileStat *stat);
		virtual SceInt32 SetPriority(SceInt32 ioPriority);

		virtual ~LocalFile();

		static common::SharedPtr<LocalFile> Open(const char *path, SceUInt32 flag, SceUInt32 mode, SceInt32 *error);

		static common::SharedPtr<LocalFile> OpenUrl(const char *path, SceUInt32 flag, SceUInt32 mode, SceInt32 *error, bool *pIsRemote);

		static SceInt32 Getstat(const char *path, LocalFileStat *buf);

		static SceInt32 RemoveFile(const char *path);

		static SceInt32 RenameFile(const char *oldname, const char *newname);

		static SceOff GetFileSize(const char *path);

		static bool Exists(const char *path);

		static bool IsDirectory(const char *path);

		static bool IsFile(const char *path);

		static SceInt32 SetDefaultPriority(SceInt32 ioPriority);

	private:

		SceInt32 unk_04;
		thread::RMutex csLock;
		LocalFilePsp2Impl *impl;
		memory::HeapAllocator *allocator;
	};

	class MemFile : public File
	{
	public:

		class OpenArg : public File::OpenArg
		{
		public:

			OpenArg() : fileType(2), ptr(SCE_NULL), size(0) {};

			SceUInt32 fileType;
			ScePVoid ptr;
			SceSize size;
		};

		MemFile();

		virtual SceInt32 GetFileType() const;
		virtual SceInt32 GetCapability() const;
		virtual SceOff   GetFileSize() const;
		virtual SceInt32 Open(const File::OpenArg *param);
		virtual SceInt32 OpenAsync(const File::OpenArg *param);
		virtual SceInt32 Close();
		virtual SceInt32 CloseAsync();
		virtual bool     IsOpened() const;
		virtual bool     IsEof();
		virtual SceInt32 Abort();
		virtual SceInt32 Read(void *buf, SceSize nbyte);
		virtual SceInt32 ReadAsync(void *buf, SceSize nbyte);
		virtual SceInt32 Write(const void *buf, SceSize nbyte);
		virtual SceInt32 WriteAsync(const void *buf, SceSize nbyte);
		virtual SceOff   Seek(SceOff offset, SceInt32 whence);
		virtual SceInt32 SeekAsync(SceOff offset, SceInt32 whence);
		virtual SceInt32 Flush();
		virtual SceInt32 FlushAsync();
		virtual SceInt32 WaitAsync(SceInt64 *pResult);
		virtual SceInt32 PollAsync(SceInt64 *pResult);
		virtual SceInt32 GetStat(FileStat *stat); // not supported
		virtual SceInt32 SetPriority(SceInt32 ioPriority); // not supported

		virtual ~MemFile();

		static common::SharedPtr<MemFile> Open(const void *ptr, SceSize size, SceInt32 *error);

		static common::SharedPtr<MemFile> Open(common::SharedPtr<MemFile> *memory, SceInt32 *error);

		SceInt8 unk_04;
		SceInt8 unk_05;
		SceInt8 unk_06;
		SceInt8 unk_07;
		SceInt32 unk_08;
		SceInt32 unk_0C;
		ScePVoid ptr;
		SceSize size;

	private:

		SceChar8 unk_18[0x18];
		thread::RMutex csLock;
	};

	class HttpFile : public File
	{
	public:

		class OpenArg : public File::OpenArg
		{
		public:

			enum Opt
			{
				Opt_ResolveTimeOut = 1,
				Opt_ConnectTimeOut = 2,
				Opt_SendTimeOut = 4,
				Opt_RecvTimeOut = 8,
			};

			OpenArg();

			~OpenArg() {};

			SceVoid SetUrl(const char *url);

			SceVoid SetUrl(Url *url);

			SceInt32 SetOpt(SceInt32 optValue, Opt optType);

			SceUInt32 fileType;
			string tx1;
			string tx2;
			SceInt32 unk_1C;
			string tx3;
			string tx4;
			string tx5;
			string userAgent;
			string tx7;
			string tx8;
			string tx9;
			SceInt32 unk_74;
			SceInt32 unk_78;
			SceInt32 unk_7C;
			SceInt32 unk_80;
			SceInt32 unk_84;
			SceInt32 unk_88;
			SceInt32 sslFlags;
			SceUChar8 unk_90[0x28];
		};

		HttpFile();

		virtual SceInt32 GetFileType() const;
		virtual SceInt32 GetCapability() const;
		virtual SceOff   GetFileSize() const;
		virtual SceInt32 Open(const File::OpenArg *param);
		virtual SceInt32 OpenAsync(const File::OpenArg *param);
		virtual SceInt32 Close();
		virtual SceInt32 CloseAsync();
		virtual bool     IsOpened() const;
		virtual bool     IsEof();
		virtual SceInt32 Abort();
		virtual SceInt32 Read(void *buf, SceSize nbyte);
		virtual SceInt32 ReadAsync(void *buf, SceSize nbyte);
		virtual SceInt32 Write(const void *buf, SceSize nbyte); // not supported
		virtual SceInt32 WriteAsync(const void *buf, SceSize nbyte); // not supported
		virtual SceOff   Seek(SceOff offset, SceInt32 whence);
		virtual SceInt32 SeekAsync(SceOff offset, SceInt32 whence);
		virtual SceInt32 Flush();
		virtual SceInt32 FlushAsync();
		virtual SceInt32 WaitAsync(SceInt64 *pResult);
		virtual SceInt32 PollAsync(SceInt64 *pResult);
		virtual SceInt32 GetStat(FileStat *stat);
		virtual SceInt32 SetPriority(SceInt32 ioPriority);

		virtual ~HttpFile();

		SceInt32 GetResponseCode(SceInt32 *code);

		static common::SharedPtr<HttpFile> Open(const char *path, SceUInt32 flag, SceUInt32 mode, SceInt32 *error);

		static common::SharedPtr<HttpFile> Open(const SceWChar16 *url, SceInt32 *error, SceUInt32 flag);

		static common::SharedPtr<HttpFile> Open(const char *url, SceInt32 *error, SceUInt32 flag);

		static SceInt32 GetStat(const char *url, HttpFileStat *stat);

	private:

		SceInt32 unk_04;
		thread::RWLock rwLock;
		thread::RMutex csLock;
		SceUChar8 unk_30[0x1C];
	};

	class BufferedFile : public File
	{
	public:

		class OpenArg : public File::OpenArg
		{
		public:

			OpenArg() : fileType(0), filename(SCE_NULL), flag(SCE_O_RDONLY), mode(0) {};

			SceUInt32 fileType;
			const char *filename;
			SceUInt32 flag;
			SceUInt32 mode;
		};

		BufferedFile();

		virtual SceInt32 GetFileType() const;
		virtual SceInt32 GetCapability() const;
		virtual SceOff   GetFileSize() const;
		virtual SceInt32 Open(const File::OpenArg *param);
		virtual SceInt32 OpenAsync(const File::OpenArg *param);
		virtual SceInt32 Close();
		virtual SceInt32 CloseAsync();
		virtual bool     IsOpened() const;
		virtual bool     IsEof();
		virtual SceInt32 Abort();
		virtual SceInt32 Read(void *buf, SceSize nbyte);
		virtual SceInt32 ReadAsync(void *buf, SceSize nbyte);
		virtual SceInt32 Write(const void *buf, SceSize nbyte);
		virtual SceInt32 WriteAsync(const void *buf, SceSize nbyte);
		virtual SceOff   Seek(SceOff offset, SceInt32 whence);
		virtual SceInt32 SeekAsync(SceOff offset, SceInt32 whence);
		virtual SceInt32 Flush();
		virtual SceInt32 FlushAsync();
		virtual SceInt32 WaitAsync(SceInt64 *pResult);
		virtual SceInt32 PollAsync(SceInt64 *pResult);
		virtual SceInt32 Getstat(FileStat *stat);
		virtual SceInt32 SetPriority(SceInt32 ioPriority);

		virtual ~BufferedFile();

		virtual int unkFun_060();
		virtual int unkFun_064();
		virtual int unkFun_068();
		virtual SceInt32 Open(const File::OpenArg *param, common::SharedPtr<Buffer> *buffer);

		static common::SharedPtr<BufferedFile> Open(common::SharedPtr<File> *file, SceInt32 *error, common::SharedPtr<Buffer> *buffer);

	private:

		SceInt32 unk_04;
		SceInt32 unk_08;
		SceInt32 unk_0C;
		thread::RMutex csLock;
		SceInt32 unk_30;
		SceInt32 unk_34;
		SceInt32 unk_38;
		SceInt32 unk_3C;
	};

	namespace compress {

		enum DecompressType
		{
			DecompressType_Deflate = 1
		};

		extern SceInt32 Decompress(ScePVoid memOut, SceSize origsize, const ScePVoid memIn, SceSize size, DecompressType type = DecompressType_Deflate);

		extern SceInt32 Compress(common::SharedPtr<LocalFile> *out, const ScePVoid memIn, SceSize size, DecompressType type = DecompressType_Deflate, paf::memory::HeapAllocator *allocator = SCE_NULL);
	}

	namespace sha1 {

		class Context : public SceSha1Context
		{

		};

		extern bool BlockInit(Context *ctx);

		extern SceInt32 BlockUpdate(Context *ctx, const ScePVoid plain, SceUInt32 len);

		extern SceInt32 BlockResult(Context *ctx, SceUChar8 *digest);

		extern SceInt32 Core(Context *ctx);
	}

	namespace system {

		enum ModelType
		{
			ModelType_Vita = 0,
			ModelType_Dolce = 1
		};

		extern bool SupportsMultiController(); //vsh capability 1

		extern bool SupportsCamera(); //vsh capability 2

		extern bool SupportsWiredEthernet(); //vsh capability 5 OR 6

		//ScePafMisc_C74F989D
		extern bool c8(); //vsh capability 7

		//ScePafMisc_D8D642F5
		extern bool c10(); //vsh capability 8

		//ScePafMisc_9DE7DA6D
		extern bool c20(); //vsh capability 9

		extern bool SupportsLocalOutputs(); //vsh capability 10, true if system has screen and speakers

		extern bool IsDolce();

		extern ModelType GetModelType();

		extern SceVoid SuspendTouchInput(SceUInt32 port);

		extern SceVoid ResumeTouchInput(SceUInt32 port);

		extern SceUInt64 GetProcessTime();

		#define SCE_PAF_IS_DOLCE (paf::system::GetModelType() == paf::system::ModelType_Dolce)
	}

	namespace image {

		enum ImageMode
		{
			ImageMode_U5U6U5_BGR,
			ImageMode_U1U5U5U5_ABGR,
			ImageMode_U4U4U4U4_ABGR,
			ImageMode_UNSUPPORTED3,
			ImageMode_U8U8U8U8_ABGR,
			ImageMode_U8U8U8U8_BGRA,
			ImageMode_U8U8U8U8_ARGB,
			ImageMode_UNSUPPORTED7,
			ImageMode_UNSUPPORTED8,
			ImageMode_UNSUPPORTED9,
			ImageMode_UNSUPPORTED10,
			ImageMode_UNSUPPORTED11,
			ImageMode_UNSUPPORTED12,
			ImageMode_UNSUPPORTED13,
			ImageMode_U8_R111,
			ImageMode_U8_1RRR,
			ImageMode_UBC1_ABGR,
			ImageMode_UNSUPPORTED17,
			ImageMode_UBC2_ABGR,
			ImageMode_UNSUPPORTED19,
			ImageMode_UBC3_ABGR,
			ImageMode_P4_ABGR,
			ImageMode_P8_ABGR,
			ImageMode_UNSUPPORTED23,
			ImageMode_UNSUPPORTED24,
			ImageMode_UNSUPPORTED25,
			ImageMode_UNSUPPORTED26,
			ImageMode_YVU420P2,
			ImageMode_YUV420P3,
			ImageMode_PVRT2BPP_ABGR,
			ImageMode_PVRT4BPP_ABGR,
			ImageMode_PVRTII2BPP_ABGR,
			ImageMode_PVRTII4BPP_ABGR,
		};

		enum ImageFormat
		{
			ImageFormat_AutoDetect,
			ImageFormat_PNG,
			ImageFormat_JPEG,
			ImageFormat_TIFF,
			ImageFormat_GIF,
			ImageFormat_BMP,
			ImageFormat_GIM,
			ImageFormat_DDS
		};

		enum ImageOrder
		{
			ImageOrder_Unsupported,
			ImageOrder_Linear,
			ImageOrder_Swizzled,
			ImageOrder_Tiled,
		};

		enum ImageResizeType
		{
			ImageResizeType_0
		};

		enum ImageFlipType
		{
			ImageFlipType_0
		};

		enum ImageRotateType
		{
			ImageRotateType_0
		};

		class ImageExtent
		{
		public:

			SceInt32 width;
			SceInt32 height;
		};

		class ImagePoint
		{
		public:

			SceInt32 x;
			SceInt32 y;
		};

		class ImageRect
		{
		public:

			SceInt32 x;
			SceInt32 y;
			SceInt32 width;
			SceInt32 height;
		};

		class ImageAttribute
		{
		public:

			ImageAttribute();

			virtual SceInt32 unkFun_00();
			virtual SceInt32 unkFun_04();
			virtual SceInt32 unkFun_08();
			virtual SceInt32 unkFun_0C();

			virtual ~ImageAttribute();

			SceInt32 GetMemSize(SceUInt32 a1) const;

			SceInt32 GetMemPitch(SceUInt32 a1) const;

			SceInt32 GetMemHeight(SceUInt32 a1) const;

			SceInt32 GetPixelSizeInBits() const;

			SceInt32 GetPixelSizeInBytes() const;

			SceInt32 GetCLUTPixelSizeInBits() const;

			SceInt32 GetCLUTPixelSizeInBytes() const;

			ImageExtent GetExtent(SceUInt32 a1) const;

			static SceInt32 GetPixelSize(ImageMode mode);

			static SceInt32 CalcMemSize(SceUInt32 a1, SceUInt32 a2, SceUInt16 a3, SceUInt16 a4, ImageMode mode, ImageFormat format);

		private:

			ImageMode mode;
			ImageMode CLUTmode;
			ImageOrder order;
			SceUInt32 CLUTsize;
			SceChar8 unk_10[0x30];
			ImageFormat format;
			SceUInt32 xType;
			SceUInt32 yType;
			SceUInt16 pitchAlign;
			SceUInt16 heightAlign;
			SceUInt32 resizeType;
		};

		class ImageBuffer
		{
		public:

			ScePVoid addr;
			SceInt32 size;
		};

		class ImageArray
		{
		public:

			ImageArray(paf::memory::HeapAllocator *alloc);

			~ImageArray();

			bool Init(SceUInt32 row, SceUInt32 col);

			bool Init(const ImagePoint& arrayDim);

			bool SetCLUTSize(const ImageAttribute *attr);

			bool Free();

			bool Alloc();

			bool Reset();

			bool SetLink();

			bool SetSize(SceUInt32 arrayIdx, SceUInt32 size);

			bool SetSize(const ImageAttribute *attr);

			bool SetSize(const ImagePoint& arrayIdx, SceUInt32 size);

			ImagePoint GetArraySize() const;

			SceUInt32 GetMax() const;

			bool IsEmpty() const;

			ScePVoid GetBuffer(SceUInt32 arrayIdx) const;

			ScePVoid GetBuffer(const ImagePoint& arrayIdx) const;

			ImageArray& operator=(const ImageArray& s);

		private:

			ScePVoid buffer;
			paf::memory::HeapAllocator *alloc;
			SceUInt32 row;
			SceUInt32 col;
			SceInt32 unk_10;
		};

		class Image
		{
		public:

			~Image();

			class Resolution
			{
			public:

				SceUInt32 width;
				SceUInt32 height;
			};

			typedef bool(*ImageDecodeCancelFunc)(ScePVoid arg);

			common::SharedPtr<Image> CopyWithEdge(SceUInt32 edge);

			common::SharedPtr<Image> FadeWithEdge();

			common::SharedPtr<Image> Transparentize(SceFloat32 factor);

			common::SharedPtr<Image> Blur(SceFloat32 factor);

			common::SharedPtr<Image> Sharpen(SceFloat32 factor, SceInt32 a2);

			common::SharedPtr<Image> Copy();

			common::SharedPtr<Image> Flip(ImageFlipType type);

			common::SharedPtr<Image> Resize(const ImageExtent& extent, ImageResizeType type);

			common::SharedPtr<Image> Rotate(ImageRotateType type);

			bool Load(bool canCancel);

			bool UnLoad();

			SceInt32 GetErrorType();

			SceInt32 GetDecErrorType() const;

			bool SetErrorType(SceInt32 error);

			bool SetDecErrorType(SceInt32 error);

			bool SetPitchAlign(SceUInt32 pitchAlign);

			bool SetHeightAlign(SceUInt32 heightAlign);

			bool CheckAlignArgument(SceInt32 arg);

			ImageBuffer ToCLUTBuffer(bool canCancel);

			ImageBuffer ToBuffer(bool canCancel);

			bool SetArrayPos(ImagePoint& pos);

			bool SetArrayPosCLUT(ImagePoint& pos);

			bool SetDecExtent(const ImageExtent& extent, ImageResizeType resizeType);

			bool SetDecSubRect(const ImageRect& rect);

			bool SetDecodeCancelFunc(ImageDecodeCancelFunc func, ScePVoid arg);

			bool SetClip(const ImageRect& clipRect);

			ImageRect GetSubRect() const;

			ImagePoint GetArrayPos() const;

			ImagePoint GetArrayPosCLUT() const;

			ImageMode GetCLUTMode() const;

			ImageMode GetMode() const;

			SceInt32 GetCLUTSize() const;

			SceInt32 GetMemPitch(SceUInt32 a1) const;

			SceInt32 GetMemHeight(SceUInt32 a1) const;

			SceInt32 GetPitchAlign() const;

			SceInt32 GetHeightAlign() const;

			ImagePoint GetCLUTArraySize() const;

			ImagePoint GetArraySize() const;

			ImageExtent GetOriginalExtent() const;

			ImageExtent GetExtent() const;

			ImageRect GetClip() const;

			ImageFormat GetFormat() const;

			ImageOrder GetOrder() const;

			SceUInt32 GetXType() const;

			SceUInt32 GetYType() const;

			bool CheckCLUT() const;

			static ImageFormat DetectFormat(ScePVoid img, SceUInt32 size);

			static ImageFormat DetectFormat(const char *path, SceOff offset, SceUInt32 whence);

			static ImageFormat DetectFormat(common::SharedPtr<File> file, SceOff offset, SceUInt32 whence);

			static ImageFormat DetectFormat(common::SharedPtr<Buffer> buf);

			static common::SharedPtr<Image> Open(const char *path, paf::memory::HeapAllocator *allocator, ImageFormat format, SceOff offset, SceSize size);

			static common::SharedPtr<Image> Open(ScePVoid mem, SceUInt32 size, paf::memory::HeapAllocator *allocator, ImageFormat format);

			//3EAFA4C0
			static common::SharedPtr<Image> Open(common::SharedPtr<File> file, paf::memory::HeapAllocator *allocator, ImageFormat format, SceOff offset, SceSize size);

			SceInt32 unk_00;
			ImageArray *array;
			SceChar8 unk_08[0x28];
			ImagePoint point;

		private:

			Image();

			//size unknown...
		};

		namespace filter {

		}
	}

	namespace input {

		class GamePad
		{
		public:

			#define SCE_PAF_CTRL_SELECT				(0x100)			/*J SELECTボタン           */
			#define SCE_PAF_CTRL_L3					(0x40000)		/*J L3ボタン               */
			#define SCE_PAF_CTRL_R3					(0x80000)		/*J R3ボタン               */
			#define SCE_PAF_CTRL_START				(0x200)			/*J STARTボタン            */
			#define SCE_PAF_CTRL_UP					(0x1)			/*J 方向キー ↑ボタン      */
			#define SCE_PAF_CTRL_RIGHT				(0x8)			/*J 方向キー →ボタン      */
			#define SCE_PAF_CTRL_DOWN				(0x2)			/*J 方向キー ↓ボタン      */
			#define SCE_PAF_CTRL_LEFT				(0x4)			/*J 方向キー ←ボタン      */
			#define SCE_PAF_CTRL_L					(0x400)			/*J Lボタン                */
			#define SCE_PAF_CTRL_R					(0x800)			/*J Rボタン                */
			#define SCE_PAF_CTRL_L2					(0x400)			/*J L2ボタン               */
			#define SCE_PAF_CTRL_R2					(0x800)			/*J R2ボタン               */
			#define SCE_PAF_CTRL_L1					(0x10000)		/*J L1ボタン               */
			#define SCE_PAF_CTRL_R1					(0x20000)		/*J R1ボタン               */
			#define SCE_PAF_CTRL_TRIANGLE			(0x40)			/*J △ボタン               */
			#define SCE_PAF_CTRL_CIRCLE				(0x20)			/*J ○ボタン               */
			#define SCE_PAF_CTRL_CROSS				(0x10)			/*J ×ボタン               */
			#define SCE_PAF_CTRL_SQUARE				(0x80)			/*J □ボタン               */

			class GamePadData : public SceCtrlData
			{

			};

			typedef void(*GamePadCallback)(GamePadData *pData);

			static GamePadCallback RegisterCallback(GamePadCallback newCb);
		};

		class Touch
		{
		public:

			class TouchData : public SceTouchData
			{

			};

			typedef void(*TouchCallback)(TouchData *pData);

			static TouchCallback RegisterCallback(SceUInt32 port, TouchCallback newCb);
		};

		class Motion
		{
		public:

			class MotionData : public SceMotionState
			{

			};

			typedef void(*MotionCallback)(MotionData *pData);

			static MotionCallback RegisterCallback(MotionCallback newCb);
		};
	}

	class Vector4
	{
	public:

		Vector4(SceFloat32 x, SceFloat32 y = 0.0f, SceFloat32 z = 0.0f, SceFloat32 w = 0.0f) : x(x), y(y), z(z), w(w)
		{

		};

		Vector4();

		SceFloat32 GetX();
		SceFloat32 GetY();
		SceFloat32 GetZ();
		SceFloat32 GetW();

		bool operator!=(Vector4 *a);
		bool operator!=(Vector4& a);

		static Vector4 Zero();

		SceFloat32 x, y, z, w;
	};

	class Matrix4
	{
	public:

		static Matrix4 Ortho(SceFloat32 left, SceFloat32 right, SceFloat32 bottom, SceFloat32 top, SceFloat32 near, SceFloat32 far);

		static Matrix4 Frustum(SceFloat32 left, SceFloat32 right, SceFloat32 bottom, SceFloat32 top, SceFloat32 near, SceFloat32 far);

		SceFloat32 mat[4][4];
	};

	namespace cache {

		class CacheManager
		{
		public:

			class InitParam
			{
			public:

				InitParam() { };

				~InitParam() { };

				string name;
				memory::HeapAllocator *decodeAllocator1;
				memory::HeapAllocator *decodeAllocator2;
				SceInt32 unk_14; // 0
				SceUInt8 unk_18; // 4
				SceUInt8 unk_19; // 4
				paf::graph::SurfacePool *workSurfacePool;
				SceInt32 unk_20; // 0
				SceInt32 unk_24; // 0
				SceInt32 unk_28; // 0
				SceInt32 unk_2C; // 0
				SceInt32 unk_30; // 0
				SceUInt8 unk_34; // 1 -> 0
				SceUInt8 unk_35; // 0
				SceUInt8 unk_36; // 0 -> 1
				SceInt32 unk_38; // 0
				SceInt32 unk_3C; // 0
				SceUInt32 localJobPrio;
				SceUInt32 netJobPrio;
				SceUInt32 operatingJobPrio;
			};

			CacheManager();

			virtual ~CacheManager();
			//virtual SceInt32 Lookup(string *path, graph::Surface **surface, void *optParam = SCE_NULL, void *cacheManagerJob = SCE_NULL, void *unk = SCE_NULL);

			//104FE238
			SceInt32 Finish();

			//52C7998E
			SceUInt32 GetRemainingJobCount();



		private:

			SceChar8 m_work[0x8];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_MISC_H */
