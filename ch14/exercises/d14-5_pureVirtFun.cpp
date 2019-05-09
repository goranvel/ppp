#include <iostream>

class B1 {
	public :
		void f() {
			std::cout << "B1::f()\n";
		}

		virtual void vf () {
			std::cout << "B1::vf()\n";
		}

		virtual void pvf() = 0;
};

class D1 : public B1{
	public :
		void vf () {
			std::cout << "D1::vf()\n";
		}

		void f () {
			std::cout << "D1::f()\n";
		}

		virtual void pvf() {
			std::cout << "D1::pvf()\n";
		}
};

int main (void) {
	D1 d;
	d.f();
	d.vf();
	d.pvf();

	B1& br = d;
	br.f();		// outputs B::f()
	br.vf();	// outputs D::f()
	br.pvf();
	
	// errors out because b1 has pure function
/*	B1 b = d;
	b.f();	// outputs B::f()
	b.vf();	// outputs B::f() */ 
}
