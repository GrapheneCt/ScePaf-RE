/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_RESOURCE_RESOURCE_OBJ_H
#define _VDSUITE_USER_PAF_RESOURCE_RESOURCE_OBJ_H

#include <stdint.h>
#include <stddef.h>
#include <paf/cxml/cxml.h>
#include <paf/resource/resource_types.h>

namespace paf {

	class File;
	class MemFile;

	namespace memory {

		class HeapAllocator;
	}

	namespace resource {

		class ResourceObj
		{
		public:

			class Option
			{
			public:

				uint32_t load_type;
				memory::HeapAllocator *allocator;
				cxml::Document::Allocator *cxml_allocator_func;
			};

			ResourceObj(const char *name, const Option *option);

			ResourceObj(void *addr, size_t size, const Option *option);

			bool IsRegisteredID(const char* str, uint32_t mode);

			bool IsRegisteredID(uint32_t value);

			int32_t GetStringIDRef(cxml::Element const& elm, const char *attrname, const char **str, cxml::Element *entity) const;

			int32_t GetStringIDRef(cxml::Element const& elm, const char *attrname, uint32_t *value, cxml::Element *entity) const;

			char *GetFileName() const;

			int32_t GetLoadStatus() const;

			uint32_t GetCreateType() const;

			cxml::Document& GetDocument() const;

			cxml::Document& GetStringDocument() const;

			cxml::Element GetTableElement(TableType type) const;

			int32_t GetPage(const char *id, cxml::Element& elm) const;
			 
			int32_t GetPage(uint32_t idhash, cxml::Element& elm) const;

			int32_t GetStyle(const char *id, cxml::Element& elm) const;

			int32_t GetStyle(uint32_t idhash, cxml::Element& elm) const;

			int32_t GetString(const char *id, const wchar_t **src, uint32_t *length) const;

			int32_t GetString(uint32_t idhash, const wchar_t **src, uint32_t *length) const;

			int32_t GetString(cxml::Element const& elm, const wchar_t **src, uint32_t *length) const;

			int32_t GetTextureFromFile(const char *id, cxml::File *src, size_t *size, uint32_t *type) const;

			int32_t GetTextureFromFile(uint32_t idhash, cxml::File *src, size_t *size, uint32_t *type) const;

			int32_t GetTextureFromFile(cxml::Element const& elm, cxml::File *src, size_t *size, uint32_t *type) const;

			int32_t GetTextureFromBuffer(const char *id, void **addr, size_t *size, uint32_t *type) const;

			int32_t GetTextureFromBuffer(uint32_t idhash, void **addr, size_t *size, uint32_t *type) const;

			int32_t GetTextureFromBuffer(cxml::Element const& elm, void **addr, size_t *size, uint32_t *type) const;

			int32_t GetModelFromFile(const char *id, cxml::File *src, size_t *size, uint32_t *type) const;

			int32_t GetModelFromFile(uint32_t idhash, cxml::File *src, size_t *size, uint32_t *type) const;

			int32_t GetModelFromFile(cxml::Element const& elm, cxml::File *src, size_t *size, uint32_t *type) const;

			int32_t GetModelFromBuffer(const char *id, void **addr, size_t *size, uint32_t *type) const;

			int32_t GetModelFromBuffer(uint32_t idhash, void **addr, size_t *size, uint32_t *type) const;

			int32_t GetModelFromBuffer(cxml::Element const& elm, void **addr, size_t *size, uint32_t *type) const;

			common::SharedPtr<MemFile> GetFile(const char *id, void *addr, size_t *size, const char **type, memory::HeapAllocator *decomp_allocator = NULL) const;

			common::SharedPtr<MemFile> GetFile(uint32_t idhash, void *addr, size_t *size, const char **type, memory::HeapAllocator *decomp_allocator = NULL) const;

			common::SharedPtr<MemFile> GetFile(cxml::Element const& elm, void *addr, size_t *size, const char **type, memory::HeapAllocator *decomp_allocator = NULL) const;

			common::SharedPtr<MemFile> GetFile(uint32_t idhash, size_t *size, const char **type, memory::HeapAllocator *file_allocator = NULL, memory::HeapAllocator *decomp_allocator = NULL) const;

			common::SharedPtr<MemFile> GetFile(const char *id, size_t *size, const char **type, memory::HeapAllocator *file_allocator = NULL, memory::HeapAllocator *decomp_allocator = NULL) const;

			common::SharedPtr<MemFile> GetFile(cxml::Element const& elm, size_t *size, const char **type, memory::HeapAllocator *file_allocator = NULL, memory::HeapAllocator *decomp_allocator = NULL) const;

			int32_t GetSoundFromFile(const char *id, cxml::File *left_or_mono, size_t *left_or_mono_size, cxml::File *right, size_t *right_size, int32_t *samplerate, uint32_t *format) const;

			int32_t GetSoundFromFile(uint32_t hash, cxml::File *left_or_mono, size_t *left_or_mono_size, cxml::File *right, size_t *right_size, int32_t *samplerate, uint32_t *format) const;

			int32_t GetSoundFromFile(cxml::Element const& elm, cxml::File *left_or_mono, size_t *left_or_mono_size, cxml::File *right, size_t *right_size, int32_t *samplerate, uint32_t *format) const;

			int32_t GetSoundFromBuffer(const char *id, void **addr1, size_t *size1, void **addr2, size_t *size2, int32_t *samplerate, uint32_t *type) const;

			int32_t GetSoundFromBuffer(uint32_t idhash, void **addr1, size_t *size1, void **addr2, size_t *size2, int32_t *samplerate, uint32_t *type) const;

			int32_t GetSoundFromBuffer(cxml::Element const& elm, void **addr1, size_t *size1, void **addr2, size_t *size2, int32_t *samplerate, uint32_t *type) const;

		private:

			common::SharedPtr<File> rscfp;
			string filename;
			cxml::Document *document;
			cxml::Document *string_document;
			memory::HeapAllocator *rscallocator;
			char unk_20[0x4C];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_RESOURCE_RESOURCE_OBJ_H */
