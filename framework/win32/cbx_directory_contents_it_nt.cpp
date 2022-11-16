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
#include <carbonx/filesystem/directories.h>
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
CBXEXPORT
carbon::filesystem::directory_contents_iterator::directory_contents_iterator(type::cstring8_t s_directory_path) throw (io::IOException) {
#pragma region <locals>
	HANDLE            h_find = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATAA* o_find_data = nullptr;
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
	o_find_data = new WIN32_FIND_DATAA;

	h_find = FindFirstFileA(s_search_path, o_find_data);

	if (INVALID_HANDLE_VALUE == h_find) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	this->native_find_data = reinterpret_cast<void*>(o_find_data);
	this->native_handle = reinterpret_cast<void*>(h_find);
}


CBXEXPORT
carbon::filesystem::directory_contents_iterator::~directory_contents_iterator(void) {
#pragma region <locals>
	WIN32_FIND_DATAA* o_find_data;
#pragma endregion

	o_find_data = reinterpret_cast<WIN32_FIND_DATAA*>(this->native_find_data);

	delete o_find_data;
}


CBXEXPORT
void carbon::filesystem::directory_contents_iterator::close(void) throw (io::IOException) {
#pragma region <locals>
	HANDLE h_find;
#pragma endregion

	h_find = reinterpret_cast<HANDLE>(this->native_handle);

	if (!FindClose(h_find)) {
		throw io::IOException();
	}
}


CBXEXPORT
bool carbon::filesystem::directory_contents_iterator::has_next(void) {
#pragma region <locals>
	BOOL              b_find = FALSE;
	WIN32_FIND_DATAA* o_find_data;
#pragma endregion

	o_find_data = reinterpret_cast<LPWIN32_FIND_DATAA>(this->native_find_data);

next:
	if (this->popped) {
		b_find = FindNextFileA(reinterpret_cast<HANDLE>(this->native_handle), o_find_data);

		if (!b_find) {
			return false;
		}
	} else {
		this->popped = true;
	}

	if ((std::strcmp(o_find_data->cFileName, ".") == 0) || (std::strcmp(o_find_data->cFileName, "..") == 0)) {
		goto next;
	}

	return true;
}


CBXEXPORT
carbon::filesystem::path carbon::filesystem::directory_contents_iterator::next(void) {
#pragma region <locals>
	WIN32_FIND_DATAA* o_find_data;
	path              s_path;
#pragma endregion

	o_find_data = reinterpret_cast<WIN32_FIND_DATAA*>(this->native_find_data);

	s_path = o_find_data->cFileName;

	if (o_find_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
		s_path.todirectory();
	}

	return s_path;
}

