#include <iostream>

int f (int& a);
int main (void) {
	int a = 5;
	f (a);

	std::cout << a << "\n";
	return 0;
}

int f (int& a) {
	a = 25;
}
