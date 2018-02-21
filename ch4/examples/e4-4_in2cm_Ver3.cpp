#include <iostream>

int main (void) {
	const double cm_per_inch = 2.54;	// number of centimeters in
														// an inch

	double length = 1;	// // lenght in inches or centimeter

	char unit = 0;
	std::cout << "Please enter a lenght followed by a unit (c or i)\n";
	std::cin >> length >> unit;

	switch (unit)  {
		case 'i':
			std::cout << length << "in = " << cm_per_inch * length << "cm\n";
			break;
		case 'c':	
			std::cout << length << "cm = " << length/cm_per_inch << "in\n";
			break;
		deafult :
			std::cout << "Sorry, I do not know a unit called " << unit << "\n";
	}
	
	return 0;
}
