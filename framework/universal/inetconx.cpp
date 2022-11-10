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

	util::memzero(&o_hostname, sizeof o_hostname);
	o_hostname.address = strtoaddr(s_address);
	o_hostname.port = std::stoul(s_port);

	return o_hostname;
}


