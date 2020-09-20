#include <iostream>
#include <fstream>

int main (void) {
	std::cout << "Please enter int file name: ";
	std::string fname;
	std::cin >> fname;
	std::ifstream isf (fname.c_str()); //, std::ifstream::in);

	if (!isf) 
		std::cerr << "Can't open file " << fname << "\n";

	std::cout << "Please enter output file name: ";
	std::cin >> fname;
	std::ofstream osf (fname.c_str()); //, std::ifstream::in);

	if (!osf) 
		std::cerr << "Can't open file " << fname << "\n";

	return 0;
}
