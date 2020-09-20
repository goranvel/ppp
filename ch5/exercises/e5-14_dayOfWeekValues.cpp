#include <iostream>
#include <vector>

int main (void) {
	std::vector<int> dayVal(7, 0);
	std::string day;
	int value;
	int rej = 0;
	int total = 0;

	while (std::cin >> day >> value) {
		for (int i = 0; i < day.length(); ++i)
			day[i] |= 0x20;

		if (day == "sun" || day == "sunday")
			dayVal[0] += value;
		else if (day == "mon" || day == "monday")
			dayVal[1] += value;
		else if (day == "tue" || day == "tuesday")
			dayVal[2] += value;
		else if (day == "wed" || day == "wednessday")
			dayVal[3] += value;
		else if (day == "thu" || day == "thursday")
			dayVal[4] += value;
		else if (day == "fri" || day == "friday")
			dayVal[5] += value;
		else if (day == "sat" || day == "saturday")
			dayVal[6] += value;
		else {
			++rej;
			continue;
		}
	}
	std::cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat\n";
	for (int i = 0; i < dayVal.size(); ++i) {
		std::cout << dayVal[i] << "\t";
		total += dayVal [i];
	}
	std::cout << "\n";
	std::cout << "Total: " << total << "\nRejected: " << rej << "\n";
	return 0;
}
