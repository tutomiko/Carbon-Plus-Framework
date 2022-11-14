/*
 * FileName: string.h
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
#include <string>
#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbonx/cbevobase.h>
#include <carbonx/type/char.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace type {
		typedef const char* cstring8_t;


		typedef class string {
		private:
			std::string bytes;
		public:
			string& operator+= (char string) {
				this->append(string);

				return *this;
			}

			string& operator+= (cstring8_t string) {
				this->append(string);

				return *this;
			}

			operator cstring8_t (void) {
				return this->c_str();
			}

			operator std::string (void) {
				return std::string(this->c_str());
			}
		public:
			string(void) {

			}

			string(cstring8_t cstring) {
				this->bytes = cstring;
			}

			string(std::string cppstring) {
				this->bytes = cppstring;
			}

			~string(void) {

			}


			string& append(char chr);


			string& append(cstring8_t other);


			string& append(string& other) {
				return this->append(other.c_str());
			}


			string& assign(int i, char c) noexcept;


			cstring8_t c_str(void) noexcept {
				return this->bytes.c_str();
			}


			char charat(int i) noexcept;


			string& clear(void);


			int compare(cstring8_t other) noexcept;


			int compare(string& other) noexcept {
				return this->compare(other.c_str());
			}


			int compare_ic(cstring8_t other) noexcept;


			int compare_ic(string& other) noexcept {
				return this->compare_ic(other.c_str());
			}


			int comparex(cstring8_t other, int count) noexcept;


			int comparex(string& other, int count) noexcept {
				return this->comparex(other.c_str(), count);
			}


			int comparex_ic(cstring8_t other, int count) noexcept;


			int comparex_ic(string& other, int count) noexcept {
				return this->comparex_ic(other.c_str(), count);
			}


			bool contains(cstring8_t other) noexcept {
				return this->contains(other, strlen(other));
			}


			bool contains(string& other) noexcept {
				return this->compare(other.c_str());
			}


			bool contains(cstring8_t other, int other_length) noexcept;


			bool contains_ic(cstring8_t other) noexcept {
				return this->contains_ic(other, strlen(other));
			}


			bool contains_ic(string& other) noexcept {
				return this->compare_ic(other.c_str());
			}


			bool contains_ic(cstring8_t other, int other_length) noexcept;


			bool endswith(char prefix) noexcept;


			bool endswith(cstring8_t prefix) noexcept;


			bool endswith(string& prefix) noexcept {
				return this->endswith(prefix.c_str());
			}


			bool equals(cstring8_t other) noexcept;


			bool equals(string& other) noexcept {
				return this->equals(other.c_str());
			}


			bool equals_ic(cstring8_t other) noexcept;


			bool equals_ic(string& other) noexcept {
				return this->equals_ic(other.c_str());
			}


			string& fill(char c) {
				return this->fill(c, this->length());
			}


			string& fill(char c, int count) noexcept;


			bool isempty(void) noexcept;


			int length(void) noexcept;


			string& lower(void) noexcept;


			string& push(char c);


			string& push(cstring8_t other);


			string& push(string& other) {
				return this->push(other.c_str());
			}


			string& reduce_left(int count);


			string& reduce_mid(unsigned int from, unsigned int count);


			string& reduce_right(int count);


			string& replace(char c0, char c1);


			string& reverse(void) noexcept;


			bool startswith(char prefix) noexcept;


			bool startswith(cstring8_t prefix) noexcept;


			bool startswith(string& prefix) noexcept;


			string& strip(void);


			string& strip_leading(char c);


			string& strip_leading(void);


			string& strip_trailing(void);


			string& strip_trailing(char c);


			string substring(int begin, int end);


			string& upper(void) noexcept;


			string& zero(void) noexcept;
		};


		string to_string(bool value);


		string to_string(unsigned char value);


		string to_string(char value);


		string to_string(double value);


		string to_string(long double value);


		string to_string(float value);


		string to_string(int value);


		string to_string(unsigned int value);


		string to_string(long value);


		string to_string(unsigned long value);


		string to_string(unsigned long long value);


		string to_string(short value);


		string to_string(unsigned short value);
	}
}