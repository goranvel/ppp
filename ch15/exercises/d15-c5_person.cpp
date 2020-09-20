#include <iostream>

struct Person {
		Person (std::string n = "", int a = 0) : p_name (n), p_age (a) {
		}

		std::string name () const {
			return p_name;
		}

		int age () const {
			return p_age;
		}
	private :
		std::string p_name;
		int p_age;
};

std::istream& operator>> (std::istream & is, Person& p) {
//	is >> p.name >> p.age;

	return is;
}

std::ostream& operator<< (std::ostream& os, Person p) {
//	os << p.name << " is " << p.age << " year"<< (p.age > 1 ? "s" : "") <<  " old.\n";

	return os;
}


int main (void) {
	Person p;

	std::cin >> p;
	std::cout << p;
	return 0;
}
