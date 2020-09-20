#include <iostream>

class A {
		int a; 
		int b;
	protected:
		A () { a = 5; b = 6;}
	public :
		int getA() const {
			return a;
		}

		int getB() const {
			return b;
		}

		virtual void print() { std::cout << "\nA\n"; }
};

class B : public A { // for b object in main to be able to use getA() we need public
		
	public :
		int getAplusB () const {
			return getA() + getB();
		}

		void print() {std::cout <<"\nB\n"; }

};

void call (A &a) {
	a.print();
}

int main (void) {
	B b;

	std::cout << b.getAplusB () << " " << b.getA(); // will error out if no public is present
													// in class B : public A

	call (b);
	return 0;
}
