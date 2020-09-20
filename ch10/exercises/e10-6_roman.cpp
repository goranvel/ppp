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

void Roman_int::to_roman_int () {
	int n = num;
	while (n >= 1000) {
		roman += 'M';
		n -= 1000;
	}

	if (n >= 900) {
		roman += "CM";
		n -= 900;
	}

	if (n >= 500) {
		roman += 'D';
		n -= 500;
	}

	if (n >= 400) {
		roman += "CD";
		n -= 400;
	}

	while (n >= 100) {
		roman += 'C';
		n -= 100;
	}

	if (n >= 90) {
		roman += "XC";
		n -= 90;
	}

	if (n >= 50) {
		roman += 'L';
		n -= 50;
	}

	if (n >= 40) {
		roman += "XL";
		n -= 40;
	}

	while (n >= 10) {
		roman += 'X';
		n -= 10;
	}
	
	if (n >= 9) {
		roman += "IX";
		n -= 9;
	}

	if (n >= 5) {
		roman += 'V';
		n -= 5;
	}

	if (n >= 4) {
		roman += "IV";
		n -= 4;
	}

	while (n >= 1) {
		roman += 'I';
		n -= 1;
	}	
} // Roman_int::to_roman_int()

void Roman_int::to_int () {
	for (int i = roman.size() - 1; i >= 0; --i) {
//		std::cout << i << " " << num << "--\n";
		if ( roman[i] != 'I' && roman[i] != 'V' &&
				roman[i] != 'X' && roman[i] != 'L' &&
				 roman[i] != 'C' && roman[i] != 'D' && 
					roman[i] != 'M') {
			throw std::runtime_error ("Invalid Roman Numeral digit.\n");
		}
	
		while (roman[i] == 'I') {
//			std::cout << "I" <<  " " << roman[i] << " " << num << "\n";

			if (num >= 3)
				throw std::runtime_error ("Invalid roman numeral number I.\n");
			num += 1;
			--i;
		}

		if (roman[i] == 'V') {
//			std::cout << "V" <<  " " << roman[i] << " " << num << "\n";

			if (num >= 4)
				throw std::runtime_error ("Invalid roman numeral number V.\n");

			if (roman[i - 1] == 'I') {
				num += 4;
				--i;
			} else
				num += 5;
		}

		while (roman[i] == 'X') {
//			std::cout << "X" <<  " " << roman[i] << " " << num << " " << i << "\n";

			if (num > 30)
				throw std::runtime_error ("Invalid roman numeral number X.\n");

			if (roman[i - 1] == 'I') {
				num += 9;
				--i;
				break;
			} 
			
			num += 10;
			if (roman[i - 1] == 'I' || roman[i - 1] == 'V')
				break;

			--i;
		}

		if (roman [i] ==	'L') {
//			std::cout <<	"L" <<  " " << roman[i] << " " << num << "\n";

			if (num >= 40)
				throw std::runtime_error ("Invalid roman numeral number L.\n");

			if (roman[i - 1] == 'X') {
				num += 40;
				--i;
			} else
				num += 50;
		}

		while (roman[i] == 'C') {
//			std::cout << "C" <<  " " << roman[i] << " " << num << "\n";

			if (num > 300)
				throw std::runtime_error ("Invalid roman numeral number C.\n");

			if (roman[i - 1] == 'X') {
				num += 90;
				--i;
				break;
			} 
			
			num += 100;
			if ( roman[i - 1] == 'I' || roman[i - 1] == 'V' || 
					roman[i - 1] == 'X' || roman[i - 1] == 'L')
				break;

			--i;
		}

		if (roman [i] == 'D') {
//			std::cout << "D" <<  " " << roman[i] << " " << num << "\n";

			if (num >= 400)
				throw std::runtime_error ("Invalid roman numeral number M.\n");

			if (roman[i - 1] == 'C') {
				num += 400;
				--i;
			} else
				num += 500;
		}

		while (roman[i] == 'M') {
//			std::cout << "M" <<  " " << roman[i] << " " << num << "\n";

			if (roman[i - 1] == 'C' && num < 100) {
				num += 900;
				--i;
				break;
			} 
			
			num += 1000;
			if ( roman[i - 1] != 'I' || roman[i - 1] != 'V' ||
					roman[i - 1] != 'X' || roman[i - 1] != 'L' || 
					 roman[i - 1] != 'C' || roman[i - 1] != 'D')
				break;

			--i;
		}

	} // for loop

} // Roman_int::to_int ();

bool operator== (Roman_int& a, Roman_int& b) {
	return a.as_roman_int() == b.as_roman_int();
}

bool operator!= (Roman_int& a, Roman_int& b) {
	return a.as_roman_int() != b.as_roman_int();
}

std::ostream& operator<< (std::ostream& os, Roman_int& r) {
	return os << r.as_roman_int();
}

std::ostream& operator>> (std::ostream& os, Roman_int& r) {

	std::string roman;;
	std::cin >> roman;

	Roman_int rr (roman);
	r = rr;
	return os;
}

int main (void) {
	int max = 4000;
	for (int i = 100; i < max; ++i) {
		Roman_int r (i); 
//		std::cout << "\t" << r.as_int();
//		std::cout << "\t" << r.as_roman_int() << " - ";
		Roman_int rr ("MCM"); (r.as_roman_int());
//		std::cout << "\t\t" << rr.as_int();
//		std::cout << "\t" << rr.as_roman_int() << "\n";
		if (r.as_int () != rr.as_int()) {
			std::cout << "ERROR\n" << i << "(" << 
								r.as_roman_int()  << " " << r.as_int() << " " << 
								rr.as_roman_int() << " " << rr.as_int() << ")\n" ;	
			break;
		}

		std::cout << r.as_int() << " " << rr.as_int() << "\n";
		if (r.as_int() % 10 == 0)
			std::cout << "\n";
	}
	return 0;
}
