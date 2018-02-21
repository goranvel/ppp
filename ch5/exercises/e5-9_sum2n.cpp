#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

int main (void) {
	std::vector<int> numbers;
	int cnt = 0;
	unsigned number = 0, sum = 0;

	std::cout << "Please enter the number of values you want to sum: ";
	while (std::cin >> cnt && cnt  < 1)
		if (cnt < 1) 
			std::cerr << "Sum count cannot be less than 1";

	std::cout << "Please enter some integers (press '|' to stop): ";
	while ((std::cin >> number))
		numbers.push_back(number);

	if (!numbers.size()) {
		std::cerr << "There was no numbers inserted.";
		return 3;
	}

	if (cnt > numbers.size()) {
		std::cerr << "Sum count cannot be greater than count of number of elements entered";
		return 1;
	}


	for (int i = 0; i < cnt; ++i)
		sum += numbers.at(i);

	if (sum <= ~(0x1 << 31)) {
		std::cout << "Sum of ";
		for (int i = 0; i < cnt; ++i)
			std::cout << numbers.at(i) << " ";

		std::cout << "is " << sum << '\n';
	} else {
		std::cout << "Sum cannot be larger than maximum integer value (2 ^ 31 - 1)";
		return 2;
	}

	

	return 0;
}
