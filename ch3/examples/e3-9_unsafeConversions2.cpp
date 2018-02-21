#include <iostream>

int main (void) {
	double d = 0;
	while (std::cin >> d) {
		int i	 = d;
		char c = i;
		int i2 = c;
		
		std::cout	<< "d = " << d	<< '\n'
						<< "i = " << i	<< '\n'
						<< "i2 = " << i2	<< '\n'
						<< "char(" << c << ")\n";
	}

	return 0;
}
