#include <iostream>
#include <sstream>

double str_to_double (std::string st) {
	std::istringstream iss (st);

	double d;
	iss >> d;
	if (!iss)
		std::cerr << "\nFormatting error, no double in " <<  st;

	return d;
}

int main (void) {
	std::string d1 = "0.15";
	std::string d2 = "5e-3";
	std::string d3 = "twelve point three";

	std::cout << str_to_double (d1) << "\n";
	std::cout << str_to_double (d2) << "\n";
	std::cout << str_to_double (d3) << "\n";

	return 0;
}
