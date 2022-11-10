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
		typedef class socket_channel : public socket_base {
		public:
			socket_channel(void) : socket_base() {

			}

			socket_channel(void* native_handle) : socket_base(native_handle) {

			}

			~socket_channel(void) {

			}
		};
	}
}


