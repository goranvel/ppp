#include <iostream>
#include <vector>

template <class T>
struct S {
	T val;
	S () : val (T()) {
	}

	S (T v) : val(v) {
	}
};

int main (void) {
	S<char> sc ('G');
	S<int> si (55);
	S<double> sd (55.5);
	S<std::string> ss ("Goran");
	S<std::vector<int>> sv (std::vector<int> ({3,5,7}));

	return 0;
}
