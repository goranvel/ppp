#include <iostream>

int main (void) {
	int a = 0, b = 0;

	std::cout << "Please enter two integers\n";
	std::cin	 >> a >> b;

	if (a < b)	// contdition
					// 1st alternative (taken if condition is true) 
		std::cout << "max (" << a << "," << b << ") is " << b << "\n";
	else			// 2nd alternative (taken if condition is false)
		std::cout << "max (" << a << "," << b << ") is " << a << "\n";

	return 0;
}
