#include <iostream>

void printArray (int[], int len);
void f(int[], int len);

int main (void) {
	int ga[10];
	ga[0] = 1;
	for (int i = 1; i < 10; ++i)
		ga[i] = ga[i - 1] << 1;

	printArray (ga, 10);
	
	f (ga, 10);
	return 0;
}

void printArray (int arr[], int len) {
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";

	std::cout << "\n";
}

void f (int arr[], int len) {
	int la[10];

	for (int i = 0; i < 10 && i < len; ++i)
		la[i] = arr[i];

	printArray (la, 10);
	int *p = new int[len];	

	for (int i = 0; i < 10 && i < len; ++i)
		p[i] = arr[i];

	printArray (p, len);

	delete[] p;
}
