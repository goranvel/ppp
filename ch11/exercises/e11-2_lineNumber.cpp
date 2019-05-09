#include <iostream>
#include <fstream>
#include <sstream>

int main (void) {
	std::string fName;
	std::cout << "Please enter the file name: ";
	std::cin >> fName;
	std::ifstream ifs (fName.c_str());
	std::istringstream iss;
	
	std::string word;
	std::cout << "Please enter the word to be found: ";
	std::cin >> word;
	std::string line;
	std::string words;
	int lineNo = 1;
	while (getline(ifs, line)) {
		iss.str(line);
		while (iss >> words) 
			if (words == word)
				std::cout << "Found word " << word << " on line " << lineNo << "\n";

		iss.clear();

		++lineNo;
	}
		
		
	return 0;
}
