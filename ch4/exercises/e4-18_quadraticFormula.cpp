#include <iostream>
#include <cmath>

int main (void) {
	double negX, posX, a, b, c;

	while (std::cin >> a >> b >> c) {
	
		negX = (-b - sqrt (b * b- 4*a*c)) / (2 * a);
		posX = (-b + sqrt (b * b - 4*a*c)) / (2 * a);

		std :: cout << "x = " << posX << " x = " << negX;
	}

	return 0;
}
