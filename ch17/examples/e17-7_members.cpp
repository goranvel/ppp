#include <iostream>

class CC {
	public:
		int aa;
		int bb;
		CC () : aa (0), bb(5) {
		}

		int getAA() {
			return aa;
		}

		int getBB() {
			return bb;
		}
};

int main (void) {
	CC *c = new CC();
	std::cout << c->getBB() << "\n";

	return 0;
}
