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
};

int main (void) {
	vector v(111);
	for (int i = 0; i < v.size(); ++i) {
		v.set (i, 1.1*i);
		std::cout << v.get(i)<<"\n";
	}

	return 0;
}
