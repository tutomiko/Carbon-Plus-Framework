/*
 * FileName: carbonplus.h
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
#ifndef _INCLUDE_CARBON_EVOLVE
#define _INCLUDE_CARBON_EVOLVE

#if !defined(_CARBONPLUS_DYNAMIC_LINKAGE) && !defined(_CARBONPLUS_STATIC_LINKAGE)
#error No build option defined: define _CARBONPLUS_DYNAMIC_LINKAGE for dynamic linkage or _CARBONPLUS_STATIC_LINKAGE for static linkage.
#else
// type headers
#include <carbonx/type/string.h>

// util headers
#include <carbonx/util/memory.h>
#include <carbonx/util/charset.h>
#include <carbonx/util/concurrency.h>
#include <carbonx/util/prandom.h>

// concurrency headers

// io headers
#include <carbonx/io/iobase.h>

// filesystem headers
#include <carbonx/filesystem/filesystem.h>

// sys headers
#include <carbonx/sys/thread.h>
#include <carbonx/sys/process.h>

// net headers
#include <carbonx/net/sockets.h>
#endif
#endif // !_INCLUDE_CARBON_EVOLVE


