#include <iostream>

int main () {
	double val1, val2;
	std::cout << "Please enter two numbers!!\n";

	std::cin >> val1 >> val2;

	if (val1 > val2)
		std::cout	<< "val1 (" << val1 
						<< ") is larger then val2 (" 
						<< val2 << ")\n";
	if (val2 > val1)
		std::cout	<< "val2 (" << val2 
						<< ") is larger then val1 (" 
						<< val1 << ")\n";
	if (val1 == val2)
		std::cout	<< "val1 (" << val1 
						<< ") and val2 (" 
						<< val2 << ") are the same";

	return 0;
}
