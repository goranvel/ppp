#include <iostream>

int main (void) {
	int d, h, o;
	std::cin >> d >> std::hex >> h >> std::oct >> o;

	std::cout	<< d << "\n"
					<< h << "\n"
					<< o << "\n\n";

	return 0;
}
