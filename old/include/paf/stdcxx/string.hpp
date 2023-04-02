#ifndef _VDSUITE_USER_PAF_STDCXX_STRING_H
#define _VDSUITE_USER_PAF_STDCXX_STRING_H

#include <scetypes.h>

namespace paf {
template<class _Elem,
	class _Traits = char_traits<_Elem>,
	class _Ax = allocator<_Elem> >
	class basic_string;

		// TEMPLATE CLASS basic_string
template<class _Elem,
	class _Traits,
	class _Alloc>
	class basic_string
{	// null-terminated transparent array of elements
public:
	typedef basic_string<_Elem, _Traits, _Alloc> _Myt;

	/**
	* @brief   コンストラクタ
	*
	*/
	basic_string()
		: _Myptr(&empty_string)
		, _Mysize(0)
#ifdef USE_HASHCODE
		, _Myhash(-1)
#endif
	{

	}
		

	/**
	* @brief   引数付きコンストラクタ
	*
	* @param   c   ->  コピーする文字列
	*/
	basic_string(const _Elem* c)
	{
		SetEmpty();

		if (c)
		{
			Copy(c, static_cast<SceInt32>(_Traits::length(c)));
#ifdef USE_HASHCODE
			this->_Myhash = CalcHashcode(WritePointer(), _Mysize);
#endif
		}
	}

	/**
	* @brief   引数付きコンストラクタ
	*
	* @param   c       ->  文字列
	* @param   length  ->  文字列からコピーする長さ
	*/
	basic_string(const _Elem* c, SceInt32 length)
	{
		SetEmpty();

		if (c)
		{
			Copy(c, length);
#ifdef USE_HASHCODE
			this->_Myhash = CalcHashcode(WritePointer(), length);
#endif
		}
	}

	/**
	* @brief   引数付きコンストラクタ
	*
	* @param[in]   s   ->  文字列
	*/
	basic_string(const _Myt& s)
	{
		if (!s.IsEmpty())
		{
			Copy(s._Myptr, s._Mysize);
			this->_Myhash = s._Myhash;
		}
		else
		{
			SetEmpty();
		}
	}

	/**
	* @brief   引数付きコンストラクタ
	*
	* @param[in]   c       ->  文字列
	* @param[in]   length  ->  文字列からコピーする長さ
	* @param[in]   usePtr  ->  trueなら引数のポインタを保持する（インスタンスと共に破棄される）<br> falseなら内部でコピーを実行する
	*/
	basic_string(const _Elem* c, SceInt32 length, bool usePtr)
	{
		SetEmpty();

		if (c)
			Initialize(c, length, usePtr);
	}

	/**
	* @brief   デストラクタ
	*
	*/
	~basic_string()
	{
		if (IsEmpty())
		{
			return;
		}

		if (this->_Myptr)
		{
			sce_paf_free((void *)this->_Myptr);
		}
	}

	/**
	* @brief =演算子のオーバーロード(_Myt型)
	*/
	_Myt& operator=(const _Myt& s)
	{
		clear(); //現在のポインタを開放してから処理する

		Copy(s._Myptr, s._Mysize);
		this->_Myhash = s._Myhash;
		return *this;
	}

	/**
	* @brief =演算子のオーバーロード(_Elem型)
	*/
	_Myt& operator=(const _Elem* c)
	{

		clear(); //現在のポインタを開放してから処理する

		if (c) {
			Copy(c, static_cast<SceInt32>(_Traits::length(c)));
#ifdef USE_HASHCODE
			this->_Myhash = CalcHashcode(this->_Myptr, this->_Mysize);
#endif
		}

		return *this;
	}

	/**
	* @brief ==演算子のオーバーロード(_Myt型)
	*/
	bool operator==(const _Myt& s) const
	{
		//サイズ違い
		if (s._Mysize != this->_Mysize) return false;

		//hashcode比較
#ifdef USE_HASHCODE
		if (this->_Myhash != s._Myhash) return false;
#endif

		if (_Traits::compare(_Myptr, s._Myptr, s._Mysize))
			return false;

		return true;
	}

	/**
	* @brief ==演算子のオーバーロード(_Elem型)
	*/
	bool operator==(const _Elem* c) const
	{
		//サイズ違い
		if (static_cast<SceInt32>(_Traits::length(c)) != this->_Mysize) return false;

		if (_Traits::compare(this->_Myptr, c, this->_Mysize))
			return false;

		return true;
	}

	/**
	* @brief <演算子のオーバーロード(_Myt型)
	*/
	bool operator<(const _Myt& s) const
	{
		if (this->_Mysize >= s._Mysize)
			return _Traits::compare(this->_Myptr, s._Myptr, s._Mysize) < 0;
		else
			return _Traits::compare(this->_Myptr, s._Myptr, this->_Mysize) < 0;
	}

