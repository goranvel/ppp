#include <iostream>

int main (void) {
	std::cin.unsetf(std::ios::dec);
	std::cin.unsetf(std::ios::hex);
	std::cin.unsetf(std::ios::oct);

	int a, b, c, d;
	std::cin >> a >> std::hex >> b >> std::oct >> c >> d;
	std::cout << a << "\t" << b << "\t" << c << "\t" << d << "\n";

	return 0;
}
