#include <iostream>
#include <fstream>
#include <vector>

int main (void) {
	std::string fname;
	std::cout << "Enter input file name: ";
	std::cin >> fname;
	std::ifstream ifs (fname.c_str());

	if (!ifs)
		return -1;

	std::cout << "Enter output file name: ";
	std::cin >> fname;
	std::ofstream ofs (fname.c_str());

	std::vector<std::string> text;
	std::string word;
	while (ifs >> word) 
		text.push_back(word);

	for (int i = text.size() - 1; i >= 0; ofs << text[i], --i)
		if (i < text.size() - 1)
			ofs << " ";

	return 0;
}
