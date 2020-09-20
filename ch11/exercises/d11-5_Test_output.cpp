#include <iostream>

int main (void) {
	int birth_year = 1985;
	
	std::cout <<	"Decimal:\t\t"			<<					birth_year << "\n" <<
						"Hexadecimal:\t\t"	<< std::hex <<	birth_year << "\n" <<
						"Octal:\t\t\t"			<< std::oct << birth_year << "\n";

	std::cout << 2018 - birth_year << "\n";
	return 0;
}
