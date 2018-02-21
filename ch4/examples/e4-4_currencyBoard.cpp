#include <iostream>

int main (void) {
	const double USD2Yen = 0.008820532053, USD2Kroner = 0.152435, USD2Pound = 1.29200;

	double ammount = 0;	

	char currency = 0;
	std::cout << "Please enter a ammount followed by a currency symbol (y, k, p)\n";
	std::cin >> ammount >> currency;

	if (currency == 'y')
		std::cout << ammount << " yen = "		<< ammount * USD2Yen		<< " USD\n";
	else if (currency == 'k')
		std::cout << ammount << " kroner = "	<< ammount * USD2Kroner	<< " USD\n";
	else if (currency == 'p')
		std::cout << ammount  << " punds = "	<< ammount * USD2Pound	<< " USDin\n";
	else
		std::cout << "Unknown currency " << currency << "\n";
	return 0;
}
