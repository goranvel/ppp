#include <iostream>

int negative (int) ;

int main (void) {
	int n = 6;
	n = negative (n);

	std::cout << n << "\n";

	return 0;
}

int negative (int n) {
	if (n > 5)
		return -n;
	else if (n < -5) {
		std::cout << "IN";
		return n;
	}

}
