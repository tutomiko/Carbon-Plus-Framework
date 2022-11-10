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
#include <carbonx/sys/thread.h>
#include <carbonx/sys/process.h>
//#include <carbonx/sys/mutex.h>
//#include <carbonx/sys/event.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace util {
		class TimeoutException : public Exception {
		public:
			TimeoutException(void) : Exception() {

			}

			TimeoutException(std::string message) : Exception(message) {

			}
		};
	}
}


