#include <iostream>
#include <vector>

int main (void) {
	int a;
	int d = 7;
	int c {5};	// C++11 standard
	std::vector <int> v(10);
	std::vector <int> v2 {1,2,3,4}; // C++11 standard

//	const int c1; // error HAVE TO BE INITIALIZED
	const int c2 = 5;

	return 0;
}