	/**
	* @brief <演算子のオーバーロード(_Elem型)
	*/
	bool operator<(const _Elem* c) const
	{
		SceInt32 len = _Traits::length(c);
		if (this->_Mysize >= len)
			return _Traits::compare(this->_Myptr, c, len) < 0;
		else
			return _Traits::compare(this->_Myptr, c, this->_Mysize) < 0;
	}

	/**
	* @brief >演算子のオーバーロード(_Myt型)
	*/
	bool operator>(const _Myt& s) const
	{
		if (this->_Mysize >= s._Mysize)
			return _Traits::compare(this->_Myptr, s._Myptr, s._Mysize) > 0;
		else
			return _Traits::compare(this->_Myptr, s._Myptr, this->_Mysize) > 0;
	}

	/**
	* @brief >演算子のオーバーロード(_Elem型)
	*/
	bool operator>(const _Elem* c) const
	{
		SceInt32 len = _Traits::length(c);
		if (this->_Mysize >= len)
			return _Traits::compare(this->_Myptr, c, len) > 0;
		else
			return _Traits::compare(this->_Myptr, c, this->_Mysize) > 0;
	}

	/**
	* @brief +演算子のオーバーロード(_Myt型)
	*/
	_Myt operator+(const _Myt& s) const
	{
		SceInt32 len1 = this->_Mysize;
		SceInt32 len2 = s._Mysize;

		if (!len1 && !len2)
		{
			_Myt ret;
			return ret;
		}

		//メモリ管理の対象外とする（寿命が把握出来ない）
		_Elem* newptr = static_cast<_Elem*>(sce_paf_malloc(sizeof(_Elem) * (len1 + len2 + 1)));

		if (newptr == NULL)
		{
			_Myt ret;
			return ret;
		}

		//
		_Traits::copy(newptr, this->_Myptr, len1); //nullを含めない
		_Traits::copy(&newptr[len1], s._Myptr, s._Mysize + 1); //nullを含めて+1

		_Myt ret(newptr, static_cast<SceInt32>(len1 + len2), true);
		return ret;
	}

	/**
	* @brief +演算子のオーバーロード(_Elem型)
	*/
	_Myt operator+(const _Elem* c) const
	{
		SceInt32 len1 = this->_Mysize;
		SceInt32 len2 = _Traits::length(c);

		//メモリ管理の対象外とする（寿命が把握出来ない）
		_Elem* newptr = static_cast<_Elem*>(sce_paf_malloc(sizeof(_Elem) * (len1 + len2 + 1)));

		if (newptr == NULL)
		{
			_Myt ret;
			return ret;
		}

		_Traits::copy(newptr, this->_Myptr, len1); //nullを含めない
		_Traits::copy(&newptr[len1], c, len2 + 1); //nullを含めて+1

		_Myt ret(newptr, static_cast<SceInt32>(len1 + len2), true);
		return ret;
	}

	/**
	* @brief +=演算子のオーバーロード(_Myt型)
	*/
	_Myt& operator+=(const _Myt& s)
	{
		_Elem* newptr = NULL;
		SceInt32 len1 = this->_Mysize;

		newptr = static_cast<_Elem*>(sce_paf_malloc(sizeof(_Elem) * (this->_Mysize + s._Mysize + 1)));

		_Traits::copy(newptr, this->_Myptr, len1); //nullを含めない
		_Traits::copy(&newptr[len1], s._Myptr, s._Mysize + 1); //nullを含めて+1

		clear(); //現在のポインタを開放してから処理する
		Initialize(newptr, len1 + s._Mysize, true);

		return *this;
	}

	/**
	* @brief +=演算子のオーバーロード(_Elem型)
	*/
	_Myt& operator+=(const _Elem* c)
	{
		SceInt32 len1 = this->_Mysize;
		SceInt32 len2 = _Traits::length(c);

		_Elem* newptr = NULL;
			
		newptr = static_cast<_Elem*>(sce_paf_malloc(sizeof(_Elem) * (len1 + len2 + 1)));

		_Traits::copy(newptr, this->_Myptr, len1); //nullを含めない
		_Traits::copy(&newptr[len1], c, len2 + 1); //nullを含めて+1

		clear(); //現在のポインタを開放してから処理する
		Initialize(newptr, static_cast<SceInt32>(len1 + len2), true);
			
		return *this;
	}

	/**
	* @brief  文字列を後方に追加する
	*
	* @param[in]   c   ->  文字列
	* @param[in]   length  ->  追加する文字列の長さ
	* @return 更新された文字列
	*/
	_Myt& append(const _Elem* c, SceInt32 length)
	{
		SceInt32 len1 = this->_Mysize;

		_Elem* newptr = NULL;

		newptr = static_cast<_Elem*>(sce_paf_malloc(sizeof(_Elem) * (len1 + length + 1)));

		_Traits::copy(newptr, this->_Myptr, len1); //nullを含めない
		_Traits::copy(&newptr[len1], c, length); //nullを含めて+1

		clear(); //現在のポインタを開放してから処理する
		Initialize(newptr, len1 + length, true);

		return *this;
	}

