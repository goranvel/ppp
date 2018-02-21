#include <iostream>

constexpr int max = 100;

void use (int n);

int main (void) {
	use (5);

	return 0;
}

void use (int n) {
	constexpr int	c1 = max	+ 7;		// OK c1 is 107
//	constexpr int	c2 = n	+ 7;		// NOT OK n is not constant
	const int		c3 = n	+ 7;		// OK since const is declared constatn on runtime
												// not on comilpe time
	
//	c1 += 7; cannot be done
//	c3 += 7;	cannot be doee

	std::cout << "Number: " << c1 << " " << c3;
}
