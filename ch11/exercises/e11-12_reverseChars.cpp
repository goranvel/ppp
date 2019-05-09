#include <iostream>
#include <fstream>

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

	std::string text;
	char ch;
	while (ifs.get(ch)) 
		text += ch;

	for (int i = text.size() - 1; i > 0; --i, ofs << text[i]); // this solution is due to vim adding \n at the end of file

	return 0;
}
