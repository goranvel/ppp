#include <iostream>

int main (void) {
	int a = 7;
	int *p = new int();
	p = &a;

	std::cout << a << "\n";
	std::cout << *p << "\n";

	return a;
}
