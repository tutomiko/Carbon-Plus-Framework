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

#pragma endregion
#pragma endregion
#
#
#pragma region <charset constant definitions>
#define CHARSET_MULTIBYTE		1
#define CHARSET_UNICODE			2
#pragma endregion


#pragma region <charset string constant definitions>
#define S_CHARSET_MULTIBYTE		"UTF-8"
#define S_CHARSET_UNICODE		"UTF-16"
#pragma endregion


#ifdef __CHARSET
#error '__CHARSET' definition prior to evaluation: undefine to build successfully
#endif // __CHARSET

#if defined(_MBCS) && _MBCS == 1
#define __CHARSET		CHARSET_MULTIBYTE
#define __S_CHARSET		S_CHARSET_MULTIBYTE
#elif defined(_UNICODE) && _UNICODE == 1
#define __CHARSET		CHARSET_UNICODE
#define __S_CHARSET		S_CHARSET_UNICODE
#else
#error no charset defined: define '__CHARSET' to build successfully
#endif


namespace carbon {
	namespace util {
		__inline static const char* charsetstr(int charset) {
			switch (charset) {
			case CHARSET_MULTIBYTE:
				return S_CHARSET_MULTIBYTE;
			case CHARSET_UNICODE:
				return S_CHARSET_UNICODE;
			default:
				return nullptr;
			}
		}
	}
}


