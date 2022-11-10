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
#include <carbonx/type/bool.h>
#include <carbonx/type/byte.h>
#include <carbonx/type/char.h>
#include <carbonx/type/wchar.h>
#include <carbonx/type/tchar.h>
#include <carbonx/type/double.h>
#include <carbonx/type/float.h>
#include <carbonx/type/int.h>
#include <carbonx/type/long.h>
#include <carbonx/type/short.h>
#pragma endregion
#pragma endregion
#
#
#pragma region <primitive bits constant definitions>
#define _BOOLEAN_BITS		8
#define _BYTE_BITS			8
#define _CHAR_BITS			8
#define _DOUBLE_BITS		64
#define _FLOAT_BITS			32
#define _INTEGER_BITS		32
#define _LONG_BITS			64
#define _SHORT_BITS			16
#define _WCHAR_BITS			16
#pragma endregion


#pragma region <primitive maximum character count constant definitions>
#define _BOOLEAN_CHARS		5
#define _BYTE_CHARS			3
#define _CHAR_CHARS			1
#define _DOUBLE_CHARS		24
#define _DOUBLE_CHARS_64	((4 + DBL_DIG + -DBL_MIN_10_EXP) - 1)
#define _FLOAT_CHARS		-1 // Adding later
#define _INTEGER_CHARS		10 + 1 // -2147483648 to 2147483647
#define _LONG_CHARS			10 + 1 // -2147483648 to 2147483647
#define _LONG_CHARS_64		19 + 1 // -9223372036854775807 to 9223372036854775807
#define _LONGLONG_CHARS		_LONG_CHARS_64
#define _SHORT_CHARS		5 + 1 // 0 to 65535
#define _UINT_CHARS			10 // 0 to 4294967295
#define _ULONG_CHARS		10 // 0 to 4294967295
#define _ULONGLONG_CHARS	_LONG_CHARS_64 //0 to 9223372036854775807
#define _WCHAR_CHARS		1
#pragma endregion


