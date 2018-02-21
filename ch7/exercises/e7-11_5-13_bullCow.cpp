#include <iostream>
#include <vector>
#include <ctime>
#include	<cstdlib>
#include <stdexcept>
#include <string>

std::string toString (int num);

class Result {
	public:
		int cows;
		int bulls;

		Result () : cows(0), bulls(0) {
		}

		Result (int c, int b) : cows (c), bulls (b) {
		}

		void print ();
		bool won ();
};

void Result::print () {
	std::cout << cows << " cow(s) " << bulls << " bull(s).\n";
}

bool Result::won () {
	return bulls == 4 ? true : false;
}

class Guess {
	public:
		std::vector<int> guess;
		Guess () : guess (0) {
			guess = std::vector<int> (4, 0);
		}

		Guess (int a, int b, int c, int d) {
			if (a == b || a == c || a == d || b == c || b == d ||	c == d)
				throw  std::runtime_error ("Duplicate number");
			guess = std::vector<int> (4, 0);

			guess[0] = a;
			guess[1] = b;
			guess[2] = c;
			guess[3] = d;
		}

		Result compare (Guess g);
		void random ();
		void print ();
};

Result Guess::compare (Guess g) {
	int bulls = 0, cows = 0;
	for (int i = 0; i < guess.size(); ++i)
		if (guess [i] == g.guess [i])
			++bulls;
		else
			for (int j = 0; j < guess.size(); ++j)
				if (guess[i] == g.guess [j])
					++cows;

	return Result (cows, bulls);
}

void Guess::random () {
	guess[0] = rand() % 10;
	while ((guess[1] = rand() % 10) == guess [0]);
	while ((guess[2] = rand() % 10) == guess [0] || guess[2] == guess[1]);
	while ((guess[3] = rand() % 10) == guess [0] || guess[3] == guess[2] || guess[3] == guess[1]);
}

void Guess::print () {
	std::cout << guess[0] << guess[1] << guess[2] << guess[3] << "\n";
}

int main (void) {
	try {
		int count = 0, mimi = ~0 & ~(1 << 31), num = 0;
		Guess rand;

		while (std::cin) {
			count = 0;
			srand (time (NULL));

			rand.random();
			rand.print();

			std::cout << "Please enter numbers between 0 and 9999.\n";
			while (std::cin >> num)
				try {
					count++;
					if (num < 0 || num > 9999) {
						std::cout << "Number must be between 0 ann 9999\n";
						continue;
					}

					Guess myGuess (num / 1000, (num % 1000) / 100, (num % 100) / 10, num % 10);
					Result r = rand.compare(myGuess);
					if (!r.won())
						r.print();
					else {
						if (mimi > count) {
							mimi = count;
							std::cout << "Good job this is your new record! " << mimi << "\n";
						}

						std::cout << "CONGRADULATION: You won!!!\n";

						std::cout << "Do you want to continue? (yes or no)\n";
						std::string cont = "no";
						std::cin >> cont;
						if (cont == "Yes" || cont == "yes") 
							break;
						else {
							std::cout << "Your best score is: " << mimi;
							return 0;
						}
					}
				} catch (std::runtime_error& ex) {
					std::cerr << ex.what() << "\n";
				}
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	} catch (...) {
		std::cerr << "Unknown exception\n";
	}

	return 0;
}
