#include <iostream>

int main (void) {
	double d = 12.30456789;

	std::cout	<< std::fixed			<< d	<< "\n"
					<< std::scientific	<< d	<< "\n"
//					<< std::defaultfloat	<< d	// c++11 standard + part of it that is nto supported by this GCC version
												<< d	<< "\n";

	return 0;
}
