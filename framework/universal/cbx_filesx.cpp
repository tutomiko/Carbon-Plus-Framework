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
#include <carbonx/filesystem/files.h>
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
CBXEXPORT
void carbon::filesystem::delete_file(path& s_file_path) throw (io::IOException) {
	return delete_file(s_file_path.c_str());
}


CBXEXPORT
void carbon::filesystem::destroy_file(type::cstring8_t s_file_path) throw (io::IOException) {
	zero_file(s_file_path);

	delete_file(s_file_path);
}


CBXEXPORT
void carbon::filesystem::destroy_file(path& s_file_path) throw (io::IOException) {
	zero_file(s_file_path);

	delete_file(s_file_path);
}


CBXEXPORT
void carbon::filesystem::zero_file(path& s_file_path) throw (io::IOException) {
	return zero_file(s_file_path.c_str());
}

