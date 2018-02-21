#include <iostream>

int main (void) {
	int number = 50, upper = 101, lower = 1;
	char answer = 'n';

	while (upper >= number && lower < number) {
//		std::cout << "Is this number less than " << number << "? ";
		std::cin	 >> answer;

		if (answer == 'y')
			upper = number;
		else if (answer == 'n')
			lower = number;
		 else {
			std::cout << "Wrong input please answer with y or n.\n";
			continue;
		} 

		number = (upper + lower) >> 1;

//		std::cout << "Lower: " << lower << "Upper " << upper << "\n";

	}

	std::cout << "Number is: " << number << "\n";

	return 0;
}
