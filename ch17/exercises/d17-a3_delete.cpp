#include <iostream>

int main (void) {
	int* intArr = new int[10];

	for (int i = 0; i < 10; ++i)
		std::cout << intArr[i] << "\n";

	delete[] intArr;

	return 0;
}
