#include <iostream>

// this version initializes variables first name and age
int main (void) {
	std::cout << "Please enter your first name and age\n";

	std::string firstName = "<first name>";
	int age = 0;

	std::cin >> firstName >> age;

	std::cout << "Hello, " << firstName << " (age " << age << ")\n";

	return 0;
}
