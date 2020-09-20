#include <iostream>

class vector {
		int size;
		double* elem;

	public:
		// empty constructor of size S
		vector (int s) : size (s), elem(new double[s]) {
			for (int i = 0; i < size; ++i)
				elem[i] = 0.0;
		}

		// constructor taking in list
		vector (std::initializer_list<double> list) : size (list.size()), elem {new double(size)}  {
			std::copy (list.begin(), list.end(), elem);
		}

		// destructor
		~vector () {
			delete elem;
		}
};

int main (void) {
	vector v1 = {1.2, 7.89, 12.34};

	vector v2(2);

	v2[0] = 1.2;
	v2[1] = 7.78;
	v2[2] = 12.34;

	return 0;
}
