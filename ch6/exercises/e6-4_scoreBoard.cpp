#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

class Name_value {
	public:
		Name_value (std::string n, int s) : name(n), score (s) {
		}

		std::string name;
		int score;
};

int main (void) {
	try {
		std::vector <Name_value> scores;
		std::string name;
		int score = -1; 
		std::cout << "Enter name followed by score\n";
		std::cout << "Type NoName and 0 to exit\n";

		for (;std::cin >> name >> score && name != "NoName" && score != 0;) {
			for (int i = 0; i < scores.size(); ++i)
				if (name == scores.at(i).name) 
					throw std::runtime_error ("Double entries.\n");

			scores.push_back (Name_value(name, score));
		}

		for (int i = 0; i < scores.size(); ++i) {
			std::cout << "Name " << scores.at(i).name << " has score of " << scores.at(i).score << ".\n";
		}
	} catch (std::runtime_error e) {
		std::cout << e.what() << "\n";
	} catch (...) {
		std::cout << "Exiting unknow error occured\n";
	}
   return 0;
}
