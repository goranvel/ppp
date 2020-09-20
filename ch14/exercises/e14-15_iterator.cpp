#include <iostream>
#include <vector>
#include <list>

class Iterator {
	public :
		virtual double * next() = 0;
};

class Vector_iterator : public Iterator {
		std::vector<double> v;
		int current;
	public :
		Vector_iterator (std::vector<double> &vv) : v (vv) {
			current = 0;
		}
		double* next() {
			if (current >= v.size()) {
				return NULL;
			}
			return &v[current++];
		}
};

class List_iterator : public Iterator {
		std::list<double> list;
		std::list<double>::iterator iter;
	public :
		List_iterator (std::list<double> &ll) : list (ll) {
			iter = list.begin();
		}

		double* next() {
			if (iter == list.end()) {
				return NULL;
			}
			return &*iter++;
		}
};

void print (Iterator &i);

int main (void) {
	std::list<double> dl;
	std::vector<double> dv;

	for (int i = 0; i < 100; ++i) {
		dl.push_front(i);
		dv.push_back(i);
	}
	
	List_iterator il (dl);
	Vector_iterator iv (dv);

	print (il);
	print (iv);
	return 0;
}

void print (Iterator &i)	{
	for (double *d = i.next(); d != NULL; d = i.next()) {
		std::cout << *d << " ";
	}

	std::cout << "\n\n";
}
