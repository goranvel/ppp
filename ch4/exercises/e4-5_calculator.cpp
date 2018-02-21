#include <iostream>

int main (void) {
	int val1, val2;
	char op;

	while (std::cin >> val1 >> val2 >> op)  {
		std::cout << val1 << " " << op << " " << val2 << " = ";
		if (op == '+')
			std::cout << val1 + val2;
		else if (op == '-')
			std::cout << val1 - val2;
		else if (op == '*')
			std::cout << val1 * val2;
		else if (op == '/')
			std::cout << val1 / val2;
	}

	return 0;
}
