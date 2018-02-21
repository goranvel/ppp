#include <iostream>
#include <vector>

int main (void) {
	std::vector<double> numbers;
	int cnt = 0;
	double number = 0, sum = 0;

	std::cout << "Please enter the number of values you want to sum: ";
	while (std::cin >> cnt && cnt  < 1)
		if (cnt < 1) 
			std::cerr << "Sum count cannot be less than 1";

	std::cout << "Please enter some integers (press '|' to stop): ";
	while (std::cin >> number)
		numbers.push_back(number);

	if (cnt < numbers.size()) {
		std::cerr << "Sum count cannot be greater than count of number of elements entered";
		return 1;
	}
	
	std::cout << "The sum of ";
	for (int i = 0; i < cnt; ++i) {
		sum += numbers.at(i);
		std::cout << numbers.at(i) << " ";
	}

	std::cout << "is " << sum << '\n';

	return 0;
}
