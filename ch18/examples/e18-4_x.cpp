#include <iostream>
#include <vector>

class X {
		int val;
		void out (const std::string &s, int v) {
			std::cerr << this << " -> " << s << " :\t" << val << " (" << v << ")\n";
		}
	public:
		X () : val (0) {
			out ("X ()", val);
		}

		X (int v) : val (v) {
			out ("X (int)", val);
		}

		X (const X& x) : val (x.val) {
			out ("X (X&)", val);
		}

		~X() {
			out ("~X ()", val);
		}

		X& operator= (const X& x) {
			out ("X =", x.val);
			val = x.val;
			return *this;
		}

		void setVal (int v) {
			val = v;
		}

		void printVal () {
			std::cout << val << "\n";
		}
};

struct XX {
	X a;
	X b;
};

X copy (X a);
X copy2(X a);
X& ref_to (X& a);
X* make (int i);

/*
X ga;		// calls X()
X gb ();	// calls nothing :(
X gc (1);	// calls X(int)
*/
int main (void) {
	std::cout << "\n";
	X la (5);
//	X lb(); // WTF??? shouldn't this call X()
	X lb;
//	X lc(3);
	X *lp = new X()

//	la = X(5);
	std::cout << "\n";
//	lb = copy (la);
	lb = la; //copy2 (la);
/*
	X ld {6}; 
	X& le = ref_to (la); 

	delete make(7);
	delete make(8);

	std::vector<X> v(4);
	XX loc4;

	X* lf = new X(9);
	delete lf;
	X* lg = new X{99};
	delete lg;

	X* lh = new X[999];
	delete[] lh;
*/
	std::cout << "\n";

	return 0;
}

X copy (X a) {
	std::cout << "copy () :\t ";
	return a;
}

X copy2 (X a) {
	std::cout << "copy2 () :\t ";
	X aa = a;
	return aa;
}

X& ref_to (X& a) {
	std::cout << "ref ";
	return a;
}

X* make (int i) {
	X a(i);
	return new X(a);
}
