#include <iostream>

int main (void) {
	int fib = 1, prev1 = 1, prev2 = 0;
	int cnt = 55;

	std::cout << "Please enter how many numbers of Fibonacci sequence you want? ";
	while (cnt > 46) { // 46th fibonachi sequence can be represented by int
		std::cin >> cnt;
		if (cnt > 46) {
			std::cerr << "Out of range of Integer\n";
			return -1;
		}
	}

	for (int i = 0; i < cnt; ++i) {
		std::cout << fib << " ";
		fib = prev1 + prev2;
		prev2 = prev1;
		prev1 = fib;

	}

	fib = 4, prev1 = 2, prev2 = 1;
	while (prev1 > prev2) {
		fib = prev1 + prev2;
		prev2 = prev1;
		prev1 = fib;
	}

	std::cout << "\n" << prev2 << "\n";

	return 0;
}
