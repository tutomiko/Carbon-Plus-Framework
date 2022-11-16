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
#include <carbonx/filesystem/path.h>
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
CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::addextension(type::cstring8_t s_extension) {
	if (s_extension == nullptr)
		s_extension = "";

	if (s_extension[0] != '.') {
		this->string.append('.');
	}

	this->string.append(s_extension);

	return *this;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::append(type::cstring8_t s_path) {
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
			end = (i + 2);

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

			if (c == '/')
				c = '\\';

			buffer[i] = c;
		}

		buffer[len] = '\0';

		this->string.append(buffer);
	} else {
		this->string.append(s_path);
	}

	return *this;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::append(type::string& s_path) {
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

			if (c == '/')
				c = '\\';

			if (c != '\\' && c != '/') {
				end = (i + 2);

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


CBXEXPORT
carbon::type::cstring8_t carbon::filesystem::path::c_str(void) noexcept {
	return this->str().c_str();
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::clear(void) {
	this->string.clear();

	return *this;
}


CBXEXPORT
int carbon::filesystem::path::countextensions(void) noexcept {
	int              counter = 0;
	type::cstring8_t s_filename;

	s_filename = this->getfname();

	if (nullptr != s_filename) {
		for (auto i = 0;; i++) {
			char c;

			c = s_filename[i];

			if (c == '\0')
				break;

			if (c == '.') {
				counter++;
			}
		}
	}

	return counter;
}


CBXEXPORT
carbon::filesystem::path carbon::filesystem::path::drive(void) {
	type::string s_path;

	s_path += this->driveletter();
	s_path += ":";

	return s_path;
}


CBXEXPORT
char carbon::filesystem::path::driveletter(void) noexcept {
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


CBXEXPORT
bool carbon::filesystem::path::equals(type::cstring8_t c_other) {
	path s_other;

	s_other = c_other;

	return this->equals(s_other);
}


CBXEXPORT
bool carbon::filesystem::path::equals(path& other) {
#pragma region <locals>
	name_iterator it1 = path::name_iterator(this);
	name_iterator it2 = path::name_iterator(&other);
#pragma endregion
	
	while (it1.has_next()) {
		path p1;
		path p2;

		p1 = it1.next();

		if (!it2.has_next()) 
			return false;

		p2 = it2.next();

		if (!p1.string.equals_ic(p2)) {
			return false;
		}
	}

	if (it2.has_next())
		return false;
	else {
		return true;
	}
}


CBXEXPORT
carbon::type::string carbon::filesystem::path::extension(void) {
	return this->extension(0);
}


CBXEXPORT
carbon::type::string carbon::filesystem::path::extension(int index) {
	type::cstring8_t s_extension;

	s_extension = this->getextension(index);

	if (nullptr != s_extension)
		return s_extension;
	else {
		return "";
	}
}


CBXEXPORT
std::vector<carbon::type::string> carbon::filesystem::path::extensions(void) {
	std::vector<carbon::type::string> a_extensions;
	int                               n_filename_length;
	type::cstring8_t                  s_extension;
	type::cstring8_t                  s_filename;

	s_filename = this->getfname();

	if (nullptr != s_filename) {
		n_filename_length = strlen(s_filename);

		for (auto i = (n_filename_length - 1); i >= 0; i--) {
			char c;

			c = s_filename[i];

			if (c == '\0') 
				break;

			if (c == '.') {
				s_extension = &(s_filename[i]);

				a_extensions.push_back(s_extension);
			}
		}
	}

	return a_extensions;
}


CBXEXPORT
carbon::filesystem::path carbon::filesystem::path::filename(void) {
	type::cstring8_t s_filename;

	s_filename = this->getfname();

	if (nullptr != s_filename)
		return s_filename;
	else {
		return "";
	}
}


CBXEXPORT
carbon::type::cstring8_t carbon::filesystem::path::getextension(void) noexcept {
	return this->getextension(0);
}


CBXEXPORT
carbon::type::cstring8_t carbon::filesystem::path::getextension(int index) noexcept {
	type::cstring8_t s_extension = nullptr;
	type::cstring8_t s_filename;
	int              cursor = -1;

	s_filename = this->getfname();

	if (nullptr == s_filename) {
		return nullptr;
	}

	for (auto i = 0;; i++) {
		char c;

		c = s_filename[i];

		if (c == '\0') {
			s_extension = nullptr;

			break;
		}

		if (c == '.') {
			cursor++;

			if (cursor == index) {
				s_extension = &(s_filename[i]);

				break;
			}
		}
	}

	return s_extension;
}


CBXEXPORT
carbon::type::cstring8_t carbon::filesystem::path::getfname(void) noexcept {
	type::cstring8_t s_filename;

	if (this->string.isempty()) {
		return nullptr;
	}

	for (auto i = (this->string.length() - 1);; i--) {
		char c;

		c = this->string.charat(i);

		if (i == 0) {
			s_filename = &(this->string[i]);

			break;
		}

		if (c == '\\' || c == '/') {
			s_filename = &(this->string[i + 1]);

			break;
		}
	}

	return s_filename;
}


CBXEXPORT
bool carbon::filesystem::path::hasdrive(void) noexcept {
	for (auto i = 1; i < _MAX_DRIVE; i++) {
		char c;

		if (i < this->string.length())
			c = this->string.charat(i);
		else {
			break;
		}

		if ((c == ':') && type::character::isalphabet(this->string.charat(i - 1))) {
			return true;
		}
	}

	return false;
}


CBXEXPORT
bool carbon::filesystem::path::hasextension(void) noexcept {
	type::cstring8_t s_filename;

	s_filename = this->getfname();

	if (nullptr != s_filename) {
		for (auto i = 0;; i++) {
			char c;

			c = s_filename[i];

			if (c == '\0')
				break;

			if (c == '.') {
				return true;
			}
		}
	}

	return false;
}


CBXEXPORT
bool carbon::filesystem::path::hasparent(void) noexcept {
	for (auto i = (this->string.length() - 1); i >= 0; i--) {
		char c;

		c = this->string.charat(i);

		if (c == '\\' || c == '/') {
			do {
				if (i == 0)
					return false;
				else {
					i--;

					c = this->string.charat(i);
				}
			} while (c == '\\' || c == '/');

			return true;
		}
	}

	return false;
}


CBXEXPORT
bool carbon::filesystem::path::isabsolute(void) noexcept {
	return this->hasdrive();
}


CBXEXPORT
bool carbon::filesystem::path::isancestorof(path& other) {
	bool b_eval = false;

	if (this->isdirectory()) { // Ensure that @this is a directory: if not, we don't have to do the heavy work;
		other.enum_subpaths([&](path& s_subpath) {
			if (s_subpath.equals(*this)) {
				b_eval = true;

				return false;
			}

			return true;
		});
	}

	return b_eval;
}


CBXEXPORT
bool carbon::filesystem::path::isdescendantof(path& other) {
	bool b_eval = false;

	if (other.isdirectory()) { // Ensure that @other is a directory: if not, we don't have to do the heavy work;
		this->enum_subpaths([&](path& s_subpath) {
			if (s_subpath.equals(other)) {
				b_eval = true;

				return false;
			}

			return true;
		});
	}

	return b_eval;
}


CBXEXPORT
bool carbon::filesystem::path::isdirectory(void) noexcept {
	return (this->string.endswith("\\") || this->string.endswith("/"));
}


CBXEXPORT
bool carbon::filesystem::path::isempty(void) noexcept {
	return this->string.isempty();
}


CBXEXPORT
bool carbon::filesystem::path::isfile(void) noexcept {
	return (!this->string.endswith("\\") && !this->string.endswith("/"));
}


CBXEXPORT
bool carbon::filesystem::path::isindirect(void) {
	int last_delimiter = 0;

	if (this->isrelative())
		return true;

	for (auto i = 0;; i++) {
		char c;

		if (i < this->string.length())
			c = this->string.charat(i);
		else {
			int  n_filename_length;
			path s_filename;

			n_filename_length = (i - last_delimiter);

			for (auto j = last_delimiter; j < i; j++) {
				s_filename += this->string.charat(j);
			}

			if (s_filename.equals(".") || s_filename.equals("..")) {
				return true;
			}

			break;
		}

		if (c == '\\' || c == '/') {
			int  n_filename_length;
			path s_filename;

			n_filename_length = (i - last_delimiter);

			if (n_filename_length > 0) {
				for (auto j = last_delimiter; j < i; j++) {
					s_filename += this->string.charat(j);
				}

				if (s_filename.equals(".") || s_filename.equals("..")) {
					return true;
				}
			}

			last_delimiter = (i + 1);
		}
	}

	return false;
}


CBXEXPORT
bool carbon::filesystem::path::isparentof(path& other) {
	path s_other_parent;

	s_other_parent = other.parent();

	return this->equals(s_other_parent);
}


CBXEXPORT
bool carbon::filesystem::path::isrelative(void) noexcept {
	return !this->isabsolute();
}


CBXEXPORT
int carbon::filesystem::path::length(void) noexcept {
	return this->string.length();
}


CBXEXPORT
std::vector<carbon::filesystem::path> carbon::filesystem::path::names(void) {
	int               last_delimiter = 0;
	std::vector<path> a_names;

	for (auto i = 0;; i++) {
		char c;

		if (i < this->string.length())
			c = this->string.charat(i);
		else {
			int  n_filename_length;
			path s_filename;

			n_filename_length = (i - last_delimiter);

			for (auto j = last_delimiter; j < i; j++) {
				s_filename += this->string.charat(j);
			}

			a_names.push_back(s_filename);

			break;
		}

		if (c == '\\' || c == '/') {
			int  n_filename_length;
			path s_filename;

			n_filename_length = (i - last_delimiter);

			if (n_filename_length > 0) {
				for (auto j = last_delimiter; j < i; j++) {
					s_filename += this->string.charat(j);
				}

				s_filename.todirectory();

				a_names.push_back(s_filename);
			}

			last_delimiter = (i + 1);
		}
	}

	return a_names;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::normalize(void) {
	for (auto i = 0; i < this->string.length(); i++) {
		char c;

		c = this->string.charat(i);

		if (c == '/') {
			this->string.assign(i, '\\');

			c = '\\';
		}

		if ((c == '\\') && (this->string.charat(i + 1) == '\\' || this->string.charat(i + 1) == '/')) {
			int n_reductions = 0;

			do {
				i++;

				n_reductions++;
			} while (this->string.charat(i) == '\\' || this->string.charat(i) == '/');

			this->string.reduce_mid(i, (n_reductions - 1));
		}
	}

	return *this;
}


CBXEXPORT
carbon::filesystem::path carbon::filesystem::path::parent(void) {
	type::string s_parent_path;

	for (auto i = (this->string.length() - 1); i >= 0; i--) {
		char c;

		c = this->string.charat(i);

		if (c == '\\' || c == '/') {
			do {
				if (i == 0) 
					return s_parent_path;
				else {
					i--;

					c = this->string.charat(i);
				}
			} while (c == '\\' || c == '/');

			s_parent_path = this->string.substring(0, (i + 2));

			break;
		}
	}

	return s_parent_path;
}


CBXEXPORT
carbon::filesystem::path carbon::filesystem::path::resolve(type::cstring8_t s_from_path_cs) {
	carbon::filesystem::path s_from_path;

	s_from_path = s_from_path_cs;

	return this->resolve(s_from_path);
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::resolve(void) {
	int  last_delimiter = 0;
	path s_absolute_path;

	for (auto i = 0;; i++) {
		char c;

		if (i < this->string.length())
			c = this->string.charat(i);
		else {
			int  n_filename_length;
			path s_filename;

			n_filename_length = (i - last_delimiter);

			for (auto j = last_delimiter; j < i; j++) {
				s_filename += this->string.charat(j);
			}

			if (s_filename.string.equals(".."))
				s_absolute_path.toparent();
			else if (!s_filename.string.equals(".")) {
				s_absolute_path.append(s_filename);
			}

			break;
		}

		if (c == '\\' || c == '/') {
			int  n_filename_length;
			path s_filename;

			n_filename_length = (i - last_delimiter);

			if (n_filename_length > 0) {
				for (auto j = last_delimiter; j < i; j++) {
					s_filename += this->string.charat(j);
				}

				if (s_filename.string.equals("..")) 
					s_absolute_path.toparent();
				else if (!s_filename.string.equals(".")) {
					s_absolute_path.append(s_filename);
				}
			}

			last_delimiter = (i + 1);
		}
	}

	this->string = s_absolute_path;

	return *this;
}


CBXEXPORT
carbon::filesystem::path carbon::filesystem::path::resolve(path& s_from_path) {
#pragma region <locals>
	int  cursor;
	int  last_delimiter;
	path s_absolute_path;
#pragma endregion

	// Relative from drive;
	if (this->string.charat(0) == '\\' || this->string.charat(0) == '/') {
		s_absolute_path.append(s_from_path.drive());

		last_delimiter = cursor = 1;
	}
	// Relative from current directory;
	else if (this->string.charat(0) == '.' && (this->string.charat(1) == '\\' || this->string.charat(1) == '/')) {
		s_absolute_path.append(s_from_path);

		last_delimiter = cursor = 2;
	}
	// Relative parent from current directory;
	else if (this->string.charat(0) == '.' && this->string.charat(1) == '.') {
		s_absolute_path.append(s_from_path.parent());

		last_delimiter = cursor = 3;
	}
	// Regular path;
	else {
		if (!this->isabsolute()) {
			s_absolute_path.append(s_from_path);
		}

		last_delimiter = cursor = 0;
	}

	for (;; cursor++) {
		char c;

		if (cursor < this->string.length())
			c = this->string.charat(cursor);
		else {
			int  n_filename_length;
			path s_filename;

			n_filename_length = (cursor - last_delimiter);

			if (n_filename_length > 0) {
				for (auto i = last_delimiter; i < cursor; i++) {
					s_filename += this->string.charat(i);
				}

				if (s_filename.string.equals(".."))
					s_absolute_path.toparent();
				else if (!s_filename.string.equals(".")) {
					s_absolute_path.append(s_filename);
				}
			}

			break;
		}

		if (c == '\\' || c == '/') {
			int  n_filename_length;
			path s_filename;

			n_filename_length = (cursor - last_delimiter);

			if (n_filename_length > 0) {
				for (auto i = last_delimiter; i < cursor; i++) {
					s_filename += this->string.charat(i);
				}

				if (s_filename.string.equals(".."))
					s_absolute_path.toparent();
				else if (!s_filename.string.equals(".")) {
					s_absolute_path.append(s_filename);
				}
			}

			last_delimiter = (cursor + 1);
		}
	}

	return s_absolute_path;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::rmvdrive(void) {
	for (auto i = 0; i < _MAX_DRIVE; i++) {
		char c;

		c = this->string.charat(i);

		if (c == ':') {
			if ((i >= 1) && type::character::isalphabet(this->string.charat(i - 1))) {
				if (this->length() > (i + 1)) 
					this->string.reduce_left(i + 2);
				else {
					this->string.reduce_left(i + 1);
				}
			}

			break;
		}
	}

	return *this;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::rmvextension(void) {
	return this->rmvextension(0);
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::rmvextension(int index) {
	int              cursor = -1;
	int              n_filename_length;
	type::cstring8_t s_filename;

	s_filename = this->getfname();

	if (nullptr != s_filename) {
		n_filename_length = strlen(s_filename);

		for (auto i = 0;; i++) {
			char c;

			c = s_filename[i];

			if (c == '\0')
				break;

			if (c == '.') {
				cursor++;

				if (cursor == index) {
					this->string.reduce_right(n_filename_length - i);

					break;
				}
			}
		}
	}

	return *this;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::setdrive(char c_drive) {
	bool has_drive = false;

	c_drive = type::character::toupper(c_drive);

	for (auto i = 0; i < this->string.length(); i++) {
		char c;

		c = this->string.charat(i);

		if (c == ':') {
			has_drive = true;

			if (i == 0)
				this->string.push(c_drive);
			else {
				this->string.assign((i - 1), c_drive);
			}

			break;
		}
	}

	if (!has_drive) {
		type::string s_drive;

		s_drive += c_drive;
		s_drive += ':';

		if (this->string.charat(0) != '\\' && this->string.charat(0) != '/') {
			s_drive += '\\';
		}

		this->string.push(s_drive);
	}

	return *this;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::setdrive(type::cstring8_t s_drive) {
	char c_drive;

	c_drive = s_drive[0];

	return this->setdrive(c_drive);
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::setextension(type::cstring8_t s_extension) {
	return this->setextension(0, s_extension);
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::setextension(int index, type::cstring8_t s_extension) {
	type::cstring8_t s_filename;
	int              cursor = -1;

	s_filename = this->getfname();

	if (nullptr != s_filename) {
		for (auto i = 0;; i++) {
			char c;

			c = s_filename[i];

			if (c == '\0') {
				break;
			}

			if (c == '.') {
				cursor++;

				if (cursor == index) {
					this->string.reduce_right(strlen(s_filename) - i);

					break;
				}
			}
		}
	}

	this->addextension(s_extension);

	return *this;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::setfname(type::cstring8_t s_fname) {
	type::cstring8_t s_extension;
	path             s_parent;

	s_extension = this->getextension();
	s_parent = this->parent();

	this->string.clear();

	if (!s_parent.isempty()) {
		this->append(s_parent);
	}

	this->append(s_fname);

	if (!this->hasextension() && (nullptr != s_extension)) {
		this->addextension(s_extension);
	}

	return *this;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::setparent(type::cstring8_t s_parent) {
	type::cstring8_t s_filename;

	s_filename = this->getfname();

	this->string.clear();
	this->append(s_parent);

	if (nullptr != s_filename) {
		this->append(s_filename);
	}

	return *this;
}


CBXEXPORT
carbon::filesystem::path carbon::filesystem::path::stem(void) {
	path s_filename;

	s_filename = this->filename();

	if (s_filename.hasextension()) {
		s_filename.rmvextension();
	}

	return s_filename;
}


CBXEXPORT
carbon::type::string& carbon::filesystem::path::str(void) noexcept {
	return this->string;
}


CBXEXPORT
std::vector<carbon::filesystem::path> carbon::filesystem::path::subpaths(void) {
	int               last_delimiter = 0;
	std::vector<path> a_subpaths;
	path              s_path;

	for (auto i = 0;; i++) {
		char c;

		if (i < this->string.length())
			c = this->string.charat(i);
		else {
			int  n_filename_length;
			path s_filename;

			n_filename_length = (i - last_delimiter);

			for (auto j = last_delimiter; j < i; j++) {
				s_filename += this->string.charat(j);
			}

			s_path.append(s_filename);

			a_subpaths.push_back(s_path);

			break;
		}

		if (c == '\\' || c == '/') {
			int  n_filename_length;
			path s_filename;

			n_filename_length = (i - last_delimiter);

			if (n_filename_length > 0) {
				for (auto j = last_delimiter; j < i; j++) {
					s_filename += this->string.charat(j);
				}

				s_path.append(s_filename);
				s_path.todirectory();

				a_subpaths.push_back(s_path);
			}

			last_delimiter = (i + 1);
		}
	}

	return a_subpaths;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::todirectory(void) {
	if (!this->isempty() && !this->isdirectory()) {
		this->string.append("\\");
	}

	return *this;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::tofile(void) {
	if (!this->isempty() && this->isdirectory()) {
		this->string.reduce_right(1);
	}

	return *this;
}


CBXEXPORT
carbon::filesystem::path& carbon::filesystem::path::toparent(void) {
	for (auto i = (this->string.length() - 1); i >= 0; i--) {
		char c;

		c = this->string.charat(i);

		if (c == '\\' || c == '/') {

			do {
				if (i == 0)
					return *this;
				else {
					i--;

					c = this->string.charat(i);
				}
			} while (c == '\\' || c == '/');

			this->string = this->string.substring(0, (i + 1));

			break;
		}
	}

	return *this;
}


