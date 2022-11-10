#
#pragma region <imports>
#pragma region "export header imports"
#include <carbonx/type/char.h>
#pragma endregion
#
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <iostream>
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
bool carbon::type::character::isalphabet(char c) {
	return (character::islower(c) || character::isupper(c));
}


bool carbon::type::character::isalphanumeric(char chr) {
	return (character::isalphabet(chr) || character::isnumber(chr));
}


bool carbon::type::character::islower(char chr) {
	return (chr >= 'a' && chr <= 'z');
}


bool carbon::type::character::isnumber(char chr) {
	return (chr >= '0' && chr <= '9');
}


bool carbon::type::character::isupper(char chr) {
	return (chr >= 'A' && chr <= 'Z');
}


bool carbon::type::character::iswhitespace(char c) {
	return (c == ' ' || c == '\t');
}


char carbon::type::character::tolower(char c) {
	return ::tolower(c);
}


char carbon::type::character::toupper(char c) {
	return ::toupper(c);
}

