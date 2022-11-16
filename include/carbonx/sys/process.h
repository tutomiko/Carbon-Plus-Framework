/*
 * FileName: process.h
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
#include <carbonx/io/iobase.h>
#include <carbonx/filesystem/paths.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace sys {
		namespace current_process {
			CBXIMPORT
			void exit(int exitcode) noexcept;


			CBXIMPORT
			filesystem::path _CARBONPLUS_EXPERIMENTAL_API get_current_directory(void) throw (io::IOException);


			CBXIMPORT
			filesystem::path _CARBONPLUS_EXPERIMENTAL_API get_directory(void) throw (io::IOException);


			CBXIMPORT
			filesystem::path _CARBONPLUS_EXPERIMENTAL_API get_executable(void) throw (io::IOException);


			CBXIMPORT
			unsigned long get_id(void) noexcept;


			CBXIMPORT
			bool _CARBONPLUS_EXPERIMENTAL_API is_elevated(void);


			_inline bool is_64bit(void) noexcept {
#			if defined(_WIN64)
				return true;
#			elif defined(_WIN32)
				return false;
#			endif
			}


			CBXIMPORT
			filesystem::path _CARBONPLUS_EXPERIMENTAL_API resolve_path(type::cstring8_t s_path) throw (io::IOException);


			CBXIMPORT
			filesystem::path _CARBONPLUS_EXPERIMENTAL_API resolve_path(filesystem::path& s_path) throw (io::IOException);


			CBXIMPORT
			filesystem::path _CARBONPLUS_EXPERIMENTAL_API resolve_path_abs(type::cstring8_t s_path) throw (io::IOException);


			CBXIMPORT
			filesystem::path _CARBONPLUS_EXPERIMENTAL_API resolve_path_abs(filesystem::path& s_path) throw (io::IOException);


			CBXIMPORT
			void _CARBONPLUS_EXPERIMENTAL_API set_current_directory(type::cstring8_t s_path) throw (io::IOException);


			CBXIMPORT
			void _CARBONPLUS_EXPERIMENTAL_API set_current_directory(filesystem::path& s_path) throw (io::IOException);
		}


		class process {
		private:
			void* native_handle;
		public:
			process(void) noexcept {
				this->native_handle = nullptr;
			}

			process(void* native_handle) noexcept {
				this->native_handle = native_handle;
			}

			~process(void) {

			}


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void close(void) throw (io::IOException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			unsigned long get_id(void) throw (io::IOException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			bool is64bit(void) throw (io::IOException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void kill(void) throw (io::IOException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			filesystem::path resolve_path_abs(type::cstring8_t s_path);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			filesystem::path resolve_path_abs(filesystem::path& s_path);
		};


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		process create_process(type::cstring8_t s_application_name) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		process create_process(type::cstring8_t s_application_name, std::vector<type::string> a_parameters) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		process create_process_detached(type::cstring8_t s_application_name) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		process create_process_detached(type::cstring8_t s_application_name, std::vector<type::string> a_parameters) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		process create_process_silent(type::cstring8_t s_application_name) throw (io::IOException);


		CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		process create_process_silent(type::cstring8_t s_application_name, std::vector<type::string> a_parameters) throw (io::IOException);


		//CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
		//process open_process(unsigned long process_id, unsigned long long requested_access);
	}
}


