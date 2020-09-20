#include <iostream>

class Vector {
		int size;
		double* elem;

	public:
		// empty constructor of size S
		Vector (int s) : size (s), elem(new double[s]) {
			for (int i = 0; i < size; ++i)
				elem[i] = 0.0;
		}

		// constructor taking in list
		Vector (std::initializer_list<double> list) : size (list.size()), elem {new double(size)}  {
			std::copy (list.begin(), list.end(), elem);
		}

		// destructor
		~Vector () {
			delete elem;
		}

		double operator[] (const int index) {
			if (index < 0 || index > size)
				std::cerr << "Indesx out of bound";

			return elem[index];
		}

		void replace (int index, double val) {
			if (index < 0 || index > size)
				std::cerr << "Indesx out of bound";

			elem[index] = val;
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
	Vector v2 = v1;

	v1.replace(1, 5.0);

	std::cout << v2[1];
	return 0;
}
