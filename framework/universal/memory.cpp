#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/util/memory.h>
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
void* carbon::util::memzero(void* ptr, size_t ptr_size) {
#pragma region <locals>
	carbon::type::byte_t* bytes;
#pragma endregion

	memset(ptr, 0, 1);

	bytes = (carbon::type::byte_t*)ptr;

	for (size_t i = 0; i < ptr_size; i++) {
		bytes[i] = (carbon::type::byte_t)0x0;
	}

	return ptr;
}

