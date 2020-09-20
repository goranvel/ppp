#include <iostream>

// convert from miles to km
int main (void) {
	std::cout << "Enter milage: ";
	double milage = 0;

	std::cin >> milage;
	
	std::cout << milage << " miles is " << milage * 1.609 << " kilometers.";

	return 0;
}
