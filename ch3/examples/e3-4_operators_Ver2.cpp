#include <iostream>
#include <cmath>

int main () {
	std::cout << "Please enter a floating point value: ";

	double n;
	std::cin >> n;
	
	std::cout	<< "\nn = "			<< n
					<< "\nn + 1 = "	<< n + 1
					<<	"\nn * 3 = "	<< n * 3
					<< "\nn * 2 = "	<< n * 2 << " " << n + n
					<< "\nn * n = "	<< n * n
					<< "\nn / 2 = "	<< n / 2 
					<< "\nsqrt(n) = "	<< sqrt(n)
					<< "\n";

	return 0;
}
