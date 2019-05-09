#include <iostream>

int main (void) {
	int a = 0;
	while (true) {
		std::cin >> a;
		if (std::cin.bad())
			std::cout << "Bad stream.";
		else if (std::cin.fail()) {
			std::cout << "Bad input.";
			std::cin.clear();
			for (char ch; std::cin >> ch;);
			if (!std::cin)
				std::cerr << "No input"; 
			std::cin.unget();
		} else 
			std::cout << "SUCCESS";
	}
	return 0;
}
