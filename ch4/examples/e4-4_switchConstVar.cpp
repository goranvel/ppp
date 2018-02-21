#include <iostream>

int main (void) {	// case labels must be constants
	// define alternatives
	int y = 'y';
	const char n = 'n';
	constexpr char m = '?';

	std::cout << "Do you like fish?\n";

	char a;
	std::cin >> a;

	switch (a) {
		case n :
			std::cout << "NO I AM NOT HERE";
			break;
		case 'y' :
			std::cout << "yeah";
			break;
		case m :
			std::cout << "Hello";
			break;
		default :
			std::cout << ":)";
	}

	return 0;
}
