/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_CXML_CXML_H
#define _VDSUITE_USER_PAF_CXML_CXML_H

#include <stdint.h>
#include <stddef.h>
#include <paf/common/shared_ptr.h>

namespace paf {

	class File;

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
		public:

			Header();

			~Header() { };

			char magic[4]; //CXML
			int32_t version;  //0x110
			int32_t tree_offset;
			int32_t tree_size;
			int32_t idtable_offset;
			int32_t idtable_size;
			int32_t idhashtable_offset;
			int32_t idhashtable_size;
			int32_t stringtable_offset;
			int32_t stringtable_size;
			int32_t wstringtable_offset;
			int32_t wstringtable_size;
			int32_t hashtable_offset;
			int32_t hashtable_size;
			int32_t intarraytable_offset;
			int32_t intarraytable_size;
			int32_t floatarraytable_offset;
			int32_t floatarraytable_size;
			int32_t filetable_offset;
			int32_t filetable_size;
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
			typedef void(*Allocator)(AllocationType type, void *userdata, void *old_addr, size_t required_size, void **addr, size_t *size);

			/// Documentの書き出し関数型
			/// @param addr [in] 書き出し元バッファのアドレス
			/// @param size [in] 書き出し元バッファのサイズ
			/// @param userdata [in] Writeの第２引数として渡された任意のポインタ
			/// @return 書き出したサイズ
			/// @note この型の関数をDocument::Writeメソッドの第１引数として渡すことによって、書き出し先や書き出し方法をカスタマイズすることが出来る。
			typedef int32_t(*Writer)(const void *addr, size_t size, void *userdata);

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
			int32_t CreateFromBuffer(const void *buf, size_t bufsize, bool copy = false);

			int32_t CreateFromFile(common::SharedPtr<paf::File> fp, bool copy_filetable = false);

			/// ファイルやバッファを解放する
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note Documentオブジェクト内部に保持しているバッファや、開いているファイル、参照しているメモリが全て解放される。
			/// @note SetAllocatorメソッドによって設定されたメモリルーチンはリセットされない。
			int32_t Clear();

			/// ルート要素を取得する
			/// @return ルート要素
			/// @note ルート要素が存在しない場合は、無効なElementオブジェクトが返る
			Element GetDocumentElement();

			/// ヘッダ中のマジックナンバーを取得する
			/// @param buf [out] マジックの書き出しバッファ
			/// @sa SetHeaderMagic
			void GetHeaderMagic(char buf[4]) const;

			/// メモリ確保ルーチンをカスタマイズする
			/// @param _allocator [in] メモリ確保/開放関数
			/// @param _userdata [in] 任意のポインタ。Allocator関数の第２引数としてそのまま渡される。
			/// @note Documentオブジェクトがメモリを確保/解放する際に使用する関数を、指定された関数で置き換える。
			/// @note メモリ確保ルーチンのカスタマイズは、パフォーマンスのチューニングや、メモリ使用量に上限を設ける場合に有効である。
			void SetAllocator(Allocator _allocator, void *_userdata) { allocator = _allocator; allocator_userdata = _userdata; }

			bool IsRegisteredID(const char* id);

			bool IsRegisteredIDHash(uint32_t idhash);

		private:
			bool IsValidElement(int32_t offset) const;
			bool IsValidAttribute(int32_t offset) const;
			const char * GetIDString(int32_t offset) const;
			const char * GetString(int32_t offset) const;
			const int32_t * GetIntArray(int32_t offset, uint32_t num) const;
			const float * GetFloatArray(int32_t offset, uint32_t num) const;
			const void * GetFileAddr(int32_t offset, uint32_t size) const;
			const int32_t LoadFile(common::SharedPtr<paf::File> fp, void *buf, size_t bufsize, int32_t offset, size_t size) const;

		private:
			AccessMode access_mode;
			Header header;
			char * tree;
			uint32_t tree_capacity;
			char * idtable;
			uint32_t idtable_capacity;
			char * idhashtable;
			uint32_t idhashtable_capacity;
			char * stringtable;
			uint32_t stringtable_capacity;
			char * wstringtable;
			uint32_t wstringtable_capacity;
			char * hashtable;
			uint32_t hashtable_capacity;
			int * intarraytable;
			uint32_t intarraytable_capacity;
			float * floatarraytable;
			uint32_t floatarraytable_capacity;
			char * filetable;
			uint32_t filetable_capacity;
			Allocator allocator;
			void *allocator_userdata;

