#include <iostream>

int main (void) {
	for (int i = 0;; ++i) {
		int *bb = new int();

		if (!(i%10))
			std::cout << "allocated " << i << 2 << " bytes.\n";
	}

	return 0;
}

// WOW 31.x GB (99.9%)
