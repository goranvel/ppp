#include <iostream>
#include <fstream>

void print_year (std::ofstream& ofs, int y);

int main (void) {
	int years[100];
	for (int i = 0; i < 100; ++i) {
		years[i] = 1990 + i;
	}
	std::ofstream ofs ("test.txt");
	for (int i = 0; i < 100; ++i) {
		ofs << years[i] << "\n";
	}
	return 0;
}

void print_year (std::ofstream& ofs, int y) {
	ofs << y;	
}
