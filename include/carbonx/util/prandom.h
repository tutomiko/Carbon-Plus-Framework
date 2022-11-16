/*
 * FileName: prandom.h
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

#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbonx/cbxbase.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace util {
		class prandom {
		private:
			unsigned long Seed;
		public:
			prandom(void) : Seed(reinterpret_cast<unsigned long>(this)) {

			}

			prandom(unsigned long Seed) : Seed(Seed) {
				
			}


			int ints(int min, int max) noexcept {
				int next;
				int val;

				val = this->rand();

				next = (min + 1 + (val % max));

				return next;
			}


			unsigned long rand(void) {
				unsigned long val;

				// Get seed to generate random with;
				val = this->Seed;

				// Chunk least random bit;
				val = ((val >> 1) & 0x7fffffff);

				// Append new "random" value to seed;
				if ((this->Seed + val) < ULONG_MAX)
					this->Seed += val;
				else {
					this->Seed = val;
				}

				return val;
			}


			void seed(unsigned long Seed) {
				this->Seed = Seed;
			}
		};
	}
}


