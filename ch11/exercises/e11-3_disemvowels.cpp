#include <iostream>
#include <fstream>

bool isVowel (char c);

int main (void) {
	std::string fileName;
	std::cout	<< "Please enter an input file name: ";
	std::cin		>> fileName;
	std::ifstream ifs (fileName.c_str());
	std::string out	= ""; 
	char c;
	while (ifs.get(c) && c != EOF) {
		if (ifs.fail()) {
			std::cerr << "Input file error";
			return -1;
		}

		if (isVowel (c) || out[out.size() - 1] == ' ' && c == ' ')
			continue;

		out += c;
	}
	
	std::cout << out << "\n";
	return 0;
}

bool isVowel (char c) {
	if (c >= 'A' && c <= 'Z')
		c |= 0x20;

	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
