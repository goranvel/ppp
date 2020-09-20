#include <iostream>
#include <vector>

template <typename T>
struct S {
		T val;
	public:
		S () : val (T()) {
		}

		S (T v) : val(v) {
		}
};

int main (void) {
	S<int> i;
	S<char> c;
	S<double> d;
	S<std::string> s;
	S<std::vector<int>> v;

	S<int> ii (5);
	S<char> ci ('c');
	S<double> di (0.11);
	S<std::string> si ("Hello");
	S<std::vector<int>> vi (std::vector<int> {1, 5, 7});

	return 0;
}
