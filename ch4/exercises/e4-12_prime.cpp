#include <iostream>
#include <vector>
#include <iomanip> // REMEBER TO INCLUDE FOR FORMATTING

int main (void) {
	std::vector<int> primes;
	primes.push_back(2);
	int max = 0;

	std::cout << "Enter maximum of the range: ";
	std::cin >> max;

	for (int i = 3; i < 100; i += 2) {
		int j = 3;

		for (; j * j < i; j += 2) {
			if (i % j == 0) {
				break;
			}
		}

		if ( j * j > i)
			primes.push_back (i);
	}

	for (int i = 0; i < primes.size(); ++i) {
		std::cout << std::setw(2) << primes.at(i);
		if (!((i + 1) % 10) && i)
			std::cout << "\n";
		else 
			std::cout << " ";
	}

	std::cout << "\n";
	return 0;
}
