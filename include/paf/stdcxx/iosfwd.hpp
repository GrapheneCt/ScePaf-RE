#ifndef _VDSUITE_USER_PAF_STDCXX_IOSFWD_H
#define _VDSUITE_USER_PAF_STDCXX_IOSFWD_H

namespace paf {
// TEMPLATE STRUCT _Char_traits (FROM <string>)
template<class _Elem,
	class _Int_type>
	struct _Char_traits
{	// properties of a string or stream element
	typedef _Elem char_type;
	typedef _Int_type int_type;

	static int compare(
		const _Elem *_First1,
		const _Elem *_First2, size_t _Count)
	{	// compare [_First1, _First1 + _Count) with [_First2, ...)
		for (; 0 < _Count; --_Count, ++_First1, ++_First2)
			if (!eq(*_First1, *_First2))
				return (lt(*_First1, *_First2) ? -1 : +1);
		return (0);
	}

	static size_t length(const _Elem *_First)
	{	// find length of null-terminated sequence
		size_t _Count;
		for (_Count = 0; !eq(*_First, _Elem()); ++_First)
			++_Count;
		return (_Count);
	}

	static _Elem *copy(
		_Elem *_First1,
		const _Elem *_First2, size_t _Count)
	{	// copy [_First2, _First2 + _Count) to [_First1, ...)
		_Elem *_Next = _First1;
		for (; 0 < _Count; --_Count, ++_Next, ++_First2)
			assign(*_Next, *_First2);
		return (_First1);
	}

	static const _Elem *find(
		const _Elem *_First,
		size_t _Count, const _Elem& _Ch)
	{	// look for _Ch in [_First, _First + _Count)
		for (; 0 < _Count; --_Count, ++_First)
			if (eq(*_First, _Ch))
				return (_First);
		return (0);
	}

	static _Elem *move(
		_Elem *_First1,
		const _Elem *_First2, size_t _Count)
	{	// copy [_First2, _First2 + _Count) to [_First1, ...)
		_Elem *_Next = _First1;
		if (_First2 < _Next && _Next < _First2 + _Count)
			for (_Next += _Count, _First2 += _Count; 0 < _Count; --_Count)
				assign(*--_Next, *--_First2);
		else
			for (; 0 < _Count; --_Count, ++_Next, ++_First2)
				assign(*_Next, *_First2);
		return (_First1);
	}

	static _Elem *assign(
		_Elem *_First,
		size_t _Count, _Elem _Ch)
	{	// assign _Count * _Ch to [_First, ...)
		_Elem *_Next = _First;
		for (; 0 < _Count; --_Count, ++_Next)
			assign(*_Next, _Ch);
		return (_First);
	}

	static void assign(_Elem& _Left, const _Elem& _Right)
	{	// assign an element
		_Left = _Right;
	}

	static bool eq(const _Elem& _Left,
		const _Elem& _Right)
	{	// test for element equality
		return (_Left == _Right);
	}

	static bool lt(const _Elem& _Left,
		const _Elem& _Right)
	{	// test if _Left precedes _Right
		return (_Left < _Right);
	}

	static _Elem to_char_type(
		const int_type& _Meta)
	{	// convert metacharacter to character
		return ((_Elem)_Meta);
	}

	static int_type to_int_type(
		const _Elem& _Ch)
	{	// convert character to metacharacter
		return ((int_type)_Ch);
	}

	static bool eq_int_type(const int_type& _Left,
		const int_type& _Right)
	{	// test for metacharacter equality
		return (_Left == _Right);
	}

	static int_type not_eof(
		const int_type& _Meta)
	{	// return anything but EOF
		return (_Meta != eof() ? (int_type)_Meta : (int_type)!eof());
	}

	static int_type eof()
	{	// return end-of-file metacharacter
		return ((int_type)EOF);
	}
};

// TEMPLATE STRUCT char_traits
template<class _Elem>
struct char_traits
	: public _Char_traits<_Elem, long>
{	// properties of a string or stream unknown element
};

// STRUCT char_traits<wchar_t>
template<>
struct char_traits<wchar_t>
{	// properties of a string or stream wchar_t element
	typedef wchar_t _Elem;
	typedef _Elem char_type;	// for overloads
	typedef unsigned int int_type;

	static int compare(const _Elem *_First1, const _Elem *_First2,
		size_t _Count)
	{	// compare [_First1, _First1 + _Count) with [_First2, ...)
		return (_Count == 0 ? 0
			: sce_paf_wmemcmp(_First1, _First2, _Count));
	}

	static size_t length(const _Elem *_First)
	{	// find length of null-terminated sequence
		return (*_First == 0 ? 0
			: sce_paf_wcslen(_First));
	}

	static _Elem *copy(_Elem *_First1, const _Elem *_First2,
		size_t _Count)
	{	// copy [_First2, _First2 + _Count) to [_First1, ...)
		return (_Count == 0 ? _First1
			: (_Elem *)sce_paf_wmemcpy(_First1, _First2, _Count));
	}

