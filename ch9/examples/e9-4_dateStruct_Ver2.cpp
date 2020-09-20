#include <iostream>

struct Date {
	int y, m, d;

	Date (int y, int m, int d);
	void add_day (int n);
};

Date::Date (int y, int m, int d) {
	this->y = y;
	this->m = m;
	this->d = d;
}
/*
void Date::add_day (int n) {
	date.d += n;
}
*/
int main (void) {
//	Date today; // compile time error

	Date my_bday (1, 1, 1055); // works
	std::cout << my_bday.d << "\n";

	Date my_bday2 {1, 1, 1155}; // works fo c++11 and up
	std::cout << my_bday2.d << "\n";

//	Date yesterda = (1234, 1, 1); // compile error 

	Date my_bday3 = {1, 1, 1255}; // works fo c++11 and up
	std::cout << my_bday3.d << "\n";

	Date my_bday4 = Date (1, 1, 1355); // works
	std::cout << my_bday4.d << "\n";

	Date my_bday5 = Date {1, 1, 1455}; // works fo c++11 and up
	std::cout << my_bday5.d << "\n";

	return 0;
}
