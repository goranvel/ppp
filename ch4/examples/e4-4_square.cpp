#include <iostream>

int main (void) {
	int i = 0;

	while (i < 100) {
		std::cout << i << '\t' << i*i << '\n'; //square (i) << '\n';
		++i;
	}
		
	return 0;;
}
