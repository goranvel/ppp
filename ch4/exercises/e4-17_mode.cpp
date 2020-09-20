#include <iostream>
#include <vector>
#include <algorithm>

int main (void) {
	std::vector<std::string> words;
	int modeCnt = 1;
	std::string word, mode, min, max;

	while (std::cin >> word)
		words.push_back (word);

	std::sort (words.begin(), words.end());

	for (int i = 1, cnt = 1; i < words.size(); ++i) {
		if (words.at(i) == words.at(i - 1))
			++cnt;
		else
			cnt = 1;

		if (cnt > modeCnt) {
			mode = words.at(i);
			modeCnt = cnt;
		}
	}

	std::cout << "Minimum is " << words.at(0) << "\n";
	std::cout << "Maximum is " << words.at(words.size() - 1) << "\n";
	std::cout << "Mode is " << mode << " with " << modeCnt << " occurances";

	return 0;
}
