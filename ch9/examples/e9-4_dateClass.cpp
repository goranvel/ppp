#include <iostream>

class Date {
// privete: not necesery here
		int y, m; 
	public :
		Date (int yy, int mm, int dd);
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
		int d;
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
} */

// YET ANOTHER WAY OF WRITTING CONSTRUCTOR
Date::Date (int yy, int mm, int dd) : y (yy), m (mm), d (dd) {
}
void Date::add_day (int n) {
	d += n;
}

int main (void) {
//	Date today; // compile time error

	Date my_bday (1, 1, 1055); // works
//	std::cout << my_bday.d << "\n";
	std::cout << my_bday.day() << "\n";

//	Date my_bday2 {1, 1, 1155}; // works fo c++11 and up
//	std::cout << my_bday2.d << "\n";

//	Date yesterda = (1234, 1, 1); // compile error 

//	Date my_bday3 = {1, 1, 1255}; // works fo c++11 and up
//	std::cout << my_bday3.d << "\n";

	Date my_bday4 = Date (1, 1, 1355); // works
//	std::cout << my_bday4.d << "\n";

//	Date my_bday5 = Date {1, 1, 1455}; // works fo c++11 and up
//	std::cout << my_bday5.d << "\n";

	return 0;
}
