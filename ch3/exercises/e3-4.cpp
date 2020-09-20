#include <iostream>

int main () {
	int val1, val2;
	std::cout << "Please enter two numbers!!\n";

	std::cin >> val1 >> val2;

	if (val1 > val2)
		std::cout << "Val1 (" << val1 << ") is larger then val2 (" << val2 << ")\n";
	if (val2 > val1)
		std::cout << "Val2 (" << val2 << ") is larger then val1 (" << val1 << ")\n";
	if (val1 == val2)
		std::cout << "Val1 (" << val1 << ") and Val2 (" << val2 << ") are the same";

	return 0;
}
