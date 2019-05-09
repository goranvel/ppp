#include <iostream>
#include <fstream>

int main (void) {
	std::cout << "Enter file name: ";
	std::string fname;
	std::cin >> fname;
	std::ifstream ifs (fname.c_str());
	int sum = 0;
	if (!ifs)
		std::cerr << "ERROR: Cannot open file " << fname << "\n";

	for (int x; ifs >> x; sum += x);

	std::cout << sum << "\n";
	return 0;
}
