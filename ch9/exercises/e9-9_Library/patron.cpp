#include "library.h"

Patron::Patron (std::string n, int lc, double f) : name(n), library_card(lc), fees(f) {
};

// setters
void Patron::setFees (const double f) {
	std::cout << "-- " << getName() << fees << " << \n";
	fees += f;
	std::cout << "-- " << getName() << fees << " >> \n";

}

bool operator== (const Patron& a, const Patron& b) {
	return a.getLibraryCard() == b.getLibraryCard();
}

bool operator!= (const Patron& a, const Patron& b) {
	return !(a == b);
}

std::ostream& operator<< (std::ostream& os, const Patron& p) {
	os	<< "Name:\t\t"		<< p.getName()				<< "\n"
		<< "Card #:\t\t"	<< p.getLibraryCard ()	<< "\n";
		if (p.owes())
			os << "Fees:\t\t" <<  p.getFees();

	return os;
}
