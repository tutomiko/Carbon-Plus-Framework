#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/sys/directories.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#include <Windows.h>
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
void carbon::sys::create_directory(type::cstring8_t s_path) {
	if (!CreateDirectoryA(s_path, NULL)) {
		switch (GetLastError()) {
		case ERROR_ACCESS_DENIED:
			throw "";
		case ERROR_ALREADY_EXISTS:
			throw "";
		case ERROR_PATH_NOT_FOUND:
			throw "";
		default:
			throw std::bad_exception();
		}
	}
}


void carbon::sys::create_directories(type::cstring8_t s_path) {

}


void carbon::sys::create_directories(path& s_path) {

}


void carbon::sys::remove_directory(type::cstring8_t s_path) {
	if (!RemoveDirectoryA(s_path)) {
		switch (GetLastError()) {
		default:
			throw std::bad_exception();
		}
	}
}

