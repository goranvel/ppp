#include <iostream>

bool is_palindrome (const std::string&);
void reverse (char[]);

int main (void) {
	for (std::string s; std::cin >> s;) 
		std::cout << s << " is" << (is_palindrome (s) ? "" : " not") << " palindrome.\n";
	return 0;
}

bool is_palindrome (const std::string& s) {
	int first = 0;
	int last = s.length() - 1;

	while (first < last) {
		if (s[first] != s[last])
			return false;

		++first;
		--last;
	}
	return true;
}

void reverse (std::string s) {
	char temp;
	int len = s.size();

	for (int i = 0; i < (len >> 1); ++i) {
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}
