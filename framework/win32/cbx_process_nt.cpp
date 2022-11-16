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
#include <carbonx/sys/process.h>
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
CBXEXPORT
void carbon::sys::process::close(void) throw (io::IOException) {
	if (!CloseHandle(reinterpret_cast<HANDLE>(this->native_handle))) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	this->native_handle = nullptr;
}


CBXEXPORT
unsigned long carbon::sys::process::get_id(void) throw (io::IOException) {
	return GetProcessId(reinterpret_cast<HANDLE>(this->native_handle));
}


CBXEXPORT
void carbon::sys::process::kill(void) throw (io::IOException) {
	if (!TerminateProcess(reinterpret_cast<HANDLE>(this->native_handle), EXIT_FAILURE)) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}
}


CBXEXPORT
carbon::sys::process carbon::sys::create_process(type::cstring8_t s_application_name) throw (io::IOException) {
	BOOL                b_create_process = FALSE;
	PROCESS_INFORMATION o_process_info;
	STARTUPINFOA        o_startup_info;

	ZeroMemory(&o_process_info, sizeof o_process_info);
	ZeroMemory(&o_startup_info, sizeof o_startup_info);

	b_create_process = CreateProcessA(
		s_application_name,
		nullptr,
		nullptr,
		nullptr,
		FALSE,
		0L,
		nullptr,
		nullptr,
		&o_startup_info,
		&o_process_info
	);

	if (!b_create_process) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	CloseHandle(o_process_info.hThread);

	return carbon::sys::process(o_process_info.hProcess);
}


CBXEXPORT
carbon::sys::process carbon::sys::create_process(type::cstring8_t s_application_name, std::vector<type::string> a_parameters) throw (io::IOException) {
	BOOL                b_create_process = FALSE;
	PROCESS_INFORMATION o_process_info;
	STARTUPINFOA        o_startup_info;
	type::string        s_commandline;

	s_commandline += '\"';
	s_commandline += s_application_name;
	s_commandline += '\"';

	if (a_parameters.size() > 0) {
		s_commandline += ' ';

		for (auto i = 0; i < a_parameters.size(); i++) {
			s_commandline += '\"';
			s_commandline += a_parameters[i];
			s_commandline += '\"';

			if ((i + 1) < a_parameters.size()) {
				s_commandline += ' ';
			}
		}
	}

	ZeroMemory(&o_process_info, sizeof o_process_info);
	ZeroMemory(&o_startup_info, sizeof o_startup_info);

	b_create_process = CreateProcessA(
		s_application_name,
		(LPSTR)s_commandline.c_str(),
		NULL,
		NULL,
		FALSE,
		0L,
		NULL,
		NULL,
		&o_startup_info,
		&o_process_info
	);

	if (!b_create_process) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	CloseHandle(o_process_info.hThread);

	return carbon::sys::process(o_process_info.hProcess);
}


CBXEXPORT
carbon::sys::process carbon::sys::create_process_detached(type::cstring8_t s_application_name) throw (io::IOException) {
	BOOL                b_create_process = FALSE;
	PROCESS_INFORMATION o_process_info;
	STARTUPINFOA        o_startup_info;

	ZeroMemory(&o_process_info, sizeof o_process_info);
	ZeroMemory(&o_startup_info, sizeof o_startup_info);

	b_create_process = CreateProcessA(
		s_application_name,
		nullptr,
		nullptr,
		nullptr,
		FALSE,
		CREATE_NEW_CONSOLE,
		nullptr,
		nullptr,
		&o_startup_info,
		&o_process_info
	);

	if (!b_create_process) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	CloseHandle(o_process_info.hThread);

	return carbon::sys::process(o_process_info.hProcess);
}


CBXEXPORT
carbon::sys::process carbon::sys::create_process_detached(type::cstring8_t s_application_name, std::vector<type::string> a_parameters) throw (io::IOException) {
	BOOL                b_create_process = FALSE;
	PROCESS_INFORMATION o_process_info;
	STARTUPINFOA        o_startup_info;
	type::string        s_commandline;

	s_commandline += '\"';
	s_commandline += s_application_name;
	s_commandline += '\"';

	if (a_parameters.size() > 0) {
		s_commandline += ' ';

		for (auto i = 0; i < a_parameters.size(); i++) {
			s_commandline += '\"';
			s_commandline += a_parameters[i];
			s_commandline += '\"';

			if ((i + 1) < a_parameters.size()) {
				s_commandline += ' ';
			}
		}
	}

	ZeroMemory(&o_process_info, sizeof o_process_info);
	ZeroMemory(&o_startup_info, sizeof o_startup_info);

	b_create_process = CreateProcessA(
		s_application_name,
		(LPSTR)s_commandline.c_str(),
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&o_startup_info,
		&o_process_info
	);

	if (!b_create_process) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	CloseHandle(o_process_info.hThread);

	return carbon::sys::process(o_process_info.hProcess);
}


CBXEXPORT
carbon::sys::process carbon::sys::create_process_silent(type::cstring8_t s_application_name) throw (io::IOException) {
	BOOL                b_create_process = FALSE;
	PROCESS_INFORMATION o_process_info;
	STARTUPINFOA        o_startup_info;

	ZeroMemory(&o_process_info, sizeof o_process_info);
	ZeroMemory(&o_startup_info, sizeof o_startup_info);

	b_create_process = CreateProcessA(
		s_application_name,
		nullptr,
		nullptr,
		nullptr,
		FALSE,
		CREATE_NO_WINDOW,
		nullptr,
		nullptr,
		&o_startup_info,
		&o_process_info
	);

	if (!b_create_process) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	CloseHandle(o_process_info.hThread);

	return carbon::sys::process(o_process_info.hProcess);
}


CBXEXPORT
carbon::sys::process carbon::sys::create_process_silent(type::cstring8_t s_application_name, std::vector<type::string> a_parameters) throw (io::IOException) {
	BOOL                b_create_process = FALSE;
	PROCESS_INFORMATION o_process_info;
	STARTUPINFOA        o_startup_info;
	type::string        s_commandline;

	s_commandline += '\"';
	s_commandline += s_application_name;
	s_commandline += '\"';

	if (a_parameters.size() > 0) {
		s_commandline += ' ';

		for (auto i = 0; i < a_parameters.size(); i++) {
			s_commandline += '\"';
			s_commandline += a_parameters[i];
			s_commandline += '\"';

			if ((i + 1) < a_parameters.size()) {
				s_commandline += ' ';
			}
		}
	}

	ZeroMemory(&o_process_info, sizeof o_process_info);
	ZeroMemory(&o_startup_info, sizeof o_startup_info);

	b_create_process = CreateProcessA(
		s_application_name,
		(LPSTR)s_commandline.c_str(),
		NULL,
		NULL,
		FALSE,
		CREATE_NO_WINDOW,
		NULL,
		NULL,
		&o_startup_info,
		&o_process_info
	);

	if (!b_create_process) {
		switch (GetLastError()) {
		default:
			throw io::IOException();
		}
	}

	CloseHandle(o_process_info.hThread);

	return carbon::sys::process(o_process_info.hProcess);
}

