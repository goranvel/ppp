#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

int main (void) {
	std::vector<int> randNumbers(4, 0);
	std::vector<int> myNumbers(4, 0);
	int num = 1234, bullCnt = 0, cowCnt = 0, moveCnt = 0;

	srand(time(NULL));

	while (!(randNumbers[0] = rand() % 10));
	while ((	randNumbers[1] = rand() % 10) == randNumbers[0] );
	while ((	randNumbers[2] = rand() % 10) == randNumbers[0] ||
					randNumbers[2] == randNumbers[1] );
	while ((	randNumbers[3] = rand() % 10) == randNumbers[0] || 
					randNumbers[3] == randNumbers[1] ||
						randNumbers[3] == randNumbers[2] );

	std::cout << "Please enter number between 1000 and 10000: ";
	while (std::cin >> num) {
		cowCnt = 0, bullCnt = 0;
		if (num < 1000 || num > 9999) {
			std::cout << "Number must be between 1000 and 9999."
							"It cannot contain same digits";
			continue;
		}

		myNumbers[0] = num/1000; 
		num = num % 1000;
		myNumbers[1] = num/100; 
		num = num % 100;
		myNumbers[2] = num/10; 
		num = num % 10;
		myNumbers[3] = num; 

		if (	myNumbers[0] == myNumbers[1] || myNumbers[0] == myNumbers[2] || myNumbers[0] == myNumbers[3] ||
					myNumbers[1] == myNumbers[2] || myNumbers[1] == myNumbers[3] ||
						myNumbers[2] == myNumbers[3]) {
			std::cout << "Duplicate digits. Please try again: ";
			continue;
		}

		for (int i = 0; i < myNumbers.size(); ++i)
			if (myNumbers[i] == randNumbers[i])
				++bullCnt;
			else
				for (int j = 0; j < randNumbers.size(); ++j)
					if (myNumbers[i] == randNumbers[j])
						++cowCnt;

		if (bullCnt > 0 && bullCnt < 4) {
			std::cout << bullCnt << " bull";
			if (bullCnt > 1)
				std::cout << "s";

			if (cowCnt > 0)
				std::cout << " and ";
		}

		if (cowCnt > 0) {
			std::cout << cowCnt << " cow";
			if (cowCnt > 1)
				std::cout << "s";
		}

		if (cowCnt == 0 && bullCnt == 0)
			std::cout << "No mathces no caws no bulls";
		
		if (bullCnt == 4) {
			std::cout << "You won within " << moveCnt << " moves!";
			break;
		}
		std::cout << ".\n";
		std::cout << "Try again: ";
		
	}

	return 0;
}
