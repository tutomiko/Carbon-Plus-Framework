/*
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
#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/sys/files.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#include <Windows.h>
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
void carbon::sys::delete_file(type::cstring8_t s_file_path) throw (io::IOException) {
	if (!DeleteFileA(s_file_path)) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}
}


unsigned int carbon::sys::get_file_size(type::cstring8_t s_file_path) throw (io::IOException) {
#pragma region <locals>
	HANDLE FileHandle = INVALID_HANDLE_VALUE;
	DWORD  FileSize;
#pragma endregion

	FileHandle = CreateFileA(
		s_file_path,
		FILE_READ_ATTRIBUTES,
		0L,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (INVALID_HANDLE_VALUE == FileHandle) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	FileSize = GetFileSize(FileHandle, NULL);

	CloseHandle(FileHandle);

	return FileSize;
}


unsigned long long carbon::sys::get_file_size_big(type::cstring8_t s_file_path) throw (io::IOException) {
#pragma region <locals>
	HANDLE        FileHandle = INVALID_HANDLE_VALUE;
	LARGE_INTEGER FileSize;
#pragma endregion

	FileHandle = CreateFileA(
		s_file_path,
		FILE_READ_ATTRIBUTES,
		0L,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (INVALID_HANDLE_VALUE == FileHandle) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	if (!GetFileSizeEx(FileHandle, &FileSize)) {
		CloseHandle(FileHandle);

		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	CloseHandle(FileHandle);

	return FileSize.QuadPart;
}


void carbon::sys::zero_file(type::cstring8_t s_file_path) throw (io::IOException) {
#pragma region <locals>
	HANDLE        FileHandle = INVALID_HANDLE_VALUE;
	LARGE_INTEGER FileSize;
	ULONGLONG     TotalBytesToWrite, 
		          TotalBytesWritten;
	CHAR          zero_buffer[512];
	DWORD         zero_buffer_size = (sizeof(zero_buffer) / sizeof(zero_buffer[0]));
#pragma endregion

	FileHandle = CreateFileA(
		s_file_path,
		FILE_READ_ATTRIBUTES | GENERIC_WRITE,
		0L,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (INVALID_HANDLE_VALUE == FileHandle) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	if (!GetFileSizeEx(FileHandle, &FileSize)) {
		CloseHandle(FileHandle);

		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	RtlSecureZeroMemory(zero_buffer, sizeof zero_buffer);

	TotalBytesToWrite = FileSize.QuadPart;
	TotalBytesWritten = 0ULL;

	for (DWORD BytesToWrite, BytesWritten; TotalBytesWritten < FileSize.QuadPart; TotalBytesWritten += BytesWritten, TotalBytesToWrite -= BytesWritten) {
		if (TotalBytesToWrite < zero_buffer_size)
			BytesToWrite = (DWORD)TotalBytesToWrite;
		else {
			BytesToWrite = zero_buffer_size;
		}

		if (!WriteFile(FileHandle, zero_buffer, BytesToWrite, &BytesWritten, NULL)) {
			CloseHandle(FileHandle);

			switch (GetLastError()) {
			default:
				throw io::IOException();
			}
		}
	}

	CloseHandle(FileHandle);
}

