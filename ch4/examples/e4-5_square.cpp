#include <iostream>

int square (int);

int main (void) {

	for (int i = 0; i < 100; ++i) {
		std::cout << i << '\t' << square (i) << '\n';
	}
		
	return 0;;
}

int square (int x) {
	return x * x;
}
