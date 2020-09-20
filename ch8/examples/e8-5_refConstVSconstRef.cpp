#include <iostream>

int g (const int & a);
// int h (const & int a); error

int main (void) {
	int a = 5;
	int b = 3;

	return a;
}

int g (const int& a) {
	return a * a;
}
/*
int h (const& int a) {
	return a * a;
} */
