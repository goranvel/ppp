#include <iostream>

int main (void) {
//	int i1 = 0, i2 = 0;
	double d1 = 0, d2 = 0;
	double diff = 1.0/100;
	
	while (std::cin >> d1) {
		std::cout << d1 << "\t" << d2 << "\n";
/*
		if (d1 != d2) {
			std::cout << "The smallest value is " << (d1 < d2 ? d1 : d2) << "\n";
			std::cout << "The biggest value is " << (d1 > d2 ? d1 : d2) << "\n";
		} else
			std::cout << "These numbers are equal\n";
*/
		if (d1 < d2)
			std::cout << "The smallest value is " << (d1 < d2 ? d1 : d2) << "\n";
		else if (d1 > d2)
			std::cout << "The biggest value is " << (d1 > d2 ? d1 : d2) << "\n";
		else if (d1 - d2 <= diff ||
						d2 - d1 <= diff)
			std::cout << "The numbers are almost equal\n";
		else
			std::cout << "These numbers are equal\n";
	 

	
	 }

	
	return 0;
}
