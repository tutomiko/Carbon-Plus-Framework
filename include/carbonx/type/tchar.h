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
#include <carbonx/type/char.h>
#include <carbonx/type/wchar.h>
#pragma endregion
#pragma endregion
#
#
/// <summary>
/// Target charset -compatible char type.
/// </summary>
#if __CHARSET == CHARSET_UNICODE
#define tchar_t					carbon::type::wchar16_t;
#elif __CHARSET	== CHARSET_MULTIBYTE
#define tchar_t					carbon::uint8_t;
#endif // __CHARSET


