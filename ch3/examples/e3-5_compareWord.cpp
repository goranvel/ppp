#include <iostream>

int main (void) {
	std::string previouse = "";

	std::string current = "";

	while (std::cin >> current) {
		if (previouse == current)
			std::cout << "repeated word: " << current << '\n';
	
		previouse = current;
	}

	return 0;
}
