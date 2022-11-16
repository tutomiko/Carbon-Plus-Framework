/*
 * FileName: socket.h
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
#include <vector>
#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbonx/cbxbase.h>
#include <carbonx/io/iobase.h>
#include <carbonx/type/primitives.h>
#include <carbonx/type/string.h>
#include <carbonx/net/inet.h>
#include <carbonx/net/socketbase.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace net {
		class socket : public socket_base {
		public:
			socket(void) : socket_base() {

			}

			socket(void* native_handle) : socket_base(native_handle) {

			}

			~socket(void) {

			}


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
			socket accept(void) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void bind(port_t port) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void bind(socket_address_in& o_name) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API
			void close(void) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void connect(port_t port) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void connect(socket_address_in& o_name) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void connect(type::string s_hostname) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			port_t get_remote_port(void) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void listen(int const backlog) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			uint8_t receive(void) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			std::vector<uint8_t> receive(unsigned int num_bytes) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			int receive(uint8_t* buffer, unsigned int buffer_size) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			std::vector<uint8_t>& receive(std::vector<uint8_t> buffer) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			std::vector<uint8_t> receive_all(unsigned int num_bytes) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			uint8_t* receive_all(uint8_t* buffer, unsigned int buffer_size) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			std::vector<uint8_t>& receive_all(std::vector<uint8_t> buffer) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void send(uint8_t const buffer) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			int send(uint8_t* const buffer, unsigned int buffer_size) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void send(type::cstring8_t const buffer) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			int send(std::vector<uint8_t>& const buffer) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void send_all(uint8_t* const buffer, unsigned int buffer_size) throw (SocketException);


			CBXIMPORT _CARBONPLUS_EXPERIMENTAL_API 
			void send_all(std::vector<uint8_t>& const buffer) throw (SocketException);
		};
	}
}