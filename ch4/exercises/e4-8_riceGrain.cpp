#include <iostream>

int power2 (int);

int main (void) {
	long double doubleSum = 0;
	int intSum = 0;
	for (int i = 0; i < 64; ++i) {
		doubleSum += power2(i);
		intSum += power2(i);

		if (intSum >= 1000 && intSum <= 2000)
			std::cout << "For 1,000\t\tgrains you need  " <<  i << " squares\n";
		if (intSum >= 1000000 && intSum <= 2000000)
			std::cout << "For 1,000,000\t\tgrains you need\t" <<  i << " squares\n";
		if (intSum >= 1000000000 && intSum <= 2000000000)
			std::cout << "For 1,000,000,000\tgrains you need\t" <<  i << " squares\n";

	}

	std::cout <<	"Double grian sum\t"			<< doubleSum << 
						"\nIntiger grain count\t"	<< intSum << "\n";
	return 0;
}

int power2 (int power) {
	int pow = 1;
	for (; power; --power)
		pow *= 2;

	return pow;
}
