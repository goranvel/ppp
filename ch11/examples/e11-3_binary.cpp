#include <iostream>
#include <fstream>
#include <vector>

int main (void) {
	std::cout << "Please enter input file name\n";

	std::string fname;
	std::cin >> fname;
	std::ifstream ifs (fname.c_str(), std::ios::binary);

	if (!ifs)
		std::cerr << "Cannot open file " << fname << " for reading.\n";

	std::cout << "Please enter output file name\n";
	std::cin >> fname;
	std::ofstream ofs (fname.c_str(), std::ios::binary);

	if (!ifs)
		std::cerr << "Cannot open file " << fname << " for writting.\n";

	std::vector<char> v;

	for (char x; ifs.read(&x, sizeof(char));) {
		v.push_back(x);
	}

	for (int i = 0; i < v.size(); ++i) {
		ofs.write(&v[i], sizeof(char));
	}

	return 0;
}
