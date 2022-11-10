#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/sys/path.h>
#pragma endregion
#
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
carbon::sys::path& carbon::sys::path::append(type::cstring8_t s_path) {
	int begin = 0,
		end, 
		len;

	end = len = strlen(s_path);

	if (!this->isempty() && !this->isdirectory())
		this->todirectory();

	for (auto i = 0; i < len; i++) {
		char c;

		c = s_path[i];

		if (c != '\\' && c != '/') {
			begin = i;

			break;
		}
	}
	
	for (auto i = (len - 1); i > 0; i--) {
		char c;

		c = s_path[i];


		if (c != '\\' && c != '/') {
			end = (i + 1);

			break;
		}
	}
	
	if ((begin != 0) || (end != len)) {
		char* buffer;

		len = (end - begin);

		buffer = new char[len + 1];

		for (auto i = 0; i < len; i++) {
			char c;

			c = s_path[begin + i];

			buffer[i] = c;
		}

		buffer[len] = '\0';

		this->string.append(buffer);
	} else {
		this->string.append(s_path);
	}

	return *this;
}


carbon::sys::path& carbon::sys::path::append(type::string& s_path) {
	int begin = 0,
		end = s_path.length();

	if (!this->isempty() && !this->isdirectory()) 
		this->todirectory();

	if (s_path.startswith('\\') || s_path.startswith('/')) {
		for (auto i = 1; i < s_path.length(); i++) {
			char c;

			c = s_path.charat(i);

			if (c != '\\' && c != '/') {
				begin = i;

				break;
			}
		}
	}

	if (s_path.endswith('\\') || s_path.endswith('/')) {
		for (auto i = (s_path.length() - 1); i > 0; i--) {
			char c;

			c = s_path.charat(i);


			if (c != '\\' && c != '/') {
				end = i;

				break;
			}
		}
	}

	if ((begin != 0) || (end != s_path.length()))
		this->string.append(s_path.substring(begin, end));
	else {
		this->string.append(s_path);
	}

	return *this;
}


char carbon::sys::path::getdriveletter(void) noexcept {
	for (auto i = 1; i < _MAX_DRIVE; i++) {
		char c;

		if (i < this->string.length()) 
			c = this->string.charat(i);
		else {
			break;
		}

		if (c == ':') {
			return (this->string.charat(i - 1));
		}
	}

	return '\0';
}


bool carbon::sys::path::isdirectory(void) noexcept {
	return (this->string.endswith("\\") || this->string.endswith("/"));
}


bool carbon::sys::path::isempty(void) noexcept {
	return this->string.isempty();
}


bool carbon::sys::path::isfile(void) noexcept {
	return (!this->string.endswith("\\") && !this->string.endswith("/"));
}


carbon::sys::path& carbon::sys::path::normalize(void) {
	return *this;
}


carbon::sys::path& carbon::sys::path::todirectory(void) {
	if (!this->isempty() && !this->isdirectory()) {
		this->string.append("\\");
	}

	return *this;
}


carbon::sys::path& carbon::sys::path::tofile(void) {
	if (!this->isempty() && this->isdirectory()) {
		this->string.reduce_right(1);
	}

	return *this;
}