		private:
			Document(const Document & src);		// コピー禁止
			void operator=(const Document & src);	// コピー禁止
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
			int32_t NumAttribute() const;

			/// 属性を取得する(インデックスで)
			/// @param index [in] インデックス値(0〜)
			/// @param attr [out] Attributeオブジェクトを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			int32_t GetAttribute(int32_t index, class Attribute * attr) const;

			/// 属性を取得する(名前で)
			/// @param name [in] 属性の名前
			/// @param attr [out] Attributeオブジェクトを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			int32_t GetAttribute(const char * name, class Attribute * attr) const;

			int32_t GetNumChild() const;

			/// Elementオブジェクトが有効か無効かを調査する
			/// @return true:有効 false:無効
			operator bool() const { return (doc != 0 && offset >= 0); }

			/// Elementオブジェクトが同一か否かを調査する
			/// @return true:同一 false:同一ではない
			bool operator==(const Element & rhs) const { return (doc == rhs.doc && offset == rhs.offset); }

		private:
			Element(Document * _doc, int _offset)
				:
				doc(_doc),
				offset(_offset)
			{
			}

		private:
			Document * doc;
			int32_t offset;
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
			int32_t GetInt(int32_t * value) const;

			/// 浮動少数を取得する
			/// @param value [out] 浮動少数を受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型が浮動少数ではない場合は RESULT_ERROR_TYPE が返ります。
			int32_t GetFloat(float * value) const;

			/// 文字列を取得する
			/// @param value [out] 文字列のアドレスを受け取るためのポインタ
			/// @param len [out] 文字列の長さを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型が文字列ではない場合は RESULT_ERROR_TYPE が返ります。
			int32_t GetString(const char ** value, uint32_t * len) const;

			/// 文字列を取得する
			/// @param value [out] 文字列のアドレスを受け取るためのポインタ
			/// @param len [out] 文字列の長さを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型が文字列ではない場合は RESULT_ERROR_TYPE が返ります。
			int32_t GetWString(const wchar_t ** value, uint32_t * len) const;

			/// 整数の配列を取得する
			/// @param addr [out] 整数の配列の先頭アドレスを受け取るためのポインタ
			/// @param num [out] 整数の配列のサイズを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型が整数の配列ではない場合は RESULT_ERROR_TYPE が返ります。
			int32_t GetIntArray(const int32_t ** addr, uint32_t * num) const;

			/// 浮動少数の配列を取得する
			/// @param addr [out] 浮動少数の配列の先頭アドレスを受け取るためのポインタ
			/// @param num [out] 浮動少数の配列のサイズを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型が浮動少数の配列ではない場合は RESULT_ERROR_TYPE が返ります。
			int32_t GetFloatArray(const float ** addr, uint32_t * num) const;

			/// ファイルを取得する
			/// @param file [out] Fileオブジェクトを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型がファイルではない場合は RESULT_ERROR_TYPE が返ります。
			int32_t GetFile(class File * file) const;

			/// ID文字列を取得する
			/// @param value [out] ID文字列を受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型がIDではない場合は RESULT_ERROR_TYPE が返ります。
			int32_t GetID(const char ** value) const;

			/// IDへの参照を取得する
			/// @param value [out] ID文字列を受け取るためのポインタ
			/// @param entity [out] ID参照の実体を指し示すElementオブジェクトを受け取るためのポインタ
			/// @return 結果値 (RESULT_OK、RESULT_ERROR_XXXのいずれか)
			/// @note 属性の型がIDではない場合は RESULT_ERROR_TYPE が返ります。
			int32_t GetIDRef(const char ** value, Element * entity) const;

			int32_t GetHash(uint32_t * value) const;

			int32_t GetIDHash(uint32_t * value) const;

			int32_t GetIDHashRef(uint32_t * value, Element * entity) const;

			/// Attributeオブジェクトが有効か無効かを調査する
			/// @return true:有効 false:無効
			operator bool() const { return (doc != 0 && offset >= 0); }

		private:

			Attribute(Document * _doc, int32_t _element_offset, int32_t _offset)
				:
				doc(_doc),
				element_offset(_element_offset),
				offset(_offset)
			{
			}

		private:
			Document * doc;
			int32_t element_offset;
			int32_t offset;
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
			const void *GetAddr() const;

