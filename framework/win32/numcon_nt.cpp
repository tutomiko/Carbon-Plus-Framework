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
uint64_t carbon::net::htonetd(type::double_t hostnum) {
	return ::htond(hostnum);
}


uint32_t carbon::net::htonetl(type::ulong_t hostnum) {
	return ::htonl(hostnum);
}


uint64_t carbon::net::htonetll(type::ulonglong_t hostnum) {
	return ::htonll(hostnum);
}


uint16_t carbon::net::htonets(type::ushort_t hostnum) {
	return ::htons(hostnum);
}


carbon::type::double_t carbon::net::nettohd(uint32_t netnum) {
	return ::ntohd(netnum);
}


carbon::type::ulong_t carbon::net::nettohl(uint32_t netnum) {
	return ::ntohl(netnum);
}


carbon::type::ulonglong_t carbon::net::nettohll(uint64_t netnum) {
	return ::ntohll(netnum);
}


carbon::type::ushort_t carbon::net::nettohs(uint16_t netnum) {
	return ::ntohs(netnum);
}

