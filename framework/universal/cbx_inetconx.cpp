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
carbon::net::inet_endpoint carbon::net::strtohn(type::string s_hostname) throw (InvalidAddressException){
#pragma region <locals>
	inet_endpoint o_hostname;
	type::string  s_address;
	type::string  s_port;
#pragma endregion


	for (auto i = 0;; i++) {
		char c;

		if (i > (_MAX_PORT + 1)) {
			throw InvalidAddressException();
		}

		c = s_hostname.charat(s_hostname.length() - i);

		if (c == ':') {
			s_address = s_hostname.substring(0, (s_hostname.length() - i));
			s_port = s_hostname.substring(((s_hostname.length() - i) + 1), s_hostname.length());

			break;
		}
	}

	util::zero_memory(&o_hostname, sizeof o_hostname);
	o_hostname.address = strtoaddr(s_address);
	o_hostname.port = std::stoul(s_port);

	return o_hostname;
}

