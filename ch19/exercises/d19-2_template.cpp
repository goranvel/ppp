#include <iostream>

template <class T>
struct S {
	T val;
	S () : val (T()) {
	}

	S (T v) : val(v) {
	}
};

int main (void) {
	return 0;
}
