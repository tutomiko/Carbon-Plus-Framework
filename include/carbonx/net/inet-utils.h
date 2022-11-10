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


		uint64_t htonetd(type::double_t hostnum);


		uint32_t htonetl(type::ulong_t hostnum);


		uint64_t htonetll(type::ulonglong_t hostnum);


		uint16_t htonets(type::ushort_t hostnum);


		type::double_t nettohd(uint32_t netnum);


		type::ulong_t nettohl(uint32_t netnum);


		type::ulonglong_t nettohll(uint64_t netnum);


		type::ushort_t nettohs(uint16_t netnum);


		inet_address_storage strtoaddr(type::string s_address);


		inet_endpoint strtohn(type::string s_hostname) throw (InvalidAddressException);


		inet_address strtoinet(type::string s_address);
	}
}


