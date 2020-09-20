#include <iostream>

int main (void) {
	int a = 20000;
	char c = a;
	int b = c;

	if (a != b)
		std::cout << "oops! " << a << " != " << b << "\n";
	else
		std::cout << "Wow!!! we have large character\n";

	return 0;
}
