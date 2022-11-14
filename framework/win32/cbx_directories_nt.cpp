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
#include <Windows.h>
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
void carbon::sys::create_directory(type::cstring8_t s_path) throw (io::IOException) {
	if (!CreateDirectoryA(s_path, NULL)) {
		switch (GetLastError()) {
		case ERROR_ACCESS_DENIED:
			throw "";
		case ERROR_ALREADY_EXISTS:
			throw "";
		case ERROR_PATH_NOT_FOUND:
			throw "";
		default:
			throw io::IOException();
		}
	}
}


void carbon::sys::enum_directory_contents(path& s_directory_path, directory_contents_enumerator f_enumerator) throw (io::IOException) {
#pragma region <locals>
	BOOL             b_find;
	HANDLE           h_find = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATAA o_find_data;
	path             s_search_path;
#pragma endregion

	/*
	 * Build search string;
	 * 
	 * The search string looks like "C:/Windows/System32/*"
	 */
	s_search_path.append(s_directory_path);
	s_search_path.todirectory();
	s_search_path += "*";

	/*
	 * Iterate over each file in directory;
	 */
	h_find = FindFirstFileA(s_search_path, &o_find_data);

	if (INVALID_HANDLE_VALUE == h_find) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	for (b_find = true; b_find; b_find = FindNextFileA(h_find, &o_find_data)) {
		bool b_enum;
		path s_file_name;

		s_file_name = o_find_data.cFileName;

		if (s_file_name.equals(".") || s_file_name.equals(".."))
			continue;

		if (o_find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			s_file_name.todirectory();
		}

		b_enum = f_enumerator(s_directory_path, s_file_name);

		if (!b_enum)
			break;

		if (!b_find) {
			switch (GetLastError()) {
			case ERROR_NO_MORE_FILES:
				break;
			default:
				FindClose(h_find);

				throw io::IOException();
			}
		}
	}

	// Close the find handle;
	FindClose(h_find);
}


std::vector<carbon::sys::path> carbon::sys::get_directory_contents(path& s_directory_path) throw (io::IOException) {
#pragma region <locals>
	std::vector<path> a_directory_contents;
	BOOL              b_find;
	HANDLE            h_find = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATAA  o_find_data;
	path              s_search_path;
#pragma endregion

	/*
	 * Build search string;
	 *
	 * The search string looks like "C:/Windows/System32/*"
	 */
	s_search_path.append(s_directory_path);
	s_search_path.todirectory();
	s_search_path += "*";

	/*
	 * Iterate over each file in directory;
	 */
	h_find = FindFirstFileA(s_search_path, &o_find_data);

	if (INVALID_HANDLE_VALUE == h_find) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	for (b_find = true; b_find; b_find = FindNextFileA(h_find, &o_find_data)) {
		path s_file_name;

		s_file_name = o_find_data.cFileName;

		if (s_file_name.equals(".") || s_file_name.equals(".."))
			continue;

		if (o_find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			s_file_name.todirectory();
		}

		a_directory_contents.push_back(s_file_name);

		if (!b_find) {
			switch (GetLastError()) {
			case ERROR_NO_MORE_FILES:
				break;
			default:
				FindClose(h_find);

				throw io::IOException();
			}
		}
	}

	// Close the find handle;
	FindClose(h_find);

	return a_directory_contents;
}


void carbon::sys::remove_directory(type::cstring8_t s_path) throw (io::IOException) {
	if (!RemoveDirectoryA(s_path)) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}
}

