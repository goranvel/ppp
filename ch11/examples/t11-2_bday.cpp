#include <iostream>

int main (void) {
	int d = 19, m = 1, y = 1985;

	std::cout <<					"\t| Month\t| Day" << 5 <<  "\t| Year\t|\n";
	std::cout <<					"--------+-------+-------+-------+\n";
	std::cout << std::hex	<<	"Hex\t| " << m << "\t| " << d << "\t| " << y <<"\t|\n";
	std::cout << std::oct	<<	"oct\t| " << m << "\t| " << d << "\t| " << y <<"\t|\n";
	std::cout << std::dec	<<	"dec\t| " << m << "\t| " << d << "\t| " << y <<"\t|\n";

	std::cout << "\n";
	std::cout << "\n";
	std::cout << std::showbase;
	std::cout <<					"\t| Month\t| Day" << 5 <<  "\t| Year\t|\n";
	std::cout <<					"--------+-------+-------+-------+\n";
	std::cout << std::hex	<<	"Hex\t| " << m << "\t| " << d << "\t| " << y <<"\t|\n";
	std::cout << std::oct	<<	"oct\t| " << m << "\t| " << d << "\t| " << y <<"\t|\n";
	std::cout << std::dec	<<	"dec\t| " << m << "\t| " << d << "\t| " << y <<"\t|\n";

	return 0;
}
