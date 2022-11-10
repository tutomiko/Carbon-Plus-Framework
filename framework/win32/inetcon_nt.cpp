#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/net/inet-utils.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#include <WinSock2.h>
#include <WS2tcpip.h>
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
carbon::net::inet_address_storage carbon::net::strtoaddr(type::string s_address) {
#pragma region <locals>
	struct addrinfo*     addrinfo = nullptr;
	struct addrinfo      hints;
	inet_address_storage o_address;
	int                  ret;
#pragma endregion


	util::memzero(&o_address, sizeof o_address);
	util::memzero(&hints, sizeof hints);

	hints.ai_flags = AI_NUMERICHOST;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	ret = getaddrinfo(s_address, nullptr, &hints, &addrinfo);

	if (ret == 0) { 
		// IPv4 address;
		o_address.type = ADDRESS_TYPE_INET;
		o_address.inet = *((inet_address*)&(((struct sockaddr_in*)addrinfo->ai_addr)->sin_addr));
	} else {
		hints.ai_family = AF_INET6;
		
		ret = getaddrinfo(s_address, nullptr, &hints, &addrinfo);

		if (ret == 0) { 
			// IPv6 address;
			o_address.type = ADDRESS_TYPE_INET6;
			o_address.inet6 = *((inet6_address*)&(((struct sockaddr_in6*)addrinfo->ai_addr)->sin6_addr));
		} else {
			// URL
			o_address.type = ADDRESS_TYPE_URL;
			o_address.url.length = s_address.length();
			memcpy(o_address.url.name, s_address, (s_address.length() * sizeof(uint8_t)));
		}
	}

	if (nullptr != addrinfo) {
		::freeaddrinfo(addrinfo);
	}


	return o_address;
}


carbon::net::inet_address carbon::net::strtoinet(type::string s_address) {
#pragma region <locals>
	inet_address o_address;
#pragma endregion


	inet_pton(AF_INET, s_address, &o_address);


	return o_address;
}

