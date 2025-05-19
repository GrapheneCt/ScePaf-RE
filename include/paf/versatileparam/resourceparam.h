/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_VERSATILEPARAM_RESOURCEPARAM_H
#define _VDSUITE_USER_PAF_VERSATILEPARAM_RESOURCEPARAM_H

#include <stddef.h>
#include <paf/std/string>

namespace paf {

	namespace cxml {

		class Element;
	}

	namespace resource {

		class ResourceObj;
	}

	class ResourceParam
	{
	public:

		enum Semantic
		{
			SEMANTIC_INT = 0,
			SEMANTIC_INT2 = 1,
			SEMANTIC_INT3 = 2,
			SEMANTIC_INT4 = 3,
			SEMANTIC_FLOAT = 4,
			SEMANTIC_VEC2 = 5,
			SEMANTIC_VEC3 = 6,
			SEMANTIC_VEC4 = 7,
			SEMANTIC_BOOL = 8,
			SEMANTIC_STRING = 9,
			SEMANTIC_HASH = 10,
			SEMANTIC_IDREF = 11,
			SEMANTIC_IDHASHREF = 12,
			SEMANTIC_STRINGREF = 13,
			SEMANTIC_HASHREF = 14,
			SEMANTIC_WIDGETREF = 15,
			SEMANTIC_STYLEREF = 16,
			SEMANTIC_LABELREF = 17,
			SEMANTIC_TEXTUREREF = 18,
			SEMANTIC_RESOARRAY = 19
		};

		enum ReadType
		{
			READTYPE_FROM_PARAMLIST = 0,
			READTYPE_FROM_XMLATTRIBUTE = 1
		};

		class SemanticParam
		{
		public:

			const char* param_name;
			void* param_addr;
			Semantic param_type;
		};

		ResourceParam();

		virtual ~ResourceParam();

		void AddParam(const char *name, void *addr, Semantic type);

		bool GetDirty();

		void SetDirty(bool flag);

		bool Read(cxml::Element const& elm, resource::ResourceObj *rscobj, ReadType type);

		void SetIDName(const char *idname);

		void SetTagName(const char *tagname);

	protected:

		char *m_idname;
		char *m_tagname;
		bool m_dirty;
		list<SemanticParam> m_param_list;
	};

}

#endif /* _VDSUITE_USER_PAF_VERSATILEPARAM_RESOURCEPARAM_H */