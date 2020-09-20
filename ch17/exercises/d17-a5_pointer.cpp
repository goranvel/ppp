#include <iostream>

int main (void) {
	int* intArr = new int[10];
	
	for (int i; i < 10; ++i)
		*(intArr + i) = 100 + i;

	delete[] intArr;
	return 0;
}
