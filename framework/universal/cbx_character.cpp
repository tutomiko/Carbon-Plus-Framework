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
#include <carbonx/type/char.h>
#pragma endregion
#
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <iostream>
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
bool carbon::type::character::isalphabet(char c) {
	return (character::islower(c) || character::isupper(c));
}


bool carbon::type::character::isalphanumeric(char chr) {
	return (character::isalphabet(chr) || character::isnumber(chr));
}


bool carbon::type::character::islower(char chr) {
	return (chr >= 'a' && chr <= 'z');
}


bool carbon::type::character::isnumber(char chr) {
	return (chr >= '0' && chr <= '9');
}


bool carbon::type::character::isupper(char chr) {
	return (chr >= 'A' && chr <= 'Z');
}


bool carbon::type::character::iswhitespace(char c) {
	return (c == ' ' || c == '\t');
}


char carbon::type::character::tolower(char c) {
	return ::tolower(c);
}


char carbon::type::character::toupper(char c) {
	return ::toupper(c);
}

