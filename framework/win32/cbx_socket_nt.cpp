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
#include <carbonx/net/socket.h>
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
carbon::net::socket carbon::net::socket::accept(void) throw (SocketException) {
#pragma region <locals>
	SOCKET          h_socket = INVALID_SOCKET;
	int             n_name_size;
	struct sockaddr o_name;
#pragma endregion


	n_name_size = sizeof(o_name);

	h_socket = ::accept(reinterpret_cast<SOCKET>(this->native_handle), (sockaddr*)&o_name, &n_name_size);

	if (INVALID_SOCKET == h_socket) {
		switch (WSAGetLastError()) {
		default:
			throw SocketException();
		}
	}

	return carbon::net::socket(reinterpret_cast<void*>(h_socket));
}


void carbon::net::socket::bind(port_t port) throw (SocketException) {
	socket_address_in o_name;
	type::string      s_name;


	util::zero_memory(&o_name, sizeof o_name);

	o_name.sin_addr = strtoinet("127.0.0.1");
	o_name.sin_family = static_cast<type::ushort_t>(AF_INET);
	o_name.sin_port = htonets(port);

	return this->bind(o_name);
}


void carbon::net::socket::bind(socket_address_in& o_name) throw (SocketException) {
#pragma region <locals>
	SOCKET h_socket = INVALID_SOCKET;
	int    namelen;
	int    retval;
#pragma endregion


	h_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (INVALID_SOCKET == h_socket) {
		switch (WSAGetLastError()) {
		default:
			throw SocketException();
		}
	}

	namelen = sizeof(o_name);

	retval = ::bind(h_socket, reinterpret_cast<const sockaddr*>(&o_name), namelen);

	if (SOCKET_ERROR == retval) {
		::closesocket(h_socket);

		switch (WSAGetLastError()) {
		default:
			throw SocketException();
		}
	}

	this->native_handle = reinterpret_cast<void*>(h_socket);
}


void carbon::net::socket::close(void) throw (SocketException) {
#pragma region <locals>
	int retval;
#pragma endregion
	

	retval = ::closesocket(reinterpret_cast<SOCKET>(this->native_handle));

	if (SOCKET_ERROR == retval) {
		switch (WSAGetLastError()) {
		default:
			throw SocketException();
		}
	}

	this->native_handle = nullptr;
}


void carbon::net::socket::connect(socket_address_in& o_name) throw (SocketException) {
#pragma region <locals>
	SOCKET h_socket = INVALID_SOCKET;
	int    namelen;
	int    retval;
#pragma endregion

	h_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (INVALID_SOCKET == h_socket) {
		switch (WSAGetLastError()) {
		default:
			throw SocketException();
		}
	}

	namelen = sizeof(o_name);

	retval = ::connect(h_socket, reinterpret_cast<struct sockaddr*>(&o_name), namelen);

	if (SOCKET_ERROR == retval) {
		::closesocket(h_socket);

		switch (WSAGetLastError()) {
		default:
			throw SocketException();
		}
	}

	this->native_handle = reinterpret_cast<void*>(h_socket);
}


carbon::net::port_t carbon::net::socket::get_remote_port(void) throw (SocketException) {
	int                n_name_len;
	struct sockaddr_in o_name;

	n_name_len = sizeof(o_name);

	if (getsockname(reinterpret_cast<SOCKET>(this->native_handle), (struct sockaddr*)&o_name, &n_name_len) != 0) {
		switch (WSAGetLastError()) {
		default:
			throw SocketException();
		}
	}

	return ntohs(o_name.sin_port);
}


void carbon::net::socket::listen(int const backlog) throw (SocketException) {
#pragma region <locals>
	int retval;
#pragma endregion

	retval = ::listen(reinterpret_cast<SOCKET>(this->native_handle), backlog);

	if (SOCKET_ERROR == retval) {
		switch (WSAGetLastError()) {
		default:
			throw SocketException();
		}
	}
}


uint8_t carbon::net::socket::receive(void) throw (SocketException) {
	uint8_t buffer;
	int     bytes_read;

	bytes_read = ::recv(reinterpret_cast<SOCKET>(this->native_handle), reinterpret_cast<char*>(&buffer), sizeof(buffer), 0);

	if (bytes_read == 0) {
		throw ConnectionResetException();
	}

	if (SOCKET_ERROR == bytes_read) {
		switch (WSAGetLastError()) {
		case WSAECONNRESET:
			throw ConnectionResetException();
		default:
			throw SocketException();
		}
	}

	return buffer;
}


int carbon::net::socket::receive(uint8_t* buffer, unsigned int buffer_size) throw (SocketException) {
	int bytes_read;

	bytes_read = ::recv(reinterpret_cast<SOCKET>(this->native_handle), reinterpret_cast<char*>(buffer), buffer_size, 0);

	if (bytes_read == 0) {
		throw ConnectionResetException();
	}

	if (SOCKET_ERROR == bytes_read) {
		switch (WSAGetLastError()) {
		case WSAECONNRESET:
			throw ConnectionResetException();
		default:
			throw SocketException();
		}
	}

	return bytes_read;
}


void carbon::net::socket::send(uint8_t const buffer) throw (SocketException) {
	int bytes_sent;

	bytes_sent = ::send(reinterpret_cast<SOCKET>(this->native_handle), reinterpret_cast<const char*>(&buffer), sizeof(buffer), 0);

	if (bytes_sent == 0) {
		throw ConnectionResetException();
	}

	if (SOCKET_ERROR == bytes_sent) {
		switch (WSAGetLastError()) {
		case WSAECONNRESET:
			throw ConnectionResetException();
		default:
			throw SocketException();
		}
	}
}


int carbon::net::socket::send(uint8_t* const buffer, unsigned int buffer_size) throw (SocketException) {
	int bytes_sent;

	bytes_sent = ::send(reinterpret_cast<SOCKET>(this->native_handle), reinterpret_cast<const char*>(buffer), buffer_size, 0);

	if (bytes_sent == 0) {
		throw ConnectionResetException();
	}

	if (SOCKET_ERROR == bytes_sent) {
		switch (WSAGetLastError()) {
		case WSAECONNRESET:
			throw ConnectionResetException();
		default:
			throw SocketException();
		}
	}

	return bytes_sent;
}

