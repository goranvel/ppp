#include <iostream>
#include <stdexcept>

#include "e9-10_leapYear/chrono.h"


class Book {
		std::string title, author, ISBN;
		Chrono::Date date;
		bool checkedOut;
		bool isValidISBN ();
	public :
		Book (std::string t, std::string a, std::string I, Chrono::Date d) :
					title (t), author (a), ISBN (I), date (d), checkedOut (false) {
				if (!isValidISBN())
					throw std::runtime_error ("Error not valid ISBN");
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

bool Book::isValidISBN () {
	if (!isdigit(ISBN[0])	|| !isdigit(ISBN[1]) ||
			!isdigit(ISBN[2]) || !(isdigit(ISBN[3]) || isalpha(ISBN[3])))
		return false;

	return true;
}

int main (void) {
	Book a ("a", "b", "1235x", Chrono::Date (2011, Chrono::Month::jan, 1));

	return 0;
}
