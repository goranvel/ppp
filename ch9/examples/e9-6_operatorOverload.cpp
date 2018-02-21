#include <iostream>

class Time {
		int m, h;
	public :
		Time (int hour, int min) : m (min), h (hour) {
		}
		Time operator+(Time t) {
			// h += t.getHour();
			// m += t.getMin();

			return Time (h + t.getHour(), m + t.getMin());
		}
		int getHour () {
			return h;
		}
		int getMin () {
			return m;
		}
};
/*
enum class Month { // for c++ 11 and up
	Jan = 1, Feb, Mar, Apr,
	May, Jun, Jul, Aug,
	Sep, Oct, Nov, Dec
};

Month operator++ (Month &m) {
	return m = (m == Month::Dec) ? Month::Jan : Month (int(m) + 1);
}
*/
/* Month operator++ () {
	return m = (m == Month::Dec) ? Month::Jan : Month (int(m) + 1);
} */

int main (void) {
/*	Month m = Month::Dec;

//	Month m = feb;
//	m = 7;
//	int n = m;

	std::cout << (int) m << "\n";
	++m;
	std::cout << (int) m << "\n";
*/
	Time t1 (3, 30);
	Time t2 (2, 20);
	Time t3 = t1 + t2;
	std::cout << t3.getMin() << "\n";
	return 0;
}
