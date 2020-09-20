#include <iostream>
#include <stdexcept>
#include <vector>

struct Person {
		Person (std::string f_n = "", std::string l_n = "", int a = 0) : 
					f_name (f_n), l_name (l_n), p_age (a) {
			int pos = -1;
			if ((pos = f_n.find_first_of (";:\"'[]*&^%$#@!")) != -1 ||
					(pos = l_n.find_first_of (";:\"'[]*&^%$#@!")) != -1) {
				std::string error = "Name cannot contain ";

				if ((pos = f_n.find_first_of (";:\"'[]*&^%$#@!")) != -1 )
					error += l_n[pos];
				else
					error += f_n[pos];

				throw std::runtime_error (error);
			}

			if (a < 0 || a > 150) {
				throw std::runtime_error ("Age cannot has to be between 0 and 150");
			}
		}

		std::string first_name () const {
			return f_name;
		}

		std::string last_name () const {
			return l_name;
		}

		int age () const {
			return p_age;
		}
	private :
		std::string f_name, l_name;
		int p_age;
};

std::istream& operator>> (std::istream & is, Person& p) {
	std::string f_name, l_name;
	int age;
	is >> f_name >> l_name >> age;
	if (!is)
		return is;

	p = Person (f_name, l_name, age);

	return is;
}

std::ostream& operator<< (std::ostream& os, Person p) {
	os	<< p.first_name() << " " << p.last_name () 
		<<  " is " << p.age() << " year" 
		<< (p.age() == 1 ? "s" : "") <<  " old.\n";

	return os;
}


int main (void) {
	std::vector<Person> people;
	Person person;

	while (std::cin >> person)
		people.push_back (person);

	for (int i = 0; i < people.size(); ++i)
		std::cout << people[i];

	return 0;
}
