#include <iostream>
#include <stdexcept>

int main(void) {
	std::cout << "Please enter expression (we can hande + and -): ";

	int lval, rval;
	lval = rval = 0;
	char op;

	std::cin >> lval;

	if (!std::cin) {
		std::cerr << "No first operand";
		return -1;
	}

	for (char op; std::cin >> op;) {
		if (op != 'x')
			std::cin >> rval;

		if (!std::cin)
			std::cerr << "No second operand";

		switch (op) {
			case '+':
				lval += rval;
				break;
			case '-':
				lval -= rval;
				break;
			case '*':
				lval *= rval;
				break;
			case '/':
				lval /= rval;
				break;
			default :
				std::cout << "Result: " << lval << "\n";
				return 0;
		}
	}

	std::cerr << "Bad expression";

	return 0;
}
