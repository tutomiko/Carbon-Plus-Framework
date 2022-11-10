#
#pragma once
#
#pragma region <imports>
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <memory>
#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbonx/type/byte.h>
#include <carbonx/type/bool.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
#pragma region <implicit macro definitions>
#define __MEMSET(P, N, V)	for (size_t i = 0; i < N; i++) ((byte_t*)P)[i] = (byte_t)V;
#define __MEMZERO(P, S)		for (size_t i = 0; i < S; i++) ((byte_t*)P)[i] = (byte_t)0x0;
#pragma endregion


#pragma region <explicit macro definitions>
#define MEMSET				__MEMSET
#define MEMZERO				__MEMZERO
#pragma endregion


namespace carbon {
	namespace util {
		typedef void* (*PFALLOCATOR)(
			size_t const number_of_bytes
			);


		typedef void(*PFDEALLOCATOR)(
			void* pointer
			);


		void* memrand(void* ptr, size_t ptr_size);


		void* memzero(void* ptr, size_t ptr_size);
	}
}


