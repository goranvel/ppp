#include <iostream>
#include <fstream>
#include <vector>

struct Reading {
	int hour;
	double temperature;

	Reading (int h, double t) : hour (h), temperature (t) {
	};
};

int main (void) {
	std::cout << "Please enter input file name: ";
	std::string fname;
	std::cin >> fname;
	std::ifstream ist (fname.c_str(), std::ios::in);

	if (!ist) {
		if (ist.bad()) {
			std::cerr << "Cannot open input file " << fname << "\n";
			return -1;
		}
		if (ist.fail()) 
			std::cerr << "Cannot read input file " << fname << "\n";
		
		ist.clear();
	}

	std::cout << "Please enter input file name: ";
	std::cin >> fname;
	std::ofstream ost (fname.c_str(), std::ios::out);

	if (!ost)
		std::cerr << "Cannot open output file " << fname << "\n";

	std::vector<Reading> temps;
	int hour;
	double temperature;

	while (ist >> hour >> temperature) {
		if (hour < 0 || hour > 23)
			std::cerr << "Hour cannot be negative or greater than 23\n";

		temps.push_back(Reading (hour,temperature));
	}

	for (int i = 0; i < temps.size(); ++i)
		ost << "(" << temps[i].hour << "," << temps[i].temperature << ")\n";

	return 0;
}
