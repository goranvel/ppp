#include <iostream>

int main (void) {
	std::string a, b, c;
	
//	std::cout << "\nPlease enter 3 numbers: ";

	std::cin >> a >> b >> c;

	if (a <= b && b <= c)
		std::cout << a << " " << b << " " << c;
	if (a <= c && c < b)
		std::cout << a << " " << c << " " << b;

	if (b < a && a <= c)
		std::cout << b << " " << a << " " << c;
	if (b <= c && c < a)
		std::cout << b << " " << c << " " << a;

	if (c < a && a <= b)
		std::cout << c << " " << a << " " << b;
	if (c < b && b < a)
		std::cout << c << " " << b << " " << a;

	std::cout << '\n';
	return 0;
}
