#include <iostream>

enum class Month { // for c++ 11 and up
	jan = 1, feb, mar, apr,
	may, jun, jul, aug,
	sep, oct, nov, dec
};

int main (void) {
	Month m = Month::jan;

//	Month m = feb;
//	m = 7;
//	int n = m;
	Month mm = Month(7);
	Month mn = Month (99);

	std::cout << (int) m << "\n";

	return 0;
}
