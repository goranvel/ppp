#include <iostream>
#include <vector>
#include <algorithm>

int celling (double d); 

enum class Currency {
	USD, DKK, CAD, EUR, GBP, AUD
};

bool operator== (Currency& c1, Currency& c2) {
	return int(c1) == int(c2);
}

class Conversion {
		Currency cur1, cur2;
		double rate;
	public:
		Conversion (Currency c1, Currency c2, double r) : cur1 (c1), cur2 (c2), rate (r){
		}

		Currency getFirst () {
			return cur1;
		}

		Currency getSecond () {
			return cur2;
		}

		double getRate () {
			return rate;
		}
};

bool operator== (Conversion& c1, Conversion& c2) {
	return c1.getFirst() == c2.getFirst() && 
				c1.getSecond() == c2.getSecond();
}

class Conversions {
		std::vector<Conversion> conversions;
		void populate (Currency c) { // add conversions that are not directly given
			for (int i = 0; i < conversions.size(); ++i) {
				try {
					if (c == conversions[i].getFirst()) {
						continue;
					}

					for (int j = 0; j < conversions.size(); ++j)
						if (c == conversions[j].getFirst() &&
								conversions[i].getSecond() == conversions[j].getSecond()) {
							add (c, conversions[i].getFirst(), conversions[j].getRate() / conversions[i].getRate());
							break;
						}
					
				} catch (std::runtime_error& e) {
				}
			}
		}
	public:
		Conversions () {
		}

		void add (Currency c1, Currency c2, double rate) {
			if (contains (Conversion(c1, c2, rate)))
				throw std::runtime_error ("Coneversion exists\n");
			conversions.push_back(Conversion(c1, c2, rate));
			conversions.push_back(Conversion(c2, c1, 1/rate));

			populate (c1);
			populate (c2);
		}

		void add (Conversion c) {
			if (contains (c))
				throw std::runtime_error ("Coneversion exists\n");

			conversions.push_back(c);
			conversions.push_back(Conversion(c.getSecond(), c.getFirst(), 1/c.getRate()));
			populate(c.getFirst());
			populate(c.getSecond());
		}


		Conversion get (Currency c1, Currency c2) {
			for (int i = 0; i < conversions.size(); ++i)
				if (c1 == conversions[i].getFirst() &&
						c2 == conversions[i].getSecond())
					return conversions[i];

			throw std::runtime_error ("No conversion from given currencies");	
		}

		bool contains (Conversion c) {
			for (int i = 0; i < conversions.size(); ++i)
				if (c == conversions[i]) 
					return true;

			return false;
		}

		void print () {
			for (int i = 0; i < conversions.size(); ++i)
				std::cout	<< int(conversions[i].getFirst())	<< " " 
								<< int(conversions[i].getSecond())	<< " "
								<< conversions[i].getRate()				<< "\n";
		}
};

Conversions conversions;

class Money {
		long cents;
		Currency currency;
	public:
		Money (double ammount, Currency curr) : 
			cents (celling (ammount * 100)), currency (curr) {
		}

		Money () : cents (0) {
		}

		int getCents () const {
			return cents;
		}

		int getDollars () const {
			return cents/100;
		}

		double getAmmount () const {
			return cents/100;
		}

		Currency getCurrency () const {
			return currency;
		}

		void convert (Currency c) {
			cents *= conversions.get (currency, c).getRate();
			currency = c;
		}
};

bool operator== (Money& m1, Money m2) {
	if (m1.getCurrency() != m2.getCurrency())
		m2.convert(m1.getCurrency());

	std::cout << m1.getCents() << " " << m2.getCents() << "\n";
	return m1.getCents() == m2.getCents();
}

bool operator!= (Money& m1, Money m2) {
	if (m1.getCurrency() != m2.getCurrency())
		m2.convert(m1.getCurrency());

	return m1.getCents() != m2.getCents();	
}

Money operator+ (Money& m1, Money m2) {
	if (m1.getCurrency() != m2.getCurrency())
		m2.convert(m1.getCurrency());

	return Money(m1.getCents() + m2.getCents(), m1.getCurrency());
}

Money operator- (Money& m1, Money m2) {
	if (m1.getCurrency() != m2.getCurrency()) 
		m2.convert(m1.getCurrency());

	return Money(m1.getCents() - m2.getCents(), m1.getCurrency());
}

Money operator* (Money& m1, Money m2) {
	if (m1.getCurrency() != m2.getCurrency())
		m2.convert(m1.getCurrency());

	return Money(m1.getCents() - m2.getCents(), m1.getCurrency());
}

Money operator/ (Money& m1, Money m2) {
	if (m1.getCurrency() != m2.getCurrency())
		m2.convert(m1.getCurrency());

	return Money(m1.getCents() - m2.getCents(), m1.getCurrency());
}

Money operator+ (Money& m, double am) {
	return Money(m.getCents() + am, m.getCurrency());
}

Money operator- (Money& m, double am) {
	return Money(m.getCents() - am, m.getCurrency());
}

Money operator* (Money& m, double am) {
	return Money(m.getCents() * am, m.getCurrency());
}

Money operator/ (Money& m, double am) {
	return Money(double(m.getCents())/am, m.getCurrency());
}

Money operator+ (double am, Money& m) {
	return Money(am + m.getCents(), m.getCurrency());
}

Money operator- (double am, Money& m) {
	return Money(am - m.getCents(), m.getCurrency());
}

Money operator* (double am, Money& m) {
	return Money(am * m.getCents(), m.getCurrency());
}

Money operator/ (double am, Money& m) {
	return Money(am/m.getCents(), m.getCurrency());
}

int celling (double c) {
	return c - int(c) >= 0.5 ? int(c) + 1 : int(c);
}

int main (void) {
	try {
		conversions.print();
	} catch (std::runtime_error& e) {
		std::cerr << e.what() << "\n";
	}

	return 0;
}
