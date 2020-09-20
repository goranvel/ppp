#include <iostream>

class Vector {
		int sz;
		double* elem;

	public:
		// empty constructor of size S
		Vector (int s) : sz (s), elem(new double[s]) {
			for (int i = 0; i < s; ++i)
				elem[i] = 0.0;
		}

		// constructor taking in list
		Vector (std::initializer_list<double> list) :
				sz (list.size()), elem {new double(list.size())}  {
			std::copy (list.begin(), list.end(), elem);
		}

		// copy constructor
		Vector (const Vector& orig) : sz (orig.size()), elem {new double [orig.size()]} {
	//		for (int i; i < orig.size(); ++i) 
	//			set(i, orig.get(i));
			std::copy (orig.elem, orig.elem + orig.size(), elem);
		}

		// move constructor
		Vector (Vector&& v) : sz (v.size()), elem (v.elem) {
			v.sz = 0;
			v.elem = nullptr;
		}

		// destructor
		~Vector () {
			delete elem;
		}

		Vector& operator=(const Vector& a) {
			delete[] elem;
			std::copy (a.elem, a.elem + a.size(), elem);

			sz = a.size();
			return *this;
		}

		Vector& operator=(Vector&& v) {
			delete[] elem;

			elem = v.elem;
			sz = v.sz;
			v.elem = nullptr;

			v.sz = 0;

			return *this;
		}

		int size() const {
			return sz;
		}

		double get (int n) const {
			return elem[n];
		}

		void set (const int n, double v) {
			elem[n] = v;
		}

		void printAll (std::ostream &os) const {
			os << "[ ";
			for (int i = 0; i < size(); ++i)
				os << get(i) << " ";

			os << "]\n";
		}
};

int main (void) {
	Vector v1 = {1.2, 7.89, 12.34};
/*
	Vector v2(2);

	v2[0] = 1.2;
	v2[1] = 7.78;
	v2[2] = 12.34;
*/
	v1.set(2, 2.2);
	Vector v2  (4);
	v2 = v1;
	v1.set(1, 5);
	std::cout << v2.get(1) << " " << v1.get(1) << "\n"; 

	return 0;
}
