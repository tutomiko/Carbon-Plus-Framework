#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/sys/process.h>
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
carbon::sys::path carbon::sys::current_process::get_current_directory(void) throw (io::IOException) {
	CHAR s_path[MAX_PATH + 1];

	ZeroMemory(s_path, sizeof s_path);

	if (0 == GetCurrentDirectoryA(MAX_PATH, s_path)) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	return s_path;
}


void carbon::sys::current_process::set_current_directory(type::cstring8_t s_path) throw (io::IOException) {
	if (!SetCurrentDirectoryA(s_path)) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}
}

