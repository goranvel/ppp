#include <iostream>

template <class T>
struct S {
	T val;
};

int main (void) {
	S<int> si;
	S<double> sd;
	S<std::string> ss;

	return 0;
}
