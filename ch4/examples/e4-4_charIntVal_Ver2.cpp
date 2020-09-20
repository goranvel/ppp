#include <iostream>

// prints numberical value for characters
int main (void) {
	for (char c = 'a'; c < 'z'; ++c) {
		std::cout << c << "\t" << c - 0 << '\n'; // c - 0 is convertion to int without cast
	}

	return 0;
}
