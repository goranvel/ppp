#include <iostream>

bool is_palindrome (const char* first, const char* last);
std::istream&  read_word (std::istream& is, char* buffer, int max);
int strLen (char*);

int main (void) {
	const int max = 128;

	for (char s[max]; read_word (std::cin, s, max); ) {
		std::cout << s << " is";
		if (!is_palindrome (s, s+strLen(s) - 1))
			std::cout << " not";

		std::cout << " a palindrome\n";
	}

	return 0;
}

std::istream&  read_word (std::istream& is, char* buffer, int max) {
	is.width (max);

	is >> buffer;	// read whitespace-terminated words
					// add zero after last character read into buffer
	return is;
}

bool is_palindrome (const char* first, const char* last) {
	if (first < last) {
		if (*first != *last)
			return false;

		return is_palindrome (first + 1, last - 1);
	}

	return true;
}

int strLen (char* s) {
	int len = 0;
	for (; *s != '\0'; ++s, ++len);

	return len;
}
