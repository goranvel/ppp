#include <iostream>
#include <vector>
#include <stdexcept>

void print (const std::string name, const std::vector<int>& v);
void fibonacci (const int x, const int y, std::vector<int>& v, const int n);

int main (void) {
	try {
		std::vector<int> v;

		try {
			fibonacci (0, 1, v, 20);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}	

		try {
			v = std::vector<int>();
			fibonacci (5, 6, v, 10);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}	
	
		try {
			v = std::vector<int>();
			fibonacci (0, 1, v, 5);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}	
	
		try {
			v = std::vector<int>();
			fibonacci (0, 0, v, 5);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}

		try {
			v = std::vector<int>();
			fibonacci (2, 2, v, 5);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}	

		try {
			v = std::vector<int>();
			fibonacci (2, 2, v, 0);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}	
	
		try {
			v = std::vector<int>();
			fibonacci (0, -1, v, 5);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}	
	
		return 0;
	} catch (...) {
		std::cout << "EXITING unknown error occured\n";
	}

	return 1;
}

void print (const std::string name, const std::vector<int>& v) {
	std::cout << "Vector '" << name << "' has following elements:\n";

	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << (i + 1 == v.size() ? "" : " ");

	std::cout << "\n\n";
}

void fibonacci (int x, int y, std::vector<int>& v, const int n) {
	if (n < 1)
		throw std::runtime_error ("ERROR: 'N' cannot be less than 1.\n");
	v.push_back (x);
	v.push_back (y);

	for (int i = 2; i < n; ++i) { // 2 for current size of 'v'
		v.push_back(v[i-1] + v[i-2]);	
	}
}
