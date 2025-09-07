/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_TOKENIZER_H
#define _PAF_COMMON_TOKENIZER_H

#include <stdint.h>
#include <stddef.h>
#include <paf/std/stdcxx.h>

namespace paf {
	namespace common {

		class Tokenizer
		{
		public:

			Tokenizer(string const& text)
			{
				if (text.empty())
				{
					init(NULL, 0);
				}
				else
				{
					init(text.c_str(), text.size());
				}
			}

			~Tokenizer()
			{

			}

			void init(const char *text, size_t size)
			{
				m_src = text;
				m_src_size = size;
			}

			void addSeparator(string const& value)
			{
				if (!value.empty())
				{
					m_separators.push_back(value);
				}
			}

			void addSeparatorChars(string const& value)
			{
				for (size_t i = 0; i != value.size(); i++)
				{
					string sep(value, i, 1);
					addSeparator(sep);
				}
			}

			void done()
			{
				m_loc.m_type = Location::DONE;
				m_loc.m_pos = m_loc.m_next_pos;
				m_loc.m_dirty = false;
				m_loc.m_word = "";
			}

			void next1()
			{
				Location::Type prev_type = m_loc.m_type;

				if (m_loc.m_next_pos == m_src_size)
				{
					done();
				}
				else
				{
					for (size_t i = 0; i != m_tokens.size(); i++)
					{
						if (match(m_loc.m_next_pos, m_tokens[i].c_str()))
						{
							m_loc.m_type = Location::TOKEN;
							m_loc.m_pos = m_loc.m_next_pos;
							m_loc.m_next_pos = m_loc.m_next_pos + m_tokens[i].size();
							m_loc.m_dirty = true;
							return;
						}
					}

					for (size_t i = 0; i != m_separators.size(); i++)
					{
						if (match(m_loc.m_next_pos, m_separators[i].c_str()))
						{
							m_loc.m_type = Location::SEPARATOR;
							m_loc.m_pos = m_loc.m_next_pos;
							m_loc.m_next_pos = m_loc.m_next_pos + m_separators[i].size();
							m_loc.m_dirty = true;
							return;
						}
					}

					if ((prev_type == Location::TOKEN) || (prev_type == Location::SEPARATOR))
					{
						m_loc.m_pos = m_loc.m_next_pos;
					}
					m_loc.m_type = Location::SCAN;
					m_loc.m_dirty = true;
					m_loc.m_next_pos = m_loc.m_next_pos + 1;
				}
			}

			Tokenizer& nextString()
			{
				char delim;

				if (m_loc.m_pos < m_src_size)
				{
					do
					{
						if (m_src[m_loc.m_pos] == '\"') break;
						m_loc.m_pos = m_loc.m_pos + 1;
					} while (m_loc.m_pos < m_src_size);
				}

				if (m_loc.m_pos == m_src_size)
				{
					done();
				}
				else
				{
					m_loc.m_pos = m_loc.m_pos + 1;
					m_loc.m_next_pos = m_loc.m_pos;
					delim = '\0';
					if (m_loc.m_next_pos < m_src_size)
					{
						do
						{
							if ((m_src[m_loc.m_next_pos] == '\"') && (delim != '\\')) break;
							m_loc.m_next_pos = m_loc.m_next_pos + 1;
							delim = m_src[m_loc.m_next_pos];
						} while (m_loc.m_next_pos < m_src_size);
					}
					if (m_loc.m_next_pos == m_src_size)
					{
						done();
					}
					else
					{
						m_loc.m_type = Location::OTHER;
						m_loc.m_dirty = true;
					}
				}

				return *this;
			}

			Tokenizer& operator++()
			{
				if (m_loc.m_type != Location::DONE)
				{
					while (true)
					{
						Location old_loc(m_loc);
						next1();
						if ((old_loc.m_type == Location::SCAN) && (m_loc.m_type != Location::SCAN))
						{
							m_loc = old_loc;
							m_loc.m_type = Location::OTHER;
						}
						if (((m_loc.m_type == Location::TOKEN) || (m_loc.m_type == Location::OTHER)) || (m_loc.m_type == Location::DONE)) break;
					}
				}
				return *this;
			}

			bool match(size_t pos, const char *str) const
			{
				const char *spos = str;
				for (size_t i = pos; (*spos != '\0' && (i < m_src_size)); i++)
				{
					if (*spos != m_src[i])
					{
						return false;
					}
					spos++;
				}
				return (*spos == '\0');
			}

			bool isDone() const
			{
				return (m_loc.m_type == Location::DONE);
			}

			string& word()
			{
				if (m_loc.m_dirty)
				{
					m_loc.m_word = string(m_src, m_loc.m_pos, m_loc.m_next_pos - m_loc.m_pos);
					m_loc.m_dirty = false;
				}
				return m_loc.m_word;
			}

			bool operator==(const char *str) const
			{
				bool ret;
				const char *spos;
				size_t i;

				if (isDone())
				{
					ret = false;
				}
				else
				{
					spos = str;
					for (i = m_loc.m_pos; ((*spos != '\0' && (i < m_src_size)) && (i < m_loc.m_next_pos)); i++)
					{
						if (*spos != this->m_src[i])
						{
							return false;
						}
						spos = spos + 1;
					}

					ret = false;
					if ((*spos == '\0') && (i == m_loc.m_next_pos))
					{
						ret = true;
					}
				}

				return ret;
			}

			bool operator!=(const char *str) const
			{
				return !(*this == str);
			}

		private:

			class Location
			{
			public:

				enum Type : int32_t
				{
					INITIAL,
					TOKEN,
					SEPARATOR,
					SCAN,
					OTHER,
					DONE
				};

				Location() : m_type(INITIAL), m_pos(0), m_next_pos(0), m_dirty(true)
				{

				}

				Location(Location const& other) : m_type(other.m_type), m_pos(other.m_pos), m_next_pos(other.m_next_pos), m_dirty(other.m_dirty), m_word(other.m_word)
				{

				}

				Location& operator=(Location const& rhs)
				{
					m_type = rhs.m_type;
					m_pos = rhs.m_pos;
					m_next_pos = rhs.m_next_pos;
					m_dirty = rhs.m_dirty;
					m_word = rhs.m_word;
					return *this;
				}

				Type m_type;
				size_t m_pos;
				size_t m_next_pos;
				bool m_dirty;
				string m_word;
			};

			const char *m_src;
			size_t m_src_size;
			vector<string> m_tokens;
			vector<string> m_separators;
			Location m_loc;
		};
	}
}

#endif /* _PAF_COMMON_TOKENIZER_H */
