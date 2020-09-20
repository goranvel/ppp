#include <iostream>
#include <cmath>

double quadraticPlus		(int a, int b, int c);
double quadraticMinus	(int a, int b, int c);

int main (void) {
	int a = 0, b = 0, c = 0;
	while (!a /* same as a != 0 */) {
		std::cout << "Enter a, b and c for a * x^2 + b * a + c = 0: \n";
		std::cin >> a >> b >> c;

		if (!a) 
			std::cout << "a cannot be 0.\n";
	}

	try {
		std::cout << "x is " << quadraticPlus	(a, b, c) << " or " <<  quadraticMinus (a, b, c) << "\n";
	} catch (const char *e) {
		std::cerr << e << "\n";
	}

	return 0;
}

double quadraticPlus		(int a, int b, int c) {
	double root = b * b - 4 * a * c;

	if (root < 0)
		throw "This program cannot handle imaginary numbers";

	return -b + sqrt(root) / 2 / a;
}

double quadraticMinus	(int a, int b, int c) {
	double root = b * b - 4 * a * c;

	if (root < 0)
		throw "This program cannot handle imaginary numbers";

	return -b - sqrt(root) / 2 / a;

}
