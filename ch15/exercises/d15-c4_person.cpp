#include <iostream>

struct Person {
	Person (std::string n = "", int a = 0) : name (n), age (a) {
	}

	std::string name;
	int age;
};

std::istream & operator >> (std::istream & is, Person& p) {
	is >> p.name >> p.age;

	return is;
}

std::ostream & operator<< (std::ostream &os, Person &p) {
	os << p.name << " is " << p.age << " year"<< (p.age > 1 ? "s" : "") <<  " old.\n";

	return os;
}


int main (void) {
	Person p;
	p.name = "Goody";
	p.age = 63;

	std::cin >> p;
	std::cout << p;
	return 0;
}
