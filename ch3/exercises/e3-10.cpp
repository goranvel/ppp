#include <iostream>

int main (void) {
	std::string operation;
	double operand1, operand2;
	
	std::cout << "Please enter operation "
					"<op> <number> <number>"
					"Example:\n"
					"\t* 10.5 13.3\n";

	std::cin >> operation;
	std::cin >> operand1 >> operand2;

	if (operation == "*")
		std::cout << operand1 * operand2;
	else if (operation == "+")
		std::cout << operand1 + operand2;
	else if (operation == "/")
		std::cout << operand1 / operand2;
	else if (operation == "-")
		std::cout << operand1 - operand2;
	else	
		std::cout << "Not valid operation";

	return 0;
}
