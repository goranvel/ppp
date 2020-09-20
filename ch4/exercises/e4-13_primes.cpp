#include <iostream>
#include <vector>

int main (void) {
	std::vector<bool> primes (100, true);
	primes.at(0) = false;
	primes.at(1) = false;

	for (int i = 2; i * i < 100; ++i)
		if (primes.at (i))
			for (int j = 2 * i; j < 100; j += i)
				primes.at(j) = false;

	for (int i = 2; i < primes.size(); ++i)
		if (primes.at(i)) 
			std::cout << i << " ";

	return 0;
}
