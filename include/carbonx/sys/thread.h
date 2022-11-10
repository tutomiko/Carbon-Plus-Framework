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
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace sys {
		namespace current_thread {
			void exit(int exitcode) noexcept;


			unsigned long get_id(void) noexcept;


			void sleep(unsigned long millis) noexcept;
		}


		class thread {
		private:
			void* native_handle;
		public:
			thread(void) noexcept {
				this->native_handle = nullptr;
			}

			thread(void* native_handle) noexcept {
				this->native_handle = native_handle;
			}

			~thread(void) {

			}
		};
	}
}


