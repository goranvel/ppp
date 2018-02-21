#include <iostream>

double ctof (double c);
double ftoc (double f);

int main (void) {
	try {
		std::cout << ctof(-275.15) << "\n";
		std::cout << ftoc(70) << "\n";
	} catch (const char *e) {
		std::cout << e;
	}
	return 0;
}

double ctof (double c) {
	if (c < -273.15)
		throw "Everything is falling appart!\n";
	return c * 9 / 5 + 32;
}

double ftoc (double f) {
	if (f < -459.67)
		throw "Everything is falling appart!\n";

	return (f - 32) * 5/9;
}
