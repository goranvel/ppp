#include <iostream>

class Date {
// privete: not necesery here
		int y, m, d; 
	public :
		class Invalid {};
		Date (int yy, int mm, int dd) : y (yy), m (mm), d (dd) {
			if (!is_valid())
				throw Invalid();
		}

		void add_day (int n);
		int month () {
			return m;
		}
		int day () {
			return d;
		}
		int year () {
			return y;
		}
	 private : // necesery here
		bool is_valid ();
		bool is_leap () {
			return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
		}
};
/* ONE WAY OF WRITTING CONSTRUCTOR
Date::Date (int yy, int mm, int dd) {
	y = yy;
	m = mm;
	d = dd;
} 

// ANOTHER WAY OF WRITTING CONSTRUCTOR 
// C++11 and up
Date::Date (int yy, int mm, int dd) : y {yy}, m {mm}, d {dd} {
}

// YET ANOTHER WAY OF WRITTING CONSTRUCTOR
Date::Date (int yy, int mm, int dd) : y (yy), m (mm), d (dd) {
}
*/
void Date::add_day (int n) {
	d += n;
}

bool Date::is_valid () {
	if (d < 0 || m < 0 || m > 12)
		return false;

	if (m == 2)
		if (d > 29)
			return false;
		else if (!is_leap () && d > 28)
			return false;

	if (m < 8)
		if (m % 2 == 1 && d > 31)
			return false;
		else if ( m % 2 == 0 && d > 30)
			return false;
	
	if (m >= 8) 
		if (m % 2 == 1 && d > 30)
			return false;
		else if (m % 2 == 0 && d > 31) 
			return false; 

	return true;
}

int main (void) {
//	Date today; // compile time error

//	Date my_bday (1, 1, 1055); // works
//	std::cout << my_bday.d << "\n";
//	std::cout << my_bday.day() << "\n";

//	Date my_bday2 {1, 1, 1155}; // works fo c++11 and up
//	std::cout << my_bday2.d << "\n";

//	Date yesterda = (1234, 1, 1); // compile error 

//	Date my_bday3 = {1, 1, 1255}; // works fo c++11 and up
//	std::cout << my_bday3.d << "\n";

//	Date my_bday4 = Date (1, 1, 1355); // works
//	std::cout << my_bday4.day() << "\n";

// Date d1 (1234, 13, 23); // throws exception 13 month
	int d, m, y;
	while (std::cin >> y >> m >> d)
		try {
			Date d1 (y, m, d);
		} catch (Date::Invalid) {
			std::cerr << "Invalid input\n\n";
		}

//	Date my_bday5 = Date {1, 1, 1455}; // works fo c++11 and up
//	std::cout << my_bday5.d << "\n";

	return 0;
}
