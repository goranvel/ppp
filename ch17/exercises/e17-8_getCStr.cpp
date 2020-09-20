#include <iostream>

int main (void) {
	char input;
	std::string string;
	int i = 0;
	while (std::cin >> input && input != '!') {
		string += input;
	}

	std::cout << string;
	return 0;
}
