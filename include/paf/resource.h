/*
	Vita Development Suite Libraries git-9c2c72f1
*/

#ifndef _VDSUITE_USER_PAF_RESOURCE_H
#define _VDSUITE_USER_PAF_RESOURCE_H

#include <kernel.h>

namespace paf {

	namespace cxml {

		class Element;
		class File;

		/// 属性の型を表す列挙型
		enum AttributeType
		{
			AttributeType_None = 0, 		///< 属性が存在しない
			AttributeType_Int = 1,			///< 整数(32bit)
			AttributeType_Float = 2,		///< 浮動少数(32bit)
			AttributeType_String = 3,		///< 文字列(UTF-8)
			AttributeType_WString = 4,		///< 文字列(UTF-16)
			AttributeType_Hash = 5,			///< ハッシュ
			AttributeType_IntArray = 6,		///< 整数の配列
			AttributeType_FloatArray = 7,	///< 浮動少数の配列
			AttributeType_File = 8,			///< ファイル
			AttributeType_ID = 9,			///< ID
			AttributeType_IDRef = 10,		///< IDへの参照
			AttributeType_IDHash = 11,		///< IDハッシュ
			AttributeType_IDHashRef = 12,	///< IDハッシュへの参照
		};

		/// アクセスモード
		enum AccessMode
		{
			AccessMode_ReadWrite, 			///< 読み書きモード
			AccessMode_ReadOnly_File,		///< ファイルをオープンする読み取り専用モード
			AccessMode_ReadOnly_Memory,		///< メモリのコピーを作成しない読み取り専用モード
		};

		/// メモリ確保/開放の用途の種類
		enum AllocationType
		{
			AllocationType_Alloc_Tree,
			AllocationType_Alloc_IDTable,
			AllocationType_Alloc_IDHashTable,
			AllocationType_Alloc_StringTable,
			AllocationType_Alloc_WStringTable,
			AllocationType_Alloc_HashTable,
			AllocationType_Alloc_IntArrayTable,
			AllocationType_Alloc_FloatArrayTable,
			AllocationType_Alloc_FileTable,

			AllocationType_Free_Tree,
			AllocationType_Free_IDTable,
			AllocationType_Free_IDHashTable,
			AllocationType_Free_StringTable,
			AllocationType_Free_WStringTable,
			AllocationType_Free_HashTable,
			AllocationType_Free_IntArrayTable,
			AllocationType_Free_FloatArrayTable,
			AllocationType_Free_FileTable,
		};

		// ファイルヘッダ
		class Header
		{
			Header();

			~Header() { };

			SceChar8 magic[4]; //CXML
			SceInt32 version;  //0x110
			SceInt32 tree_offset;
			SceInt32 tree_size;
			SceInt32 idtable_offset;
			SceInt32 idtable_size;
			SceInt32 idhashtable_size;
			SceInt32 idhashtable_offset;
			SceInt32 stringtable_offset;
			SceInt32 stringtable_size;
			SceInt32 wstringtable_offset;
			SceInt32 wstringtable_size;
			SceInt32 hashtable_offset;
			SceInt32 hashtable_size;
			SceInt32 intarraytable_offset;
			SceInt32 intarraytable_size;
			SceInt32 floatarraytable_offset;
			SceInt32 floatarraytable_size;
			SceInt32 filetable_offset;
			SceInt32 filetable_size;
		};

		SceVoid DefaultAllocator(AllocationType type, ScePVoid userdata, ScePVoid old_addr, SceSize required_size, ScePVoid* addr, SceSize* size);

		/// CXML文書クラス
		class Document
		{
			friend class Element;
			friend class Attribute;
			friend class File;

		public:

