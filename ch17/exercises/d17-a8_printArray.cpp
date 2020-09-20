#include <iostream>

void printArray (std::ostream& os, int *a, int n);

int main (void) {
	int n = 20;
	int* intArr = new int[n];

	for (int i; i < n; ++i)
		intArr[i] = 100 + i;

	printArray (std::cout, intArr, n);

	delete[] intArr;

	return 0;
}

void printArray (std::ostream& os, int *a, int n) {
	for (int i = 0; i < n; ++i)
		os << *(a + i) << "\n";
}
