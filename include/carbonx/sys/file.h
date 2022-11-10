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
		class file {
		private:
			void* native_handle;
		public:
			file(void) noexcept {
				this->native_handle = nullptr;
			}

			file(void* native_handle) noexcept {
				this->native_handle = native_handle;
			}

			~file(void) {

			}
		};
	}
}