			/// Documentのメモリ確保/開放関数型
			/// @param type [in] メモリ確保/開放の用途の種類
			/// @param userdata [in] SetAllocatorの第２引数として渡された任意のポインタ
			/// @param old_addr [in] 古いバッファのアドレス
			/// @param required_size [in] 最低限必要なサイズ( Allocのときに使用 )
			/// @param addr [out] 新しいバッファのアドレス ( Allocのときに使用 )
			/// @param size [out] 新しいバッファのサイズ ( Allocのときに使用 )
			/// @note typeがAllocationType_Alloc_Xxxの場合は、old_addr渡された古いバッファの内容をコピーしながら、最低 required_size byteのメモリを確保し、アドレスと実際に確保されたサイズを*addrと*sizeに格納する。
			/// @note typeがAllocationType_Free_Xxxの場合は、old_addrに渡された古いバッファを解放する。required_sizeとaddrとsizeには0が渡される。
			/// @note メモリが新規に確保される場合は、old_addrにはNULLが渡される。
			/// @note required_sizeに渡されたサイズよりも大きなバッファを確保することによって、メモリの再確保やコピーのコストを抑えることができる。
			/// @note また、メモリの使用量に上限を設けるために、old_addrがNULLのときだけ固定サイズのバッファを確保し、old_addrがNULLではないときには確保に失敗させる、という方法が使用できる。
			/// @note メモリ確保に失敗するには、*addrと*sizeに0を格納する。
			/// @sa SetAllocator
			typedef SceVoid (*Allocator)( AllocationType type, ScePVoid userdata, ScePVoid old_addr, SceSize required_size, ScePVoid* addr, SceSize* size );

			/// Documentの書き出し関数型
			/// @param addr [in] 書き出し元バッファのアドレス
			/// @param size [in] 書き出し元バッファのサイズ
			/// @param userdata [in] Writeの第２引数として渡された任意のポインタ
			/// @return 書き出したサイズ
			/// @note この型の関数をDocument::Writeメソッドの第１引数として渡すことによって、書き出し先や書き出し方法をカスタマイズすることが出来る。
			typedef SceInt32 (*Writer)( const ScePVoid addr, SceSize size, ScePVoid userdata );

		public:

			/// Documentクラスのコンストラクタ
			/// @note Documentクラスの生成直後は、アクセスモードはReadWriteモードに、マジックは"CXML"に、初期化されています。
			Document();

			/// Documentクラスのデストラクタ
			~Document();

			/// メモリ上のCXMLファイルイメージからCXML文書を生成する
			/// @param buf [in] CXMLファイルイメージの先頭アドレス
			/// @param bufsize [in] CXMLファイルイメージのサイズ
			/// @param writable [in] アクセスモード
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			SceInt32 CreateFromBuffer( const ScePVoid buf, SceSize bufsize, bool writable=false );

			/// ファイルやバッファを解放する
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note Documentオブジェクト内部に保持しているバッファや、開いているファイル、参照しているメモリが全て解放される。
			/// @note SetAllocatorメソッドによって設定されたメモリルーチンはリセットされない。
			SceInt32 Clear();

			/// ルート要素を取得する
			/// @return ルート要素
			/// @note ルート要素が存在しない場合は、無効なElementオブジェクトが返る
			Element GetDocumentElement();

			/// ヘッダ中のマジックナンバーを取得する
			/// @param buf [out] マジックの書き出しバッファ
			/// @sa SetHeaderMagic
			SceVoid GetHeaderMagic( char buf[4] ) const;

			/// メモリ確保ルーチンをカスタマイズする
			/// @param _allocator [in] メモリ確保/開放関数
			/// @param _userdata [in] 任意のポインタ。Allocator関数の第２引数としてそのまま渡される。
			/// @note Documentオブジェクトがメモリを確保/解放する際に使用する関数を、指定された関数で置き換える。
			/// @note メモリ確保ルーチンのカスタマイズは、パフォーマンスのチューニングや、メモリ使用量に上限を設ける場合に有効である。
			SceVoid SetAllocator( Allocator _allocator, ScePVoid _userdata ) { allocator=_allocator; allocator_userdata = _userdata; }

			bool IsRegisteredID(const char* id);

			bool IsRegisteredIDHash(SceUInt32 idhash);

		private:
			bool IsValidElement(SceInt32 offset ) const;
			bool IsValidAttribute(SceInt32 offset ) const;
			const char * GetIDString(SceInt32 offset ) const;
			const char * GetString(SceInt32 offset ) const;
			const SceInt32 * GetIntArray(SceInt32 offset, SceUInt32 num ) const;
			const SceFloat32 * GetFloatArray(SceInt32 offset, SceUInt32 num ) const;
			const ScePVoid GetFileAddr(SceInt32 offset, SceUInt32 size ) const;

