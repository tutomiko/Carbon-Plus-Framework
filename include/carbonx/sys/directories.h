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
		void create_directory(type::cstring8_t s_path);


		void create_directories(type::cstring8_t s_path);


		void create_directories(path& s_path);


		void remove_directory(type::cstring8_t s_path);
	}
}


