#include <iostream>

class X { 
	public:
		int m;
		int mf (int v) {
			int old = m;
			m = v;
			return old;
		}
};

int main (void) {
	X var;
	var.m = 7;
	std::cout << var.m << "\n";

	int x = var.mf(9);
	std::cout << var.m << " " << x << "\n";

	return 0;
}
