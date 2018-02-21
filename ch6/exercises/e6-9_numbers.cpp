#include <iostream>

int main () {
	int thousand = 0, hundreed = 0, ten = 0, one = 0;
	char input = 0;
	for (int i = 0; std::cin >> input && i < 4; ++i) {
		if (input < '0' || input > '9') {
			std::cout << "non digit character.\n";
			break;
		}

		if (3 <= i)
			thousand = hundreed;
		if (2 <= i)
			hundreed = ten;
		if (1 <= i)
			ten = one;
	
			one = input - '0';
	}

	if (thousand > 0) {
		std::cout << thousand << " thousand";
		if (thousand > 1)
			std::cout << "s";

		std::cout << " ";
	}
		
	if (hundreed > 0) {
		std::cout << hundreed << " hundreed";
		if (hundreed > 1)
			std::cout << "s";

		std::cout << " ";
	}

	if (ten > 0) {
		std::cout << ten << " ten";
		if (ten > 1)
			std::cout << "s";

		std::cout << " ";
	}
		
	if (one > 0) {
		std::cout << one << " hundreed";
		if (one > 1) 
			std::cout << "s";
	}


	return 0;
}
