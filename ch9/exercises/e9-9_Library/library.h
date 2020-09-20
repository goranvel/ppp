#include <iostream>
#include <stdexcept>
#include <vector>

#include "chrono.h"

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
		Book () : title(""), author (""), ISBN ("") {
		}

		Book (std::string t, std::string a, std::string I, Chrono::Date d, Genre g);

		// getter
		std::string getTitle ()		const {
			return title;
		}

		std::string getAuthor ()	const {
			return author;
		}

		std::string getISBN ()		const {
			return ISBN;
		}

		Chrono::Date getDate()		const {
			return date;
		}

		Genre getGenre()				const {
			return genre;
		}

		bool isCheckedOut ()			const {
			return checkedOut;
		}

		// setter method
		void checkOut ();
};

bool operator== (const Book& a, const Book& b);
bool operator!= (const Book& a, const Book& b);
std::ostream& operator<< (std::ostream& os, const Book& b);

class Patron {
		std::string name;
		int library_card;
		double fees;
	public :
		Patron (std::string name, int lib_card, double fees);

		// getters
		std::string getName () const {
			return name;
		}

		int getLibraryCard () const {
			return library_card;
		}

		double getFees () const {
			return fees;
		}

		bool owes () const {
			return fees > 0;
		}

		// setters
		void setFees (const double f);
};

bool operator== (const Patron& a, const Patron& b);
bool operator!= (const Patron& a, const Patron& b);
std::ostream& operator<< (std::ostream& os, const Patron& p);

class Library {
		std::vector<Book> books;
		std::vector<Patron> patrons;

		struct Transaction {
			Book book;
			Patron patron;
			Chrono::Date date;
			double fee;

			Transaction (const Book& b, const Patron& p, const Chrono::Date& d, const double& f);
			Transaction (const Patron& p, const Chrono::Date& d, const double& f);
		};
	
		std::vector <Transaction> transactions;
	public :
		Library ();

		// getters
		bool bookExists (Book book) const {
			for (Book b : books)
				if (b == book)
					return true;
			return false;
		}

		bool patronExists (Patron patron) const {
			for (Patron p : patrons)
				if (p == patron)
					return true;
			return false;
		}

		std::vector<Patron> whoOwes () const {
			std::vector<Patron> owes;
			for (Patron p : patrons)
				if (p.owes())
					owes.push_back(p);
			return owes;
		}

		void printCatalog () const {
			for (Book b : books)
				std::cout << b << "\n";
		}

		void printMembers () const {
			for (Patron p : patrons)
				std::cout << p << "\n";
		}

		void printTransactions () const {
			for (Transaction t : transactions)
				std::cout << "Transaction\nBook: " << t.book.getTitle() << 
									"\nPatron: " << t.patron.getName() << "\nFee: " << t.fee << "\n";
		}

		// setter
		void addBook	(const Book& b);
		void addPatron	(const Patron& p);
		void checkOut (Book& b, Patron& p, const Chrono::Date& d, const double& f);
		void payFees(Patron& p, const Chrono::Date& d, const double& f);
};
