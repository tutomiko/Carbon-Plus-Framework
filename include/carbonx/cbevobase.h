#
#pragma once
#
#pragma region <imports>
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <exception>
#include <string>
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
namespace carbon {
	class Exception : public std::exception {
	private:
		std::string message;
	public:
		Exception(void) {

		}

		Exception(std::string message) {
			this->message = message;
		}


		const char* what(void) const throw () {
			return this->message.c_str();
		}
	};


	class UnsupportedOperationException : public Exception {
	public:
		UnsupportedOperationException(void) : Exception() {

		}

		UnsupportedOperationException(std::string message) : Exception(message) {

		}
	};
}