/*
 * FileName: directories.h
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

#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbonx/cbxbase.h>
#include <carbonx/io/iobase.h>
#include <carbonx/filesystem/path.h>
#include <carbonx/filesystem/paths.h>
#include <carbonx/filesystem/files.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace filesystem {
		typedef bool(*directory_contents_enumerator)(path& s_directory_path, path& s_file_name);


		class directory_contents_iterator {
		private:
			void* native_find_data;
			void* native_handle;
			bool  popped = false;
		public:
			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
			directory_contents_iterator(type::cstring8_t s_directory_path) throw (io::IOException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
			~directory_contents_iterator(void);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
			void close(void) throw (io::IOException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
			bool has_next(void);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
			path next(void);
		};


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void create_directory(type::cstring8_t s_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void create_directories(type::cstring8_t s_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void create_directories(path& s_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void delete_directory(type::cstring8_t s_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void delete_directory(path& s_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void destroy_directory(type::cstring8_t s_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void destroy_directory(path& s_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void destroy_directory_contents(type::cstring8_t s_directory_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void destroy_directory_contents(path& s_directory_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void enum_directory_contents(type::cstring8_t s_directory_path, directory_contents_enumerator f_enumerator) throw (io::IOException);


		template <typename directory_contents_enumerator_permissive>
		_inline void _CARBONPLUS_EXPERIMENTAL_API enum_directory_contents(path& s_directory_path, directory_contents_enumerator_permissive f_enumerator) throw (io::IOException) {
			auto it = directory_contents_iterator(s_directory_path);

			while (it.has_next()) {
				bool b_enum;
				path s_file_name;

				s_file_name = it.next();

				b_enum = f_enumerator(s_directory_path, s_file_name);

				if (!b_enum) break;
			}
		}


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void enum_directory_contents(path& s_directory_path, directory_contents_enumerator f_enumerator) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		std::vector<path> get_directory_contents(type::cstring8_t s_directory_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		std::vector<path> get_directory_contents(path& s_directory_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void remove_directory(type::cstring8_t s_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void remove_directory_contents(type::cstring8_t s_directory_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void remove_directory_contents(path& s_directory_path) throw (io::IOException);
	}
}


