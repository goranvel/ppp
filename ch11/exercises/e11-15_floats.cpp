#include <iostream>
#include <fstream>
#include <iomanip>

int main (void) {
	std::string fname;

	std::cout << "Please enter input file name:\n";
	std::cin >> fname;
	std::ifstream ifs (fname.c_str());

	std::cout << "Please enter output file name:\n";
	std::cin >> fname;
	std::ofstream ofs (fname.c_str());

	double d;
	while (ifs >> d) 
		ofs << std::setw(20) << std::setprecision(8) << d << "\n";
	return 0;
}
