#include <iostream>

int main (void) {
//	int i1 = 0, i2 = 0;
	double d1 = 0, max = 0, min = ~(1 << 31), empty; // d2 = 0;
	
	while (std::cin >> d1) {
		if (d1 > max) {
			max = d1;
			std::cout << d1 << " is largest number so far\n";
		} else if (d1 < min) {
			min = d1;
			std::cout << d1 << " is smallest number so far\n";
		}
	}

	return 0;
}
