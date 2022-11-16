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
void carbon::sys::current_process::exit(int exitcode) noexcept {
	ExitProcess(exitcode);
}


CBXEXPORT
carbon::filesystem::path carbon::sys::current_process::get_current_directory(void) throw (io::IOException) {
	CHAR s_path[MAX_PATH + 1];

	ZeroMemory(s_path, sizeof s_path);

	if (0 == GetCurrentDirectoryA(MAX_PATH, s_path)) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	return s_path;
}


CBXEXPORT
carbon::filesystem::path carbon::sys::current_process::get_executable(void) throw (io::IOException) {
	CHAR cs_path[MAX_PATH + 1];

	ZeroMemory(cs_path, sizeof cs_path);

	if (GetModuleFileNameA(NULL, cs_path, MAX_PATH) <= 0) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	return cs_path;
}


CBXEXPORT
unsigned long carbon::sys::current_process::get_id(void) noexcept {
	return GetCurrentProcessId();
}


CBXEXPORT
void carbon::sys::current_process::set_current_directory(type::cstring8_t s_path) throw (io::IOException) {
	if (!SetCurrentDirectoryA(s_path)) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}
}

