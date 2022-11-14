/*
 * FileName: memory.h
 *
 * Written by Tuomas Kontiainen <https://www.github.com/tutomiko>
 *
 * Copyright (c) 2022, Tuomas Kontiainen
 *
 * This file is a part of Carbon Plus Framework <https://github.com/tutomiko/Carbon-Plus-Framework>
 * Carbon Plus Framework is a free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later versions.
 *
 * Carbon Plus Framework is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Carbon Plus Framework. If not, see <http://www.gnu.org/licenses/>.
 */
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


		void* zero_memory(void* ptr, size_t ptr_size);
	}
}


