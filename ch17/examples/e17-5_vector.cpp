#include <iostream>

class vector {
		int vectorSize;
		double * elements;
	public:
		vector (int s) : vectorSize {s}, elements {new double[s]}  {
			for (int i = 0; i < s; ++i) 
				elements[i] = i;
		}
		~vector () {
			std::cout << "Destructor called";
			delete[] elements;
		}

		int size() {
			return vectorSize;
		}
};

vector* f(int n) {
	double *p = new double[n];

	vector v(n);

	delete[] p;

	return &v;
}		

int main (void) {
	vector *vv = f(5);
	std::cout << &vv[3] << '\n';
	return 0;
}
