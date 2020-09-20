#include <iostream>

int main (void) {
	int *ptr = new int[4];

	*(ptr - 5555) = 5;

	std::cout << ptr[-5555] << "\n";

	std::cout << ptr << " " << &ptr[-55555] << "\n";

	return 0;
}
