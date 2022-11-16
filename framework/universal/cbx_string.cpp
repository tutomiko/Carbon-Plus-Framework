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
#include <carbonx/type/string.h>
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
CBXEXPORT
carbon::type::string& carbon::type::string::append(char chr) {
	char buffer[2];

	buffer[0] = chr;
	buffer[1] = '\0';

	return this->append(buffer);
}


CBXEXPORT
carbon::type::string& carbon::type::string::append(cstring8_t other) {
	this->bytes.append(other);

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::assign(int i, char c) noexcept {
	this->bytes[i] = c;

	return *this;
}


CBXEXPORT
char carbon::type::string::charat(int i) noexcept {
	return this->bytes[i];
}


CBXEXPORT
carbon::type::string& carbon::type::string::clear(void) {
	this->bytes.clear();

	return *this;
}


CBXEXPORT
int carbon::type::string::compare(cstring8_t other) noexcept {
	return this->bytes.compare(other);
}


CBXEXPORT
int carbon::type::string::compare_ic(cstring8_t other) noexcept {
	return _stricmp(this->c_str(), other);
}


CBXEXPORT
int carbon::type::string::comparex(cstring8_t other, int count) noexcept {
	return strncmp(this->c_str(), other, count);
}


CBXEXPORT
int carbon::type::string::comparex_ic(cstring8_t other, int count)noexcept {
	return _strnicmp(this->c_str(), other, count);
}


CBXEXPORT
bool carbon::type::string::contains(cstring8_t other, int other_length) noexcept {
#pragma region <locals>
	bool b_contains = false;
#pragma endregion

	for (auto i = 0; i < this->length(); i++) {
		char c;

		c = this->charat(i);

		if (c == '\0') 
			break;

		if (c != other[0]) 
			continue;

		if (strncmp(&(this->bytes[i]), other, other_length) == 0) {
			b_contains = true;

			break;
		}
	}

	return b_contains;
}


CBXEXPORT
bool carbon::type::string::contains_ic(cstring8_t other, int other_length) noexcept {
#pragma region <locals>
	bool b_contains = false;
#pragma endregion

	for (auto i = 0; i < this->length(); i++) {
		char c;

		c = this->charat(i);

		if (c == '\0')
			break;

		if (std::tolower(c) != std::tolower(other[0])) 
			continue;

		if (_strnicmp(&(this->bytes[i]), other, other_length) == 0) {
			b_contains = true;

			break;
		}
	}

	return b_contains;
}


CBXEXPORT
bool carbon::type::string::endswith(char suffix) noexcept {
	return (this->charat(this->length() - 1) == suffix);
}


CBXEXPORT
bool carbon::type::string::endswith(cstring8_t suffix) noexcept {
#pragma region <locals>
	bool b_equals;
	int  suffix_length;
#pragma endregion

	suffix_length = strlen(suffix);

	if (this->length() >= suffix_length)
		b_equals = (strncmp(&(this->bytes[this->length() - suffix_length]), suffix, suffix_length) == 0);
	else {
		b_equals = false;
	}

	return b_equals;
}


CBXEXPORT
bool carbon::type::string::equals(cstring8_t other) noexcept {
	return (this->compare(other) == 0);
}


CBXEXPORT
bool carbon::type::string::equals_ic(cstring8_t other) noexcept {
	return (this->compare_ic(other) == 0);
}


CBXEXPORT
carbon::type::string& carbon::type::string::fill(char c, int count) noexcept {
	for (auto i = 0; i < count; i++) {
		this->assign(i, c);
	}

	return *this;
}


CBXEXPORT
bool carbon::type::string::isempty(void) noexcept {
	return this->bytes.empty();
}


CBXEXPORT
int carbon::type::string::length(void) noexcept {
	return this->bytes.length();
}


CBXEXPORT
carbon::type::string& carbon::type::string::lower(void) noexcept {
	for (auto i = 0; i < this->length(); i++) {
		char c;

		c = this->charat(i);

		if (c == '\0')
			break;
		else {
			this->assign(i, std::tolower(c));
		}
	}

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::push(char c) {
#pragma region <locals>
	int this_length;
#pragma endregion

	this_length = this->length();

	this->bytes.resize(this_length + 1);

	for (auto i = this_length; i >= 0; i--) {
		char c;

		c = this->charat(i);

		this->assign((i + 1), c);
	}

	this->assign(0, c);

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::push(cstring8_t other) {
#pragma region <locals>
	int this_length;
	int other_length;
#pragma endregion

	this_length = this->length();
	other_length = strlen(other);

	this->bytes.resize(this_length + other_length);

	for (auto i = this_length; i >= 0; i--) {
		char c;

		c = this->charat(i);

		this->assign((i + other_length), c);
	}

	for (auto i = 0; i < other_length; i++) {
		char c;

		c = other[i];

		this->assign(i, c);
	}

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::reduce_left(int count) {
	for (auto i = 0; i < this->length(); i++) {
		char c;

		c = this->charat(i + count);

		this->assign(i, c);

		if (c == '\0') {
			this->reduce_right(count);

			break;
		}
	}

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::reduce_mid(unsigned int from, unsigned int count) {
	std::string new_bytes;

	new_bytes += this->bytes.substr(0, (from - count));
	new_bytes += this->bytes.substr(from, this->bytes.length());

	this->bytes = new_bytes;

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::reduce_right(int count) {
	for (auto i = 0; i < count; i++) {
		this->bytes.pop_back();
	}

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::replace(char c0, char c1) {
	for (auto i = 0; i < this->length(); i++) {
		char c;

		c = this->charat(i);

		if (c == c0) {
			this->assign(i, c1);
		}
	}

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::reverse(void) noexcept {
	this->bytes = _strrev((char*)this->bytes.c_str());

	return *this;
}


CBXEXPORT
bool carbon::type::string::startswith(char prefix) noexcept {
	return (this->charat(0) == prefix);
}


CBXEXPORT
bool carbon::type::string::startswith(cstring8_t prefix) noexcept {
	return (this->comparex(prefix, strlen(prefix)) == 0);
}


CBXEXPORT
bool carbon::type::string::startswith(string& prefix) noexcept {
	return (this->comparex(prefix.c_str(), prefix.length()) == 0);
}


CBXEXPORT
carbon::type::string& carbon::type::string::strip(void) {
	this->strip_leading();
	this->strip_trailing();

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::strip_leading(void) {
	for (auto i = 0; i < this->length(); i++) {
		char c;

		c = this->charat(i);

		if (!character::iswhitespace(c)) {
			if (i > 0) {
				this->reduce_left(i);
			}

			break;
		}
	}

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::strip_leading(char pc) {
	for (auto i = 0; i < this->length(); i++) {
		char c;

		c = this->charat(i);

		if (c != pc) {
			if (i > 0) {
				this->reduce_left(i);
			}

			break;
		}
	}

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::strip_trailing(void) {
	for (auto i = 0; i < this->length(); i++) {
		char c;

		c = this->charat((this->length() - 1) - i);

		if (!character::iswhitespace(c)) {
			if (i > 0) {
				this->reduce_right(i);
			}

			break;
		}
	}

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::strip_trailing(char pc) {
	for (auto i = 0; i < this->length(); i++) {
		char c;

		c = this->charat((this->length() - 1) - i);

		if (c != pc) {
			if (i > 0) {
				this->reduce_right(i);
			}

			break;
		}
	}

	return *this;
}


CBXEXPORT
carbon::type::string carbon::type::string::substring(int begin, int end) {
	return this->bytes.substr(begin, end);
}


CBXEXPORT
carbon::type::string& carbon::type::string::upper(void) noexcept {
	for (auto i = 0; i < this->length(); i++) {
		char c;

		c = this->charat(i);

		if (c == '\0') 
			break;
		else {
			this->assign(i, std::toupper(c));
		}
	}

	return *this;
}


CBXEXPORT
carbon::type::string& carbon::type::string::zero(void) noexcept {
	int count;

	count = this->bytes.length();

	for (auto i = 0; i < count; i++) {
		this->assign(i, '\0');
	}

	return *this;
}

