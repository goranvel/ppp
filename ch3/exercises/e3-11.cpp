#include <iostream>

int main (void) {
	int pennies, nickels, dimes, quarters, halfs;

	std::cout << "Please enter how many pennies you have:\t\t";
	std::cin >> pennies;

	std::cout << "Please enter how many nickels you have:\t\t";
	std::cin >> nickels;

	std::cout << "Please enter how many dimes you have:\t\t";
	std::cin >> dimes;

	std::cout << "Please enter how many quarters you have:\t";
	std::cin >> quarters;

	std::cout << "Please enter how many half dollars you have:\t";
	std::cin >> halfs;

	std::cout ;

	if (pennies > 0) {
		std::cout << "You have " << pennies << " pennie";
		if (pennies > 1)
			std::cout << 's';

		std::cout << "\n";
	}

	if (nickels > 0) {
		std::cout << "You have " << nickels << " nickel";
		if (nickels > 1)
			std::cout << 's';

		std::cout << "\n";
	}

	if (dimes > 0) {
		std::cout << "You have " << dimes << " dime";
		if (dimes > 1)
			std::cout << 's';

		std::cout << "\n";
	}

	if (quarters > 0) {
		std::cout << "You have " << quarters << " quarter";
		if (quarters > 1)
			std::cout << 's';

		std::cout << "\n";
	}

	if (halfs > 0) {
		std::cout << "You have " << halfs << " half dolar coin";
		if (halfs > 1)
			std::cout << 's';

		std::cout << "\n";
	}

	std::cout << '\n';

	int sum = pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * halfs;
	std::cout	<< "The value of all of your coins is: $"
					<<	sum/100
					<< "." << sum % 100 
					<< " (" << sum << " cents).\n";

	return 0;
}
