#include "library.h"

Library::Library () {
}

void Library::addBook (const Book& b) {
	if (bookExists(b))
		throw std::runtime_error ("Book exists!");

	books.push_back (b);
}

void Library::addPatron (const Patron& p) {
	if (patronExists(p))
		throw std::runtime_error ("Patron exists!");
	
	patrons.push_back (p);
}

void Library::checkOut (Book& b, Patron& p, const Chrono::Date& d, const double& f) {
	if (!bookExists(b))
		throw std::runtime_error ("Book does not exist");
		
	if (b.isCheckedOut())
		throw std::runtime_error ("Book is checked out.");
		
	if (!patronExists(p)) {
		std::cout << "Patron " << p.getName() << " is not registred. Would you like to register? (Y/N)";
		char c;
		std::cin >> c;
		if (c == 'y' || c == 'Y')
			addPatron (p);
	}

	if (p.owes())
		throw  std::runtime_error ("User owes money");

	b.checkOut();
	p.setFees (p.getFees() + f);
	transactions.push_back(Transaction (b, p, d, f));
}

void Library::payFees (Patron& p, const Chrono::Date& d, const double& f) {
	for (Patron pp : patrons)
		if (pp.getLibraryCard () == p.getLibraryCard()) {
			p.setFees (pp.getFees() + f);
			transactions.push_back (Transaction(p, d, f));
			printMembers ();
			return;
		}
	
	throw std::runtime_error ("Cannot find person with that name");
}

Library::Transaction::Transaction (const Book& b, const Patron& p, const Chrono::Date& d, const double& f) :
		book (b), patron (p), date (d), fee(f) {
}

Library::Transaction::Transaction (const Patron& p, const Chrono::Date& d, const double& f) :
		patron (p), date (d), fee(f), book(Book()) {
}
