#include <iostream>
#include "e9-10_leapYear/chrono.h"
#include <stdexcept>

enum class Genre {
	fiction=0, nonfiction, periodical, biography, children
};

class Book {
		std::string title, author, ISBN;
		Chrono::Date date;
		Genre genre;
		bool checkedOut;
		bool isValidISBN ();
	public :
		Book (std::string t, std::string a, std::string I, Chrono::Date d, Genre g) :
					title (t), author (a), ISBN (I), date (d), genre(g), checkedOut (false) {
			if (!isValidISBN ())
				throw std::runtime_error ("Invalid ISBN.");
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

		Genre getGenre () const {
			return genre;
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

int main (void)
try {
	Book a ("a", "aa", "123X", Chrono::Date(2011,Chrono::Month::jan,1), Genre::fiction);
	Book b ("b", "aa", "123X", Chrono::Date(2011,Chrono::Month::jan,1), Genre::children);
	std::cout << b;
} catch (std::runtime_error& e) {
	std::cerr << e.what();
}
