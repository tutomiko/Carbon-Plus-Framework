/*
 * FileName: path.h
 *
 * Written by Tuomas Kontiainen <https://www.github.com/tutomiko>
 *
 * Copyright (c) 2022, Tuomas Kontiainen
 *
 * This file is a part of Carbon Plus Framework <https://github.com/tutomiko/Carbon-Plus-Framework>
 * Carbon Plus Framework is a free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later versions.
 *
 * Carbon Plus Framework is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Carbon Plus Framework. If not, see <http://www.gnu.org/licenses/>.
 */
#
#pragma once
#
#pragma region <imports>
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <vector>
#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbonx/cbevobase.h>
#include <carbonx/type/string.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace sys {
		class path {
		public:
			class name_iterator {
			private:
				int   last_delimiter = 0;
				path* target;
				int   cursor = 0;
			public:
				name_iterator(path* target) {
					this->target = target;
				}


				void first(void);


				bool has_next(void);


				path next(void);
			};


			class subpath_iterator {
			private:
				int   last_delimiter = 0;
				path* target;
				int   cursor = 0;
			public:
				subpath_iterator(path* target) {
					this->target = target;
				}


				void first(void);


				bool has_next(void);


				path next(void);
			};
		private:
			type::string string;
		public:
			path& operator+= (char chr) {
				this->string.append(chr);

				return *this;
			}

			path& operator+= (type::cstring8_t string) {
				this->string.append(string);

				return *this;
			}

			operator type::cstring8_t (void) {
				return this->c_str();
			}

			operator type::string (void) {
				return type::string(this->c_str());
			}
		public:
			path(void) {

			}

			path(type::cstring8_t cstring) : string(std::move(cstring)) {

			}

			path(type::string& string) : string(std::move(string)) {

			}

			~path(void) {

			}


			path& addextension(type::cstring8_t s_extension);


			path& append(type::cstring8_t s_cpath);


			path& append(type::string& s_path);


			type::cstring8_t c_str(void) noexcept;


			path& clear(void);


			int countextensions(void) noexcept;


			path drive(void);


			char driveletter(void) noexcept;


			template <typename name_enumerator_prermissive>
			void enum_names(name_enumerator_prermissive f_enumerator) {
				auto it = path::name_iterator(this);

				while (it.has_next()) {
					bool b_enum;
					path s_file_name;

					s_file_name = it.next();

					b_enum = f_enumerator(s_file_name);

					if (!b_enum) break;
				}
			}


			template <typename name_enumerator_prermissive>
			void enum_subpaths(name_enumerator_prermissive f_enumerator) {
				auto it = path::subpath_iterator(this);

				while (it.has_next()) {
					bool b_enum;
					path s_file_path;

					s_file_path = it.next();

					b_enum = f_enumerator(s_file_path);

					if (!b_enum) break;
				}
			}


			bool equals(path other);


			bool equals_absolute(type::cstring8_t other);


			bool equals_absolute(path& other);


			type::string extension(void);


			type::string extension(int index);


			std::vector<type::string> extensions(void);


			path filename(void);


			type::cstring8_t getextension(void) noexcept;


			type::cstring8_t getextension(int index) noexcept;


			type::cstring8_t getfname(void) noexcept;


			bool hasdrive(void) noexcept;


			bool hasextension(void) noexcept;


			bool hasparent(void) noexcept;


			bool hasstem(void);


			bool isabsolute(void) noexcept;


			bool isancestorof(path& other);


			bool isdescendantof(path& other);


			bool isdirectory(void) noexcept;


			bool isempty(void) noexcept;


			bool isfile(void) noexcept;


			bool isindirect(void);


			bool isparentof(path& other);


			bool isrelative(void) noexcept;


			int length(void) noexcept;


			std::vector<path> names(void);


			path& normalize(void);


			path parent(void);


			path& resolve(void);


			path resolve(type::cstring8_t s_from_path);


			path resolve(path& s_from_path);


			path& rmvdrive(void);


			path& rmvextension(void);


			path& rmvextension(int index);


			path& setdrive(char c_drive);


			path& setdrive(type::cstring8_t s_drive);


			path& setextension(type::cstring8_t s_extension);


			path& setextension(int index, type::cstring8_t s_extension);


			path& setfname(type::cstring8_t s_fname);


			path& setparent(type::cstring8_t s_parent);


			path stem(void);


			type::string& str(void) noexcept;


			std::vector<path> subpaths(void);


			path& todirectory(void);


			path& tofile(void);


			path& toparent(void);
		};
	}
}

