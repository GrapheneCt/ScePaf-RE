/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_TOKENIZER_H
#define _VDSUITE_USER_PAF_COMMON_TOKENIZER_H

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
				_src = text;
				_src_size = size;
			}

			void addSeparator(string const& value)
			{
				if (!value.empty())
				{
					_separators.push_back(value);
				}
			}

			void addSeparatorChars(string const& value)
			{
				for (uint32_t i = 0; i != value.size(); i++)
				{
					string sep(value, i, 1);
					addSeparator(sep);
				}
			}

			void done()
			{
				_loc._type = Location::DONE;
				_loc._pos = _loc._next_pos;
				_loc._dirty = false;
				_loc._word = "";
			}

			void next1()
			{
				Location::Type prev_type = _loc._type;

				if (_loc._next_pos == _src_size)
				{
					done();
				}
				else
				{
					for (uint32_t i = 0; i != _tokens.size(); i++)
					{
						if (match(_loc._next_pos, _tokens[i].c_str()))
						{
							_loc._type = Location::TOKEN;
							_loc._pos = _loc._next_pos;
							_loc._next_pos = _loc._next_pos + _tokens[i].size();
							_loc._dirty = true;
							return;
						}
					}

					for (uint32_t i = 0; i != _separators.size(); i++)
					{
						if (match(_loc._next_pos, _separators[i].c_str()))
						{
							_loc._type = Location::SEPARATOR;
							_loc._pos = _loc._next_pos;
							_loc._next_pos = _loc._next_pos + _separators[i].size();
							_loc._dirty = true;
							return;
						}
					}

					if ((prev_type == Location::TOKEN) || (prev_type == Location::SEPARATOR))
					{
						_loc._pos = _loc._next_pos;
					}
					_loc._type = Location::SCAN;
					_loc._dirty = true;
					_loc._next_pos = _loc._next_pos + 1;
				}
			}

			Tokenizer& nextString()
			{
				char delim;

				if (_loc._pos < _src_size)
				{
					do
					{
						if (_src[_loc._pos] == '\"') break;
						_loc._pos = _loc._pos + 1;
					} while (_loc._pos < _src_size);
				}

				if (_loc._pos == _src_size)
				{
					done();
				}
				else
				{
					_loc._pos = _loc._pos + 1;
					_loc._next_pos = _loc._pos;
					delim = '\0';
					if (_loc._next_pos < _src_size)
					{
						do
						{
							if ((_src[_loc._next_pos] == '\"') && (delim != '\\')) break;
							_loc._next_pos = _loc._next_pos + 1;
							delim = _src[_loc._next_pos];
						} while (_loc._next_pos < _src_size);
					}
					if (_loc._next_pos == _src_size)
					{
						done();
					}
					else
					{
						_loc._type = Location::OTHER;
						_loc._dirty = true;
					}
				}

				return *this;
			}

			Tokenizer& operator++()
			{
				if (_loc._type != Location::DONE)
				{
					while (true)
					{
						Location old_loc(_loc);
						next1();
						if ((old_loc._type == Location::SCAN) && (_loc._type != Location::SCAN))
						{
							_loc = old_loc;
							_loc._type = Location::OTHER;
						}
						if (((_loc._type == Location::TOKEN) || (_loc._type == Location::OTHER)) || (_loc._type == Location::DONE)) break;
					}
				}
				return *this;
			}

			bool match(size_t pos, const char *str) const
			{
				const char *spos = str;
				for (uint32_t i = pos; (*spos != '\0' && (i < _src_size)); i++)
				{
					if (*spos != _src[i])
					{
						return false;
					}
					spos++;
				}
				return (*spos == '\0');
			}

			bool isDone() const
			{
				return (_loc._type == Location::DONE);
			}

			string& word()
			{
				if (_loc._dirty)
				{
					_loc._word = string(_src, _loc._pos, _loc._next_pos - _loc._pos);
					_loc._dirty = false;
				}
				return _loc._word;
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
					for (i = _loc._pos; ((*spos != '\0' && (i < _src_size)) && (i < _loc._next_pos)); i++)
					{
						if (*spos != this->_src[i])
						{
							return false;
						}
						spos = spos + 1;
					}

					ret = false;
					if ((*spos == '\0') && (i == _loc._next_pos))
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

				enum Type
				{
					INITIAL,
					TOKEN,
					SEPARATOR,
					SCAN,
					OTHER,
					DONE
				};

				Location() : _type(INITIAL), _pos(0), _next_pos(0), _dirty(true)
				{

				}

				Location(Location const& other) : _type(other._type), _pos(other._pos), _next_pos(other._next_pos), _dirty(other._dirty), _word(other._word)
				{

				}

				Location& operator=(Location const& rhs)
				{
					_type = rhs._type;
					_pos = rhs._pos;
					_next_pos = rhs._next_pos;
					_dirty = rhs._dirty;
					_word = rhs._word;
					return *this;
				}

				Type _type;
				size_t _pos;
				size_t _next_pos;
				bool _dirty;
				string _word;
			};

			const char *_src;
			size_t _src_size;
			vector<string> _tokens;
			vector<string> _separators;
			Location _loc;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_TOKENIZER_H */
