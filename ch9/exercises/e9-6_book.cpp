#include <iostream>
#include "e9-10_leapYear/chrono.h"
#include <stdexcept>

class Book {
		std::string title, author, ISBN;
		Chrono::Date date;
		bool checkedOut;
		bool isValidISBN ();
	public :
		Book (std::string t, std::string a, std::string I, Chrono::Date d) :
					title (t), author (a), ISBN (I), date (d), checkedOut (false) {
		}

		// getters
		std::string getTitle () const {
			return title;
		}

		std::string getAuthor () const {
			return author;
		}

		std::string getISBN () const {
			return ISBN;
		}

		Chrono::Date getDate () const  {
			return date;
		}

		bool isChekcedOut() const {
			return checkedOut;
		}

		// setter method
		void checkOut () {
			checkedOut = true;
		}
}; // class Book

bool operator== (const Book& a, const Book& b) {
	return a.getISBN() == b.getISBN();
}

bool operator!= (const Book& a, const Book& b) {
	return !(a == b);
}

std::ostream& operator<< (std::ostream& os, const Book& b) {
	return	os	<< "BOOK:\t\t" << b.getTitle()	<< "\n"
					<< "Author:\t" << b.getAuthor()	<< "\n"
					<< "ISBN:\t\t" << b.getISBN()		<< "\n"
					<< "Date:\t\t" << b.getDate()		<< "\n";
}

int main (void)
try {
	Book a ("a", "aa", "123X", Chrono::Date(2011,Chrono::Month::jan,1));
	Book b ("b", "aa", "123X", Chrono::Date(2011,Chrono::Month::jan,1));
	std::cout << (a == b);
} catch (std::runtime_error& e) {
	std::cerr << e.what();
}
