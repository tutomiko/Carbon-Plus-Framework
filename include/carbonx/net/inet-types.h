#
#pragma once
#
#pragma region <imports>
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <cinttypes>
#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbonx/type/primitives.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <string max definitions>
#define _MAX_INET					22
#define _MAX_INET6					65
#define _MAX_MAC					-1
#define _MAX_MAC64					-1
#define _MAX_PORT					5
#define _MAX_URL					260
#pragma endregion


#pragma region <portnum constraint constant definitions>
#define PORT_MAX					65535
#define PORT_MIN					1
#pragma endregion


namespace carbon {
	namespace net {
		typedef type::ushort_t port_t;


		enum address_type : int {
			ADDRESS_TYPE_INET = 1,
			ADDRESS_TYPE_INET6 = 2,
			ADDRESS_TYPE_URL = 3,
		};


		typedef struct inet_address {
			union {
				struct {
					type::byte_t s_b1;
					type::byte_t s_b2;
					type::byte_t s_b3;
					type::byte_t s_b4;
				} S_un_b;

				struct {
					type::ushort_t s_w1;
					type::ushort_t s_w2;
				} S_un_w;

				type::uint_t S_addr;
			} S_un;
		};


		typedef struct inet6_address {
			union {
				type::byte_t Byte[16];
				type::ushort_t Word[8];
			} u;
		};


		typedef uint8_t urlstring[_MAX_URL + 1];


		typedef struct url {
			type::byte_t length;
			uint8_t name[_MAX_URL];
		};


		typedef struct inet_address_storage {
			type::byte_t type;

			union {
				inet_address  inet;
				inet6_address inet6;
				url           url;
			};
		};


		typedef struct inet_endpoint {
			inet_address_storage address;

			port_t port;
		};


		typedef struct mac_address {
			type::byte_t b1;
			type::byte_t b2;
			type::byte_t b3;
			type::byte_t b4;
			type::byte_t b5;
			type::byte_t b6;
			type::byte_t b7;
			type::byte_t b8;
		};
	}
}

