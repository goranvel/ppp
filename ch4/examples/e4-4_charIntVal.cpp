#include <iostream>

// prints numberical value for characters
int main (void) {
	char c = 'a';

	while (c < 'z')  {
		std::cout << c << "\t" << c - 0 << '\n'; // c - 0 is convertion to int without cast
		++c;
	}

	return 0;
}
