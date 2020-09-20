#include <iostream>
#include <vector>

int main (void) {
	int max = 0;
	std::cout << "Please enter up to what number you want primes printed ";
	std::cin >> max;
	
	std::vector<bool> primes (max, true);
	primes.at(0) = false;
	primes.at(1) = false;


	for (int i = 2; i * i < max; ++i)
		if (primes.at (i))
			for (int j = 2 * i; j < max; j += i)
				primes.at(j) = false;

	for (int i = 2; i < primes.size(); ++i)
		if (primes.at(i)) 
			std::cout << i << " ";

	return 0;
}
