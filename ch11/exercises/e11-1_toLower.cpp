#include <iostream>
#include <fstream>
// #include <cctype>

void myToLower (char& ch) {
	if (ch >= 'A' && ch <= 'Z')	
		ch |= 0x20;
}

void myToUpper (char& ch) {
	if (ch >= 'a' && ch <= 'z')	
		ch &= 0xcf;
}


int main (void) {
	std::string fName = "in.txt";
	std::cout << "Enter input file name: ";
	std::cin >> fName;
	std::ifstream ifs (fName.c_str());
	std::cout << "Enter input file name: ";
	std::cin >> fName;
	std::ofstream ofs (fName.c_str());

	char ch;
	while (ifs.get(ch)) {
		myToLower (ch);
		ofs << ch;
	}

	return 0;
}
