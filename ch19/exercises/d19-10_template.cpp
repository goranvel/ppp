#include <iostream>
#include <vector>

class out_of_range : public std::exception {
		std::string error;
	public:
		out_of_range () : error("Something went wrong") {
		}

		out_of_range (std::string e) : error (e) {
		}

		const std::string what() {
			return error;
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

		explicit Vector (int* arr, int s) : sz {s}, elem {new T[sz]} {
			for (int i = 0; i < sz; ++i)
				elem [i] = arr[i];
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

		T& at (int i) {
			if (i < 0)
				throw out_of_range ("Index cannot be netagive\n");

			if (i > sz)
				throw out_of_range ("Index greater than size\n");

			return elem [i];
		}

		const T& at (int i) const {
			if (i < 0)
				throw out_of_range ("Index cannot be netagive\n");

			if (i > sz)
				throw out_of_range ("Index greater than size\n");

			return elem [i];
		}

		// assigment operator[]
		T& operator[] (const int i) {
			/* not in std::vector for speed and compatibility
			if (i < 0)
				throw out_of_range ("Index cannot be netagive\n");

			if (i > sz)
				throw out_of_range ("Index greater than size\n");
			*/
			return elem [i];
		}

		const T& operator[] (const int i) const{
			/* see above
			if (i < 0)
				throw out_of_range ("Index cannot be netagive\n");

			if (i > sz)
				throw out_of_range ("Index greater than size\n");
			*/
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

template <class T>
class S {
		T val;
	public:
		S () : val (T()) {
		}

		S (T v) : val(v) {
		}

		T& get();

		T& operator=(const T&);

		template<class C>
		friend std::ostream& operator<<(std::ostream& os, const S<C>& s);
};

template <class T>
T& S<T>::get () {
	return val;
}

template <class T>
T& S<T>::operator= (const T& v) {
	val = v.get;

	return *this;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const S<T>& s) {
	os << s.val;
	return os;
}	

int main (void) {
	S<char>	sc ('G');
	S<int>	si (55);
	S<double>	sd (55.5);
	S<std::string> ss ("Goran");
	int ar[] = {3,5,7,9};
	S<Vector<int>> sv (Vector<int> (ar,4));

	std::cout << sc << " " << si << " " << sd << " " << ss << " " << sv << "\n";
	
	return 0;
}
