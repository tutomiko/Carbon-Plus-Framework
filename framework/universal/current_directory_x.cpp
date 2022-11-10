#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/sys/process.h>
#pragma endregion
#
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

#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
void carbon::sys::current_process::set_current_directory(path& s_path) throw (io::IOException) {
	return set_current_directory(s_path.c_str());
}

