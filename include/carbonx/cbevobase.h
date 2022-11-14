/*
 * FileName: cbevobase.h
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
#include <exception>
#include <string>
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
#pragma region <core annotation definitions>
#ifndef _CARBONPLUS_ENABLE_DEPRECATED_FEATURES
#define _CARBONPLUS_DEPRECATED_API __declspec(deprecated("function is deprecated and will be REMOVED: You can define _CARBONPLUS_ENABLE_DEPRECATED_FEATURES to acknowledge that you understand this and still want to enable its usage."))
#else
#define _CARBONPLUS_DEPRECATED_API
#endif // !_CARBONPLUS_ENABLE_DEPRECATED_FEATURES

#ifndef _CARBONPLUS_ENABLE_EXPERIMENTAL_FEATURES
#define _CARBONPLUS_EXPERIMENTAL_API __declspec(deprecated("function is still in development and experimental: You can define _CARBONPLUS_ENABLE_EXPERIMENTAL_FEATURES to acknowledge that you understand this and still want to enable its usage."))
#else
#define _CARBONPLUS_EXPERIMENTAL_API
#endif // !_CARBONPLUS_ENABLE_EXPERIMENTAL_FEATURES
#pragma endregion


namespace carbon {
	class Exception : public std::exception {
	private:
		std::string message;
	public:
		Exception(void) {

		}

		Exception(std::string message) {
			this->message = message;
		}


		const char* what(void) const throw () {
			return this->message.c_str();
		}
	};


	class UnsupportedOperationException : public Exception {
	public:
		UnsupportedOperationException(void) : Exception() {

		}

		UnsupportedOperationException(std::string message) : Exception(message) {

		}
	};
}