	static const _Elem *find(const _Elem *_First, size_t _Count,
		const _Elem& _Ch)
	{	// look for _Ch in [_First, _First + _Count)
		return (_Count == 0 ? (const _Elem *)0
			: (const _Elem *)sce_paf_wmemchr(_First, _Ch, _Count));
	}

	static _Elem *move(_Elem *_First1, const _Elem *_First2,
		size_t _Count)
	{	// copy [_First2, _First2 + _Count) to [_First1, ...)
		return (_Count == 0 ? _First1
			: (_Elem *)sce_paf_wmemmove(_First1, _First2, _Count));
	}

	static _Elem *assign(_Elem *_First, size_t _Count,
		_Elem _Ch)
	{	// assign _Count * _Ch to [_First, ...)
		return ((_Elem *)sce_paf_wmemset(_First, _Ch, _Count));
	}

	static void assign(_Elem& _Left, const _Elem& _Right)
	{	// assign an element
		_Left = _Right;
	}

	static bool eq(const _Elem& _Left,
		const _Elem& _Right)
	{	// test for element equality
		return (_Left == _Right);
	}

	static bool lt(const _Elem& _Left,
		const _Elem& _Right)
	{	// test if _Left precedes _Right
		return (_Left < _Right);
	}

	static _Elem to_char_type(
		const int_type& _Meta)
	{	// convert metacharacter to character
		return (_Meta);
	}

	static int_type to_int_type(
		const _Elem& _Ch)
	{	// convert character to metacharacter
		return (_Ch);
	}

	static bool eq_int_type(const int_type& _Left,
		const int_type& _Right)
	{	// test for metacharacter equality
		return (_Left == _Right);
	}

	static int_type not_eof(
		const int_type& _Meta)
	{	// return anything but EOF
		return (_Meta != eof() ? _Meta : !eof());
	}

	static int_type eof()
	{	// return end-of-file metacharacter
		return (WEOF);
	}
};

// STRUCT char_traits<char> (FROM <string>)
template<> struct char_traits<char>
{	// properties of a string or stream char element
	typedef char _Elem;
	typedef _Elem char_type;
	typedef int int_type;

	static int compare(const _Elem *_First1, const _Elem *_First2,
		size_t _Count)
	{	// compare [_First1, _First1 + _Count) with [_First2, ...)
		return (_Count == 0 ? 0
			: sce_paf_memcmp(_First1, _First2, _Count));
	}

	static size_t length(const _Elem *_First)
	{	// find length of null-terminated string
		return (*_First == 0 ? 0
			: sce_paf_strlen(_First));
	}

	static _Elem *copy(_Elem *_First1, const _Elem *_First2,
		size_t _Count)
	{	// copy [_First2, _First2 + _Count) to [_First1, ...)
		return (_Count == 0 ? _First1
			: (_Elem *)sce_paf_memcpy(_First1, _First2, _Count));
	}

	static const _Elem *find(const _Elem *_First, size_t _Count,
		const _Elem& _Ch)
	{	// look for _Ch in [_First, _First + _Count)
		return (_Count == 0 ? (const _Elem *)0
			: (const _Elem *)sce_paf_memchr(_First, _Ch, _Count));
	}

	static _Elem *move(_Elem *_First1, const _Elem *_First2,
		size_t _Count)
	{	// copy [_First2, _First2 + _Count) to [_First1, ...)
		return (_Count == 0 ? _First1
			: (_Elem *)sce_paf_memmove(_First1, _First2, _Count));
	}

	static _Elem *assign(_Elem *_First, size_t _Count,
		_Elem _Ch)
	{	// assign _Count * _Ch to [_First, ...)
		return ((_Elem *)sce_paf_memset(_First, _Ch, _Count));
	}

	static void assign(_Elem& _Left, const _Elem& _Right)
	{	// assign an element
		_Left = _Right;
	}

	static bool eq(const _Elem& _Left,
		const _Elem& _Right)
	{	// test for element equality
		return (_Left == _Right);
	}

	static bool lt(const _Elem& _Left,
		const _Elem& _Right)
	{	// test if _Left precedes _Right
		return ((unsigned char)_Left < (unsigned char)_Right);
	}

	static _Elem to_char_type(
		const int_type& _Meta)
	{	// convert metacharacter to character
		return ((_Elem)_Meta);
	}

	static int_type to_int_type(
		const _Elem& _Ch)
	{	// convert character to metacharacter
		return ((unsigned char)_Ch);
	}

	static bool eq_int_type(const int_type& _Left,
		const int_type& _Right)
	{	// test for metacharacter equality
		return (_Left == _Right);
	}

	static int_type not_eof(
		const int_type& _Meta)
	{	// return anything but EOF
		return (_Meta != eof() ? _Meta : !eof());
	}

	static int_type eof()
	{	// return end-of-file metacharacter
		return (EOF);
	}
};
}

#endif /* _IOSFWD_ */