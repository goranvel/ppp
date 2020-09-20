#include <iostream>

class X { 
		int m;
		int mf (int v) {
			int old = m;
			m = v;
			return old;
		}
	public:
		int f (int i ) {
			m = i;
			return mf (i);
		}
	private:
};

int main (void) {
	X x;
	int y = x.f (2);
	std::cout << y << "\n";
	return 0;
}
