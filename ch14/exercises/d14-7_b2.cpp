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

class B2 {
	public :
		virtual void pvf () = 0;
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

class D2 : public D1 {
	public :
		void pvf() {
			std::cout << "D2::pvf()\n";
		}
		
}; 

class D21 : public B2 {
		std::string member;
	public :
		D21 () {
			member = " D21 member ";
		}

		void pvf() {
			std::cout << "D21::pvf() " << member << "\n";
		}
		
};

class D22 : public B2 {
		int member;
	public :
		D22 () {
			member = 22;
		}

		void pvf() {
			std::cout << "D22::pvf()  D" << member << " member\n"; 
		}
};

void f (B2& b2) {
	b2.pvf();
}

int main (void) {
	D2 d;
	d.f();
	d.vf();
	d.pvf();
/*
	B1& br = d;
	br.f();		// outputs B::f()
	br.vf();	// outputs D::f()
	br.pvf();
*/	
	// errors out because b1 has pure function
/*	B1 b = d;
	b.f();	// outputs B::f()
	b.vf();	// outputs B::f() */ 

	D21 d21;
	d21.pvf();

	D22 d22;
	d22.pvf();

	f (d21);
	f (d22);
}
