#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/sys/thread.h>
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
void carbon::sys::current_thread::exit(int exitcode) noexcept {
	ExitThread(exitcode);
}


unsigned long carbon::sys::current_thread::get_id(void) noexcept {
	return GetCurrentThreadId();
}


void carbon::sys::current_thread::sleep(unsigned long millis) noexcept {
	Sleep(millis);
}

