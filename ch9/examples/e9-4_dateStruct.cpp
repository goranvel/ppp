#include <iostream>

struct Date {
	int y;
	int m;
	int d;
};

void init_day (Date &date, int y, int m, int d);
void add_day (Date &date, int n);

int main (void) {
	Date today;
	std::cout << today.y << "\n";

	return 0;
}

void init_day (Date &date, int y, int m, int d) {
	date.y = y;
	date.m = m;
	date.d = d;
}

void add_day (Date &date, int n) {
	date.d += n;
}
