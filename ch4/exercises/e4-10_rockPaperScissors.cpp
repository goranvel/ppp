#include <iostream>
#include <vector>

void RPS (int human, int computer);

int main (void) {
	std::string hChoice, cChoice;
	int humanNum, seed;
	
	while (hChoice != "end") {
		while	( hChoice != "papper"		&&
					hChoice != "rock"			&&	
					 hChoice != "scissors") {
			std::cout << "Enter your choice paper rock or scissors.\n";
			std::cin >> hChoice;
		}

		std::cout	<< "Enter seed: (1, 2 or 3): ";
		std::cin		>>	seed; 
		--seed;
		
		switch (seed) {
			case 0:
				cChoice = "rock";
				break;
			case 1: 
				cChoice = "papper";
				break;
			case 2:
				cChoice = "scissors";
				break;
		}

		if (hChoice == "rock")
			humanNum = 0;
		else if (hChoice == "papper")
			humanNum = 1;
		else
			humanNum = 2;



		if (seed == humanNum)
			std::cout << "Tie!!!\n";
		else if (humanNum - seed == 1 ||
						humanNum - seed == -2) {
			std::cout << "You won! You chose " << hChoice << " I chose " << cChoice;
			RPS (humanNum, seed);
			std::cout << "\n :(\n";
		} else {
			std::cout << "I won! You chose " << hChoice << " I chose " << cChoice;
			RPS (humanNum, seed);
			std::cout << "\n :)\n";
		}

		hChoice = "";

	}

	return 0;
}

void RPS (int h, int c) {
	if	((h == 0 && c == 1) ||
			(h == 1 && c == 0)) 
		std::cout << "Papper covers rocks.\n";
	else if	((h == 0 && c == 2) ||
					(h == 2 && c == 0))
		std::cout << "Rock crashes scissors.\n";
	else
		std::cout << "Scissors cut papper.\n";
}
