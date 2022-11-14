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
#include <carbonx/sys/directories.h>
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
void carbon::sys::create_directories(type::cstring8_t s_path) throw (io::IOException) {

}


void carbon::sys::create_directories(path& s_path) throw (io::IOException) {

}


void carbon::sys::delete_directory(type::cstring8_t s_path) throw (io::IOException) {
	remove_directory_contents(s_path);

	remove_directory(s_path);
}


void carbon::sys::delete_directory(path& s_path) throw (io::IOException) {
	remove_directory_contents(s_path);

	remove_directory(s_path);
}


void carbon::sys::destroy_directory(type::cstring8_t s_path) throw (io::IOException) {
	destroy_directory_contents(s_path);

	remove_directory(s_path);
}


void carbon::sys::destroy_directory(path& s_path) throw (io::IOException) {
	destroy_directory_contents(s_path);

	remove_directory(s_path);
}


void carbon::sys::destroy_directory_contents(type::cstring8_t s_directory_cpath) throw (io::IOException) {
	path s_directory_path;

	s_directory_path = s_directory_cpath;

	return destroy_directory_contents(s_directory_path);
}


void carbon::sys::destroy_directory_contents(path& s_directory_path) throw (io::IOException) {
	enum_directory_contents(s_directory_path, [](path& s_directory_path, path& s_file_name) {
		path s_file_path;

		s_file_path.append(s_directory_path);
		s_file_path.append(s_file_name);

		if (s_file_path.isdirectory())
			destroy_directory(s_file_path);
		else {
			destroy_file(s_file_path);
		}

		return true;
	});
}


void carbon::sys::enum_directory_contents(type::cstring8_t s_directory_cpath, directory_contents_enumerator f_enumerator) throw (io::IOException) {
	path s_directory_path;

	s_directory_path = s_directory_cpath;

	return enum_directory_contents(s_directory_path, f_enumerator);
}


std::vector<carbon::sys::path> carbon::sys::get_directory_contents(type::cstring8_t s_directory_path_cs) throw (io::IOException) {
	path s_directory_path;

	s_directory_path = s_directory_path_cs;

	return get_directory_contents(s_directory_path);
}


void carbon::sys::remove_directory_contents(type::cstring8_t s_directory_cpath) throw (io::IOException) {
	path s_directory_path;

	s_directory_path = s_directory_cpath;

	return remove_directory_contents(s_directory_path);
}


void carbon::sys::remove_directory_contents(path& s_directory_path) throw (io::IOException) {
	enum_directory_contents(s_directory_path, [](path& s_directory_path, path& s_file_name) {
		path s_file_path;

		s_file_path.append(s_directory_path);
		s_file_path.append(s_file_name);

		if (s_file_path.isdirectory()) 
			delete_directory(s_file_path);
		else {
			delete_file(s_file_path);
		}

		return true;
	});
}

