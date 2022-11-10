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
#include <carbonx/cbevobase.h>
#include <carbonx/type/string.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
namespace carbon {
	namespace sys {
		class path {
		private:
			type::string string;
		public:
			path& operator+= (type::cstring8_t string) {
				this->string.append(string);

				return *this;
			}

			operator type::cstring8_t (void) {
				return this->c_str();
			}

			operator type::string(void) {
				return type::string(this->c_str());
			}
		public:
			path(void) {

			}

			path(type::cstring8_t cstring) : string(std::move(cstring)) {

			}

			path(type::string& string) : string(std::move(string)) {

			}

			~path(void) {

			}


			path& append(type::cstring8_t s_cpath);


			path& append(type::string& s_path);


			type::cstring8_t c_str(void) noexcept {
				return this->str().c_str();
			}


			bool equals(path& other) noexcept;


			path getdrive(void);


			char getdriveletter(void) noexcept;


			type::string getextension(void);


			type::string getextension(int index);


			path getfname(void);


			path getparent(void);


			bool hasparent(void) noexcept;


			bool isabsolute(void) noexcept;


			bool isancestorof(path& other);


			bool isdescendantof(path& other);


			bool isdirectory(void) noexcept;


			bool isempty(void) noexcept;


			bool isfile(void) noexcept;


			bool isparentof(path& other);


			bool isrelative(void) noexcept;


			path& normalize(void);


			path& resolve(path& s_from_path);


			path& rmvdrive(void);


			path& rmvextension(void);


			path& rmvextension(int index);


			path& setdrive(char c_drive);


			path& setdrive(type::cstring8_t s_drive);


			path& setdrive(type::string& s_drive);


			path& setextension(type::cstring8_t s_extension);


			path& setextension(type::string& s_extension);


			path& setextension(int index, type::cstring8_t s_extension);


			path& setextension(int index, type::string& s_extension);


			path& setfname(type::cstring8_t s_fname);


			path& setfname(type::string& s_fname);


			path& setparent(type::cstring8_t s_parent);


			path& setparent(type::string& s_parent);


			type::string& str(void) noexcept {
				return this->string;
			}


			path& todirectory(void);


			path& tofile(void);


			path& toparent(void);
		};
	}
}

