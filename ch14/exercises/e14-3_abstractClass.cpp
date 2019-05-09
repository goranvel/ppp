#include <iostream>

class A {
	protected :
		A () {}

	public :
		virtual void f () = 0;
		virtual void f1 () = 0;
		virtual void f2 () = delete;
		void aa ();
};

class B : A {
	public :
		B () {}
		void f () {};
		void f1 () {};
		void f2 () {};
};

int main (void) {
	B a; // give abstract class error

	return 0;
}
