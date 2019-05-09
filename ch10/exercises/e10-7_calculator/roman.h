#include <iostream>
#include <stdexcept>

class Roman_int {
		int num;
		std::string roman;
		void to_int ();
		void to_roman_int ();
		bool check_roman_numeral (char c, int n);
	public :
		Roman_int ()		: num (0), roman ("") {
		}

		Roman_int (int n)	: num (n), roman ("") {
			to_roman_int ();
		}
	
		Roman_int (std::string r)	: num (0), roman (r) {
			to_int ();
		}

		std::string as_roman_int () {
			return roman;
		}

		int as_int() {
			return num ;
		}
}; // class Roman_int

bool operator== (Roman_int r1, Roman_int r2);
bool operator!= (Roman_int r1, Roman_int r2);

bool operator> (Roman_int r1, int d);
bool operator< (Roman_int r1, int d);

std::ostream &operator<< (std::ostream &os, Roman_int r2);
std::istream &operator>> (std::istream &is, Roman_int& r2);

Roman_int operator+ (Roman_int& r1, Roman_int r2);
Roman_int operator- (Roman_int& r1, Roman_int r2);
Roman_int operator* (Roman_int& r1, Roman_int r2);
Roman_int operator/ (Roman_int& r1, Roman_int r2);
Roman_int operator% (Roman_int& r1, Roman_int r2);

Roman_int operator+= (Roman_int& r1, Roman_int r2);
Roman_int operator-= (Roman_int& r1, Roman_int r2);
Roman_int operator*= (Roman_int& r1, Roman_int r2);
Roman_int operator/= (Roman_int& r1, Roman_int r2);
Roman_int operator%= (Roman_int& r1, Roman_int r2);
Roman_int operator++ (Roman_int& r);
Roman_int operator-- (Roman_int& r);

Roman_int operator- (Roman_int& r);

