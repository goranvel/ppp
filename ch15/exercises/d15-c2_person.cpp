#include <iostream>

struct Person {
	std::string name;
	int age;
};

int main (void) {
	Person p;
	p.name = "Goody";
	p.age = 63;

	std::cout << p.name << " is " << p.age << " year"<< (p.age > 1 ? "s" : "") <<  " old.\n";
	return 0;
}
