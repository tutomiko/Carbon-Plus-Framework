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

#pragma endregion
#
#pragma region "local imports"
#include "./socket.h"
#include "./socket-channel.h"
#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace net {
		void cleanup_sockets(void);


		void init_sockets(void) throw (SocketInitializeException);
	}
}


