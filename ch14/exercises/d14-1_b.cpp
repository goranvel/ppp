#include <iostream>

class B {
	public :
		void f() {
			std::cout << "B::f()\n";
		}

		void vf () {
			std::cout << "B::vf()\n";
		}
};

int main (void) {
	B b;

	b.f();

	b.vf();
}
