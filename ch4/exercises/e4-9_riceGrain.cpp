#include <iostream>
#include <iomanip> // for formating output

int power2 (int);

int main (void) {
	long double doubleSum = 0;
	int intSum = 0;
	unsigned unsignedInt = 0;
	unsigned long unsignedLong = 0;
	std::cout <<	"Square\t| Double\t| Intiger\t| \n";
	std::cout <<	"--------+---------------+-----------\n";

	for (int i = 0; i < 64; ++i) {
		doubleSum += power2(i);
		unsignedInt += power2(i);
		unsignedLong += power2(i);
		intSum = unsignedLong; 
		std::cout	<< std::setw(7) << std::right << i				<< " | " 
						<< std::setw(14) << std::left << doubleSum	<< "| "
						<< intSum << "\n";
	}


	return 0;
}

int power2 (int power) {
	int pow = 1;
	for (; power; --power)
		pow *= 2;

	return pow;
}
