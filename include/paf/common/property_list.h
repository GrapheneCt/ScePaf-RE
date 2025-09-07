/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_PROPERTY_LIST_H
#define _PAF_COMMON_PROPERTY_LIST_H

#include <stdint.h>
#include <stddef.h>
#include <paf/std/stdcxx.h>
#include <paf/common/shared_ptr.h>
#include <paf/versatileparam/idparam.h>
#include <paf/paf_types.h>

namespace paf {
	namespace common {
		namespace property_list {

			class PropertyValue
			{
			public:

				PropertyValue() : l(0)
				{

				}

				PropertyValue(int64_t v) : l(v)
				{

				}

				PropertyValue(int32_t v) : i(v)
				{

				}

				PropertyValue(float v) : f(v)
				{

				}

				PropertyValue(void* v) : p(v)
				{

				}

				PropertyValue(PropertyValue const& rhs) : l(rhs.l)
				{

				}

				~PropertyValue()
				{

				}

				PropertyValue& operator=(PropertyValue const& rhs)
				{
					l = rhs.l;
					return *this;
				}

			private:

				union
				{
					int64_t l;
					int32_t i;
					float f;
					void *p;
				};
			};

			class PropertyElement
			{
			public:

				PropertyElement()
				{

				}

				virtual bool IsInherit(const char *type);

				virtual const char *GetTypeName() const;

				virtual ~PropertyElement()
				{

				}

				const char *TypeName();

			protected:

				SCE_PAF_IMPORTED_FROM_PRX static const char *m_type_name;
			};

			class StringElement : public PropertyElement
			{
			public:

				static string const& GetString(SharedPtr<PropertyElement> value);

				StringElement(string const& value) : m_value(value)
				{

				}

				virtual bool IsInherit(const char *type);

				virtual const char *GetTypeName() const;

				virtual ~StringElement()
				{

				}

				const char *TypeName();

				string& GetValue()
				{
					return m_value;
				}

				const string& GetEmpty() const
				{
					return s_empty_string;
				}

				SCE_PAF_IMPORTED_FROM_PRX static const string s_empty_string;

			private:

				SCE_PAF_IMPORTED_FROM_PRX static const char *m_type_name;

				string m_value;
			};

			class WStringElement : public PropertyElement
			{
			public:

				static wstring const& GetString(SharedPtr<PropertyElement> value);

				WStringElement(wstring const& value) : m_value(value)
				{

				}

				virtual bool IsInherit(const char *type);

				virtual const char *GetTypeName() const;

				virtual ~WStringElement()
				{

				}

				const char *TypeName();

				wstring& GetValue()
				{
					return m_value;
				}

				const wstring& GetEmpty() const
				{
					return s_empty_string;
				}

				SCE_PAF_IMPORTED_FROM_PRX static const wstring s_empty_string;

			private:

				SCE_PAF_IMPORTED_FROM_PRX static const char *m_type_name;

				wstring m_value;
			};


			// TODO: needs paf::vector fix
			class PropertyList
			{
			public:

				PropertyList()
				{

				}

				~PropertyList()
				{

				}

				void SetElement(size_t sce_paf_index, SharedPtr<PropertyElement> value);
				void SetElement(IDParam const& key, SharedPtr<PropertyElement> value);

				void SetString(size_t sce_paf_index, string const& value);
				void SetString(IDParam const& key, string const& value);

				void SetWString(size_t sce_paf_index, wstring const& value);
				void SetWString(IDParam const& key, wstring const& value);

				void SetValue(size_t sce_paf_index, PropertyValue value);
				void SetValue(IDParam const& key, PropertyValue value);

				SharedPtr<PropertyElement> GetElement(size_t sce_paf_index) const;
				SharedPtr<PropertyElement> GetElement(IDParam const& key) const;

				string const& GetString(size_t sce_paf_index) const;
				string const& GetString(IDParam const& key) const;

				wstring const& GetWString(size_t sce_paf_index) const;
				wstring const& GetWString(IDParam const& key) const;

				PropertyValue GetValue(size_t sce_paf_index) const;
				PropertyValue GetValue(IDParam const& key) const;

				bool HasElement(IDParam const& key) const;
				bool HasValue(IDParam const& key) const;

			private:

				vector<SharedPtr<PropertyElement>> m_elem_vector;
				map<IDParam, SharedPtr<PropertyElement>> m_elem_map;
				vector<PropertyValue> m_pod_vector;
				map<IDParam, PropertyValue> m_pod_map;
			};
		}
	}
}

#endif /* _PAF_COMMON_PROPERTY_LIST_H */
