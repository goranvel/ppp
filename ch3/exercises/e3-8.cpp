#include <iostream>

int main (void) {
	int number;

	std::cout	<< "Please enter a nubmer: ";	
	std::cin		>> number;

	std::cout	<< "Number " << number << " is ";
	if (number % 2)
		std::cout << "odd";
	else
		std::cout << "even";

	return 0;
}
