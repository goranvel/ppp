#include <iostream>
#include <vector>

void initNames ();
int getNumber ();

std::vector<std::string> name;

int main () {
	initNames();
	int val1 = 0;
	int val2 = 0;
	char op = 0;

   while (op != -1) {
		val1 = getNumber();
		val2 = getNumber();
		std::cin >> op;
      std::cout << val1 << " " << op << " " << val2 << " = ";
      if (op == '+')
         std::cout << val1 + val2;
      else if (op == '-')
         std::cout << val1 - val2;
      else if (op == '*')
         std::cout << val1 * val2;
      else if (op == '/')
         std::cout << val1 / val2;
   }

   return 0;
}

void initNames () {
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
}

int getNumber() {
	int num;
	if (std::cin >> num) {
		return num;
	}

	std::cin.clear();
	std::string number;
	std::cin >> number;
		
	for (num = 0; num < name.size() && name.at(num) != number; ++num);

	return num;
}
