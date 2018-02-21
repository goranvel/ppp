#include <iostream>
#include <vector>
#include <stdexcept>

void print (const std::string name, const std::vector<int>& v);
void fibonacci (const int x, const int y, std::vector<int>& v, const int n);

int main (void) {
	try {
		int n = 3;
		std::vector<int> v;

		int a = 0, b = 1; 
		while (b + a > 0 && a + 1 > 0) {
			fibonacci (a, b, v, n);
			a = v[v.size() - 2];
			b = v[v.size() - 1];
			if (a + b <= 0) {
				a = b;
				b = 1;
			} 
			std::cout << a << " "<< b << " " << v.size() << ";\n";
		}
		print ("max", v);
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
	int sum = x + y;

	for (int i = 2; i < n && sum > 0; ++i, sum = v[i-1] + v[i-2]) { // 2 for current size of 'v'
		v.push_back(sum);	
	}
}
