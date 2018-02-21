#include <iostream>

double ctok (double c);

int main (void) {
	double c = -275;	// declare input variable

	std::cout << "Please enter temperature (in Celcius):\n";
	std::cin >> c; // remove temprature to input variable

	try {
		double k = ctok (c);		// convert temperature
		std::cout << k << '\n';	// print out temperature;
	} catch (const char* e) {
		std::cout << "Ooops";
	}

	return 0;
}

double ctok (double c) {
	if (c < -273.15)
		throw "Damn everything is broke into pieces!";

	double k = c + 273.15;

	return k;
}
