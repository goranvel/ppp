#include <iostream>
#include <vector>

#include "chrono.h" 
namespace Chrono {
	Date::Date (int yy, Month mm, int dd) : d (dd) {
		if (!is_date(yy, mm, dd))
			throw Invalid();
		zero = 1970;
		int m = int (mm) - 2; // -1 for array aligment and -1 for month (do not need current month only previous)
		for (; m >= 0; --m) {
			d += days[m];
		}

		int years = yy - zero;
		int leaps = years/4;
		d += leaps * 366;
		d += (years - leaps) * 365;
	}

	Date::Date () {
		zero = 1970;
		Date (zero, Month::jan, 1);
	}

	void Date::add_day (int n) {
		d += n;
	}

	void Date::add_month (int n) {
		int m = int(month());
		for (; n; --n, ++m)
			d += days[m-1];
	}

	void Date::add_year (int n) {
		int y = year();
		for (; n; --n, ++y);
		y += 365 + leapyear(y);
	}

	bool is_date (int y, Month m, int d) {
		int mm = int (m);
		if (d <= 0 || d > 31 || m < Chrono::Month::jan || Month::dec < m)
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
		return os << d.year() << ", " << int(d.month()) << ", " << d.day();
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
	} // operator >> 

	Day day_of_week (const Date& d) {
		// using formula W = (days[m] + int(2.6 * int(m)) - 2 * y % 100 + y + y >> 2 + C >> 2) % 7
		int k = d.day();
		int mm = int(d.month());
		int c = d.year()/100;
		int yy = (mm > 2) ? int(d.year() % 100) : int(d.year() % 100) - 1;
		mm = mm > 2 ? mm - 2 : mm + 10;

		int w = (k + int(2.6 * mm - 0.2) +
					yy + (yy >> 2) + (c >> 2) - (c << 1)) % 7;
		return Day(w >= 0 ? w : w + 7);
	}

	Date next_Sunday (const Date& d) {
		// 7 - day_of_week to find sunday
		int sun = 7 - int(day_of_week (d));
		int day = d.day(), month = int(d.month()), year = d.year();

//		std::cout << day + sun << " " <<  days [month - 1] << "\n";
		if (day + sun > days [month - 1]) {
			day = day + sun - days [month - 1];
			++month;
		} else 
			day += sun;
		
		if (month > 12) {
			month -= 12;
		}
		if (!is_date(year, Month(month), day))
			throw Date::Invalid();

		return Date(year, Month(month), day);
	}

	Date next_workday (const Date& d) {
		// 8 - day_of_week to find work day
		int sun = 8 - int(day_of_week (d));
		int day = d.day(), month = int(d.month()), year = d.year();

//		std::cout << day + sun << " " <<  days [month - 1] << "\n";
		if (day + sun > days [month - 1]) {
			day = day + sun - days [month - 1];
			++month;

			if (month > 12) {
				month = 1;
			}
		} else 
			day += sun;
		
		
		return Date(year, Month(month), day);
	}
} // namespace Chrono

int main (void) { /*
	std::vector <Chrono::Date> ds;
	for (int i = 2000; i < 2014; ++i)
		for (int j = 1; j < 13; ++j)
			for (int k = 1; k < 32; ++k)
				if (is_date(i, Chrono::Month(j), k)) {
					Chrono::Date d (i, Chrono::Month(j), k);
					ds.push_back (d);
				}
			
	int n = 145; */
	Chrono::Date d (2018, Chrono::Month::feb, 9);
	std::cout << d << "\n";

	d.add_month (5);

	std::cout << d << "\n";

	return 0;
} 
