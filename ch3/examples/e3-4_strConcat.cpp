#include <iostream>

int main (void) {
	std::string firstName, lastName, fullName;

	std::cout << "Please enter first name: ";
	std::cin >> firstName;

	std::cout << "Please enter last name: ";
	std::cin >> lastName;

	fullName = firstName + " " + lastName;

	std::cout << "Hello, " << fullName << "!\n";

	return 0;
}
