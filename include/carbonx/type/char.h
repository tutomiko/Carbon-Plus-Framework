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

#pragma endregion
#
#pragma region "local imports"
#include <carbonx/util/charset.h>
#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace type {
		namespace character {
			bool isalphabet(char c);

			bool isalphanumeric(char c);

			bool islower(char c);

			bool isnumber(char c);

			bool isupper(char c);

			bool iswhitespace(char c);

			char tolower(char c);

			char toupper(char c);
		}
	}
}


