#include <iostream>

int main (void) {
	std::cout << "Spell out the number: ";
	std::string num;
	
	std::cin >> num;

	if (num == "zero")
		std::cout << 0;
	if (num == "one")
		std::cout << 1;
	if (num == "two")
		std::cout << 2;
	if (num == "three")
		std::cout << 3;
	if (num == "four")
		std::cout << 4;
	if (num == "five")
		std::cout << 5;
	if (num == "six")
		std::cout << 6;
	if (num == "seven")
		std::cout << 7;
	if (num == "eight")
		std::cout << 8;
	if (num == "nine")
		std::cout << 9;
	if (num >= "0" && num <= "9")
		std::cout << num;
	else
		std::cout << "not a number I know";

	std::cout << '\n';

	return 0;
}
