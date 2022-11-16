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
#include <carbonx/net/inet-utils.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#include <WinSock2.h>
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
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
uint64_t carbon::net::htonetd(type::double_t hostnum) {
	return ::htond(hostnum);
}


CBXEXPORT
uint32_t carbon::net::htonetl(type::ulong_t hostnum) {
	return ::htonl(hostnum);
}


CBXEXPORT
uint64_t carbon::net::htonetll(type::ulonglong_t hostnum) {
	return ::htonll(hostnum);
}


CBXEXPORT
uint16_t carbon::net::htonets(type::ushort_t hostnum) {
	return ::htons(hostnum);
}


CBXEXPORT
carbon::type::double_t carbon::net::nettohd(uint32_t netnum) {
	return ::ntohd(netnum);
}


CBXEXPORT
carbon::type::ulong_t carbon::net::nettohl(uint32_t netnum) {
	return ::ntohl(netnum);
}


CBXEXPORT
carbon::type::ulonglong_t carbon::net::nettohll(uint64_t netnum) {
	return ::ntohll(netnum);
}


CBXEXPORT
carbon::type::ushort_t carbon::net::nettohs(uint16_t netnum) {
	return ::ntohs(netnum);
}

