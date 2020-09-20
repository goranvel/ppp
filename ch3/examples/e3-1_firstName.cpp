#include <iostream>

int main (void) {
	std::cout << "Please enter your irst name (followed by 'enter')\n";

	std::string firstName;
	std::cin >> firstName;

	std::cout << "Hello, " << firstName << "\n";

	return 0;
}	
