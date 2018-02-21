#include <iostream>

// this version is baset up on Version 2 and prints out how old somebodi is in months
int main (void) {
	std::cout << "Please enter your first name and age\n";

	std::string firstName = "<first name>";
	double age = 0;

	std::cin >> firstName >> age;

	std::cout << "Hello, " << firstName << " (age " << age * 12 << ")\n";

	return 0;
}
