#include <iostream>

class vector {
		int vectorSize;
		double *elements;
	public:
		vector (int s) : vectorSize(s), elements (new double[s]) {
			for (int i = 0; i < vectorSize; ++i)
				elements[i] = 0;
		}

		~vector () {
			delete[] elements;
		}

		int size () const {
			return vectorSize;
		}

		double get (int n) const {
			return elements[n];
		}

		void set (const int n, double v) {
			elements[n] = v;
		}

		void printAll (std::ostream &os) const {
			for (int i = 0; i < size(); ++i)
				os << get(i) << "\n";
		}

};

int main (void) {
	int size = 20;
	vector v (size);
	
	for (int i; i < size; ++i)
		v.set(i, 100 + i);

	v.printAll (std::cout);

	return 0;
}
