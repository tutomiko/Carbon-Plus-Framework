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
#include <carbonx/sys/paths.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace sys {
		namespace current_process {
			void exit(int exitcode) noexcept;


			path get_current_directory(void) throw (io::IOException);


			unsigned long get_id(void) noexcept;


			bool is_elevated(void);


			void set_current_directory(type::cstring8_t s_path) throw (io::IOException);


			void set_current_directory(path& s_path) throw (io::IOException);
		}


		class process {
		private:
			void* native_handle;
		public:
			process(void) noexcept {
				this->native_handle = nullptr;
			}

			process(void* native_handle) noexcept {
				this->native_handle = native_handle;
			}

			~process(void) {

			}


			void close(void) throw (io::IOException);


			unsigned long get_id(void) throw (io::IOException);


			bool is64bit(void) throw (io::IOException);


			void kill(void) throw (io::IOException);
		};


		process create_process(type::cstring8_t s_application_name) throw (io::IOException);


		process create_process(type::cstring8_t s_application_name, std::vector<type::string> a_parameters) throw (io::IOException);


		process create_process_silent(type::cstring8_t s_application_name) throw (io::IOException);


		process create_process_silent(type::cstring8_t s_application_name, std::vector<type::string> a_parameters) throw (io::IOException);


		process open_process(unsigned long process_id, unsigned long long requested_access);
	}
}


