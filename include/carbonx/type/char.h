/*
 * FileName: char.h
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

#pragma endregion
#
#pragma region "local imports"
#include <carbonx/util/charset.h>
#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace type {
		namespace character {
			CBXIMPORT
			bool isalphabet(char c);


			CBXIMPORT
			bool isalphanumeric(char c);


			CBXIMPORT
			bool islower(char c);


			CBXIMPORT
			bool isnumber(char c);


			CBXIMPORT
			bool isupper(char c);


			CBXIMPORT
			bool iswhitespace(char c);


			CBXIMPORT
			char tolower(char c);


			CBXIMPORT
			char toupper(char c);
		}
	}
}


