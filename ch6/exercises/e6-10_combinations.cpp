#include <iostream>

unsigned permutation (unsigned a, unsigned b);
unsigned fibonachi	(unsigned n);

int main () {
	std::cout << "Would you like permutation or compination?\n";
	std::cout << "Enter 'c' for combination\n";
	std::cout << "Enter 'p' for permutation\n";
	char choice = 0;
	while (choice != 'p' && choice != 'c') {
		std::cin >> choice;
		if (choice != 'p' && choice != 'c') 
			std::cout << "Invalid input posible choices are 'p' or 'c'\n";
	}
	
	int a, b, result;
	a = b = result = 0;
	std::cout << "Enter a total number of choices: ";
	while (a <= 0) {
		std::cin >> a;
		if (a < 0)
			std::cout << "Number of choices cannot be less than 1\n";
	}
	std::cout << "Enter a number of picks from " << a << " choices: ";
	
	while (b < 1 || b > a) {
		std::cin >> b;
		if (b < 1)
			std::cout << "Number of picks cannot be 0\n";
		
		if (b > a)
			std::cout << "Number of picks cannot be greather than number of choices.";
	}

	result = permutation (a, b);

	if (choice == 'c')
		result = result / fibonachi (b);

	std::cout << "Result is " << result << "\n";
		
}

unsigned permutation  (unsigned a, unsigned b) {
	return fibonachi (a)/fibonachi(a - b);
}

unsigned fibonachi (unsigned i) {
	if (i <= 1)
		return 1;

	return i * fibonachi(i - 1);
}
