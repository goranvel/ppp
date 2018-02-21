#include <iostream>

int celling (double d);

class Money {
		long cents;
	public:
		Money (double ammount) : cents (celling (ammount * 100)) {
		}

		Money () : cents (0) {
		}

		int getCents () {
			return cents;
		}

		int getDollars () {
			return cents/100;
		}

		double getAmmount () {
			return cents/100;
		}

};

bool operator== (Money& m1, Money& m2) {
	return m1.getCents() == m2.getCents();	
}

bool operator!= (Money& m1, Money& m2) {
	return m1.getCents() != m2.getCents();	
}

Money operator+ (Money& m1, Money& m2) {
	return Money(m1.getCents() + m2.getCents());
}

Money operator- (Money& m1, Money& m2) {
	return Money(m1.getCents() - m2.getCents());
}

Money operator* (Money& m1, Money& m2) {
	return Money(m1.getCents() * m2.getCents());
}

Money operator/ (Money& m1, Money& m2) {
	return Money(double(m1.getCents())/m2.getCents()/100);
}

Money operator+ (Money& m, double am) {
	return Money(m.getCents() + am);
}

Money operator- (Money& m, double am) {
	return Money(m.getCents() - am);
}

Money operator* (Money& m, double am) {
	return Money(m.getCents() * am);
}

Money operator/ (Money& m, double am) {
	return Money(double(m.getCents())/am);
}

Money operator+ (double am, Money& m) {
	return Money(am + m.getCents());
}

Money operator- (double am, Money& m) {
	return Money(am - m.getCents());
}

Money operator* (double am, Money& m) {
	return Money(am * m.getCents());
}

Money operator/ (double am, Money& m) {
	return Money(am/m.getCents());
}

int celling (double c) {
	return c - int(c) >= 0.5 ? int(c) + 1 : int(c);
}


int main() {
}
