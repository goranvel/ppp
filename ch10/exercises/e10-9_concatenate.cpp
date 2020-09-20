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

	std::ifstream ifs1 (inFile1.c_str());
	std::ifstream ifs2 (inFile2.c_str());

	std::ofstream ofs (outFile.c_str());
	std::string data1, data2;
	ifs1 >> data1;
	ifs2 >> data2;

	while (ifs1 && ifs2) {
		if (data1 < data2) {
			while (data1 < data2 && !ifs1.fail()) {
				ofs << data1 << "\n";
				ifs1 >> data1;
			}
		} else {
			while (data1 > data2 && !ifs2.fail()) {
				ofs << data2 << "\n";
				ifs2 >> data2;
			}
		}
	} 

	if (ifs1.fail()) {
		ifs2.unget();
		while (ifs2 >> data2)
			ofs << data2 << "\n";
	}
	if (ifs2.fail()) {
		ifs1.unget();
		while (ifs1 >> data1)
			ofs << data1 << "\n";
	}

	return 0;
}
