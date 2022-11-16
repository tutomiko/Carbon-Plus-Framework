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
#include <carbonx/filesystem/path.h>
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
void carbon::filesystem::path::name_iterator::first(void) {
	this->cursor = this->last_delimiter = 0;
}


CBXEXPORT
bool carbon::filesystem::path::name_iterator::has_next(void) {
	for (;; this->cursor++) {
		char c;

		if (this->cursor < this->target->string.length()) {
			c = this->target->string.charat(this->cursor);
		}
		else if (this->cursor == this->target->string.length()) {
			cursor++;

			return true;
		}
		else {
			return false;
		}

		if (c == '\\' || c == '/') {
			do {
				cursor++;

				c = this->target->string.charat(this->cursor);
			} while (c == '\\' || c == '/');

			if (cursor == this->target->string.length()) {
				cursor++;
			}

			return true;
		}
	}

	return false;
}


CBXEXPORT
carbon::filesystem::path carbon::filesystem::path::name_iterator::next(void) {
	int  n_filename_length;
	path s_filename;

	n_filename_length = (cursor - last_delimiter);

	for (auto i = last_delimiter; i < cursor; i++) {
		char c;

		c = this->target->string.charat(i);

		if (c == '/')
			c = '\\';

		s_filename += c;

		if (c == '\\') {
			n_filename_length = i;

			break;
		}
	}

	last_delimiter = cursor;

	return s_filename;
}