		private:
			AccessMode access_mode;
			Header header;
			char * tree;
			SceUInt32 tree_capacity;
			char * idtable;
			SceUInt32 idtable_capacity;
			char * idhashtable;
			SceUInt32 idhashtable_capacity;
			char * stringtable;
			SceUInt32 stringtable_capacity;
			char * wstringtable;
			SceUInt32 wstringtable_capacity;
			char * hashtable;
			SceUInt32 hashtable_capacity;
			int * intarraytable;
			SceUInt32 intarraytable_capacity;
			float * floatarraytable;
			SceUInt32 floatarraytable_capacity;
			char * filetable;
			SceUInt32 filetable_capacity;
			Allocator allocator;
			ScePVoid allocator_userdata;

		private:
			Document( const Document & src );		// コピー禁止
			void operator=( const Document & src );	// コピー禁止
		};

		/// 要素クラス
		class Element
		{
			friend class Document;
			friend class Attribute;
			friend class capi;

		public:
			/// Elementクラスのコンストラクタ
			Element()
				:
				doc(0),
				offset(-1)
			{
			}

			/// Elementクラスのデストラクタ
			~Element()
			{
			}

			/// 親要素を取得する
			/// @return 親要素を指すElementオブジェクト
			/// @note 親要素が存在しない場合には、無効なElementオブジェクトが返る
			Element GetParent() const;

			/// 前の要素を取得する
			/// @return 前の要素を指すElementオブジェクト
			/// @note 前の要素が存在しない場合には、無効なElementオブジェクトが返る
			Element GetPreviousSibling() const;

			/// 次の要素を取得する
			/// @return 次の要素を指すElementオブジェクト
			/// @note 次の要素が存在しない場合には、無効なElementオブジェクトが返る
			Element GetNextSibling() const;

			/// 最初の子要素を取得する
			/// @return 最初の子要素を指すElementオブジェクト
			/// @note 最初の子要素が存在しない場合には、無効なElementオブジェクトが返る
			Element GetFirstChild() const;

			/// 最後の子要素を取得する
			/// @return 最後の子要素を指すElementオブジェクト
			/// @note 最後の子要素が存在しない場合には、無効なElementオブジェクトが返る
			Element GetLastChild() const;

			/// 要素の名前を取得する
			/// @return 要素の名前
			const char * GetName() const;

			/// 属性の数を取得する
			/// @return 属性の数
			SceInt32 NumAttribute() const;

			/// 属性を取得する(インデックスで)
			/// @param index [in] インデックス値(0〜)
			/// @param attr [out] Attributeオブジェクトを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			SceInt32 GetAttribute(SceInt32 index, class Attribute * attr ) const;

			/// 属性を取得する(名前で)
			/// @param name [in] 属性の名前
			/// @param attr [out] Attributeオブジェクトを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			SceInt32 GetAttribute( const char * name, class Attribute * attr ) const;

			SceInt32 GetNumChild() const;

			/// Elementオブジェクトが有効か無効かを調査する
			/// @return true:有効 false:無効
			operator bool() const { return ( doc!=0 && offset>=0 ); }

			/// Elementオブジェクトが同一か否かを調査する
			/// @return true:同一 false:同一ではない
			bool operator==( const Element & rhs ) const { return ( doc==rhs.doc && offset==rhs.offset ); }

		private:
			Element( Document * _doc, int _offset )
				:
				doc(_doc),
				offset(_offset)
			{
			}

		private:
			Document * doc;
			SceInt32 offset;
		};

		/// 属性クラス
		class Attribute
		{
			friend class Element;

		public:

			/// Attributeクラスのコンストラクタ
			Attribute()
				:
				doc(0),
				element_offset(-1),
				offset(-1)
			{
			}

			/// Attributeクラスのデストラクタ
			~Attribute()
			{
			}

			/// 属性の名前を取得する
			/// @return 属性の名前
			const char * GetName() const;

			/// 属性の型を取得する
			/// @return 属性の型
			AttributeType GetType() const;

			/// 整数を取得する
			/// @param value [out] 整数を受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型が整数ではない場合は RESULT_ERROR_TYPE が返ります。
			SceInt32 GetInt( SceInt32 * value ) const;

			/// 浮動少数を取得する
			/// @param value [out] 浮動少数を受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型が浮動少数ではない場合は RESULT_ERROR_TYPE が返ります。
			SceInt32 GetFloat( SceFloat32 * value ) const;

