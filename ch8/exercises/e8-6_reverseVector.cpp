#include <iostream>
#include <vector>
#include <stdexcept>

void print (const std::string name, const std::vector<std::string>& v);
void fibonacci (int x, int y, std::vector<std::string>& v, const int n);
void reverse (std::vector<std::string>& v);
std::string itoa (int n);

int main (void) {
	try {
		std::vector<std::string> v;

		try {
			fibonacci (0, 1, v, 20);
			reverse (v);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}	

		try {
			v = std::vector<std::string>();
			fibonacci (5, 5, v, 10);;
			reverse (v);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}	
	
		try {
			v = std::vector<std::string>();
			fibonacci (0, 1, v, 5);
			reverse (v);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}	
	
		try {
			v = std::vector<std::string>();
			fibonacci (0, 0, v, 5);
			reverse (v);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}

		try {
			v = std::vector<std::string>();
			fibonacci (2, 2, v, 5);
			reverse (v);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}	

		try {
			v = std::vector<std::string>();
			fibonacci (2, 2, v, 0);
			reverse (v);
			print ("v", v);
		} catch (std::runtime_error e) {
			std::cout << e.what () << '\n';
		}	
	
		try {
			v = std::vector<std::string>();
			fibonacci (0, -1, v, 10);
			reverse (v);
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

void print (const std::string name, const std::vector<std::string>& v) {
	std::cout << "Vector '" << name << "' has following elements:\n";

	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << (i + 1 == v.size() ? "" : " ");

	std::cout << "\n\n";
}

void fibonacci (int x, int y, std::vector<std::string>& v, const int n) {
	if (n < 1)
		throw std::runtime_error ("ERROR: 'N' cannot be less than 1.\n");
	v.push_back (itoa(x));
	v.push_back (itoa(y));
	
	for (int i = 2, temp = x + y; i < n; ++i) { // 2 for current size of 'v'
		v.push_back(itoa(temp));
		x = y;
		y = temp;
		temp = x + y;
	}
}

void reverse (std::vector<std::string>& v) {
	for (int i = 0, l = v.size() - 1; i < l; ++i, --l) {
		std::string temp = v[i];
		v[i] = v[l];
		v[l] = temp;
	}
}

std::string itoa (int n) {
	std::string a = "";
	if (n < 0) {
		a.push_back ('-');
		n = -n;
	}

	while (n > 9) {
		a.push_back(n % 10 + '0');
		n /= 10;
	}
	a.push_back(n % 10 + '0');
	for (int i = a[0] == '-' ? 1 : 0, l = a.size() - 1; i < l; ++i, --l) {
		char temp = a[i];
		a[i] = a[l];
		a[l] = temp;
	}

	return a;
}
