#include <iostream>
#include <fstream>

int main (void) {
	std::string inFile1, inFile2, outFile;

	std::cout << "Please enter first input file: ";
	std::cin >> inFile1;

	std::cout << "\nPlease enter second input file name: ";
	std::cin >> inFile2;

	std::cout << "\nPlease enter output file name: ";
	std::cin >> outFile;

	std::ifstream ifs1 (inFile1.c_str(), std::ios::binary);
	std::ifstream ifs2 (inFile2.c_str(), std::ios::binary);

	std::ofstream ofs (outFile.c_str(), std::ios::binary);
	char data;

	while (ifs1.get(data))
		ofs.put(data);

	while (ifs2.get(data))
		ofs.put(data);
	
	return 0;
}
