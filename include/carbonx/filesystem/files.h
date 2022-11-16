/*
 * FileName: files.h
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
#include <carbonx/type/string.h>
#include <carbonx/filesystem/path.h>
#include <carbonx/filesystem/file.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace filesystem {
		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void delete_file(type::cstring8_t s_file_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void delete_file(path& s_file_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void destroy_file(type::cstring8_t s_file_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void destroy_file(path& s_file_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		unsigned int get_file_size(type::cstring8_t s_file_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		unsigned long long get_file_size_big(type::cstring8_t s_file_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void zero_file(type::cstring8_t s_file_path) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		void zero_file(path& s_file_path) throw (io::IOException);
	}
}


