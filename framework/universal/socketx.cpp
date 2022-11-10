#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/net/socket.h>
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
void carbon::net::socket::connect(port_t port) throw (SocketException) {
	socket_address_in o_name;

	util::memzero(&o_name, sizeof o_name);

	o_name.sin_addr = strtoinet("127.0.0.1");
	o_name.sin_port = htonets(port);

	return this->connect(o_name);
}


void carbon::net::socket::connect(type::string s_hostname) throw (SocketException) {
	inet_endpoint o_hostname;

	o_hostname = carbon::net::strtohn(s_hostname);

	switch (o_hostname.address.type) {
	case address_type::ADDRESS_TYPE_INET: {
		socket_address_in o_name;

		o_name.sin_addr = o_hostname.address.inet;
		o_name.sin_port = htonets(o_hostname.port);

		return this->connect(o_name);
	}
	case ADDRESS_TYPE_INET6: {
		throw UnsupportedOperationException();
	}
	case ADDRESS_TYPE_URL: {
		throw UnsupportedOperationException();
	}
	default:
		throw UnsupportedOperationException();
	}
}


std::vector<uint8_t> carbon::net::socket::receive(unsigned int num_bytes) throw (SocketException) {
	std::vector<uint8_t> buffer;

	return this->receive(buffer);
}


std::vector<uint8_t>& carbon::net::socket::receive(std::vector<uint8_t> buffer) throw (SocketException) {
	this->receive(buffer.data(), buffer.size());

	return buffer;
}


std::vector<uint8_t> carbon::net::socket::receive_all(unsigned int num_bytes) throw (SocketException) {
	std::vector<uint8_t> buffer;

	return this->receive_all(buffer);
}


uint8_t* carbon::net::socket::receive_all(uint8_t* buffer, unsigned int buffer_size) throw (SocketException) {
	size_t n_bytes_read = 0,
		   n_bytes_read_total = 0,
		   n_bytes_to_read = 0;

	do {
		n_bytes_to_read = (buffer_size - n_bytes_read_total);

		if (n_bytes_to_read == 0) 
			break;
		else {
			n_bytes_read = this->receive(buffer, buffer_size);
			n_bytes_read_total += n_bytes_read;
		}
	} while (n_bytes_read_total < buffer_size);

	return buffer;
}


std::vector<uint8_t>& carbon::net::socket::receive_all(std::vector<uint8_t> buffer) throw (SocketException) {
	this->receive_all(buffer.data(), buffer.size());

	return buffer;
}


void carbon::net::socket::send(type::cstring8_t const buffer) throw (SocketException) {
	return this->send_all((uint8_t*)buffer, strlen(buffer));
}


int carbon::net::socket::send(std::vector<uint8_t>& const buffer) throw (SocketException) {
	return this->send(buffer.data(), buffer.size());
}


void carbon::net::socket::send_all(uint8_t* const buffer, unsigned int buffer_size) throw (SocketException) {
	size_t n_bytes_to_write = 0,
		   n_bytes_written = 0,
		   n_bytes_written_total = 0;

	do {
		n_bytes_to_write = (buffer_size - n_bytes_written_total);

		if (n_bytes_to_write == 0) 
			break;
		else {
			n_bytes_written = this->send(&(buffer[n_bytes_written_total]), n_bytes_to_write);
			n_bytes_written_total += n_bytes_written;
		}
	} while (n_bytes_written_total < buffer_size);
}


void carbon::net::socket::send_all(std::vector<uint8_t>& const buffer) throw (SocketException) {
	return this->send_all(buffer.data(), buffer.size());
}

