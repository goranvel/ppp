#include <iostream>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>

bool contains (std::vector <std::string> v, std::string w);

int main (void) {
	std::string input;
	std::vector<std::string> dictionary;

	std::string fName;

	std::cout << "Enter input file name: ";
	std::cin >> fName;
	std::ifstream ifs (fName.c_str());

	std::cout << "Enter output file name: ";
	std::cin >> fName;
	std::ofstream ofs (fName.c_str());

	int n = 1;
	while (ifs.getline(input)) {
		for (int i = 0; i < input.size(); ++i) {
			if (input[i] == '-' && input[i-1] != ' ' && input[i+1] != ' ')
				continue;
		
			if (input[i] == '\'') {
				if (input[i+1] == 't' && input[i-1] == 'n') { 
					input[i-1] = ' ';
					input[i] = 'n';
					input[i + 1] = 'o';
					input += 't';
				}

				if (input[i+1] == 's') {
					input [i] = ' ';
					input [i+1] = 'i';
					input += 's';
				}

				if (input[i+1] == 'd') {
					input [i] = ' ';
					input [i+1] = 'd';
					input += "id";
				}
				
				if (input[i+1] == 'm') {
					input [i] = ' ';
					input [i+1] = 'a';
					input += "m";
				}

				if (input[i+1] == 'r' && input[i+2] == 'e') {
					input [i] = ' ';
					input [i+1] = 'a';
					input [i+2] = 'r';
					input += "e";
				}

				if (input[i+1] == 'l' && input[i+2] == 'l') {
					input [i] = ' ';
					input [i+1] = 'w';
					input [i+2] = 'i';
					input += "ll";
				}

			} else if (std::ispunct(input[i]))
				input[i] = ' ';
		}

		if (!contains(dictionary, input)) {
			dictionary.push_back(input);
//			std::sort (dictionary.begin(), dictionary.end());
		}
/*
		std::cout << n << " ";
		++n;
		if (!(n % 10))
			std::cout << '\n'; */
	}

	for (int i = 0; i < dictionary.size(); ++i)
		ofs << dictionary[i] << "\n";

	return 0;
}

bool contains (std::vector <std::string> v, std::string w) {
	for (int i = 0; i < v.size(); ++i)
		if (v[i] == w)
			return true;

	return false;
}

