#include <iostream>

int main (void) {
	int size = 7;
	int arr[7];
	int *p = arr;

	*p = 1;

	for (int i = 1; i < 7; ++i, ++p) 
		*p = *(p - 1) * 2;

	return 0;
}
