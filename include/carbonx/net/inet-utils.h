/*
 * FileName: inet-utils.h
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
#include <carbonx/type/string.h>
#include <carbonx/util/memory.h>
#include <carbonx/net/inet-types.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <known address constant definitions>
#define LOCALHOST_LOOPBACK			"127.0.0.1"
#pragma endregion


#pragma region <known port constant definitions>
#define PORT_ADB_CLIENT_TCP_MAX		5585
#define PORT_ADB_CLIENT_TCP_MIN		5555
#define PORT_ADB_SERVER_TCP			5037
#define PORT_AUTO					0
#define PORT_DEFAULT_WEBHOST		80
#define PORT_DEFAULT_WEBHOST2		8080
#define PORT_SECURE_STANDARD_PORT	443
#define PORT_SMB_NETBIOS			139
#define PORT_SMB_TCP				445
#define PORT_TELNET					23
#pragma endregion


namespace carbon {
	namespace net {
		class InvalidAddressException : public Exception {
		public:
			InvalidAddressException(void) : Exception() {

			}

			InvalidAddressException(std::string message) : Exception(message) {

			}
		};


		CBXIMPORT
		uint64_t htonetd(type::double_t hostnum);


		CBXIMPORT
		uint32_t htonetl(type::ulong_t hostnum);


		CBXIMPORT
		uint64_t htonetll(type::ulonglong_t hostnum);


		CBXIMPORT
		uint16_t htonets(type::ushort_t hostnum);


		CBXIMPORT
		type::double_t nettohd(uint32_t netnum);


		CBXIMPORT
		type::ulong_t nettohl(uint32_t netnum);


		CBXIMPORT
		type::ulonglong_t nettohll(uint64_t netnum);


		CBXIMPORT
		type::ushort_t nettohs(uint16_t netnum);


		CBXIMPORT
		inet_address_storage strtoaddr(type::string s_address);


		CBXIMPORT
		inet_endpoint strtohn(type::string s_hostname) throw (InvalidAddressException);


		CBXIMPORT
		inet_address strtoinet(type::string s_address);
	}
}


