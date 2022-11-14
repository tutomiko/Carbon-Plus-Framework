/*
 * FileName: socketbase.h
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
#include <carbonx/cbevobase.h>
#include <carbonx/type/primitives.h>
#include <carbonx/type/string.h>
#include <carbonx/io/iobase.h>
#include <carbonx/net/inet.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace net {
		class SocketException : public io::IOException {
		public:
			SocketException(void) : io::IOException() {

			}

			SocketException(std::string message) : io::IOException(message) {

			}
		};


		class ConnectionResetException : public SocketException {
		public:
			ConnectionResetException(void) : SocketException() {

			}

			ConnectionResetException(std::string message) : SocketException(message) {

			}
		};


		class SocketInitializeException : public SocketException {
		public:
			SocketInitializeException(void) : SocketException() {

			}

			SocketInitializeException(std::string message) : SocketException(message) {

			}
		};


		class SocketTimeoutException : public SocketException {
		public:
			SocketTimeoutException(void) : SocketException() {

			}

			SocketTimeoutException(std::string message) : SocketException(message) {

			}
		};


		typedef struct socket_address {
			type::ushort_t sa_family;
			type::byte_t   sa_data[14];
		};


		typedef struct socket_address_in {
			type::ushort_t sin_family;
			type::ushort_t sin_port;
			inet_address   sin_addr;
			type::byte_t   sin_zero[8];
		};


		typedef class socket_base {
		protected:
			void* native_handle;
		public:
			socket_base(void) {
				this->native_handle = nullptr;
			}

			socket_base(void* native_handle) {
				this->native_handle = native_handle;
			}

			~socket_base(void) {

			}


			void reset(void) noexcept {
				this->native_handle = nullptr;
			}
		};
	}
}