#include <iostream>
#include <stdexcept>

struct Person {
		Person (std::string n = "", int a = 0) : p_name (n), p_age (a) {
			int pos = -1;
			if ((pos = n.find_first_of (";:\"'[]*&^%$#@!")) != -1) {
				std::string error = "Name cannot contain ";
				error += n[pos];
				throw std::runtime_error (error);
			}

			if (a < 0 || a > 150)
				throw std::runtime_error ("Age cannot has to be between 0 and 150");
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
	std::string name;
	int age;
	is >> name >> age;

	p = Person (name, age);

	return is;
}

std::ostream& operator<< (std::ostream& os, Person p) {
	os << p.name() << " is " << p.age() << " year" << (p.age() == 1 ? "s" : "") <<  " old.\n";
	return os;
}


int main (void) {
	Person p;

	std::cin >> p;
	std::cout << p;
	return 0;
}