			/// 文字列を取得する
			/// @param value [out] 文字列のアドレスを受け取るためのポインタ
			/// @param len [out] 文字列の長さを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型が文字列ではない場合は RESULT_ERROR_TYPE が返ります。
			SceInt32 GetString( const char ** value, SceUInt32 * len ) const;

			/// 文字列を取得する
			/// @param value [out] 文字列のアドレスを受け取るためのポインタ
			/// @param len [out] 文字列の長さを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型が文字列ではない場合は RESULT_ERROR_TYPE が返ります。
			SceInt32 GetWString(const wchar_t ** value, SceUInt32 * len) const;

			/// 整数の配列を取得する
			/// @param addr [out] 整数の配列の先頭アドレスを受け取るためのポインタ
			/// @param num [out] 整数の配列のサイズを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型が整数の配列ではない場合は RESULT_ERROR_TYPE が返ります。
			SceInt32 GetIntArray(const SceInt32 ** addr, SceUInt32 * num) const;

			/// 浮動少数の配列を取得する
			/// @param addr [out] 浮動少数の配列の先頭アドレスを受け取るためのポインタ
			/// @param num [out] 浮動少数の配列のサイズを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型が浮動少数の配列ではない場合は RESULT_ERROR_TYPE が返ります。
			SceInt32 GetFloatArray( const SceFloat32 ** addr, SceUInt32 * num ) const;

			/// ファイルを取得する
			/// @param file [out] Fileオブジェクトを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型がファイルではない場合は RESULT_ERROR_TYPE が返ります。
			SceInt32 GetFile( class File * file ) const;

			/// ID文字列を取得する
			/// @param value [out] ID文字列を受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型がIDではない場合は RESULT_ERROR_TYPE が返ります。
			SceInt32 GetID( const char ** value ) const;

			/// IDへの参照を取得する
			/// @param value [out] ID文字列を受け取るためのポインタ
			/// @param entity [out] ID参照の実体を指し示すElementオブジェクトを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型がIDではない場合は RESULT_ERROR_TYPE が返ります。
			SceInt32 GetIDRef( const char ** value, Element * entity ) const;

			SceInt32 GetHash( SceUInt32 * value) const;

			SceInt32 GetIDHash(SceUInt32 * value) const;

			SceInt32 GetIDHashRef( SceUInt32 * value, Element * entity) const;

			/// Attributeオブジェクトが有効か無効かを調査する
			/// @return true:有効 false:無効
			operator bool() const { return ( doc!=0 && offset>=0 ); }

		private:

			Attribute( Document * _doc, SceInt32 _element_offset, SceInt32 _offset )
				:
				doc(_doc),
				element_offset(_element_offset),
				offset(_offset)
			{
			}

		private:
			Document * doc;
			SceInt32 element_offset;
			SceInt32 offset;
		};

		/// ファイルクラス
		class File
		{
			friend class Document;
			friend class Attribute;

		public:
			/// Fileクラスのコンストラクタ
			File()
				:
				doc(0),
				offset(-1),
				size(0)
			{
			}

			/// Fileクラスのデストラクタ
			~File()
			{
			}

			/// ファイルのメモリ上のイメージの先頭アドレスを取得する
			/// @return 先頭アドレス
			/// @note このメソッドは、Documentオブジェクトのアクセスモードが、AccessMode_ReadWrite または AccessMode_ReadOnly_Memory の場合にのみ使用できる。
			const ScePVoid GetAddr() const;

			/// ファイルのサイズを取得する
			/// @return ファイルのサイズ
			SceSize GetSize() const { return size; }

			/// Fileオブジェクトが有効か無効かを調査する
			/// @return true:有効 false:無効
			operator bool() const { return ( doc!=0 && offset>=0 ); }

		private:
			File( Document * _doc, SceInt32 _offset, SceInt32 _size )
				:
				doc(_doc),
				offset(_offset),
				size(_size)
			{
			}

		private:
			Document * doc;
			SceInt32 offset;
			SceInt32 size;
		};

		namespace util {
			/// 要素の名前が、指定されたものと一致するかを検査する
			/// @param elm [in] 要素
			/// @param valid_name [in] 期待している要素の名前
			/// @return true:一致した false:不一致だった
			extern bool CheckElementName( const cxml::Element & elm, const char * valid_name );

