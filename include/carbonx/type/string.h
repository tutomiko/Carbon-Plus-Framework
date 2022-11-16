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
#include <carbonx/cbxbase.h>
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


		class string {
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


			CBXIMPORT
			string& append(char chr);


			CBXIMPORT
			string& append(cstring8_t other);


			string& append(string& other) {
				return this->append(other.c_str());
			}


			CBXIMPORT
			string& assign(int i, char c) noexcept;


			cstring8_t c_str(void) noexcept {
				return this->bytes.c_str();
			}


			CBXIMPORT
			char charat(int i) noexcept;


			CBXIMPORT
			string& clear(void);


			CBXIMPORT
			int compare(cstring8_t other) noexcept;


			int compare(string& other) noexcept {
				return this->compare(other.c_str());
			}


			CBXIMPORT
			int compare_ic(cstring8_t other) noexcept;


			int compare_ic(string& other) noexcept {
				return this->compare_ic(other.c_str());
			}


			CBXIMPORT
			int comparex(cstring8_t other, int count) noexcept;


			int comparex(string& other, int count) noexcept {
				return this->comparex(other.c_str(), count);
			}


			CBXIMPORT
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


			CBXIMPORT
			bool contains(cstring8_t other, int other_length) noexcept;


			bool contains_ic(cstring8_t other) noexcept {
				return this->contains_ic(other, strlen(other));
			}


			bool contains_ic(string& other) noexcept {
				return this->compare_ic(other.c_str());
			}


			CBXIMPORT
			bool contains_ic(cstring8_t other, int other_length) noexcept;


			CBXIMPORT
			bool endswith(char prefix) noexcept;


			CBXIMPORT
			bool endswith(cstring8_t prefix) noexcept;


			bool endswith(string& prefix) noexcept {
				return this->endswith(prefix.c_str());
			}


			CBXIMPORT
			bool equals(cstring8_t other) noexcept;


			bool equals(string& other) noexcept {
				return this->equals(other.c_str());
			}


			CBXIMPORT
			bool equals_ic(cstring8_t other) noexcept;


			bool equals_ic(string& other) noexcept {
				return this->equals_ic(other.c_str());
			}


			string& fill(char c) {
				return this->fill(c, this->length());
			}


			CBXIMPORT
			string& fill(char c, int count) noexcept;


			CBXIMPORT
			bool isempty(void) noexcept;


			CBXIMPORT
			int length(void) noexcept;


			CBXIMPORT
			string& lower(void) noexcept;


			CBXIMPORT
			string& push(char c);


			CBXIMPORT
			string& push(cstring8_t other);


			string& push(string& other) {
				return this->push(other.c_str());
			}


			CBXIMPORT
			string& reduce_left(int count);


			CBXIMPORT
			string& reduce_mid(unsigned int from, unsigned int count);


			CBXIMPORT
			string& reduce_right(int count);


			CBXIMPORT
			string& replace(char c0, char c1);


			CBXIMPORT
			string& reverse(void) noexcept;


			CBXIMPORT
			bool startswith(char prefix) noexcept;


			CBXIMPORT
			bool startswith(cstring8_t prefix) noexcept;


			CBXIMPORT
			bool startswith(string& prefix) noexcept;


			CBXIMPORT
			string& strip(void);


			CBXIMPORT
			string& strip_leading(char c);


			CBXIMPORT
			string& strip_leading(void);


			CBXIMPORT
			string& strip_trailing(void);


			CBXIMPORT
			string& strip_trailing(char c);


			CBXIMPORT
			string substring(int begin, int end);


			CBXIMPORT
			string& upper(void) noexcept;


			CBXIMPORT
			string& zero(void) noexcept;
		};


		CBXIMPORT
		string to_string(bool value);


		CBXIMPORT
		string to_string(unsigned char value);


		CBXIMPORT
		string to_string(char value);


		CBXIMPORT
		string to_string(double value);


		CBXIMPORT
		string to_string(long double value);


		CBXIMPORT
		string to_string(float value);


		CBXIMPORT
		string to_string(int value);


		CBXIMPORT
		string to_string(unsigned int value);


		CBXIMPORT
		string to_string(long value);


		CBXIMPORT
		string to_string(unsigned long value);


		CBXIMPORT
		string to_string(unsigned long long value);


		CBXIMPORT
		string to_string(short value);


		CBXIMPORT
		string to_string(unsigned short value);
	}
}