			/// ファイルのサイズを取得する
			/// @return ファイルのサイズ
			size_t GetSize() const { return size; }

			int32_t Load(common::SharedPtr<paf::File> fp, void *buf, size_t bufsize) const;

			/// Fileオブジェクトが有効か無効かを調査する
			/// @return true:有効 false:無効
			operator bool() const { return (doc != 0 && offset >= 0); }

		private:
			File(Document * _doc, int32_t _offset, int32_t _size)
				:
				doc(_doc),
				offset(_offset),
				size(_size)
			{
			}

		private:
			Document * doc;
			int32_t offset;
			int32_t size;
		};

		namespace util {
			/// 要素の名前が、指定されたものと一致するかを検査する
			/// @param elm [in] 要素
			/// @param valid_name [in] 期待している要素の名前
			/// @return true:一致した false:不一致だった
			extern bool CheckElementName(const cxml::Element & elm, const char * valid_name);

			/// 指定した名前とid属性を持つ子要素を検索する
			/// @param parent [in] 検索対象となる親要素
			/// @param name [in] 要素の名前
			/// @param idname [in] 検索条件とするID属性の名前
			/// @param idvalue [in] 検索条件とするID属性の値
			/// @return 最初に見つかった要素
			/// @note 引数idname/idvalueを省略するかNULLを与えたときは、IDは検索条件として使用されない
			/// @note 条件に一致する要素が発見されなかった場合には、無効なElementオブジェクトが返る
			extern cxml::Element FindChildElement(const cxml::Element & parent, const char * name, const char * idname = 0, const char * idvalue = 0);

			extern cxml::Element FindChildElement(const cxml::Element & parent, const char * name, const char * idname = 0, SceUInt32 idhashvalue = 0);

			extern cxml::Element FindChildElement(const cxml::Element & parent, const char * name);

			/// 要素の使われていない属性を検索する
			/// @param elm [in] 検索対象となる要素
			/// @param attr [out] 使われていない属性を格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 FindEmptyAttribute(const cxml::Element & elm, cxml::Attribute * attr);

			/// 要素の指定された名前の整数型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param i [out] 属性の値を格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetInt(const cxml::Element & elm, const char * attrname, SceInt32 * i);

			/// 要素の指定された名前の浮動少数型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param f [out] 属性の値を格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			SceInt32 GetFloat(const cxml::Element & elm, const char * attrname, SceFloat32 * f);

			/// 要素の指定された名前の文字列型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param str [out] 文字列のアドレスを格納するためのポインタ
			/// @param len [out] 文字列の長さを格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetString(const cxml::Element & elm, const char * attrname, const char ** str, SceUInt32 * len);

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
			extern SceInt32 GetIntArray(const cxml::Element & elm, const char * attrname, const SceInt32 ** addr, SceUInt32 * num);

			/// 要素の指定された名前の浮動少数配列型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param addr [out] 配列の先頭アドレスを格納するためのポインタ
			/// @param num [out] 配列の要素数を格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetFloatArray(const cxml::Element & elm, const char * attrname, const SceFloat32 ** addr, SceUInt32 * num);

			/// 要素の指定された名前のファイル型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param file [out] Fileオブジェクトを格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetFile(const cxml::Element & elm, const char * attrname, cxml::File * file);

			/// 要素の指定された名前のID型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param str [out] ID文字列のアドレスを格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetID(const cxml::Element & elm, const char * attrname, const char ** str);

			/// 要素の指定された名前のID参照型の属性を取得する
			/// @param elm [in] 要素
			/// @param attrname [in] 属性の名前
			/// @param str [out] ID文字列のアドレスを格納するためのポインタ
			/// @param entity [out] ID参照の実体を示すElementオブジェクトを格納するためのポインタ
			/// @return 結果値(CXML_OK、CXML_ERROR_XXXのいずれか)
			extern SceInt32 GetIDRef(const cxml::Element & elm, const char * attrname, const char ** str, cxml::Element * entity);

			extern SceInt32 GetHash(const cxml::Element & elm, const char * attrname, SceUInt32 * hash);

			extern SceInt32 GetIDHash(const cxml::Element & elm, const char * attrname, SceUInt32 * idhash);

			extern SceInt32 GetIDHashRef(const cxml::Element & elm, const char * attrname, SceUInt32 * idhash, cxml::Element * entity);
		}
	}
}

#endif /* _VDSUITE_USER_PAF_CXML_CXML_H */
