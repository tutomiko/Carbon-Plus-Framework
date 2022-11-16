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
#include <carbonx/cbxbase.h>
#include <carbonx/type/string.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace filesystem {
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


				CBXIMPORT
				void first(void);


				CBXIMPORT
				bool has_next(void);


				CBXIMPORT
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


				CBXIMPORT
				void first(void);


				CBXIMPORT
				bool has_next(void);


				CBXIMPORT
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


			CBXIMPORT
			path& addextension(type::cstring8_t s_extension);


			CBXIMPORT
			path& append(type::cstring8_t s_cpath);


			CBXIMPORT
			path& append(type::string& s_path);


			CBXIMPORT
			type::cstring8_t c_str(void) noexcept;


			CBXIMPORT
			path& clear(void);


			CBXIMPORT
			int countextensions(void) noexcept;


			CBXIMPORT
			path drive(void);


			CBXIMPORT
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


			CBXIMPORT
			bool equals(type::cstring8_t other);


			CBXIMPORT
			bool equals(path& other);


			CBXIMPORT
			type::string extension(void);


			CBXIMPORT
			type::string extension(int index);


			CBXIMPORT
			std::vector<type::string> extensions(void);


			CBXIMPORT
			path filename(void);


			CBXIMPORT
			type::cstring8_t getextension(void) noexcept;


			CBXIMPORT
			type::cstring8_t getextension(int index) noexcept;


			CBXIMPORT
			type::cstring8_t getfname(void) noexcept;


			CBXIMPORT
			bool hasdrive(void) noexcept;


			CBXIMPORT
			bool hasextension(void) noexcept;


			CBXIMPORT
			bool hasparent(void) noexcept;


			//CBXIMPORT
			//bool hasstem(void);


			CBXIMPORT
			bool isabsolute(void) noexcept;


			CBXIMPORT
			bool isancestorof(path& other);


			CBXIMPORT
			bool isdescendantof(path& other);


			CBXIMPORT
			bool isdirectory(void) noexcept;


			CBXIMPORT
			bool isempty(void) noexcept;


			CBXIMPORT
			bool isfile(void) noexcept;


			CBXIMPORT
			bool isindirect(void);


			CBXIMPORT
			bool isparentof(path& other);


			CBXIMPORT
			bool isrelative(void) noexcept;


			CBXIMPORT
			int length(void) noexcept;


			CBXIMPORT
			std::vector<path> names(void);


			CBXIMPORT
			path& normalize(void);


			CBXIMPORT
			path parent(void);


			CBXIMPORT
			path& resolve(void);


			CBXIMPORT
			path resolve(type::cstring8_t s_from_path);


			CBXIMPORT
			path resolve(path& s_from_path);


			CBXIMPORT
			path& rmvdrive(void);


			CBXIMPORT
			path& rmvextension(void);


			CBXIMPORT
			path& rmvextension(int index);


			CBXIMPORT
			path& setdrive(char c_drive);


			CBXIMPORT
			path& setdrive(type::cstring8_t s_drive);


			CBXIMPORT
			path& setextension(type::cstring8_t s_extension);


			CBXIMPORT
			path& setextension(int index, type::cstring8_t s_extension);


			CBXIMPORT
			path& setfname(type::cstring8_t s_fname);


			CBXIMPORT
			path& setparent(type::cstring8_t s_parent);


			CBXIMPORT
			path stem(void);


			CBXIMPORT
			type::string& str(void) noexcept;


			CBXIMPORT
			std::vector<path> subpaths(void);


			CBXIMPORT
			path& todirectory(void);


			CBXIMPORT
			path& tofile(void);


			CBXIMPORT
			path& toparent(void);
		};
	}
}