			/// 指定した名前とid属性を持つ子要素を検索する
			/// @param parent [in] 検索対象となる親要素
			/// @param name [in] 要素の名前
			/// @param idname [in] 検索条件とするID属性の名前
			/// @param idvalue [in] 検索条件とするID属性の値
			/// @return 最初に見つかった要素
			/// @note 引数idname/idvalueを省略するかNULLを与えたときは、IDは検索条件として使用されない
			/// @note 条件に一致する要素が発見されなかった場合には、無効なElementオブジェクトが返る
			extern cxml::Element FindChildElement( const cxml::Element & parent, const char * name, const char * idname=0, const char * idvalue=0 );

			extern cxml::Element FindChildElement(const cxml::Element & parent, const char * name, const char * idname=0, SceUInt32 idhashvalue=0);

			extern cxml::Element FindChildElement(const cxml::Element & parent, const char * name);

			/// 要素の使われていない属性を検索する
			/// @param elm [in] 検索対象となる要素
			/// @param attr [out] 使われていない属性を格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 FindEmptyAttribute( const cxml::Element & elm, cxml::Attribute * attr );

			/// 要素の指定された名前の整数型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param i [out] 属性の値を格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetInt( const cxml::Element & elm, const char * attrname, SceInt32 * i );

			/// 要素の指定された名前の浮動少数型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param f [out] 属性の値を格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			SceInt32 GetFloat( const cxml::Element & elm, const char * attrname, SceFloat32 * f );

			/// 要素の指定された名前の文字列型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param str [out] 文字列のアドレスを格納するためのポインタ
			/// @param len [out] 文字列の長さを格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetString( const cxml::Element & elm, const char * attrname, const char ** str, SceUInt32 * len );

			/// 要素の指定された名前の文字列型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param str [out] 文字列のアドレスを格納するためのポインタ
			/// @param len [out] 文字列の長さを格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetWString(const cxml::Element & elm, const char * attrname, const wchar_t ** str, SceUInt32 * len);

			/// 要素の指定された名前の整数配列型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param addr [out] 配列の先頭アドレスを格納するためのポインタ
			/// @param num [out] 配列の要素数を格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetIntArray( const cxml::Element & elm, const char * attrname, const SceInt32 ** addr, SceUInt32 * num );

			/// 要素の指定された名前の浮動少数配列型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param addr [out] 配列の先頭アドレスを格納するためのポインタ
			/// @param num [out] 配列の要素数を格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetFloatArray( const cxml::Element & elm, const char * attrname, const SceFloat32 ** addr, SceUInt32 * num );

			/// 要素の指定された名前のファイル型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param file [out] Fileオブジェクトを格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetFile( const cxml::Element & elm, const char * attrname, cxml::File * file );

			/// 要素の指定された名前のID型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param str [out] ID文字列のアドレスを格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetID( const cxml::Element & elm, const char * attrname, const char ** str );

			/// 要素の指定された名前のID参照型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param str [out] ID文字列のアドレスを格納するためのポインタ
			/// @param entity [out] ID参照の実体を示すElementオブジェクトを格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetIDRef( const cxml::Element & elm, const char * attrname, const char ** str, cxml::Element * entity );

			extern SceInt32 GetHash(const cxml::Element & elm, const char * attrname, SceUInt32 * hash);

			extern SceInt32 GetIDHash(const cxml::Element & elm, const char * attrname, SceUInt32 * idhash);

			extern SceInt32 GetIDHashRef(const cxml::Element & elm, const char * attrname, SceUInt32 * idhash, cxml::Element * entity);
		}
	}

	namespace rco {

		class Element
		{
		public:

			Element() : hash(0)
			{

			}

			~Element()
			{

			}

			SceUInt32 GetHash(paf::string *id);

			paf::string id;
			SceUInt32 hash;
		};

		class Resource
		{
		public:

			enum ResourceType
			{
				ResourceType_File,
				ResourceType_Buffer,
			};

			enum TableType
			{
				TableType_Pagetable,
				TableType_Styletable,
				TableType_Stringtable,
				TableType_Texturetable,
				TableType_Modeltable,
				TableType_Sounddatatable,
				TableType_Soundindextable,
				TableType_Filetable,
				TableType_Templatetable,
				TableType_Aliastable,
			};

