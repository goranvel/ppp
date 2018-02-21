#include <iostream>

int main (void) {
	std::cout << "Please enter your first name and age\n";

	int age;
	std::string firstName;

	std::cin >> firstName;
	std::cin >> age;

	std::cout << "Hello, " << firstName << " (age " << age << ")\n";

	return 0;
}
