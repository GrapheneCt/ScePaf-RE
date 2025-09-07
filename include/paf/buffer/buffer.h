/*
	ScePaf-RE Project
*/

#ifndef _PAF_BUFFER_BUFFER_H
#define _PAF_BUFFER_BUFFER_H

#include <stdint.h>
#include <stddef.h>
#include <paf/common/shared_ptr.h>
#include <paf/memory/heap_allocator.h>
#include <paf/std/stdc.h>

namespace paf {

	namespace memory {

		class HeapAllocator;
	}

	class Buffer
	{
	public:

		Buffer() : m_addr(NULL), m_size(0)
		{

		}

		virtual void* GetAddr()
		{
			return m_addr;
		}

		virtual const void* GetAddr() const
		{
			return m_addr;
		}

		virtual size_t GetSize() const
		{
			return m_size;
		}

		virtual ~Buffer()
		{

		};

	protected:

		void* m_addr;
		size_t m_size;
	};

	class SubBuffer : public Buffer
	{
	public:

		virtual ~SubBuffer()
		{

		};

		static common::SharedPtr<SubBuffer> Create(void *_addr, size_t _size, common::SharedPtr<Buffer> _buffer);

	private:

		common::SharedPtr<Buffer> m_buffer;
	};

	class SubConstBuffer : public Buffer
	{
	public:

		virtual const void* GetAddr() const
		{
			return m_const_addr;
		}

		virtual ~SubConstBuffer()
		{

		};

		static common::SharedPtr<SubConstBuffer> Create(const void *_addr, size_t _size, common::SharedPtr<Buffer> _buffer);

	private:

		const void* m_const_addr;
		common::SharedPtr<Buffer> m_buffer;
	};

	class UnmanagedBuffer : public Buffer
	{
	public:

		virtual ~UnmanagedBuffer()
		{

		};

		static common::SharedPtr<UnmanagedBuffer> Create(void *_addr, size_t _size);
	};

	class UnmanagedConstBuffer : public Buffer
	{
	public:

		virtual const void* GetAddr() const
		{
			return m_const_addr;
		}

		virtual ~UnmanagedConstBuffer()
		{

		};

		static common::SharedPtr<UnmanagedConstBuffer> Create(const void *addr, size_t size);

	private:

		const void* m_const_addr;
	};

	class MallocBuffer : public Buffer
	{
	public:

		virtual ~MallocBuffer()
		{
			sce_paf_free(m_addr);
		}

		static common::SharedPtr<MallocBuffer> Create(void *_addr, size_t _size);

		static common::SharedPtr<MallocBuffer> Allocate(size_t _size);
	};

	class HeapAllocBuffer : public Buffer
	{
	public:

		static common::SharedPtr<HeapAllocBuffer> Create(void *_addr, size_t _size, memory::HeapAllocator *_alloc);

		static common::SharedPtr<HeapAllocBuffer> Allocate(size_t _size, memory::HeapAllocator *_alloc);

	private:

		memory::HeapAllocator *m_allocator;
	};
}

#endif /* _PAF_BUFFER_BUFFER_H */
