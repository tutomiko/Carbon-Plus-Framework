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
void carbon::sys::current_process::exit(int exitcode) noexcept {
	ExitProcess(exitcode);
}


unsigned long carbon::sys::current_process::get_id(void) noexcept {
	return GetCurrentProcessId();
}

