#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/net/sockets.h>
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
void carbon::net::cleanup_sockets(void) {
	WSACleanup();
}


void carbon::net::init_sockets(void) throw (SocketInitializeException) {
#pragma region <locals>
	WSADATA WSAData;
#pragma endregion

	if (0 != WSAStartup(MAKEWORD(2, 2), &WSAData)) {
		switch (GetLastError()) {
		default:
			throw SocketInitializeException();
		}
	}
}