			enum TextureFormat
			{
				TextureFormat_Invalid = -1,
				TextureFormat_PNG,
				TextureFormat_JPEG,
				TextureFormat_TIFF,
				TextureFormat_GIF,
				TextureFormat_BMP,
				TextureFormat_GIM,
				TextureFormat_DDS,
				TextureFormat_GXT
			};

			enum ModelFormat
			{
				ModelFormat_Invalid = -1,
				ModelFormat_GMO,
			};

			enum SoundFormat
			{
				SoundFormat_Invalid = -1,
				SoundFormat_WAV,
				SoundFormat_VAG,
				SoundFormat_MP3,
				SoundFormat_AT3,
				SoundFormat_AAC,
			};

			class InitParam
			{
			public:

				SceUInt32 flags;
				paf::memory::HeapAllocator *memAllocator;
				paf::cxml::Document::Allocator allocator;
			};

			Resource(const char *resourcePath, InitParam *param);

			Resource(const ScePVoid memory, SceSize size, InitParam *param);

			~Resource();

			cxml::Element FindTable(TableType type);

			SceInt32 GetPage(SceUInt32 hash, cxml::Element * page);

			SceInt32 GetPage(const char *id, cxml::Element * page);

			SceInt32 GetWString(SceUInt32 hash, const wchar_t **str, SceUInt32 *len);

			SceInt32 GetWString(const char *id, const wchar_t **str, SceUInt32 *len);

			SceInt32 GetWString(const paf::cxml::Element & elm, const wchar_t **str, SceUInt32 *len);

			SceInt32 GetTexture(SceUInt32 hash, cxml::File *texture, SceUInt32 *size, TextureFormat *format);

			SceInt32 GetTexture(const char *id, cxml::File *texture, SceUInt32 *size, TextureFormat *format);

			SceInt32 GetTexture(const paf::cxml::Element & elm, cxml::File *texture, SceUInt32 *size, TextureFormat *format);

			SceInt32 GetModel(SceUInt32 hash, cxml::File *model, SceUInt32 *size, ModelFormat *format);

			SceInt32 GetModel(const char *id, cxml::File *model, SceUInt32 *size, ModelFormat *format);

			SceInt32 GetModel(const paf::cxml::Element & elm, cxml::File *model, SceUInt32 *size, ModelFormat *format);

			SceInt32 GetSound(SceUInt32 hash, cxml::File *leftOrMono, SceUInt32 *leftOrMonoSize, cxml::File *right, SceUInt32 *rightSize, SceUInt32 *samplerate, SoundFormat *format);

			SceInt32 GetSound(const char *id, cxml::File *leftOrMono, SceUInt32 *leftOrMonoSize, cxml::File *right, SceUInt32 *rightSize, SceUInt32 *samplerate, SoundFormat *format);

			SceInt32 GetSound(const paf::cxml::Element & elm, cxml::File *leftOrMono, SceUInt32 *leftOrMonoSize, cxml::File *right, SceUInt32 *rightSize, SceUInt32 *samplerate, SoundFormat *format);

			common::SharedPtr<MemFile> GetFile(SceUInt32 hash, ScePVoid decompMem, SceSize *size, const char **type, paf::memory::HeapAllocator *decompAlloc = SCE_NULL);

			common::SharedPtr<MemFile> GetFile(const char *id, ScePVoid decompMem, SceSize *size, const char **type, paf::memory::HeapAllocator *decompAlloc = SCE_NULL);

			common::SharedPtr<MemFile> GetFile(const paf::cxml::Element & elm, ScePVoid decompMem, SceSize *size, const char **type, paf::memory::HeapAllocator *decompAlloc = SCE_NULL);

			common::SharedPtr<MemFile> GetFile(SceUInt32 hash, SceSize *size, const char **type, paf::memory::HeapAllocator *fileAlloc = SCE_NULL, paf::memory::HeapAllocator *decompAlloc = SCE_NULL);

			common::SharedPtr<MemFile> GetFile(const char *id, SceSize *size, const char **type, paf::memory::HeapAllocator *fileAlloc = SCE_NULL, paf::memory::HeapAllocator *decompAlloc = SCE_NULL);

			common::SharedPtr<MemFile> GetFile(const paf::cxml::Element & elm, SceSize *size, const char **type, paf::memory::HeapAllocator *fileAlloc = SCE_NULL, paf::memory::HeapAllocator *decompAlloc = SCE_NULL);

