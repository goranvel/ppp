#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

int main (void) {
	std::vector<int> randNumbers(4, 0);
	int num = 1234, bullCnt = 0, cowCnt = 0;

	srand(time(NULL));

	randNumbers[0] = rand() % 10;
	while ((	randNumbers[1] = rand() % 10) == randNumbers[0] );
	while ((	randNumbers[2] = rand() % 10) == randNumbers[0] ||
					randNumbers[2] == randNumbers[1] );
	while ((	randNumbers[3] = rand() % 10) == randNumbers[0] || 
					randNumbers[3] == randNumbers[1] ||
						randNumbers[3] == randNumbers[2] );
/*
	for (int i = 0; i < randNumbers.size(); ++i)
		std::cout << randNumbers.at(i);
	
	std::cout << "\n";

//	std::please 
//	std::cin >> num

	for (int i = 0; i < numbers.size(); ++i)
		std::cout << numbers.at(i);
	
	std::cout << "\n"; */
	std::cout << "Please enter 4 digit number.\n";

	while ( num != -1) {
		std::cin >> num; 
		std::vector<int> numbers(4);
		numbers[0] = num/1000; 
		num = num % 1000;
		numbers[1] = num/100; 
		num = num % 100;
		numbers[2] = num/10; 
		num = num % 10;
		numbers[3] = num; 
	
		for (int i = 0; i < numbers.size(); ++i)
			if (numbers[i] == randNumbers[i])
				++bullCnt;
			else
				for (int j = 0; j < randNumbers.size(); ++j)
					if (numbers[i] == randNumbers[j])
						++cowCnt;

		if (bullCnt > 0) {
			std::cout << bullCnt << " bull";
			if (bullCnt > 1)
				std::cout << "s";

			if (cowCnt > 0)
				std::cout << " and ";
			else
				std::cout << ".\n";
		}

		if (cowCnt > 0) {
			std::cout << cowCnt << " cow";
			if (cowCnt > 1)
				std::cout << "s";
			std::cout << ".\n";
		}

		if (bullCnt == 4) {
			std::cout << "Congrats you got it!!!!\n";	
			for (int i = 0; i < randNumbers.size(); ++i)
				std::cout << randNumbers.at(i);
	
			std::cout << "\n";
			return 0;
		}
		bullCnt = 0;
		cowCnt = 0;
		std::cout << "Try again!\n";
	}

	return 0;
}
