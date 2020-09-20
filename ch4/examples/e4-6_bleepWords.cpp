#include <iostream>
#include <vector>

int main (void) {
	std::vector<std::string> bleeps;
	std::vector<std::string> words;

	bleeps.push_back("fuck");
	bleeps.push_back("shit");
	bleeps.push_back("piss");
	bleeps.push_back("cunt");
	bleeps.push_back("cocksucker");
	bleeps.push_back("motherfucker");
	bleeps.push_back("tits");

	for (std::string word; std::cin >> word; )
		for (std::string bleep : bleeps)
			if (bleep != word)
				words.push_back(word);
			else
				words.push_back ("BLEEP");
	

	for (std::string word : words)
		std::cout << word << "\n";

	return 0;
}
