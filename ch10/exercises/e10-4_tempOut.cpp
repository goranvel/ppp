#include <iostream>
#include <fstream>
#include <vector>

struct Reading {
	int hour;
	double temperature;
	char unit;

	Reading (int h, double t, char u) : hour (h), temperature (t), unit (u) {
	};
};

int main (void) {

	std::cout << "Please enter output file name: ";
	std::string fname;
	std::cin >> fname;
	std::ofstream ost (fname.c_str(), std::ios::out);

	if (!ost)
		std::cerr << "Cannot open output file " << fname << "\n";

	std::vector<Reading> temps;
	int hour;
	double temperature;
	char unit;
	while (std::cin >> hour >> temperature >> unit) {
		if (hour < 0 || hour > 23) {
			std::cerr << "Hour cannot be negative or greater than 23\n";
			continue;
		}
		if (unit != 'c' || unit != 'f') {
			std::cerr << "Wrong unit use F for Frengheight or C for Celsius";
			continue;
		}

		temps.push_back(Reading (hour,temperature, unit));
	}

	for (int i = 0; i < temps.size(); ++i)
		ost << "(" << temps[i].hour << "," << temps[i].temperature << " " << temps[i].unit << ")\n";

	return 0;
}
