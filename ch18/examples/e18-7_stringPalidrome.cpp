#include <iostream>

bool is_palindrome (const std::string&);

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
