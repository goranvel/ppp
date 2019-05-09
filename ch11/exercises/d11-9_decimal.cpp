#include <iostream>

int main (void) {
	double d = 1234567.89;

	std::cout << d << "\n";
	std::cout << std::fixed << d << "\n";
	std::cout << std::scientific << d << "\n";
//	std::cout << std::defaultfloat << d << "\n";

	return 0;
}
