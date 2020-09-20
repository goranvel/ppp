#include <iostream>

int main (void) {
	int size = 7;
	int arr[7];
	int *p = arr;

	*p = 1;
	++p;
	for (int i = 1; i < 7; ++i, ++p) 
		*p = *(p - 1) * 2;

	p = arr;
	for (; p - arr < 7; ++p)
		std::cout << *p << "\n";

	return 0;
}
