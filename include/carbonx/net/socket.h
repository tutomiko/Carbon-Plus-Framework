#
#pragma once
#
#pragma region <imports>
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <vector>
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
		typedef class socket : public socket_base {
		public:
			socket(void) : socket_base() {

			}

			socket(void* native_handle) : socket_base(native_handle) {

			}

			~socket(void) {

			}


			socket accept(void) throw (SocketException);


			void bind(port_t port) throw (SocketException);


			void bind(socket_address_in& o_name) throw (SocketException);


			void close(void) throw (SocketException);


			void connect(port_t port) throw (SocketException);


			void connect(socket_address_in& o_name) throw (SocketException);


			void connect(type::string s_hostname) throw (SocketException);


			port_t get_remote_port(void) throw (SocketException);


			void listen(int const backlog) throw (SocketException);


			uint8_t receive(void) throw (SocketException);


			std::vector<uint8_t> receive(unsigned int num_bytes) throw (SocketException);


			int receive(uint8_t* buffer, unsigned int buffer_size) throw (SocketException);


			std::vector<uint8_t>& receive(std::vector<uint8_t> buffer) throw (SocketException);


			std::vector<uint8_t> receive_all(unsigned int num_bytes) throw (SocketException);


			uint8_t* receive_all(uint8_t* buffer, unsigned int buffer_size) throw (SocketException);


			std::vector<uint8_t>& receive_all(std::vector<uint8_t> buffer) throw (SocketException);


			void send(uint8_t const buffer) throw (SocketException);


			int send(uint8_t* const buffer, unsigned int buffer_size) throw (SocketException);


			void send(type::cstring8_t const buffer) throw (SocketException);


			int send(std::vector<uint8_t>& const buffer) throw (SocketException);


			void send_all(uint8_t* const buffer, unsigned int buffer_size) throw (SocketException);


			void send_all(std::vector<uint8_t>& const buffer) throw (SocketException);
		};
	}
}