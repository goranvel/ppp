#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> lengths(const std::vector<std::string>& s);
void minMax (const std::vector<int>& l, int& min, int& max);

int main (void) {
	std::vector<std::string> words;
	std::string word;
	std::vector<int> l;
	while (std::cin >> word) {
		words.push_back (word);
	}

	l = lengths (words);
	int min = 0, max = 0;
	minMax (l, min, max);
	std::cout << "Maximum lenght is: " << max;
	std::cout << " minimum lenght is : " << min;

	sort(words.begin(), words.end());

	std::cout << " alphabetically start is " << words[0] << " and the end is " << words[words.size() - 1] << "\n";

	return 0;
}

std::vector<int> lengths(const std::vector<std::string>& s) {
	std::vector<int> l;
	for (int i = 0; i < s.size(); ++i)
		l.push_back(s[i].size());
	
	return l;
}
		
void  minMax (const std::vector<int>& l, int& min, int& max) {
	max = 0, min = -1;
	for (int i = 0; i < l.size(); ++i) {
		if (l[i] > max)
			max = l[i];
		if (min == -1 || l[i] < min)
			min = l[i];
	}
}
