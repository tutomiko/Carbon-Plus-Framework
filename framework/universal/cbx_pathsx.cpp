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
#include <carbonx/filesystem/paths.h>
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
#include <carbonx/sys/process.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
CBXEXPORT
carbon::filesystem::path carbon::filesystem::absolute(type::cstring8_t s_path) {
	return sys::current_process::resolve_path(s_path);
}


CBXEXPORT
carbon::filesystem::path carbon::filesystem::absolute(path& s_path) {
	return sys::current_process::resolve_path(s_path);
}


CBXEXPORT
bool carbon::filesystem::equals(type::cstring8_t s_path0, type::cstring8_t s_path1) {
	return absolute(s_path0).equals(absolute(s_path1));
}


CBXEXPORT
bool carbon::filesystem::equals(path& s_path0, path& s_path1) {
	return absolute(s_path0).equals(absolute(s_path1));
}