	/**
	* @brief   文字サイズを拡張して文字を埋める
	*
	* @param[in]   length   ->  拡張する文字数
	* @param[in]   v        ->  埋める文字
	* @return 更新された文字列
	*/
	_Myt& append(SceInt32 length, const _Elem v)
	{
		SceInt32 len1 = this->_Mysize;

		_Elem* newptr = NULL;

		// 必要な長さ∔NULL分1バイトを新規確保
		newptr = static_cast<_Elem*>(sce_paf_malloc(sizeof(_Elem) * (len1 + length + 1)));
		// 元々の分をコピー
		_Traits::copy(newptr, this->_Myptr, len1); //nullを含めない
		// 新しい箇所をコピー
		for (SceInt32 i = len1 + length - 1; i >= len1; --i) newptr[i] = v;

		clear(); //現在のポインタを開放してから処理する
		Initialize(newptr, len1 + length, true);

		return *this;
	}

	/**
	* @brief   ポインタを解放する
	*/
	void clear()
	{
		if (IsEmpty())
		{
			return;
		}

		sce_paf_free((void *)this->_Myptr);

		SetEmpty();
	}

	const _Elem* c_str() const
	{
		return _Myptr;
	}

	const _Elem* data() const
	{
		return _Myptr;
	}

	bool empty() const
	{
		return IsEmpty();
	}

	SceInt32 size() const
	{
		return _Mysize;
	}

	SceInt32 length() const
	{
		return _Mysize;
	}

	SceInt32 capacity() const
	{
		return _Mysize;
	}

	__declspec(dllimport) static _Elem empty_string;

	_Elem* _Myptr;                         ///< 文字型配列のポインタ
	SceInt32 _Mysize;                      ///< 半角文字数（メモリ確保は最後に0が入るためlength+1）
	SceInt32 _Myhash;                      ///< インスタンスに当てられたハッシュ値

protected:

	/**
	* @brief   文字列をコピーする. 終端に\0を追加する
	*
	* @param[in]   c   ->  文字列
	* @param[in]   length  ->  コピーする文字数
	*/
	void Copy(const _Elem* c, SceInt32 length)
	{
		if (!length)
		{
			return;
		}

		this->_Mysize = length;

		this->_Myptr = static_cast<_Elem*>(sce_paf_malloc(sizeof(_Elem) * (length + 1)));

		_Traits::copy(this->_Myptr, c, length);
		this->_Myptr[length] = 0x0;
	}

	/**
	* @brief   Stringインスタンスの初期化関数。文字列のセットとハッシュコードの算出を行う。
	*
	* @param[in]   c       ->  文字列のポインタ
	* @param[in]   length  ->  文字列の長さ
	* @param[in]   usePtr  ->  trueなら第一引数のポインタを保持する(インスタンスと共に破棄される)。<br> falseなら内部でコピーを実行する
	*/
	void Initialize(const _Elem* c, SceInt32 length, bool usePtr)
	{
		if (!length)
		{
			SetEmpty();

			return;
		}

		if (!usePtr)
		{
			Copy(c, length);
		}
		else
		{
			this->_Myptr = const_cast<_Elem*>(c);
			this->_Mysize = length;
			this->_Myptr[length] = 0x0;
		}
#ifdef USE_HASHCODE
		this->_Myhash = CalcHashcode(this->_Myptr, this->_Mysize);
#endif
	}

#ifdef USE_HASHCODE
	/**
	* @brief   文字列からハッシュ値を生成して返す
	*
	* @param[in]   c       ->  文字列
	* @param[in]   length  ->  ハッシュ値の長さ
	* @return      文字列から生成したハッシュ値
	*/
	SceInt32 CalcHashcode(const _Elem* c, SceInt32 length)
	{
		SceInt32 hash = 0;
		for (SceInt32 i = length; i >= 0; --i)
		{
			hash = hash * 31 + c[i];
		}
		if (c == &empty_string)
		{
			hash = -1;
		}
		return hash;
	}
#endif

private:

	/**
	* @brief 文字列が空かどうか？
	*
	* 文字列が空かどうか確認する。
	*
	* @retval  true    空の文字列
	* @retval  false   値が設定されている
	*/
	bool IsEmpty() const
	{
		return (this->_Myptr == &empty_string);
	}

	/**
	* @brief 文字列を空に設定
	*
	* 文字列を空に設定する。
	*
	* @note ポインタに対してfree()はしない。
	*/
	void SetEmpty()
	{
		this->_Myptr = &empty_string;
		this->_Mysize = 0;
#ifdef USE_HASHCODE
		this->_Myhash = CalcHashcode(WritePointer(), this->_Mysize);
#endif
	}

	/**
	* @brief   C言語文字列としてのポインタを取得する
	*
	* @return   C言語文字列のポインタ
	*/
	_Elem* WritePointer()
	{
		return this->_Myptr;
	}
};
	
typedef basic_string<char, char_traits<char>, allocator<char> >
	string;
typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >
	wstring;

}
#endif