#include <iostream>

int strLen (const char *);
bool is_palindrome (const char*, int);
std::istream& read_word(std::istream&, char*, int);

int main (void) {
	constexpr int max = 128;

	for (char s[max]; read_word(std::cin, s, max); ) {
		std::cout << "Exiting\n";

		std::cout << s << " is";
		
		if (!is_palindrome (s, strLen(s)))
			std::cout << " not";

		std::cout << " a polindrome\n";

	}

	return 0;
}

bool is_palindrome (const char* s, int n) {
	int first = 0;
	int last = n - 1;

	while (first < last) {
		if (s[first] != s[last])
			return false;

		++first;
		--last;
	}
	return true;
}

int strLen (const char* s) {
	int size = 0;
	for (; *s != '\0'; ++s, ++size);

	return size;
}

std::istream& read_word (std::istream& is, char* buffer, int max) {
	is.width (max);
	is >> buffer;

	return is;
}
