#include "library.h"

Book::Book (std::string t, std::string a, std::string I, Chrono::Date d, Genre g) :
					title (t), author (a), ISBN (I), date (d), genre(g), checkedOut (false) {
			if (!isValidISBN ())
				throw std::runtime_error ("Invalid ISBN.");
		}

		// setter method
void Book::checkOut () {
	checkedOut = true;
}

bool operator== (const Book& a, const Book& b) {
	return a.getISBN() == b.getISBN();
}

bool operator!= (const Book& a, const Book& b) {
	return !(a == b);
}

std::ostream& operator<< (std::ostream& os, const Book& b) {
	return	os	<< "BOOK:\t\t" << b.getTitle()	<< "\n"
					<< "Author:\t\t" << b.getAuthor()	<< "\n"
					<< "ISBN:\t\t" << b.getISBN()		<< "\n"
					<< "Date:\t\t" << b.getDate()		<< "\n"
					<< "Genre:\t\t"	<< int(b.getGenre())	<< "\n";
}

bool Book::isValidISBN () {
	if (!isdigit(ISBN[0])	|| !isdigit(ISBN[1]) ||
			!isdigit(ISBN[2]) || !(isdigit(ISBN[3]) || isalpha(ISBN[3])))
		return false;

	return true;
}
