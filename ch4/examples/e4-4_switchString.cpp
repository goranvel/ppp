#include <iostream>

int main (void) { // you can switch only on integers, chars or enum types
	std::string ans = "no";

	std::cout	<< "Do you like fish? (yes/no) ";
	std::cin		>> ans;
	switch (b) { // cannot be done because value has to be int based
		case true: // "yes":
			std::cout << "Yes!!!";
			break;
		case false: // "no":
			std::cout << "No!!!!";
			break;
	}

	return 0;
}
