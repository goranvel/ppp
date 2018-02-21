#include <iostream>

double ctok (double c);
double ktoc (double k);

int main (void) {
	double count = -275;	// declare input variable
	char unit;

	std::cout << "Please enter temperature (followed by C or c for Celcius" 
						"and k or K for kelvin):\n";
	std::cin >> count >> unit; // remove temprature to input variable

	try {
		double conv = 0;
		if (unit == 'c' || unit == 'C')  
			conv = ctok (count);		// convert temperature
		else if (unit == 'k' || unit == 'K')  
			conv = ktoc (count);		// convert temperature
		else {
			std::cout << "Wrong unit!";
			return 0;
		}

		std::cout << conv << ((unit == 'c' || unit == 'C') ? " Kelvin" : " Celcius") 
				<< '\n';	// print out temperature;
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

double ktoc (double k) {
	if (k < 0)
		throw "Damn everything is broke into pieces!";

	return k - 273.15;
}

