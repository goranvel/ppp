#include <iostream>
#include <vector>

struct Range_error : std::out_of_range {
	int index;
	Range_error (int i) : std::out_of_range ("Range error"), index (i) {
	}
};

template <typename T>
class Vector {
		int sz;			// number of elements
		T* elem;		// address of first element
		int space;		// number of elements plus "free space"/"slots"
						// for new elements ("the current allocation")
	public:
		Vector() : sz (0), elem (nullptr), space (0){
		}

		explicit Vector (int s) : sz {s}, elem {new T [s] {0}}, space {s} {
			for (int i = 0; i < sz; ++i)
				elem[i] = 0;
		}

		Vector (int* elems, int s) : sz {s}, elem {new T[s] {0}}, space (s) {
			for (; s; --s) 
				elem [s] = elems[s];
			elem[s] = elems[s];
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

template <typename T>
struct S {
		T val;
		S () : val (T()) {
		}

		S (T v) : val(v) {
		}
};

template <typename T>
std::ostream& operator<< (std::ostream& os, S<T>& s) {
	os << s.val;

	return os;
}

int main (void) {
	S<int> i;
	S<char> c;
	S<double> d;
	S<std::string> s;
	S<Vector<int>> v;

	int *n = new int[5] {1, 2, 3, 4, 5};
	S<int> ii (5);
	S<char> ci ('c');
	S<double> di (0.11);
	S<std::string> si ("Hello");
//	S<std::vector<int>> vi (std::vector<int> {1, 5, 7}); // when using std::vector error's out
	Vector<int> vv (n, 5);
	std::cout << vv.size();
	S<Vector<int>> vi (vv);

	std::cout << i << " " << ii << "\n";
	std::cout << c << " " << ci << "\n";
	std::cout << d << " " << di << "\n";
	std::cout << s << " " << si << "\n";
	std::cout << v << " " << vi << "\n";

	return 0;
}
