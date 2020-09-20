#include <iostream>

int f(const int a);
int main (void) {
	int a = 5;
	f (a);
	
	return 0;
}

int f (const int a) {
	a = 25;
}
