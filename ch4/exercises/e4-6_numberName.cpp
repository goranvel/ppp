#include <iostream>
#include <vector>

int main (void) {
	std::vector<std::string> name;

	name.push_back("zero");
	name.push_back("one");
	name.push_back("two");
	name.push_back("three");
	name.push_back("four");
	name.push_back("five");
	name.push_back("six");
	name.push_back("seven");
	name.push_back("eight");
	name.push_back("nine");
	name.push_back("ten"); // what the heck ;)

	int n;
	if (std::cin >> n) {
		std::cout << name.at(n);
		return 0;
	}

	std::cin.clear();
	std::string number;
	std::cin >> number;
	
	for (int i = 0; i < name.size(); ++i)
		if (name.at(i) == number) {
			std::cout << i;
			break;
		}
}
