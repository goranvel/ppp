#include <iostream>
#include <vector>

int main (void) {
	std::vector <std::string> names;
	std::vector <int> scores;
	std::string name;
	int score = -1;
	std::cout << "Enter name followed by score\n";
	std::cout << "Type NoName and 0 to exit\n";

	for (;std::cin >> name >> score && name != "NoName" && score != 0;) {
		for (int i = 0; i < names.size(); ++i)
			if (name == names.at(i)) {
				std::cout << "Double entries.\n";
				return 0;
			}
		names.push_back(name);
		scores.push_back (score);

	}
	
	std::cout << "Enter score you want to look for: ";
	std::cin >> score;
	bool found = false;

	for (int i = 0; i < scores.size(); ++i)
		if (score == scores.at(i)) {
			std::cout << names.at(i) << " has score of " << scores.at(i) << "\n";
			found = true;
		}

	if (!found)
		std::cout << "No person with score of " << score << " was found.\n";

	return 0;
}
