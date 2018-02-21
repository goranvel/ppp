#include <iostream>
#include <cmath>

constexpr double pitagora (int a, int b);
constexpr bool isSquare (int a, int b);
int getInt (int a);

int main (void) {
	constexpr double x = 3;
	constexpr double y = 4;
	std::cout << pitagora(x, y) << "\n";

	int a = getInt (x);
	int b = 5;
	std::cout << isSquare (a, b) << "\n";
	return 0;
}

int getInt (int a) {
	a * 5 / (2+3);
	return a;
}
constexpr double pitagora (int a, int b) {
	return std::sqrt(a*a + b*b);
}

constexpr bool isSquare (int a, int b) {
/*	while (!int(pitagora (a, b)) % 5 != 0) {
		return true;
	} // THIS IS ILLIGAL */

	return ((int) pitagora (a, b)) % 5 ? true : false;
}
