#include <iostream>

template <typename T>
class Vector {
		int sz;			// number of elements
		T* elem;	// address of first element
		int space;		// number of elements plus "free space"/"slots"
						// for new elements ("the current allocation")
	public:
		Vector() : sz (0), elem (nullptr), space (0){
		}

		explicit Vector (int s) : sz {s}, elem {new T [s] {0}}, space {s} {
			for (int i = 0; i < sz; ++i)
				elem[i] = 0;
		}

		Vector ( const Vector& orig) : sz {orig.size()}, 
					elem {new T [orig.size()] {0}}, space {orig.space} {
			for (int i = 0; i < sz; ++i)
				elem [i] = orig[i];
		}

		Vector ( Vector&& v ) : sz {v.size()}, elem {v.elem}, space {v.space} {
			v.sz = 0;
			v.elem = nullptr;
		}

		~Vector () {
			delete[] elem;
		}

		void reserve (int newalloc) {
			if (newalloc <= space)	// never decrease allocation
				return;

			T* p = new T [newalloc];	// allocate new space

			for (int i = 0; i < sz; ++i)
				p[i] = elem[i];		// copy old elements;

			delete[] elem;		// dealocate old space

			elem = p;
			space = newalloc;
		}

		int capacity () const {
			return space;
		}
/*
		void resize (int newsize) {
			if (newsize <= 0)
				return;

			reserve (newsize);

			for (int i = sz; i < newsize; ++i)
				elem[i] = 0;	// initialize new elements

			sz = newsize;
		}
*/
		void resize (int newsize, T defVal = T()) {
			if (newsize <= 0)
				return;

			reserve (newsize);

			for (int i = sz; i < newsize; ++i)
				elem[i] = defVal;	// initialize new elements

			sz = newsize;
		}
		int size () const {
			return sz;
		}

		void push_back (double d) {
			if (space == 0)
				reserve (8);
			else if (space == sz)
				reserve (space << 1);
			
			elem [sz] = d;
			++sz;
		}

		Vector& operator= (const Vector& v) {
			if (this == &v)
				return *this;

			if (v.sz <= space) {
				for (int i = 0; i < v.sz; ++i)
					elem [i] = v.elem[i];

				sz = v.sz;
				return *this;
			}

			T* p = new T [v.sz];

			for (int i = 0; i < v.sz; ++i)
				p[i] = v.elem[i];

			delete [] elem;

			space = sz = v.sz;

			elem = p;

			return *this;
		}

		Vector& operator= (Vector&& v) {
			delete[] elem;

			elem = v.elem;
			sz = v.sz;
			space = v.space;
			v.elem = nullptr;
			v.sz = 0;
			v.space = 0;

			return *this;
		}
		// assigment operator[]
		T& operator[] (const int i) {
			if (i < 0)
				std::cerr << "Index cannot be netagive\n";

			if (i > sz)
				std::cerr << "Index greater than size\n";

			return elem [i];
		}

		T& operator[] (const int i) const{
			if (i < 0)
				std::cerr << "Index cannot be netagive\n";

			if (i > sz)
				std::cerr << "Index greater than size\n";

			return elem [i];
		} 
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const Vector<T>& v) {
	os << "[ ";
	for (int i = 0; i < v.size (); ++i)
		os << v[i] << " ";

	os << "]";

	return os;
}

int main (void) {
	Vector <double> v;

	v.resize (99);
	v.resize (200, 0.0);
	v.resize (300, 1.0);
	v[5] = 2;
	std::cout << v << "\n";

	return 0;
}
