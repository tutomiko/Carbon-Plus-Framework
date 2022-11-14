/*
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
#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/sys/process.h>
#pragma endregion
#
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

#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
carbon::sys::path carbon::sys::current_process::get_directory(void) throw (io::IOException) {
	path s_path;

	s_path = current_process::get_executable();
	s_path.toparent();

	return s_path;
}


carbon::sys::path carbon::sys::current_process::resolve_path(type::cstring8_t cs_path) throw (io::IOException) {
	path s_path;

	s_path = cs_path;

	return current_process::resolve_path(s_path);
}


carbon::sys::path carbon::sys::current_process::resolve_path(path& s_path) throw (io::IOException) {
	path s_from_path;

	s_from_path = current_process::get_current_directory();

	return s_path.resolve(s_from_path);
}


carbon::sys::path carbon::sys::current_process::resolve_path_abs(type::cstring8_t cs_path) throw (io::IOException) {
	path s_path;

	s_path = cs_path;

	return current_process::resolve_path_abs(s_path);
}


carbon::sys::path carbon::sys::current_process::resolve_path_abs(path& s_path) throw (io::IOException) {
	path s_from_path;

	s_from_path = current_process::get_directory();

	return s_path.resolve(s_from_path);
}


void carbon::sys::current_process::set_current_directory(path& s_path) throw (io::IOException) {
	return set_current_directory(s_path.c_str());
}

