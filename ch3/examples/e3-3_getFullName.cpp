#include <iostream>

int main (void) {
	std::cout << "Please enter your first and last name\n";

	std::string firstName;
	std::string lastName;

	std::cin >> firstName >> lastName;

	std::cout << "Hello, " << firstName << " " << lastName << "!\n";

	return 0;
}
