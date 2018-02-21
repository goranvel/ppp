#include <iostream>

int main (void) {
	int number_of_words = 0;

	std::string previous = "", current;

	while (std::cin >> current) {
		++number_of_words;

		if (previous == current)
			std::cout << "word number " << number_of_words << " repeated " << current << "\n";

		previous = current;
	}

	return 0;
}
