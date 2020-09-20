#include <iostream>

std::string cat_dot (const std::string&, const std::string&);

int main (void) {
	std::cout << cat_dot ("Hello", "world");
	return 0;
}

std::string cat_dot (const std::string& s1, const std::string& s2) {
	return s1 + "." + s2;
}
