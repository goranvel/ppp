#include <iostream>

double ctok (double c);

int main (void) {
	double c = -275;	// declare input variable

	std::cout << "Please enter temperature (in Celcius)";
	while (c < -273.15)
		std::cin >> c; // remove temprature to input variable

	double k = ctok (c);		// convert temperature

	std::cout << k << '\n';	// print out temperature;
	return 0;
}

double ctok (double c) {
	double k = c + 273.15;

	return k;
}
