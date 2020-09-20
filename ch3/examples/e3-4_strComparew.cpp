#include <iostream>

int main (void) {
	std::cout << "Please enter two names:\n";

	std::string name1, name2;

	std::cin >> name1 >> name2;

	if (name1 == name2) 
		std::cout << "Both names are the same.";
	if (name1 > name2)
		std::cout << name1 << " comes after " << name2 << " alphabetically!";
	if (name1 < name2)
		std::cout << name1 << " comes before " << name2 << " alphabetically!";

	return 0;
}
