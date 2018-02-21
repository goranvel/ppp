#include <iostream>
#include <stdexcept>

int gcd (int a, int b);

class Rational {
		int num, div;
	public:
		Rational (int n, int d) : num (n), div (d) {
			if (div == 0)
				throw std::runtime_error ("Divider cannot be 0");

			if (div < 0) {
				num *= -1;
				div *= -1;
			}
			num /= gcd (n, d);
			div /= gcd (n, d);
		}
		Rational () : num (0), div(1) {
		}

		int getNum() const {
			return num;
		}

		int getDiv() const {
			return div;
		}
};

std::ostream& operator<< (std::ostream& os, const Rational& r) {
	return os << r.getNum() << "/" << r.getDiv();
}

bool operator== (Rational& r1, Rational& r2) {
	return r1.getNum() * r2.getDiv() == r2.getNum() * r1.getDiv();
}

bool operator!= (Rational& r1, Rational& r2) {
	return !(r1 == r2);
}

Rational operator+ (Rational r1, Rational r2) {
	return Rational (r1.getNum() * r2.getDiv() + r2.getNum() * r1.getDiv(), r1.getDiv() * r2.getDiv());
}

Rational operator- (Rational r1, Rational r2) {
	return Rational (r1.getNum() * r2.getDiv() - r2.getNum() * r1.getDiv(), r1.getDiv() * r2.getDiv());
}

Rational operator- (Rational r) {
	return Rational (-r.getNum(), r.getDiv());
}

Rational operator* (Rational r1, Rational r2) {
	return Rational (r1.getNum() * r2.getNum(), r1.getDiv() * r2.getDiv());
}

Rational operator/ (Rational r1, Rational r2) {
	return Rational (r1.getNum() * r2.getDiv(), r1.getDiv() * r2.getNum());
}

int gcd (int a, int b) {
	a = a < 0 ? a * -1 : a;
	b = b < 0 ? b * -1 : b;
	if (b <= 0)
		return a;

	return gcd (b, a % b);
}

double to_double (Rational r) {
	return double(r.getNum())/r.getDiv();
}

int main (void) {
	Rational r (4, 18);
	Rational r2 (5, 30);
	Rational rr = r * r2;
	std::cout << rr << "\n";
	return 0;
}
