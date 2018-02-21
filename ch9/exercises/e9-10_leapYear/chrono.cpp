#include <iostream>
#include "chrono.h"

namespace Chrono {
	Date::Date (int yy, Month mm, int dd) : y (yy), m (mm), d (dd) {
		if (!is_date(yy, mm, dd))
			throw Invalid();

	}

	const Date& default_date() {
		static Date dd (0, Month::jan, 1);
		return dd;
	}
		
	Date::Date () : y (default_date().year()), m (default_date().month()), d (default_date().day()) {
	}

	void Date::add_day (int n) {
		// TODO
	}

	void Date::add_month (int n) {
		// TODO
	}

	void Date::add_year (int n) {
		if ( m == Month::feb && d == 29 && !leapyear (y + n)) {
			m = Month::mar;
			d = 1;
		}

		y += n;
	}

	bool is_date (int y, Month m, int d) {
		int mm = int (m);
		if (d <= 0 || d > 31 || m < Month::jan || Month::dec < m)
			return false;

		if (mm == 2)
			return d < 29 || leapyear (y) && d < 30;

		if (mm % 2 == 0 && mm < 8)
			return d < 31;
		else if (mm % 2 == 1 && mm >= 8)
			return d < 31;

		return true;
	} // is_date

	bool leapyear (int y) {
		return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
	}

	bool operator== (const Date& a, const Date& b) {
		return a.year() == b.year() &&
					a.month() == b.month() &&
						a.day() == a.day();
	}

	bool operator!= (const Date& a, const Date& b) {
		return !(a==b);
	}

	std::ostream& operator<< (std::ostream& os, const Date& d) {
		return os << d.year() << ", " << int(d.month())  << ", " << d.day();
	}

	std::istream& operator>> (std::istream& is, Date& dd) {
		int y, m, d;

		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;

		if (!is)
			return is;

		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')  {
			is.clear (std::istream::failbit);
			return is;
		}
		
		dd = Date (y, Month(m), d);

		return is;
	}

	Day day_of_week (const Date& d) {
		// TODO
	}

	Date next_Sunday (const Date& d) {
		// TODO
	}

	Date next_weekday (const Date& d) {
		// TODO
	}
} // namespace Chrono

/*
int main (void) {
	for (int i = 2000; i < 2014; ++i) {
		std::cout << "Year " << i << "\n";
		for (int j = 1; j < 13; ++j) {
			std::cout << j << " ";
			for (int k = 1; k < 32; ++k) {
				if (is_date(i, Chrono::Month(j), k)) {
					Chrono::Date d (i, Chrono::Month(j), k);
					std::cout << d << "\n";
				}
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}

	return 0;
} */
