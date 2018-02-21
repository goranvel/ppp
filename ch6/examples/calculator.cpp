#include <iostream>

int main(void) {
	std::cout << "Please enter expression (we can hande + and -): ";

	int lval, rval, res;
	lval = rval = res = 0;
	char op;

	std::cin>>lval>>op>>rval;		// read something like 1 + 3

	if (op == '+')
		res = lval + rval;
	else if (op == '-')
		res = lval - rval;

	std::cout << "Result: " << res << "\n";

	return 0;
}
