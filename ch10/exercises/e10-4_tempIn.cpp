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

	if (!ist)
		std::cerr << "Cannot open onput file " << fname << "\n";

	std::vector<Reading> temps;
	int hour;
	double temperature;
	char open, close, comma;
	while (ist >> open >> hour >> comma >>  temperature >> close) {
		if (open != '(' && comma != ',' && close != ')') {
			std::cerr << "Formatting error\n";
			continue;
		}

		if (hour < 0 || hour > 23) {
			std::cerr << "Hour cannot be negative or greater than 23\n";
			continue;
		}

		temps.push_back(Reading (hour,temperature));
	}

	for (int i = 0; i < temps.size(); ++i)
		std::cout << "(" << temps[i].hour << "," << temps[i].temperature << ")\n";

	return 0;
}
