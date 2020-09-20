#include <iostream>
#include <vector>
#include <algorithm>

const double feet2in	= 12;
const double feet2m	= 0.3048;
const double km2m		= 1000;

int main (void) {
//	int i1 = 0, i2 = 0;
	double d1 = 0, max = 0, min = ~(1 << 31), sum = 0; // d2 = 0;
	std::string unit;
	std::vector<double> values;

	std::cout << "Please enter length followed by unit (m, km, in ft):\n";
	while (std::cin >> d1 >> unit) {
		if (unit != "m" && unit != "km" &&
				unit != "in" && unit != "ft") {
			std::cout << "Not correct unit!!! m, km, in, ft are accepted.\n";
			continue;
		}

		if (unit == "km")
			d1 *= km2m;
		else if (unit == "ft")
			d1 *= feet2m;
		else if (unit == "in")
			d1 *= feet2m/12;

		values.push_back (d1);
		sum += d1;

		if (d1 > max) {
			max = d1;
		} else if (d1 < min) {
			min = d1;
		}
	}

	std::sort(values.begin(), values.end());

	std::cout << "Values are:\n";	
	for (int i = 0; i < values.size(); ++i)
		std::cout << values.at(i) << " m\n";
	
	std::cout << "You entered " << values.size() << " values\n";
	std::cout << " Sum of values entered is: " << sum << "\n";
	std::cout << "\t" << max << " is largest number so far\n";
	std::cout << "\t" << min << " is smallest number so far\n";

	return 0;
}