			bool IsRegisteredID(const char* id, bool checkByHash = false);

			bool IsRegisteredIDHash(SceUInt32 idhash);

			cxml::Document *GetDocument() const;

			SceInt32 GetError() const;

			ResourceType GetType() const;

			char *GetPath() const;

		private:

			SceChar8 unk_00[0x6C];
		};

		class ResourceBase
		{
		public:

			ResourceBase();

			virtual const char *name() const;
			virtual ~ResourceBase();
			virtual SceInt32 unkFun_08();
			virtual SceInt32 unkFun_0C();
			virtual SceInt32 unkFun_10();

		protected:

			__declspec(dllimport) static char *_Myname;

		private:

			SceChar8 unk_00[0x20];
		};

		class WidgetBase
		{
		public:

			virtual const char *name() const;
			virtual ~WidgetBase();
			virtual SceInt32 unkFun_08();
			virtual SceInt32 unkFun_0C();
			virtual SceInt32 unkFun_10();
			virtual SceInt32 unkFun_14();
			virtual SceInt32 unkFun_18();
			virtual SceInt32 unkFun_1C();
			virtual SceInt32 unkFun_20();
			virtual SceInt32 unkFun_24();
			virtual SceInt32 unkFun_28();

		protected:

			__declspec(dllimport) static char *_Myname;

		private:

			WidgetBase();

			SceChar8 unk_00[0x20];
		};

		class DrawObj
		{
		public:

			virtual const char *name() const;
			virtual ~DrawObj();
			virtual SceInt32 unkFun_08();
			virtual SceInt32 unkFun_0C();
			virtual SceInt32 unkFun_10();
			virtual SceInt32 unkFun_14();
			virtual SceInt32 unkFun_18();
			virtual SceInt32 unkFun_1C();
			virtual SceInt32 unkFun_20();
			virtual SceInt32 unkFun_24();
			virtual SceInt32 unkFun_28();
			virtual SceInt32 unkFun_2C();
			virtual SceInt32 unkFun_30();

		protected:

			__declspec(dllimport) static char *_Myname;

		private:

			DrawObj();

			SceChar8 unk_00[0x20];
		};

		class LayoutHint
		{
		public:

			LayoutHint();

			virtual const char *name() const;
			virtual ~LayoutHint();
			virtual SceInt32 unkFun_08();
			virtual SceInt32 unkFun_0C();
			virtual SceInt32 unkFun_10();
			virtual SceInt32 unkFun_14();
			virtual SceInt32 unkFun_18();
			virtual SceInt32 unkFun_1C();
			virtual SceInt32 unkFun_20();
			virtual SceInt32 unkFun_24();
			virtual SceInt32 unkFun_28();

		protected:

			__declspec(dllimport) static char *_Myname;

		private:

			SceChar8 unk_00[0x98];
		};

		class FocusHint
		{
		public:

			FocusHint();

			virtual const char *name() const;
			virtual ~FocusHint();
			virtual SceInt32 unkFun_08();
			virtual SceInt32 unkFun_0C();
			virtual SceInt32 unkFun_10();
			virtual SceInt32 unkFun_14();
			virtual SceInt32 unkFun_18();
			virtual SceInt32 unkFun_1C();
			virtual SceInt32 unkFun_20();
			virtual SceInt32 unkFun_24();
			virtual SceInt32 unkFun_28();

		protected:

			__declspec(dllimport) static char *_Myname;

		private:

			SceChar8 unk_00[0xC4];
		};

		class StyleWidget
		{
		public:

			virtual const char *name() const;
			virtual ~StyleWidget();
			virtual SceInt32 unkFun_08();
			virtual SceInt32 unkFun_0C();
			virtual SceInt32 unkFun_10();
			virtual SceInt32 unkFun_14();
			virtual SceInt32 unkFun_18();
			virtual SceInt32 unkFun_1C();
			virtual SceInt32 unkFun_20();
			virtual SceInt32 unkFun_24();
			virtual SceInt32 unkFun_28();
			virtual SceInt32 unkFun_2C();
			virtual SceInt32 unkFun_30();
			virtual SceInt32 unkFun_34();
			virtual SceInt32 unkFun_38();

		protected:

			__declspec(dllimport) static char *_Myname;

		private:

			StyleWidget();

			SceChar8 unk_00[0xC4];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_RESOURCE_H */
