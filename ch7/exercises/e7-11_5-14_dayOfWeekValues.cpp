#include <iostream>
#include <vector>

class Day {
	public :
		std::string name;
		std::string shortName ;
		int val;
		Day (std::string n) : name (n), val (0) {
			shortName = std::string(n, 0, 3);
		}

};

class DayVals {
		int total;
	public:
		std::vector<Day> dayVals;

		DayVals () {
			total = 0;
			dayVals.push_back (Day("Monday"));
			dayVals.push_back (Day("Tuesday"));
			dayVals.push_back (Day("Wednessday"));
			dayVals.push_back (Day("Thursday"));
			dayVals.push_back (Day("Friday"));
			dayVals.push_back (Day("Saturday"));
			dayVals.push_back (Day("Sunday"));
		}



		bool update (std::string day, int val);
		void print ();
		int getTotal ();
};

bool DayVals::update (std::string day, int val) {
	day[0] &= ~(0x20);
   for (int i = 1; i < day.length(); ++i)
		day[i] |= 0x20;

	for (int i = 0; i < dayVals.size(); ++i)
		if (day == dayVals[i].name || day == dayVals[i].shortName) {
			dayVals[i].val += val;
			total += val;;
			return true;
		}

	return false;
}

void DayVals::print () {
	std::cout << "\n\n";
	for (int i = 0; i < dayVals.size(); ++i) {
		if (dayVals[i].val) { 
			std::cout << dayVals[i].name << "\t" ;

			if (dayVals[i].name.length() < 8)
				std::cout << '\t';

			std::cout << dayVals[i].val << "\n";
		}
	}
}

int DayVals::getTotal () {
	return total;
}

int main (void) {
	DayVals dayVals;

	DayVals dv;
	std::string day;
	int val = 0, rejected = 0;
	std::cout << "USAGE:\tType <day> <value> pairs. Press CTL + D when done.\n";
	std::cout << "\t\tExample: Monday 3, mon 2, tuesday 5\n";
	while (std::cin >> day >> val) {
		if (!dayVals.update(day, val))
			++rejected;
	}
	
	dayVals.print();

	std::cout << "\nTotal:\t\t" << dayVals.getTotal() << "\n";
	std::cout << "Rejected:\t" << rejected << "\n";

	return 0;
}
