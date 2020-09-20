#include <iostream>

void printArray10 (std::ostream& os, int *a);

int main (void) {
	int* intArr = new int[10];

	printArray10 (std::cout, intArr);

	delete[] intArr;

	return 0;
}

void printArray10 (std::ostream& os, int *a) {
	for (int i = 0; i < 10; ++i)
		os << *(a + i) << "\n";
}
